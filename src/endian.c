#include "endian.h"

#define SRC_BYTE(_IDX) (((uint8_t *)src)[_IDX])
#define DST_BYTE(_IDX) (((uint8_t *)dst)[_IDX])


void
read_le_u8(uint8_t * restrict dst, void const * restrict src)
{
    *dst = SRC_BYTE(0);
}

void
read_le_i8(int8_t * restrict dst, void const * restrict src)
{
    *dst = SRC_BYTE(0);
}

void
read_le_u16(uint16_t * restrict dst, void const * restrict src)
{
    *dst = (SRC_BYTE(1) << 8) | SRC_BYTE(0);
}

void
read_le_i16(int16_t * restrict dst, void const * restrict src)
{
    *dst = (SRC_BYTE(1) << 8) | SRC_BYTE(0);
}

void
read_le_u32(uint32_t * restrict dst, void const * restrict src)
{
    *dst = (SRC_BYTE(3) << 24) | (SRC_BYTE(2) << 16) | (SRC_BYTE(1) << 8)
           | SRC_BYTE(0);
}

void
read_le_i32(int32_t * restrict dst, void const * restrict src)
{
    *dst = (SRC_BYTE(3) << 24) | (SRC_BYTE(2) << 16) | (SRC_BYTE(1) << 8)
           | SRC_BYTE(0);
}

void
read_le_u64(uint64_t * restrict dst, void const * restrict src)
{
    *dst = ((uint64_t)SRC_BYTE(7) << 56) | ((uint64_t)SRC_BYTE(6) << 48)
           | ((uint64_t)SRC_BYTE(5) << 40) | ((uint64_t)SRC_BYTE(4) << 32)
           | ((uint64_t)SRC_BYTE(3) << 24) | ((uint64_t)SRC_BYTE(2) << 16)
           | ((uint64_t)SRC_BYTE(1) << 8) | (uint64_t)SRC_BYTE(0);
}

void
read_le_i64(int64_t * restrict dst, void const * restrict src)
{
    *dst = ((uint64_t)SRC_BYTE(7) << 56) | ((uint64_t)SRC_BYTE(6) << 48)
           | ((uint64_t)SRC_BYTE(5) << 40) | ((uint64_t)SRC_BYTE(4) << 32)
           | ((uint64_t)SRC_BYTE(3) << 24) | ((uint64_t)SRC_BYTE(2) << 16)
           | ((uint64_t)SRC_BYTE(1) << 8) | (uint64_t)SRC_BYTE(0);
}

void
read_le_f(float * restrict dst, void const * restrict src)
{
    uint32_t val = (SRC_BYTE(3) << 24) | (SRC_BYTE(2) << 16)
                   | (SRC_BYTE(1) << 8) | SRC_BYTE(0);
    *((uint32_t *)dst) = val;
}

void
read_le_d(double * restrict dst, void const * restrict src)
{
    uint64_t val =
        ((uint64_t)SRC_BYTE(7) << 56) | ((uint64_t)SRC_BYTE(6) << 48)
        | ((uint64_t)SRC_BYTE(5) << 40) | ((uint64_t)SRC_BYTE(4) << 32)
        | ((uint64_t)SRC_BYTE(3) << 24) | ((uint64_t)SRC_BYTE(2) << 16)
        | ((uint64_t)SRC_BYTE(1) << 8) | (uint64_t)SRC_BYTE(0);
    *((uint64_t *)dst) = val;
}


void
read_be_u8(uint8_t * restrict dst, void const * restrict src)
{
    *dst = SRC_BYTE(0);
}

void
read_be_i8(int8_t * restrict dst, void const * restrict src)
{
    *dst = SRC_BYTE(0);
}

void
read_be_u16(uint16_t * restrict dst, void const * restrict src)
{
    *dst = (SRC_BYTE(0) << 8) | SRC_BYTE(1);
}

void
read_be_i16(int16_t * restrict dst, void const * restrict src)
{
    *dst = (SRC_BYTE(0) << 8) | SRC_BYTE(1);
}

void
read_be_u32(uint32_t * restrict dst, void const * restrict src)
{
    *dst = (SRC_BYTE(0) << 24) | (SRC_BYTE(1) << 16) | (SRC_BYTE(2) << 8)
           | SRC_BYTE(3);
}

void
read_be_i32(int32_t * restrict dst, void const * restrict src)
{
    *dst = (SRC_BYTE(0) << 24) | (SRC_BYTE(1) << 16) | (SRC_BYTE(2) << 8)
           | SRC_BYTE(3);
}

