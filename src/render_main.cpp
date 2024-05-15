#include "include.hpp"

#include <cstring>
#include <cassert>


static img::GrayView make_ascii_view(char c)
{
#include "../cpp_out/joystick_8.cpp"

    auto& ascii = ascii_chars;

    auto id = c - ' ';

    img::GrayView view{};
    view.width = (u32)ascii.widths[id];
    view.height = (u32)ascii.height;
    view.matrix_data_ = (u8*)ascii.u8_pixel_data[id];

    return view;
}


static img::Pixel mask_char(u8 mask, img::Pixel p)
{
    return (mask) ? img::to_pixel(0, 0, 255) : p;
}


static void render_text(cstr text, img::SubView const& dst)
{
    auto const len = std::strlen(text);

    Rect2Du32 d_range = { 0 };

    u32 width = 0;
    u32 height = 0;
    i32 w_remaining = dst.width;

    for (u32 i = 0; i < len && w_remaining > 0; i++)
    {
        auto ch_filter = make_ascii_view(text[i]);

        width = std::min(ch_filter.width, (u32)w_remaining);
        height = std::min(ch_filter.height, dst.height);

        d_range.x_end += width;
        d_range.y_end = height;

        auto s_view = img::sub_view(ch_filter, img::make_range(width, height));
        auto d_view = img::sub_view(dst, d_range);
        
        img::transform(s_view, d_view, mask_char);

        d_range.x_begin = d_range.x_end;
        w_remaining -= width;
    }
}


int main()
{
    auto const text = "The quick brown fox jumps over the lazy dog";
    u32 width = 500;
    u32 height = 50;

    img::Image image;
    if (!img::create_image(image, width, height))
    {
        return 1;
    }

    Rect2Du32 range{};
    range.x_begin = 10;
    range.x_end = 490;
    range.y_begin = 10;
    range.y_end = 40;

    render_text(text, img::sub_view(image, range));

    img::write_image(image, RENDER_OUT_PATH.string().c_str());

    img::destroy_image(image);

    return 0;
}