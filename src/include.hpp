#pragma once

#include "image.hpp"

#include <filesystem>


namespace img = image;
namespace fs = std::filesystem;


constexpr u64 N_ASCII_CHARS = 95;

constexpr auto ROOT = "C:/D_Data/Repos/BitmapFont";

const auto ROOT_DIR = fs::path(ROOT);

const auto ASCII_IMAGE_PATH = ROOT_DIR / "png_in/pixiloid_sans_h8.png";
const auto CPP_OUT_PATH = ROOT_DIR / "cpp_out/code.cpp";
const auto RENDER_OUT_PATH = ROOT_DIR / "png_out/text.png";