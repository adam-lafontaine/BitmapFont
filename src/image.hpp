#pragma once

#include "types.hpp"

#include <functional>

template <class F>
using fn = std::function<F>;


/*  image types */

namespace image
{
    class RGBAu8
    {
    public:
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    };

    using Pixel = RGBAu8;
    using Image = Matrix2D<Pixel>;
    using ImageView = MatrixView2D<Pixel>;    
    using ImageGray = Matrix2D<u8>;
    using GrayView = MatrixView2D<u8>;
    

    template <typename T>
    class MatrixSubView2D
    {
    public:
        T*  matrix_data_;
        u32 matrix_width;

        u32 width;
        u32 height;

        union
        {
            Rect2Du32 range;

            struct
            {
                u32 x_begin;
                u32 x_end;
                u32 y_begin;
                u32 y_end;
            };
        };
    };


    using SubView = MatrixSubView2D<Pixel>;    
    using GraySubView = MatrixSubView2D<u8>;
}


namespace image
{
    constexpr inline Pixel to_pixel(u8 red, u8 green, u8 blue, u8 alpha)
    {
        Pixel p{};
        p.red = red;
        p.green = green;
        p.blue = blue;
        p.alpha = alpha;

        return p;
    }


    constexpr inline Pixel to_pixel(u8 red, u8 green, u8 blue)
    {
        return to_pixel(red, green, blue, 255);
    }


    constexpr inline Pixel to_pixel(u8 gray)
    {
        return to_pixel(gray, gray, gray);
    }
}


/* create destroy */

namespace image
{
    bool create_image(Image& image, u32 width, u32 height);

    void destroy_image(Image& image);
}


/* make_view */

namespace image
{
    ImageView make_view(Image const& image);
}


/* sub_view */

namespace image
{
    template <typename T>
    static MatrixSubView2D<T> sub_view(Matrix2D<T> const& image, Rect2Du32 const& range)
    {
        MatrixSubView2D<T> sub_view;

		sub_view.matrix_data = image.data_;
		sub_view.matrix_width = image.width;
		
		sub_view.range = range;

		sub_view.width = range.x_end - range.x_begin;
		sub_view.height = range.y_end - range.y_begin;

		return sub_view;
    }


    template <typename T>
    static MatrixSubView2D<T> sub_view(MatrixView2D<T> const& view, Rect2Du32 const& range)
    {
        MatrixSubView2D<T> sub_view{};

        sub_view.matrix_data_ = view.matrix_data_;
        sub_view.matrix_width = view.width;
        sub_view.range = range;
        sub_view.width = range.x_end - range.x_begin;
        sub_view.height = range.y_end - range.y_begin;

        return sub_view;
    }


    template <typename T>
    static MatrixSubView2D<T> sub_view(MatrixSubView2D<T> const& view, Rect2Du32 const& range)
    {
        MatrixSubView2D<T> sub_view{};

        sub_view.matrix_data_ = view.matrix_data_;
        sub_view.matrix_width = view.matrix_width;

        sub_view.x_begin = range.x_begin + view.x_begin;
		sub_view.x_end = range.x_end + view.x_begin;
		sub_view.y_begin = range.y_begin + view.y_begin;
		sub_view.y_end = range.y_end + view.y_begin;

		sub_view.width = range.x_end - range.x_begin;
		sub_view.height = range.y_end - range.y_begin;

        return sub_view;
    }
}


/* transform */

namespace image
{
    void transform(GraySubView const& src, SubView const& dst, fn<Pixel(u8, Pixel)> const& func);
}


/* read write */

namespace image
{    
    bool read_image_from_file(const char* img_path_src, Image& image_dst);

    bool write_image(Image const& image_src, const char* img_path_dst);
}


/* span */

namespace image
{
    template <typename T>
    SpanView<T> to_span(Matrix2D<T> const& mat)
    {
        SpanView<T> span{};

        span.begin = mat.data_;
        span.length = mat.width * mat.height;

        return span;
    }


    template <typename T>
    SpanView<T> to_span(MatrixView2D<T> const& view)
    {
        SpanView<T> span{};

        span.begin = view.matrix_data_;
        span.length = view.width * view.height;

        return span;
    }


    template <typename T>
    static inline SpanView<T> row_span(MatrixView2D<T> const& view, u32 y)
    {
        SpanView<T> span{};

        span.begin = view.matrix_data_ + (u64)(y * view.width);
        span.length = view.width;

        return span;
    }


    template <typename T>
    static inline SpanView<T> row_span(MatrixSubView2D<T> const& view, u32 y)
    {
        SpanView<T> span{};

        span.begin = view.matrix_data_ + (u64)((view.y_begin + y) * view.matrix_width + view.x_begin);
        span.length = view.width;

        return span;
    }
}


/* rect */

namespace image
{    
    static inline Rect2Du32 make_range(u32 width, u32 height)
    {
        Rect2Du32 range{};
        range.x_begin = 0;
        range.x_end = width;
        range.y_begin = 0;
        range.y_end = height;

        return range;
    }
}