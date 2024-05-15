#include "include.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cassert>


constexpr auto BLACK = img::to_pixel(0);
constexpr auto TRANSPARENT = img::to_pixel(0, 0, 0, 0);


static bool is_black(img::Pixel p)
{
    return p.alpha > 0 && p.red == 0 && p.green == 0 && p.blue == 0;
}


static bool is_white(img::Pixel p)
{
    return p.alpha > 0 && p.red == 255 && p.green == 255 && p.blue == 255;
}


static bool is_gray(img::Pixel p)
{
    return p.alpha > 0 && p.red == p.green && p.red == p.blue;
}


static bool is_boundary(img::Pixel p)
{
    return p.alpha > 0 && !is_black(p);
}


static void format_image(img::Image const& image)
{
    auto view = img::make_view(image);

    auto span = to_span(image);
    for (u32 i = 0; i < span.length; i++)
    {
        auto& p = span.begin[i];
        if (!p.alpha || is_black(p))
        {
            continue;
        }
        else if (is_white(p))
        {
            p = TRANSPARENT;
        }
        else if (is_gray(p))
        {
            p = BLACK;
        }
       
    }
}


static bool validate_h(img::Image const& raw_ascii)
{
    auto view = img::make_view(raw_ascii);
    u32 count = 0;

    auto row = img::row_span(view, 0);

    printf("count: %u\n", count);

    return count == N_ASCII_CHARS;
}


static std::vector<img::SubView> split_chars_h(img::Image const& raw_ascii)
{
    auto view = img::make_view(raw_ascii);

    auto const w = view.width;
    auto const h = view.height;

    std::vector<img::SubView> list;

    Rect2Du32 range{};
    range.x_begin = 0;
    range.x_end = view.width;
    range.y_begin = 0;
    range.y_end = h;    

    int count = 0;

    auto top_row = img::row_span(view, 0);
    for (u32 x = 0; x < w; x++)
    {
        if (is_boundary(top_row.begin[x]) || x == w - 1)
        {
            if (x > range.x_begin)
            {
                range.x_end = x;
                list.push_back(img::sub_view(view, range));
            }

            range.x_begin = x + 1;
        }
    }

    assert(list.size() == N_ASCII_CHARS);

    return list;
}


static std::string to_cpp_text(img::Image const& raw_ascii)
{
    auto list = split_chars_h(raw_ascii);    

    std::ostringstream oss;

    oss
    << "/*** " 
    << ASCII_IMAGE_PATH.filename()
    << " ***/\n"
    << "static const struct\n"
    << "{\n"
    << "    unsigned char height;\n"
    << "    unsigned char widths[95];\n"
    << "    const char* u8_pixel_data[95];\n"

    << "}\n"

    << "ascii_chars = \n"

    << "{\n"
    << "    " << list[0].height << ", // height\n\n";

    oss
    << "    { // widths\n"
    << "        ";

    for (auto const& view : list)
    {
        oss << view.width << ", ";
    }

    oss
    << "\n"
    << "    },\n\n";

    oss
    << "    { // u8_pixel_data\n";

    int char_id = 32;
    for (auto const& view : list)
    {
        oss << "        /* ";
        oss << "'" << (char)(char_id++) << "'";
        oss << " */ \"";

        for (u32 y = 0; y < view.height; y++)
        {
            auto row = img::row_span(view, y);
            for (u32 x = 0; x < row.length; x++)
            {
                oss << '\\' << (row.begin[x].alpha ? 1 : 0);
            }
        }

        oss << "\",\n";
    }

    oss
    << "    } //\n"
    << "};\n";

    return oss.str();
}


static bool write_to_file(std::string const& str, cstr filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    file << str;

    file.close();

    return true;
}



int main()
{
    img::Image image;
    if(!img::read_image_from_file(ASCII_IMAGE_PATH.string().c_str(), image))
    {
        printf("Did not read image\n");
        return 1;
    }

    format_image(image);

    auto const cpp_text = to_cpp_text(image);

    if (!write_to_file(cpp_text, CPP_OUT_PATH.string().c_str()))
    {
        printf("Did not write file\n");
        return 1;
    }
    
    img::destroy_image(image);

    return 0;
}