void
read_be_u64(uint64_t * restrict dst, void const * restrict src)
{
    *dst = ((uint64_t)SRC_BYTE(0) << 56) | ((uint64_t)SRC_BYTE(1) << 48)
           | ((uint64_t)SRC_BYTE(2) << 40) | ((uint64_t)SRC_BYTE(3) << 32)
           | ((uint64_t)SRC_BYTE(4) << 24) | ((uint64_t)SRC_BYTE(5) << 16)
           | ((uint64_t)SRC_BYTE(6) << 8) | (uint64_t)SRC_BYTE(7);
}

void
read_be_i64(int64_t * restrict dst, void const * restrict src)
{
    *dst = ((uint64_t)SRC_BYTE(0) << 56) | ((uint64_t)SRC_BYTE(1) << 48)
           | ((uint64_t)SRC_BYTE(2) << 40) | ((uint64_t)SRC_BYTE(3) << 32)
           | ((uint64_t)SRC_BYTE(4) << 24) | ((uint64_t)SRC_BYTE(5) << 16)
           | ((uint64_t)SRC_BYTE(6) << 8) | (uint64_t)SRC_BYTE(7);
}

void
read_be_f(float * restrict dst, void const * restrict src)
{
    uint32_t val = (SRC_BYTE(0) << 24) | (SRC_BYTE(1) << 16)
                   | (SRC_BYTE(2) << 8) | SRC_BYTE(3);
    *((uint32_t *)dst) = val;
}

void
read_be_d(double * restrict dst, void const * restrict src)
{
    uint64_t val =
        ((uint64_t)SRC_BYTE(0) << 56) | ((uint64_t)SRC_BYTE(1) << 48)
        | ((uint64_t)SRC_BYTE(2) << 40) | ((uint64_t)SRC_BYTE(3) << 32)
        | ((uint64_t)SRC_BYTE(4) << 24) | ((uint64_t)SRC_BYTE(5) << 16)
        | ((uint64_t)SRC_BYTE(6) << 8) | (uint64_t)SRC_BYTE(7);
    *((uint64_t *)dst) = val;
}

void
write_le_u8(void * dst, uint8_t val)
{
    DST_BYTE(0) = val;
}

void
write_le_i8(void * dst, int8_t val)
{
    DST_BYTE(0) = val;
}


void
write_le_u16(void * dst, uint16_t val)
{
    DST_BYTE(0) = val & 0xff;
    DST_BYTE(1) = (val >> 8) & 0xff;
}

void
write_le_i16(void * dst, int16_t val)
{
    DST_BYTE(0) = val & 0xff;
    DST_BYTE(1) = (val >> 8) & 0xff;
}

void
write_le_u32(void * dst, uint32_t val)
{
    DST_BYTE(0) = val & 0xff;
    DST_BYTE(1) = (val >> 8) & 0xff;
    DST_BYTE(2) = (val >> 16) & 0xff;
    DST_BYTE(3) = (val >> 24) & 0xff;
}

void
write_le_i32(void * dst, int32_t val)
{
    DST_BYTE(0) = val & 0xff;
    DST_BYTE(1) = (val >> 8) & 0xff;
    DST_BYTE(2) = (val >> 16) & 0xff;
    DST_BYTE(3) = (val >> 24) & 0xff;
}

void
write_le_u64(void * dst, uint64_t val)
{
    DST_BYTE(0) = val & 0xff;
    DST_BYTE(1) = (val >> 8) & 0xff;
    DST_BYTE(2) = (val >> 16) & 0xff;
    DST_BYTE(3) = (val >> 24) & 0xff;
    DST_BYTE(4) = (val >> 32) & 0xff;
    DST_BYTE(5) = (val >> 40) & 0xff;
    DST_BYTE(6) = (val >> 48) & 0xff;
    DST_BYTE(7) = (val >> 56) & 0xff;
}


void
write_le_i64(void * dst, int64_t val)
{
    DST_BYTE(0) = val & 0xff;
    DST_BYTE(1) = (val >> 8) & 0xff;
    DST_BYTE(2) = (val >> 16) & 0xff;
    DST_BYTE(3) = (val >> 24) & 0xff;
    DST_BYTE(4) = (val >> 32) & 0xff;
    DST_BYTE(5) = (val >> 40) & 0xff;
    DST_BYTE(6) = (val >> 48) & 0xff;
    DST_BYTE(7) = (val >> 56) & 0xff;
}

