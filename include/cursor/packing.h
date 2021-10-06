#ifndef PACKING_H
#define PACKING_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void
unpack_le_u8(uint8_t * dst, void const * src);

void
unpack_le_i8(int8_t * dst, void const * src);

void
unpack_le_u16(uint16_t * dst, void const * src);

void
unpack_le_i16(int16_t * dst, void const * src);

void
unpack_le_u32(uint32_t * dst, void const * src);

void
unpack_le_i32(int32_t * dst, void const * src);

void
unpack_le_u32(uint32_t * dst, void const * src);

void
unpack_le_i32(int32_t * dst, void const * src);

void
unpack_le_u64(uint64_t * dst, void const * src);

void
unpack_le_i64(int64_t * dst, void const * src);

void
unpack_le_f(float * dst, void const * src);

void
unpack_le_d(double * dst, void const * src);


void
unpack_be_u8(uint8_t * dst, void const * src);

void
unpack_be_i8(int8_t * dst, void const * src);

void
unpack_be_u16(uint16_t * dst, void const * src);

void
unpack_be_i16(int16_t * dst, void const * src);

void
unpack_be_u32(uint32_t * dst, void const * src);

void
unpack_be_i32(int32_t * dst, void const * src);

void
unpack_be_u32(uint32_t * dst, void const * src);

void
unpack_be_i32(int32_t * dst, void const * src);

void
unpack_be_u64(uint64_t * dst, void const * src);

void
unpack_be_i64(int64_t * dst, void const * src);

void
unpack_be_f(float * dst, void const * src);

void
unpack_be_d(double * dst, void const * src);


void
pack_le_u8(void * dst, uint8_t val);

void
pack_le_i8(void * dst, int8_t val);

void
pack_le_u16(void * dst, uint16_t val);

void
pack_le_i16(void * dst, int16_t val);

void
pack_le_u32(void * dst, uint32_t val);

void
pack_le_i32(void * dst, int32_t val);

void
pack_le_u64(void * dst, uint64_t val);

void
pack_le_i64(void * dst, int64_t val);

void
pack_le_f(void * dst, float val);

void
pack_le_d(void * dst, double val);


void
pack_be_u8(void * dst, uint8_t val);

void
pack_be_i8(void * dst, int8_t val);

void
pack_be_u16(void * dst, uint16_t val);

void
pack_be_i16(void * dst, int16_t val);

void
pack_be_u32(void * dst, uint32_t val);

void
pack_be_i32(void * dst, int32_t val);

void
pack_be_u64(void * dst, uint64_t val);

void
pack_be_i64(void * dst, int64_t val);

void
pack_be_f(void * dst, float val);

void
pack_be_d(void * dst, double val);

#ifdef __cplusplus
}
#endif

#endif /* PACKING_H */
