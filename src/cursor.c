#include "cursor.h"
#include "endian.h"
#include <assert.h>

/* Check that buffer has enough bytes left to read the desired type out */
#define SIZE_CHECK(_CSR, _T)                                                   \
    do                                                                         \
    {                                                                          \
        if ((_CSR->pos + sizeof(_T)) > _CSR->len)                              \
        {                                                                      \
            return cursor_buf_err_exhausted;                                   \
        }                                                                      \
    } while (0)

#define INC_POS(_CSR, _T)                                                      \
    do                                                                         \
    {                                                                          \
        _CSR->pos += sizeof(_T);                                               \
    } while (0)

struct cursor
cursor_new(void * buf, size_t buflen)
{
    assert(buf);
    return (struct cursor){
        .buf = buf, .len = buflen, .pos = 0,
    };
}

enum cursor_res
cursor_read_le_u8(struct cursor * csr, uint8_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_u8(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_le_i8(struct cursor * csr, int8_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_i8(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_le_u16(struct cursor * csr, uint16_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_u16(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_le_i16(struct cursor * csr, int16_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_i16(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_le_u32(struct cursor * csr, uint32_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_u32(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_le_i32(struct cursor * csr, int32_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_i32(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_le_u64(struct cursor * csr, uint64_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_u64(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_le_f(struct cursor * csr, float * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_f(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_le_d(struct cursor * csr, double * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_d(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_u8(struct cursor * csr, uint8_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_u8(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_i8(struct cursor * csr, int8_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_i8(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_u16(struct cursor * csr, uint16_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_u16(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_i16(struct cursor * csr, int16_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_i16(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_u32(struct cursor * csr, uint32_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_u32(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_i32(struct cursor * csr, int32_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_i32(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_u64(struct cursor * csr, uint64_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_u64(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_le_i64(struct cursor * csr, int64_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_le_i64(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_i64(struct cursor * csr, int64_t * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_i64(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_f(struct cursor * csr, float * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_f(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_read_be_d(struct cursor * csr, double * dst)
{
    SIZE_CHECK(csr, *dst);
    read_be_d(dst, &csr->buf[csr->pos]);
    INC_POS(csr, *dst);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_u8(struct cursor * csr, uint8_t val)
{
    SIZE_CHECK(csr, val);
    write_le_u8(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_i8(struct cursor * csr, int8_t val)
{
    SIZE_CHECK(csr, val);
    write_le_i8(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_u16(struct cursor * csr, uint16_t val)
{
    SIZE_CHECK(csr, val);
    write_le_u16(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_i16(struct cursor * csr, int16_t val)
{
    SIZE_CHECK(csr, val);
    write_le_i16(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_u32(struct cursor * csr, uint32_t val)
{
    SIZE_CHECK(csr, val);
    write_le_u32(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_i32(struct cursor * csr, int32_t val)
{
    SIZE_CHECK(csr, val);
    write_le_i32(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_u64(struct cursor * csr, uint64_t val)
{
    SIZE_CHECK(csr, val);
    write_le_u64(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_i64(struct cursor * csr, int64_t val)
{
    SIZE_CHECK(csr, val);
    write_le_i64(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_f(struct cursor * csr, float val)
{
    SIZE_CHECK(csr, val);
    write_le_f(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}

enum cursor_res
cursor_write_le_d(struct cursor * csr, double val)
{
    SIZE_CHECK(csr, val);
    write_le_d(&csr->buf[csr->pos], val);
    INC_POS(csr, val);
    return cursor_res_ok;
}
