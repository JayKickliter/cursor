#ifndef CURSOR_H
#define CURSOR_H

#include <stddef.h>
#include <stdint.h>

/* A context for [de]serializing data from a buffer */
struct cursor
{
    uint8_t * restrict buf;
    size_t             len;
    size_t             pos;
};

enum cursor_res
{
    /* The read/write operation was successful */
    cursor_res_ok,
    /* No more bytes left in the buffer */
    cursor_buf_err_exhausted,
};


/**
 * Creates and returns a new cursor object
 */
struct cursor
cursor_new(void * buf, size_t buflen);


enum cursor_res
cursor_read_le_u8(struct cursor * restrict csr, uint8_t * restrict dst);

enum cursor_res
cursor_read_le_i8(struct cursor * restrict csr, int8_t * restrict dst);

enum cursor_res
cursor_read_le_u16(struct cursor * restrict csr, uint16_t * restrict dst);

enum cursor_res
cursor_read_le_i16(struct cursor * restrict csr, int16_t * restrict dst);

enum cursor_res
cursor_read_le_u32(struct cursor * restrict csr, uint32_t * restrict dst);

enum cursor_res
cursor_read_le_i32(struct cursor * restrict csr, int32_t * restrict dst);

enum cursor_res
cursor_read_le_u64(struct cursor * restrict csr, uint64_t * restrict dst);

enum cursor_res
cursor_read_le_i64(struct cursor * restrict csr, int64_t * restrict dst);

enum cursor_res
cursor_read_le_f(struct cursor * restrict csr, float * restrict dst);

enum cursor_res
cursor_read_le_d(struct cursor * restrict csr, double * restrict dst);

#define cursor_read_le(_CSR, _DST)                                             \
    _Generic((_DST),                                                           \
             uint8_t*:  cursor_read_le_u8,                                     \
             uint16_t*: cursor_read_le_u16,                                    \
             uint32_t*: cursor_read_le_u32,                                    \
             uint64_t*: cursor_read_le_u64,                                    \
             int8_t*:   cursor_read_le_i8,                                     \
             int16_t*:  cursor_read_le_i16,                                    \
             int32_t*:  cursor_read_le_i32,                                    \
             int64_t*:  cursor_read_le_i64,                                    \
             float*:    cursor_read_le_f,                                      \
             double*:   cursor_read_le_d                                       \
             )(_CSR, _DST)

enum cursor_res
cursor_read_be_u8(struct cursor * restrict csr, uint8_t * restrict dst);

enum cursor_res
cursor_read_be_i8(struct cursor * restrict csr, int8_t * restrict dst);

enum cursor_res
cursor_read_be_u16(struct cursor * restrict csr, uint16_t * restrict dst);

enum cursor_res
cursor_read_be_i16(struct cursor * restrict csr, int16_t * restrict dst);

enum cursor_res
cursor_read_be_u32(struct cursor * restrict csr, uint32_t * restrict dst);

enum cursor_res
cursor_read_be_i32(struct cursor * restrict csr, int32_t * restrict dst);

enum cursor_res
cursor_read_be_u64(struct cursor * restrict csr, uint64_t * restrict dst);

enum cursor_res
cursor_read_be_i64(struct cursor * restrict csr, int64_t * restrict dst);

enum cursor_res
cursor_read_be_f(struct cursor * restrict csr, float * restrict dst);

enum cursor_res
cursor_read_be_d(struct cursor * restrict csr, double * restrict dst);

#define cursor_read_be(_CSR, _DST)                                             \
    _Generic((_DST),                                                           \
             uint8_t*:  cursor_read_be_u8,                                     \
             uint16_t*: cursor_read_be_u16,                                    \
             uint32_t*: cursor_read_be_u32,                                    \
             uint64_t*: cursor_read_be_u64,                                    \
             int8_t*:   cursor_read_be_i8,                                     \
             int16_t*:  cursor_read_be_i16,                                    \
             int32_t*:  cursor_read_be_i32,                                    \
             int64_t*:  cursor_read_be_i64,                                    \
             float*:    cursor_read_be_f,                                      \
             double*:   cursor_read_be_d                                       \
             )(_CSR, _DST)

enum cursor_res
cursor_write_le_u8(struct cursor * writer, uint8_t val);

enum cursor_res
cursor_write_le_i8(struct cursor * writer, int8_t val);

enum cursor_res
cursor_write_le_u16(struct cursor * writer, uint16_t val);

enum cursor_res
cursor_write_le_i16(struct cursor * writer, int16_t val);

enum cursor_res
cursor_write_le_u32(struct cursor * writer, uint32_t val);

enum cursor_res
cursor_write_le_i32(struct cursor * writer, int32_t val);

enum cursor_res
cursor_write_le_u64(struct cursor * writer, uint64_t val);

enum cursor_res
cursor_write_le_i64(struct cursor * writer, int64_t val);

enum cursor_res
cursor_write_le_f(struct cursor * writer, float val);

enum cursor_res
cursor_write_le_d(struct cursor * writer, double val);

#define cursor_write_le(_CSR, _DST)                                            \
    _Generic((_DST),                                                           \
             uint8_t:  cursor_write_le_u8,                                     \
             uint16_t: cursor_write_le_u16,                                    \
             uint32_t: cursor_write_le_u32,                                    \
             uint64_t: cursor_write_le_u64,                                    \
             int8_t:   cursor_write_le_i8,                                     \
             int16_t:  cursor_write_le_i16,                                    \
             int32_t:  cursor_write_le_i32,                                    \
             int64_t:  cursor_write_le_i64,                                    \
             float:    cursor_write_le_f,                                      \
             double:   cursor_write_le_d                                       \
             )(_CSR, _DST)

enum cursor_res
cursor_write_be_u8(struct cursor * writer, uint8_t val);

enum cursor_res
cursor_write_be_i8(struct cursor * writer, int8_t val);

enum cursor_res
cursor_write_be_u16(struct cursor * writer, uint16_t val);

enum cursor_res
cursor_write_be_i16(struct cursor * writer, uint16_t val);

enum cursor_res
cursor_write_be_u32(struct cursor * writer, uint32_t val);

enum cursor_res
cursor_write_be_i32(struct cursor * writer, uint32_t val);

enum cursor_res
cursor_write_be_u64(struct cursor * writer, uint64_t val);

enum cursor_res
cursor_write_be_i64(struct cursor * writer, uint64_t val);

enum cursor_res
cursor_write_be_f(struct cursor * writer, float val);

enum cursor_res
cursor_write_be_d(struct cursor * writer, double val);

#define cursor_write_be(_CSR, _DST)                                            \
    _Generic((_DST),                                                           \
             uint8_t:  cursor_write_be_u8,                                     \
             uint16_t: cursor_write_be_u16,                                    \
             uint32_t: cursor_write_be_u32,                                    \
             uint64_t: cursor_write_be_u64,                                    \
             int8_t:   cursor_write_be_i8,                                     \
             int16_t:  cursor_write_be_i16,                                    \
             int32_t:  cursor_write_be_i32,                                    \
             int64_t:  cursor_write_be_i64,                                    \
             float:    cursor_write_be_f,                                      \
             double:   cursor_write_be_d                                       \
             )(_CSR, _DST)


#endif /* CURSOR_H */