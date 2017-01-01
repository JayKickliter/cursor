#ifndef BUFRW_H
#define BUFRW_H

#include <stddef.h>
#include <stdint.h>

/* A context for [de]serializing data from a buffer */
struct bufrw
{
    uint8_t * restrict buf;
    size_t             len;
    size_t             pos;
};

enum bufrw_res
{
    /* The read/write operation was successful */
    bufrw_res_ok,
    /* No more bytes left in the buffer */
    bufrw_buf_err_exhausted,
};


/**
 * Creates and returns a new bufrw object
 */
struct bufrw
bufrw_new(void * buf, size_t buflen);


enum bufrw_res
bufrw_read_le_u8(struct bufrw * restrict reader, uint8_t * restrict dst);

enum bufrw_res
bufrw_read_le_i8(struct bufrw * restrict reader, int8_t * restrict dst);

enum bufrw_res
bufrw_read_le_u16(struct bufrw * restrict reader, uint16_t * restrict dst);

enum bufrw_res
bufrw_read_le_i16(struct bufrw * restrict reader, int16_t * restrict dst);

enum bufrw_res
bufrw_read_le_u32(struct bufrw * restrict reader, uint32_t * restrict dst);

enum bufrw_res
bufrw_read_le_i32(struct bufrw * restrict reader, int32_t * restrict dst);

enum bufrw_res
bufrw_read_le_u64(struct bufrw * restrict reader, uint64_t * restrict dst);

enum bufrw_res
bufrw_read_le_i64(struct bufrw * restrict reader, int64_t * restrict dst);

enum bufrw_res
bufrw_read_le_f(struct bufrw * restrict reader, float * restrict dst);

enum bufrw_res
bufrw_read_le_d(struct bufrw * restrict reader, double * restrict dst);

#define bufrw_read_le(_READER, _DST)                                           \
    _Generic((_DST),                                                           \
             uint8_t*:  bufrw_read_le_u8,                                      \
             uint16_t*: bufrw_read_le_u16,                                     \
             uint32_t*: bufrw_read_le_u32,                                     \
             uint64_t*: bufrw_read_le_u64,                                     \
             int8_t*:   bufrw_read_le_i8,                                      \
             int16_t*:  bufrw_read_le_i16,                                     \
             int32_t*:  bufrw_read_le_i32,                                     \
             int64_t*:  bufrw_read_le_i64,                                     \
             float*:    bufrw_read_le_f,                                       \
             double*:   bufrw_read_le_d                                        \
             )(_READER, _DST)

enum bufrw_res
bufrw_read_be_u8(struct bufrw * restrict reader, uint8_t * restrict dst);

enum bufrw_res
bufrw_read_be_i8(struct bufrw * restrict reader, int8_t * restrict dst);

enum bufrw_res
bufrw_read_be_u16(struct bufrw * restrict reader, uint16_t * restrict dst);

enum bufrw_res
bufrw_read_be_i16(struct bufrw * restrict reader, int16_t * restrict dst);

enum bufrw_res
bufrw_read_be_u32(struct bufrw * restrict reader, uint32_t * restrict dst);

enum bufrw_res
bufrw_read_be_i32(struct bufrw * restrict reader, int32_t * restrict dst);

enum bufrw_res
bufrw_read_be_u64(struct bufrw * restrict reader, uint64_t * restrict dst);

enum bufrw_res
bufrw_read_be_i64(struct bufrw * restrict reader, int64_t * restrict dst);

enum bufrw_res
bufrw_read_be_f(struct bufrw * restrict reader, float * restrict dst);

enum bufrw_res
bufrw_read_be_d(struct bufrw * restrict reader, double * restrict dst);

