#ifndef CURSOR_H
#define CURSOR_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Common state for both reader and writer cursors. */
struct cursor_state_ {
    size_t len;
    size_t pos;
};
/* A context for serializing data to a buffer */
struct cursor_wtr {
    struct cursor_state_ state;
    uint8_t *            buf;
};

/* A context for deserializing data from a buffer */
struct cursor_rdr {
    struct cursor_state_ state;
    uint8_t const *      buf;
};

enum cursor_res {
    /* The unpack/pack operation was successful */
    cursor_res_ok,
    /* No more bytes left in the buffer */
    cursor_res_err_buf_exhausted,
};

/**
 * Creates and returns a writer cursor object
 */
struct cursor_wtr
cursor_wtr_new(uint8_t * buf, size_t buflen);

/**
 * Creates and returns a writer cursor object
 */
struct cursor_rdr
cursor_rdr_new(uint8_t const * buf, size_t buflen);

size_t
cursor_remaining(void const * csr);

enum cursor_res
cursor_take(struct cursor_rdr * csr, size_t n, uint8_t * dst);

size_t
cursor_take_remaining(struct cursor_rdr * csr, uint8_t * dst);

enum cursor_res
cursor_put(struct cursor_wtr * csr, void const * src, size_t src_len);

enum cursor_res
cursor_unpack_le_u8(struct cursor_rdr * csr, uint8_t * dst);

enum cursor_res
cursor_unpack_le_i8(struct cursor_rdr * csr, int8_t * dst);

enum cursor_res
cursor_unpack_le_u16(struct cursor_rdr * csr, uint16_t * dst);

enum cursor_res
cursor_unpack_le_i16(struct cursor_rdr * csr, int16_t * dst);

enum cursor_res
cursor_unpack_le_u32(struct cursor_rdr * csr, uint32_t * dst);

enum cursor_res
cursor_unpack_le_i32(struct cursor_rdr * csr, int32_t * dst);

enum cursor_res
cursor_unpack_le_u64(struct cursor_rdr * csr, uint64_t * dst);

enum cursor_res
cursor_unpack_le_i64(struct cursor_rdr * csr, int64_t * dst);

enum cursor_res
cursor_unpack_le_f(struct cursor_rdr * csr, float * dst);

enum cursor_res
cursor_unpack_le_d(struct cursor_rdr * csr, double * dst);

#define cursor_unpack_le(_CSR, _DST)                                           \
    _Generic((_DST),                                                           \
             uint8_t*:  cursor_unpack_le_u8,                                     \
             uint16_t*: cursor_unpack_le_u16,                                    \
             uint32_t*: cursor_unpack_le_u32,                                    \
             uint64_t*: cursor_unpack_le_u64,                                    \
             int8_t*:   cursor_unpack_le_i8,                                     \
             int16_t*:  cursor_unpack_le_i16,                                    \
             int32_t*:  cursor_unpack_le_i32,                                    \
             int64_t*:  cursor_unpack_le_i64,                                    \
             float*:    cursor_unpack_le_f,                                      \
             double*:   cursor_unpack_le_d                                       \
             )(_CSR, _DST)

enum cursor_res
cursor_unpack_be_u8(struct cursor_rdr * csr, uint8_t * dst);

enum cursor_res
cursor_unpack_be_i8(struct cursor_rdr * csr, int8_t * dst);

enum cursor_res
cursor_unpack_be_u16(struct cursor_rdr * csr, uint16_t * dst);

enum cursor_res
cursor_unpack_be_i16(struct cursor_rdr * csr, int16_t * dst);

enum cursor_res
cursor_unpack_be_u32(struct cursor_rdr * csr, uint32_t * dst);

enum cursor_res
cursor_unpack_be_i32(struct cursor_rdr * csr, int32_t * dst);

enum cursor_res
cursor_unpack_be_u64(struct cursor_rdr * csr, uint64_t * dst);

enum cursor_res
cursor_unpack_be_i64(struct cursor_rdr * csr, int64_t * dst);

enum cursor_res
cursor_unpack_be_f(struct cursor_rdr * csr, float * dst);

enum cursor_res
cursor_unpack_be_d(struct cursor_rdr * csr, double * dst);

