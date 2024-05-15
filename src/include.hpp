#pragma once

#include "image.hpp"

#include <filesystem>
#include <array>


namespace img = image;
namespace fs = std::filesystem;


constexpr u64 N_ASCII_CHARS = 95;

constexpr auto ROOT = "C:/D_Data/Repos/BitmapFont";

const auto ROOT_DIR = fs::path(ROOT);

const auto ASCII_IMAGE_DIR = ROOT_DIR / "png_in";
const auto CPP_OUT_DIR = ROOT_DIR / "cpp_out";
const auto RENDER_OUT_PATH = ROOT_DIR / "png_out/text.png";

std::array<const char*, 4> ASCII_IMAGE_FILES = {
    "ascii_5.png",
    "ascii_8.png",
    "joystick_8.png",
    "pixiloid_sans_8.png"
};