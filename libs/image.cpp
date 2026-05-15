#include "image.hpp"
#include "stb_image_options.hpp"


/* create destroy */

namespace image
{
    bool create_image(Image& image, u32 width, u32 height)
    {
        auto data = (Pixel*)std::malloc((size_t)(sizeof(Pixel) * width * height));
        if (!data)
        {
            return false;
        }

        image.data_ = data;
        image.width = width;
        image.height = height;

        return true;
    }

    
    void destroy_image(Image& image)
    {
        if (image.data_)
		{
			std::free((void*)image.data_);
			image.data_ = nullptr;
		}

		image.width = 0;
		image.height = 0;
    }
}


/* make view */

namespace image
{
    ImageView make_view(Image const& image)
    {
        ImageView view{};

        view.width = image.width;
        view.height = image.height;
        view.matrix_data_ = image.data_;

        return view;
    }
}


/* transform */

namespace image
{
    template <typename P_SRC, typename P_DST>
    static void transform_span(SpanView<P_SRC> const& src, SpanView<P_DST> const& dst, fn<Pixel(P_SRC, P_DST)> const& func)
    {
        auto s = src.begin;
        auto d = dst.begin;

        for (u32 i = 0; i < src.length; i++)
        {
            d[i] = func(s[i], d[i]);
        }
    }


    void transform(GraySubView const& src, SubView const& dst, fn<Pixel(u8, Pixel)> const& func)
    {
        assert(src.matrix_data_);
        assert(dst.matrix_data_);
        assert(dst.width == src.width);
        assert(dst.height == src.height);

        for (u32 y = 0; y < src.height; y++)
        {
            transform_span(row_span(src, y), row_span(dst, y), func);
        }
    }
}


/* read write */

namespace image
{
    static bool has_extension(const char* filename, const char* ext)
    {
        size_t file_length = std::strlen(filename);
        size_t ext_length = std::strlen(ext);

        return !std::strcmp(&filename[file_length - ext_length], ext);
    }


    static bool is_valid_image_file(const char* filename)
    {
        return 
            has_extension(filename, ".bmp") || 
            has_extension(filename, ".BMP") ||
            has_extension(filename, ".png")||
            has_extension(filename, ".PNG");
    }


    static bool is_bmp(const char* filename)
    {
        return has_extension(filename, ".bmp") || has_extension(filename, ".BMP");
    }


    static bool is_png(const char* filename)
    {
        return has_extension(filename, ".png") || has_extension(filename, ".PNG");
    }


    bool read_image_from_file(const char* img_path_src, Image& image_dst)
	{
        auto is_valid_file = is_valid_image_file(img_path_src);
        assert(is_valid_file && "invalid image file");

        if (!is_valid_file)
        {
            return false;
        }

		int width = 0;
		int height = 0;
		int image_channels = 0;
		int desired_channels = 4;

		auto data = (Pixel*)stbi_load(img_path_src, &width, &height, &image_channels, desired_channels);

		assert(data && "stbi_load() - no image data");
		assert(width && "stbi_load() - no image width");
		assert(height && "stbi_load() - no image height");

		if (!data)
		{
			return false;
		}

		image_dst.data_ = data;
		image_dst.width = width;
		image_dst.height = height;

		return true;
	}


    bool write_image(Image const& image_src, const char* img_path_dst)
    {
        assert(image_src.width);
		assert(image_src.height);
		assert(image_src.data_);

        auto is_valid_file = is_valid_image_file(img_path_dst);
        assert(is_valid_file && "invalid image file");

        if (!is_valid_file)
        {
            return false;
        }

		int width = (int)(image_src.width);
		int height = (int)(image_src.height);
		int channels = 4;
		auto const data = image_src.data_;

		int result = 0;

		if(is_bmp(img_path_dst))
		{
			result = stbi_write_bmp(img_path_dst, width, height, channels, data);
			assert(result);
		}
		else if(is_png(img_path_dst))
		{
			int stride_in_bytes = width * channels;

			result = stbi_write_png(img_path_dst, width, height, channels, data, stride_in_bytes);
			assert(result);
		}
		else
		{
			assert(false);
		}

		return (bool)result;
    }
}