#define cursor_unpack_be(_CSR, _DST)                                           \
    _Generic((_DST),                                                           \
             uint8_t*:  cursor_unpack_be_u8,                                   \
             uint16_t*: cursor_unpack_be_u16,                                  \
             uint32_t*: cursor_unpack_be_u32,                                  \
             uint64_t*: cursor_unpack_be_u64,                                  \
             int8_t*:   cursor_unpack_be_i8,                                   \
             int16_t*:  cursor_unpack_be_i16,                                  \
             int32_t*:  cursor_unpack_be_i32,                                  \
             int64_t*:  cursor_unpack_be_i64,                                  \
             float*:    cursor_unpack_be_f,                                    \
             double*:   cursor_unpack_be_d                                     \
             )(_CSR, _DST)

enum cursor_res
cursor_pack_le_u8(struct cursor_wtr * csr, uint8_t val);

enum cursor_res
cursor_pack_le_i8(struct cursor_wtr * csr, int8_t val);

enum cursor_res
cursor_pack_le_u16(struct cursor_wtr * csr, uint16_t val);

enum cursor_res
cursor_pack_le_i16(struct cursor_wtr * csr, int16_t val);

enum cursor_res
cursor_pack_le_u32(struct cursor_wtr * csr, uint32_t val);

enum cursor_res
cursor_pack_le_i32(struct cursor_wtr * csr, int32_t val);

enum cursor_res
cursor_pack_le_u64(struct cursor_wtr * csr, uint64_t val);

enum cursor_res
cursor_pack_le_i64(struct cursor_wtr * csr, int64_t val);

enum cursor_res
cursor_pack_le_f(struct cursor_wtr * csr, float val);

enum cursor_res
cursor_pack_le_d(struct cursor_wtr * csr, double val);

#define cursor_pack_le(_CSR, _DST)                                             \
    _Generic((_DST), uint8_t                                                   \
             : cursor_pack_le_u8, uint16_t                                     \
             : cursor_pack_le_u16, uint32_t                                    \
             : cursor_pack_le_u32, uint64_t                                    \
             : cursor_pack_le_u64, int8_t                                      \
             : cursor_pack_le_i8, int16_t                                      \
             : cursor_pack_le_i16, int32_t                                     \
             : cursor_pack_le_i32, int64_t                                     \
             : cursor_pack_le_i64, float                                       \
             : cursor_pack_le_f, double                                        \
             : cursor_pack_le_d)(_CSR, _DST)

enum cursor_res
cursor_pack_be_u8(struct cursor_wtr * csr, uint8_t val);

enum cursor_res
cursor_pack_be_i8(struct cursor_wtr * csr, int8_t val);

enum cursor_res
cursor_pack_be_u16(struct cursor_wtr * csr, uint16_t val);

enum cursor_res
cursor_pack_be_i16(struct cursor_wtr * csr, int16_t val);

enum cursor_res
cursor_pack_be_u32(struct cursor_wtr * csr, uint32_t val);

enum cursor_res
cursor_pack_be_i32(struct cursor_wtr * csr, int32_t val);

enum cursor_res
cursor_pack_be_u64(struct cursor_wtr * csr, uint64_t val);

enum cursor_res
cursor_pack_be_i64(struct cursor_wtr * csr, int64_t val);

enum cursor_res
cursor_pack_be_f(struct cursor_wtr * csr, float val);

enum cursor_res
cursor_pack_be_d(struct cursor_wtr * csr, double val);

#define cursor_pack_be(_CSR, _DST)                                             \
    _Generic((_DST), uint8_t                                                   \
             : cursor_pack_be_u8, uint16_t                                     \
             : cursor_pack_be_u16, uint32_t                                    \
             : cursor_pack_be_u32, uint64_t                                    \
             : cursor_pack_be_u64, int8_t                                      \
             : cursor_pack_be_i8, int16_t                                      \
             : cursor_pack_be_i16, int32_t                                     \
             : cursor_pack_be_i32, int64_t                                     \
             : cursor_pack_be_i64, float                                       \
             : cursor_pack_be_f, double                                        \
             : cursor_pack_be_d)(_CSR, _DST)

#ifdef __cplusplus
}
#endif

#endif /* CURSOR_H */