#define bufrw_read_be(_READER, _DST)                                           \
    _Generic((_DST),                                                           \
             uint8_t*:  bufrw_read_be_u8,                                      \
             uint16_t*: bufrw_read_be_u16,                                     \
             uint32_t*: bufrw_read_be_u32,                                     \
             uint64_t*: bufrw_read_be_u64,                                     \
             int8_t*:   bufrw_read_be_i8,                                      \
             int16_t*:  bufrw_read_be_i16,                                     \
             int32_t*:  bufrw_read_be_i32,                                     \
             int64_t*:  bufrw_read_be_i64,                                     \
             float*:    bufrw_read_be_f,                                       \
             double*:   bufrw_read_be_d                                        \
             )(_READER, _DST)

enum bufrw_res
bufrw_write_le_u8(struct bufrw * writer, uint8_t val);

enum bufrw_res
bufrw_write_le_i8(struct bufrw * writer, int8_t val);

enum bufrw_res
bufrw_write_le_u16(struct bufrw * writer, uint16_t val);

enum bufrw_res
bufrw_write_le_i16(struct bufrw * writer, int16_t val);

enum bufrw_res
bufrw_write_le_u32(struct bufrw * writer, uint32_t val);

enum bufrw_res
bufrw_write_le_i32(struct bufrw * writer, int32_t val);

enum bufrw_res
bufrw_write_le_u64(struct bufrw * writer, uint64_t val);

enum bufrw_res
bufrw_write_le_i64(struct bufrw * writer, int64_t val);

enum bufrw_res
bufrw_write_le_f(struct bufrw * writer, float val);

enum bufrw_res
bufrw_write_le_d(struct bufrw * writer, double val);

#define bufrw_write_le(_READER, _DST)                                          \
    _Generic((_DST),                                                           \
             uint8_t:  bufrw_write_le_u8,                                      \
             uint16_t: bufrw_write_le_u16,                                     \
             uint32_t: bufrw_write_le_u32,                                     \
             uint64_t: bufrw_write_le_u64,                                     \
             int8_t:   bufrw_write_le_i8,                                      \
             int16_t:  bufrw_write_le_i16,                                     \
             int32_t:  bufrw_write_le_i32,                                     \
             int64_t:  bufrw_write_le_i64,                                     \
             float:    bufrw_write_le_f,                                       \
             double:   bufrw_write_le_d                                        \
             )(_READER, _DST)

enum bufrw_res
bufrw_write_be_u8(struct bufrw * writer, uint8_t val);

enum bufrw_res
bufrw_write_be_i8(struct bufrw * writer, int8_t val);

enum bufrw_res
bufrw_write_be_u16(struct bufrw * writer, uint16_t val);

enum bufrw_res
bufrw_write_be_i16(struct bufrw * writer, uint16_t val);

enum bufrw_res
bufrw_write_be_u32(struct bufrw * writer, uint32_t val);

enum bufrw_res
bufrw_write_be_i32(struct bufrw * writer, uint32_t val);

enum bufrw_res
bufrw_write_be_u64(struct bufrw * writer, uint64_t val);

enum bufrw_res
bufrw_write_be_i64(struct bufrw * writer, uint64_t val);

enum bufrw_res
bufrw_write_be_f(struct bufrw * writer, float val);

enum bufrw_res
bufrw_write_be_d(struct bufrw * writer, double val);

#define bufrw_write_be(_READER, _DST)                                          \
    _Generic((_DST),                                                           \
             uint8_t:  bufrw_write_be_u8,                                      \
             uint16_t: bufrw_write_be_u16,                                     \
             uint32_t: bufrw_write_be_u32,                                     \
             uint64_t: bufrw_write_be_u64,                                     \
             int8_t:   bufrw_write_be_i8,                                      \
             int16_t:  bufrw_write_be_i16,                                     \
             int32_t:  bufrw_write_be_i32,                                     \
             int64_t:  bufrw_write_be_i64,                                     \
             float:    bufrw_write_be_f,                                       \
             double:   bufrw_write_be_d                                        \
             )(_READER, _DST)


#endif /* BUFRW_H */
