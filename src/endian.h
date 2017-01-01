#ifndef ENDIAN_H
#define ENDIAN_H

#include <stdint.h>


void
read_le_u8(uint8_t * restrict dst, void const * restrict src);

void
read_le_i8(int8_t * restrict dst, void const * restrict src);

void
read_le_u16(uint16_t * restrict dst, void const * restrict src);

void
read_le_i16(int16_t * restrict dst, void const * restrict src);

void
read_le_u32(uint32_t * restrict dst, void const * restrict src);

void
read_le_i32(int32_t * restrict dst, void const * restrict src);

void
read_le_u32(uint32_t * restrict dst, void const * restrict src);

void
read_le_i32(int32_t * restrict dst, void const * restrict src);

void
read_le_u64(uint64_t * restrict dst, void const * restrict src);

void
read_le_i64(int64_t * restrict dst, void const * restrict src);

void
read_le_f(float * restrict dst, void const * restrict src);

void
read_le_d(double * restrict dst, void const * restrict src);


#define read_le(_DST, _SRC)                                                    \
    _Generic((_DST),                                                           \
             uint8_t*:  read_le_u8,                                            \
             int8_t*:   read_le_i8,                                            \
             uint16_t*: read_le_u16,                                           \
             int16_t*:  read_le_i16,                                           \
             uint32_t*: read_le_u32,                                           \
             int32_t*:  read_le_i32,                                           \
             uint64_t*: read_le_u64,                                           \
             int64_t*:  read_le_i64,                                           \
             float*:    read_le_f,                                             \
             double*:   read_le_d                                              \
)(_DST, _SRC)

void
read_be_u8(uint8_t * restrict dst, void const * restrict src);

void
read_be_i8(int8_t * restrict dst, void const * restrict src);

void
read_be_u16(uint16_t * restrict dst, void const * restrict src);

void
read_be_i16(int16_t * restrict dst, void const * restrict src);

void
read_be_u32(uint32_t * restrict dst, void const * restrict src);

void
read_be_i32(int32_t * restrict dst, void const * restrict src);

void
read_be_u32(uint32_t * restrict dst, void const * restrict src);

void
read_be_i32(int32_t * restrict dst, void const * restrict src);

void
read_be_u64(uint64_t * restrict dst, void const * restrict src);

void
read_be_i64(int64_t * restrict dst, void const * restrict src);

void
read_be_f(float * restrict dst, void const * restrict src);

void
read_be_d(double * restrict dst, void const * restrict src);

#define read_be(_DST, _SRC)                                                    \
    _Generic((_DST),                                                           \
             uint8_t*:  read_be_u8,                                            \
             int8_t*:   read_be_i8,                                            \
             uint16_t*: read_be_u16,                                           \
             int16_t*:  read_be_i16,                                           \
             uint32_t*: read_be_u32,                                           \
             int32_t*:  read_be_i32,                                           \
             uint64_t*: read_be_u64,                                           \
             int64_t*:  read_be_i64,                                           \
             float*:    read_be_f,                                             \
             double*:   read_be_d                                              \
)(_DST, _SRC)

void
write_le_u8(void * dst, uint8_t val);

void
write_le_i8(void * dst, int8_t val);

void
write_le_u16(void * dst, uint16_t val);

void
write_le_i16(void * dst, int16_t val);

void
write_le_u32(void * dst, uint32_t val);

void
write_le_i32(void * dst, int32_t val);

void
write_le_u64(void * dst, uint64_t val);

void
write_le_i64(void * dst, int64_t val);

void
write_le_f(void * dst, float val);

void
write_le_d(void * dst, double val);

#define write_le(_DST, _VAL)                                                   \
    _Generic((_VAL),                                                           \
             uint8_t:  write_le_u8,                                            \
             int8_t:   write_le_i8,                                            \
             uint16_t: write_le_u16,                                           \
             int16_t:  write_le_i16,                                           \
             uint32_t: write_le_u32,                                           \
             int32_t:  write_le_i32,                                           \
             uint64_t: write_le_u64,                                           \
             int64_t:  write_le_i64,                                           \
             float:    write_le_f,                                             \
             double:   write_le_d                                              \
             )(_DST, _VAL)

void
write_be_u8(void * dst, uint8_t val);

void
write_be_i8(void * dst, int8_t val);

void
write_be_u16(void * dst, uint16_t val);

void
write_be_i16(void * dst, int16_t val);

void
write_be_u32(void * dst, uint32_t val);

void
write_be_i32(void * dst, int32_t val);

void
write_be_u64(void * dst, uint64_t val);

void
write_be_i64(void * dst, int64_t val);

void
write_be_f(void * dst, float val);

void
write_be_d(void * dst, double val);

#define write_be(_DST, _VAL)                                                   \
    _Generic((_VAL),                                                           \
             uint8_t:  write_be_u8,                                            \
             int8_t:   write_be_i8,                                            \
             uint16_t: write_be_u16,                                           \
             int16_t:  write_be_i16,                                           \
             uint32_t: write_be_u32,                                           \
             int32_t:  write_be_i32,                                           \
             uint64_t: write_be_u64,                                           \
             int64_t:  write_be_i64,                                           \
             float:    write_be_f,                                             \
             double:   write_be_d                                              \
)(_DST, _VAL)

#endif /* ENDIAN_H */
