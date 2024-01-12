#pragma once

#include <cstdint>
#include <cstddef>

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using f32 = float;
using f64 = double;

using b32 = u32;
using b8 = u8;

using cstr = const char*;


template <typename T>
class Rect2D
{
public:
	T x_begin;
	T x_end;
	T y_begin;
	T y_end;
};


template <typename T>
class Matrix2D
{
public:
	T* data_ = nullptr;
	u32 width = 0;
	u32 height = 0;
};


template <typename T>
class MatrixView2D
{
public:

	T* matrix_data_ = nullptr;

	u32 width = 0;
	u32 height = 0;
};


template <typename T>
class SpanView
{
public:
	T* begin = nullptr;
	u32 length = 0;
};


using Rect2Du32 = Rect2D<u32>;