void
write_le_f(void * dst, float val)
{
    uint32_t val_cast = *((uint32_t *)&val);
    DST_BYTE(0)       = val_cast & 0xff;
    DST_BYTE(1)       = (val_cast >> 8) & 0xff;
    DST_BYTE(2)       = (val_cast >> 16) & 0xff;
    DST_BYTE(3)       = (val_cast >> 24) & 0xff;
}

void
write_le_d(void * dst, double val)
{
    uint64_t val_cast = *((uint64_t *)&val);
    DST_BYTE(0)       = val_cast & 0xff;
    DST_BYTE(1)       = (val_cast >> 8) & 0xff;
    DST_BYTE(2)       = (val_cast >> 16) & 0xff;
    DST_BYTE(3)       = (val_cast >> 24) & 0xff;
    DST_BYTE(4)       = (val_cast >> 32) & 0xff;
    DST_BYTE(5)       = (val_cast >> 40) & 0xff;
    DST_BYTE(6)       = (val_cast >> 48) & 0xff;
    DST_BYTE(7)       = (val_cast >> 56) & 0xff;
}

void
write_be_u8(void * dst, uint8_t val)
{
    DST_BYTE(0) = val;
}

void
write_be_i8(void * dst, int8_t val)
{
    DST_BYTE(0) = val;
}

void
write_be_u16(void * dst, uint16_t val)
{
    DST_BYTE(0) = (val >> 8) & 0xff;
    DST_BYTE(1) = val & 0xff;
}

void
write_be_i16(void * dst, int16_t val)
{
    DST_BYTE(0) = (val >> 8) & 0xff;
    DST_BYTE(1) = val & 0xff;
}

void
write_be_u32(void * dst, uint32_t val)
{
    DST_BYTE(0) = (val >> 24) & 0xff;
    DST_BYTE(1) = (val >> 16) & 0xff;
    DST_BYTE(2) = (val >> 8) & 0xff;
    DST_BYTE(3) = val & 0xff;
}

void
write_be_i32(void * dst, int32_t val)
{
    DST_BYTE(0) = (val >> 24) & 0xff;
    DST_BYTE(1) = (val >> 16) & 0xff;
    DST_BYTE(2) = (val >> 8) & 0xff;
    DST_BYTE(3) = val & 0xff;
}

void
write_be_u64(void * dst, uint64_t val)
{
    DST_BYTE(0) = (val >> 56) & 0xff;
    DST_BYTE(1) = (val >> 48) & 0xff;
    DST_BYTE(2) = (val >> 40) & 0xff;
    DST_BYTE(3) = (val >> 32) & 0xff;
    DST_BYTE(4) = (val >> 24) & 0xff;
    DST_BYTE(5) = (val >> 16) & 0xff;
    DST_BYTE(6) = (val >> 8) & 0xff;
    DST_BYTE(7) = val & 0xff;
}


void
write_be_i64(void * dst, int64_t val)
{
    DST_BYTE(0) = (val >> 56) & 0xff;
    DST_BYTE(1) = (val >> 48) & 0xff;
    DST_BYTE(2) = (val >> 40) & 0xff;
    DST_BYTE(3) = (val >> 32) & 0xff;
    DST_BYTE(4) = (val >> 24) & 0xff;
    DST_BYTE(5) = (val >> 16) & 0xff;
    DST_BYTE(6) = (val >> 8) & 0xff;
    DST_BYTE(7) = val & 0xff;
}

void
write_be_f(void * dst, float val)
{
    uint32_t val_cast = *((uint32_t *)&val);
    DST_BYTE(0)       = (val_cast >> 24) & 0xff;
    DST_BYTE(1)       = (val_cast >> 16) & 0xff;
    DST_BYTE(2)       = (val_cast >> 8) & 0xff;
    DST_BYTE(3)       = val_cast & 0xff;
}

void
write_be_d(void * dst, double val)
{
    uint64_t val_cast = *((uint64_t *)&val);
    DST_BYTE(0)       = (val_cast >> 56) & 0xff;
    DST_BYTE(1)       = (val_cast >> 48) & 0xff;
    DST_BYTE(2)       = (val_cast >> 40) & 0xff;
    DST_BYTE(3)       = (val_cast >> 32) & 0xff;
    DST_BYTE(4)       = (val_cast >> 24) & 0xff;
    DST_BYTE(5)       = (val_cast >> 16) & 0xff;
    DST_BYTE(6)       = (val_cast >> 8) & 0xff;
    DST_BYTE(7)       = val_cast & 0xff;
}
