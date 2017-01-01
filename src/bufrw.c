#include "bufrw.h"
#include "endian.h"
#include <assert.h>

/* Check that buffer has enough bytes left to read the desired type out */
#define SIZE_CHECK()                                                           \
    do                                                                         \
    {                                                                          \
        if ((ctx->pos + sizeof(*dst)) <= ctx->len)                             \
        {                                                                      \
            return bufrw_buf_err_exhausted;                                    \
        }                                                                      \
    } while (0)

#define INC_READ_POS()                                                         \
    do                                                                         \
    {                                                                          \
        ctx->pos += sizeof(*dst);                                              \
    } while (0)

struct bufrw
bufrw_new(void * buf, size_t buflen)
{
    assert(buf);
    return (struct bufrw){
        .buf = buf, .len = buflen, .pos = 0,
    };
}

enum bufrw_res
bufrw_read_le_u8(struct bufrw * ctx, uint8_t * dst)
{
    SIZE_CHECK();
    read_le_u8(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_le_i8(struct bufrw * ctx, int8_t * dst)
{
    SIZE_CHECK();
    read_le_i8(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_le_u16(struct bufrw * ctx, uint16_t * dst)
{
    SIZE_CHECK();
    read_le_u16(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_le_i16(struct bufrw * ctx, int16_t * dst)
{
    SIZE_CHECK();
    read_le_i16(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_le_u32(struct bufrw * ctx, uint32_t * dst)
{
    SIZE_CHECK();
    read_le_u32(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_le_i32(struct bufrw * ctx, int32_t * dst)
{
    SIZE_CHECK();
    read_le_i32(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_le_u64(struct bufrw * ctx, uint64_t * dst)
{
    SIZE_CHECK();
    read_le_u64(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_u8(struct bufrw * ctx, uint8_t * dst)
{
    SIZE_CHECK();
    read_be_u8(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_i8(struct bufrw * ctx, int8_t * dst)
{
    SIZE_CHECK();
    read_be_i8(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_u16(struct bufrw * ctx, uint16_t * dst)
{
    SIZE_CHECK();
    read_be_u16(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_i16(struct bufrw * ctx, int16_t * dst)
{
    SIZE_CHECK();
    read_be_i16(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_u32(struct bufrw * ctx, uint32_t * dst)
{
    SIZE_CHECK();
    read_be_u32(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_i32(struct bufrw * ctx, int32_t * dst)
{
    SIZE_CHECK();
    read_be_i32(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_u64(struct bufrw * ctx, uint64_t * dst)
{
    SIZE_CHECK();
    read_be_u64(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_le_i64(struct bufrw * ctx, int64_t * dst)
{
    SIZE_CHECK();
    read_le_i64(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_i64(struct bufrw * ctx, int64_t * dst)
{
    SIZE_CHECK();
    read_be_i64(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_f(struct bufrw * ctx, float * dst)
{
    SIZE_CHECK();
    read_be_f(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}

enum bufrw_res
bufrw_read_be_d(struct bufrw * ctx, double * dst)
{
    SIZE_CHECK();
    read_be_d(dst, &ctx->buf[ctx->pos]);
    INC_READ_POS();
    return bufrw_res_ok;
}
