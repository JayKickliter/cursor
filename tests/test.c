#include "bufrw.h"
#include "endian.h"
#include "greatest.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

GREATEST_MAIN_DEFS();

enum instruction_type
{
    it_u8,
    it_i8,
    it_u16,
    it_i16,
    it_u32,
    it_i32,
    it_u64,
    it_i64,
    it_f,
    it_d,
};
#define IT_VARIANT_CNT (it_d + 1)
static_assert(IT_VARIANT_CNT == 10, "");

/* A single 'instruction' in randmonized multi-part serialize/deserialize test
 * plan
 */
struct instruction
{
    enum instruction_type it;
    union {
        uint8_t  u8;
        int8_t   i8;
        uint16_t u16;
        int16_t  i16;
        uint32_t u32;
        int32_t  i32;
        uint64_t u64;
        int64_t  i64;
        float    f;
        double   d;
    } val;
    size_t val_size;
};

void
rand_instruction(struct instruction * inst)
{
    /* generate a random tag */
    int tag_idx = rand() % IT_VARIANT_CNT;
    switch (tag_idx)
    {
    case it_u8:
        inst->it       = it_u8;
        inst->val.u8   = rand();
        inst->val_size = sizeof(inst->val.u8);
    case it_i8:
        inst->it       = it_i8;
        inst->val.i8   = rand();
        inst->val_size = sizeof(inst->val.i8);
    case it_u16:
        inst->it       = it_u16;
        inst->val.u16  = rand();
        inst->val_size = sizeof(inst->val.u16);
    case it_i16:
        inst->it       = it_i16;
        inst->val.i16  = rand();
        inst->val_size = sizeof(inst->val.i16);
    case it_u32:
        inst->it       = it_u32;
        inst->val.u32  = rand();
        inst->val_size = sizeof(inst->val.u32);
    case it_i32:
        inst->it       = it_i32;
        inst->val.i32  = rand();
        inst->val_size = sizeof(inst->val.i32);
    case it_u64:
        inst->it       = it_u64;
        inst->val.u64  = rand();
        inst->val_size = sizeof(inst->val.u64);
    case it_i64:
        inst->it       = it_i64;
        inst->val.i64  = rand();
        inst->val_size = sizeof(inst->val.i64);
    case it_f:
        inst->it       = it_f;
        inst->val.f    = rand();
        inst->val_size = sizeof(inst->val.f);
    case it_d:
        inst->it       = it_d;
        inst->val.d    = rand();
        inst->val_size = sizeof(inst->val.d);
    }
}

size_t
instructions_required_buf_size(struct instruction * is, size_t nis)
{
    size_t req_buf_size = 0;
    for (size_t i = 0; i < nis; i++)
    {
        req_buf_size += is[i].val_size;
    }
    return req_buf_size;
}

struct plan
{
    struct instruction * is;
    size_t               nis;
    size_t               req_buf_size;
};

struct plan
plan_random()
{
    size_t plan_size;
    do
    {
        plan_size = rand() % 10000;
    } while (plan_size < 1024);
    struct instruction * is = malloc(plan_size * sizeof(struct instruction));
    for (size_t i = 0; i < plan_size; i++)
    {
        rand_instruction(&is[i]);
    }
    size_t req_buf_size = instructions_required_buf_size(is, plan_size);
    struct plan plan = {
        .is = is, .nis = plan_size, .req_buf_size = req_buf_size,
    };
    return plan;
}


