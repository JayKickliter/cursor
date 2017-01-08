#include "cursor.h"
#include "packing.h"
#include <assert.h>

struct cursor
cursor_new(void * buf, size_t buflen)
{
    assert(buf);
    return (struct cursor){
        .buf = buf, .len = buflen, .pos = 0,
    };
}

/* Check that buffer has enough bytes left to unpack the desired type out */
#define SIZE_CHECK(_CSR, _PRIM_TYPE)                                           \
    do                                                                         \
    {                                                                          \
        if ((_CSR->pos + sizeof(_PRIM_TYPE)) > _CSR->len)                      \
        {                                                                      \
            return cursor_buf_err_exhausted;                                   \
        }                                                                      \
    } while (0)

#define INC_POS(_CSR, _PRIM_TYPE)                                              \
    do                                                                         \
    {                                                                          \
        _CSR->pos += sizeof(_PRIM_TYPE);                                       \
    } while (0)

#define GENERATE(_PRIM_TYPE, _SHORT_NAME)                                      \
    enum cursor_res cursor_unpack_le_##_SHORT_NAME(struct cursor * csr,        \
                                                   _PRIM_TYPE *    dst)        \
    {                                                                          \
        SIZE_CHECK(csr, *dst);                                                 \
        unpack_le_##_SHORT_NAME(dst, &csr->buf[csr->pos]);                     \
        INC_POS(csr, *dst);                                                    \
        return cursor_res_ok;                                                  \
    }                                                                          \
    enum cursor_res cursor_pack_le_##_SHORT_NAME(struct cursor * csr,          \
                                                 _PRIM_TYPE      val)          \
    {                                                                          \
        SIZE_CHECK(csr, val);                                                  \
        pack_le_##_SHORT_NAME(&csr->buf[csr->pos], val);                       \
        INC_POS(csr, val);                                                     \
        return cursor_res_ok;                                                  \
    }                                                                          \
    enum cursor_res cursor_unpack_be_##_SHORT_NAME(struct cursor * csr,        \
                                                   _PRIM_TYPE *    dst)        \
    {                                                                          \
        SIZE_CHECK(csr, *dst);                                                 \
        unpack_be_##_SHORT_NAME(dst, &csr->buf[csr->pos]);                     \
        INC_POS(csr, *dst);                                                    \
        return cursor_res_ok;                                                  \
    }                                                                          \
    enum cursor_res cursor_pack_be_##_SHORT_NAME(struct cursor * csr,          \
                                                 _PRIM_TYPE      val)          \
    {                                                                          \
        SIZE_CHECK(csr, val);                                                  \
        pack_be_##_SHORT_NAME(&csr->buf[csr->pos], val);                       \
        INC_POS(csr, val);                                                     \
        return cursor_res_ok;                                                  \
    }


GENERATE(uint8_t, u8)
GENERATE(int8_t, i8)
GENERATE(uint16_t, u16)
GENERATE(int16_t, i16)
GENERATE(uint32_t, u32)
GENERATE(int32_t, i32)
GENERATE(uint64_t, u64)
GENERATE(int64_t, i64)
GENERATE(float, f)
GENERATE(double, d)