TEST
generic_write_read_le_u8_should_match(void)
{
    uint8_t wrote = rand();
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    uint8_t read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_le_i8_should_match(void)
{
    int8_t  wrote = rand();
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    int8_t read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_le_u16_should_match(void)
{
    uint16_t wrote = rand();
    uint8_t  buf[sizeof(wrote)];
    write_le(buf, wrote);
    uint16_t read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_le_i16_should_match(void)
{
    int16_t wrote = rand();
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    int16_t read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_le_u32_should_match(void)
{
    uint32_t wrote = rand();
    uint8_t  buf[sizeof(wrote)];
    write_le(buf, wrote);
    uint32_t read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_le_i32_should_match(void)
{
    int32_t wrote = rand();
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    int32_t read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_le_u64_should_match(void)
{
    uint64_t wrote = ((uint64_t)rand() << 32) & rand();
    uint8_t  buf[sizeof(wrote)];
    write_le(buf, wrote);
    uint64_t read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_le_i64_should_match(void)
{
    int64_t wrote = ((int64_t)rand() << 32) & rand();
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    int64_t read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_le_f_should_match(void)
{
    float   wrote = rand() * rand() / rand();
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    float read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_le_d_should_match(void)
{
    double  wrote = rand() * rand() / rand();
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    double read;
    read_le(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

SUITE(generic_write_read_le)
{
    RUN_TEST(generic_write_read_le_u8_should_match);
    RUN_TEST(generic_write_read_le_i8_should_match);
    RUN_TEST(generic_write_read_le_u16_should_match);
    RUN_TEST(generic_write_read_le_i16_should_match);
    RUN_TEST(generic_write_read_le_u32_should_match);
    RUN_TEST(generic_write_read_le_i32_should_match);
    RUN_TEST(generic_write_read_le_u64_should_match);
    RUN_TEST(generic_write_read_le_i64_should_match);
    RUN_TEST(generic_write_read_le_f_should_match);
    RUN_TEST(generic_write_read_le_d_should_match);
}

TEST
generic_write_read_be_u8_should_match(void)
{
    uint8_t wrote = rand();
    uint8_t buf[sizeof(wrote)];
    write_be(buf, wrote);
    uint8_t read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_be_i8_should_match(void)
{
    int8_t  wrote = rand();
    uint8_t buf[sizeof(wrote)];
    write_be(buf, wrote);
    int8_t read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_be_u16_should_match(void)
{
    uint16_t wrote = rand();
    uint8_t  buf[sizeof(wrote)];
    write_be(buf, wrote);
    uint16_t read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_be_i16_should_match(void)
{
    int16_t wrote = rand();
    uint8_t buf[sizeof(wrote)];
    write_be(buf, wrote);
    int16_t read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_be_u32_should_match(void)
{
    uint32_t wrote = rand();
    uint8_t  buf[sizeof(wrote)];
    write_be(buf, wrote);
    uint32_t read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_be_i32_should_match(void)
{
    int32_t wrote = rand();
    uint8_t buf[sizeof(wrote)];
    write_be(buf, wrote);
    int32_t read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_be_u64_should_match(void)
{
    uint64_t wrote = ((uint64_t)rand() << 32) & rand();
    uint8_t  buf[sizeof(wrote)];
    write_be(buf, wrote);
    uint64_t read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_be_i64_should_match(void)
{
    int64_t wrote = ((int64_t)rand() << 32) & rand();
    uint8_t buf[sizeof(wrote)];
    write_be(buf, wrote);
    int64_t read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_be_f_should_match(void)
{
    float   wrote = rand() * rand() / rand();
    uint8_t buf[sizeof(wrote)];
    write_be(buf, wrote);
    float read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

TEST
generic_write_read_be_d_should_match(void)
{
    double  wrote = rand() * rand() / rand();
    uint8_t buf[sizeof(wrote)];
    write_be(buf, wrote);
    double read;
    read_be(&read, buf);
    ASSERT_EQ(wrote, read);
    PASS();
}

SUITE(generic_write_read_be)
{
    RUN_TEST(generic_write_read_be_u8_should_match);
    RUN_TEST(generic_write_read_be_i8_should_match);
    RUN_TEST(generic_write_read_be_u16_should_match);
    RUN_TEST(generic_write_read_be_i16_should_match);
    RUN_TEST(generic_write_read_be_u32_should_match);
    RUN_TEST(generic_write_read_be_i32_should_match);
    RUN_TEST(generic_write_read_be_u64_should_match);
    RUN_TEST(generic_write_read_be_i64_should_match);
    RUN_TEST(generic_write_read_be_f_should_match);
    RUN_TEST(generic_write_read_be_d_should_match);
}

TEST
generic_mixed_endian_u16_should_not_match(void)
{
    uint8_t b0;
    uint8_t b1;
    do
    {
        b0 = rand();
        b1 = rand();
    } while (b0 == b1);
    uint16_t wrote = b1 << 8 | b0;
    uint8_t  buf[sizeof(wrote)];
    write_le(buf, wrote);
    uint16_t read;
    read_be(&read, buf);
    ASSERT_FALSE(wrote == read);
    write_be(buf, wrote);
    read_le(&read, buf);
    ASSERT_FALSE(wrote == read);
    PASS();
}

TEST
generic_mixed_endian_i16_should_not_match(void)
{
    uint8_t b0;
    uint8_t b1;
    do
    {
        b0 = rand();
        b1 = rand();
    } while (b0 == b1);
    int16_t wrote = b1 << 8 | b0;
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    int16_t read;
    read_be(&read, buf);
    ASSERT_FALSE(wrote == read);
    write_be(buf, wrote);
    read_le(&read, buf);
    ASSERT_FALSE(wrote == read);
    PASS();
}

TEST
generic_mixed_endian_u32_should_not_match(void)
{
    uint8_t b0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
    do
    {
        b0 = rand();
        b1 = rand();
        b2 = rand();
        b3 = rand();
    } while (b0 == b3);
    uint32_t wrote = b3 << 24 | b2 << 16 | b1 << 8 | b0;
    uint8_t  buf[sizeof(wrote)];
    write_le(buf, wrote);
    uint32_t read;
    read_be(&read, buf);
    ASSERT_FALSE(wrote == read);
    write_be(buf, wrote);
    read_le(&read, buf);
    ASSERT_FALSE(wrote == read);
    PASS();
}

TEST
generic_mixed_endian_i32_should_not_match(void)
{
    uint8_t b0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
    do
    {
        b0 = rand();
        b1 = rand();
        b2 = rand();
        b3 = rand();
    } while (b0 == b3);
    int32_t wrote = b3 << 24 | b2 << 16 | b1 << 8 | b0;
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    int32_t read;
    read_be(&read, buf);
    ASSERT_FALSE(wrote == read);
    write_be(buf, wrote);
    read_le(&read, buf);
    ASSERT_FALSE(wrote == read);
    PASS();
}

TEST
generic_mixed_endian_u64_should_not_match(void)
{
    uint8_t b0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
    uint8_t b4;
    uint8_t b5;
    uint8_t b6;
    uint8_t b7;
    do
    {
        b0 = rand();
        b1 = rand();
        b2 = rand();
        b3 = rand();
        b4 = rand();
        b5 = rand();
        b6 = rand();
        b7 = rand();
    } while (b0 == b7);
    uint64_t wrote = (uint64_t)b7 << 56 | (uint64_t)b6 << 48
                     | (uint64_t)b5 << 40 | (uint64_t)b4 << 32 | 3 << 24
                     | b2 << 16 | b1 << 8 | b0;
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    uint64_t read;
    read_be(&read, buf);
    ASSERT_FALSE(wrote == read);
    write_be(buf, wrote);
    read_le(&read, buf);
    ASSERT_FALSE(wrote == read);
    PASS();
}

TEST
generic_mixed_endian_i64_should_not_match(void)
{
    uint8_t b0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
    uint8_t b4;
    uint8_t b5;
    uint8_t b6;
    uint8_t b7;
    do
    {
        b0 = rand();
        b1 = rand();
        b2 = rand();
        b3 = rand();
        b4 = rand();
        b5 = rand();
        b6 = rand();
        b7 = rand();
    } while (b0 == b7);
    int64_t wrote = (int64_t)b7 << 56 | (int64_t)b6 << 48 | (int64_t)b5 << 40
                    | (int64_t)b4 << 32 | 3 << 24 | b2 << 16 | b1 << 8 | b0;
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    int64_t read;
    read_be(&read, buf);
    ASSERT_FALSE(wrote == read);
    write_be(buf, wrote);
    read_le(&read, buf);
    ASSERT_FALSE(wrote == read);
    PASS();
}

TEST
generic_mixed_endian_f_should_not_match(void)
{
    uint8_t b0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
    do
    {
        b0 = rand();
        b1 = rand();
        b2 = rand();
        b3 = rand();
    } while (b0 == b3);
    float   wrote = b3 << 24 | b2 << 16 | b1 << 8 | b0;
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    float read;
    read_be(&read, buf);
    ASSERT_FALSE(wrote == read);
    write_be(buf, wrote);
    read_le(&read, buf);
    ASSERT_FALSE(wrote == read);
    PASS();
}

TEST
generic_mixed_endian_d_should_not_match(void)
{
    uint8_t b0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
    uint8_t b4;
    uint8_t b5;
    uint8_t b6;
    uint8_t b7;
    do
    {
        b0 = rand();
        b1 = rand();
        b2 = rand();
        b3 = rand();
        b4 = rand();
        b5 = rand();
        b6 = rand();
        b7 = rand();
    } while (b0 == b7);
    double wrote = (uint64_t)b7 << 56 | (uint64_t)b6 << 48 | (uint64_t)b5 << 40
                   | (uint64_t)b4 << 32 | 3 << 24 | b2 << 16 | b1 << 8 | b0;
    uint8_t buf[sizeof(wrote)];
    write_le(buf, wrote);
    double read;
    read_be(&read, buf);
    ASSERT_FALSE(wrote == read);
    write_be(buf, wrote);
    read_le(&read, buf);
    ASSERT_FALSE(wrote == read);
    PASS();
}

TEST
write_read_plan() {
    struct plan plan = plan_random();
    uint8_t * buf = malloc(plan.req_buf_size);
    for (size_t i = 0; i < plan.nis; i++) {
        struct instruction const * instr = &plan.is[i];
        switch (instr->it) {
        case it_u8:
            bufrw_write_le(ctx, &instr->u8);
            break;
        case it_i8:
            bufrw_write_le(ctx, &instr->i8);
            break;
        case it_u16:
            bufrw_write_le(ctx, &instr->u16);
            break;
        case it_i16:
            bufrw_write_le(ctx, &instr->i16);
            break;
        case it_u32:
            bufrw_write_le(ctx, &instr->u32);
            break;
        case it_i32:
            bufrw_write_le(ctx, &instr->i32);
            break;
        case it_u64:
            bufrw_write_le(ctx, &instr->u64);
            break;
        case it_i64:
            bufrw_write_le(ctx, &instr->i64);
            break;
        case it_f:
            bufrw_write_le(ctx, &instr->f);
            break;
        case it_d:
            bufrw_write_le(ctx, &instr->d);
            break;
        }
    }
    PASS();
}

SUITE(generic_mixed_endian)
{
    RUN_TEST(generic_mixed_endian_u16_should_not_match);
    RUN_TEST(generic_mixed_endian_i16_should_not_match);
    RUN_TEST(generic_mixed_endian_u32_should_not_match);
    RUN_TEST(generic_mixed_endian_i32_should_not_match);
    RUN_TEST(generic_mixed_endian_u64_should_not_match);
    RUN_TEST(generic_mixed_endian_i64_should_not_match);
    RUN_TEST(generic_mixed_endian_f_should_not_match);
    RUN_TEST(generic_mixed_endian_d_should_not_match);
}

SUITE(plan)
{
    RUN_TEST(write_read_plan);
}

int
main(int argc, char ** argv)
{
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(generic_write_read_le);
    RUN_SUITE(generic_write_read_be);
    RUN_SUITE(generic_mixed_endian);
    RUN_SUITE(plan);
    GREATEST_MAIN_END();
}
