#include "bufrw.h"
#include "endian.h"
#include "greatest.h"
#include <stdint.h>
#include <stdlib.h>

GREATEST_MAIN_DEFS();

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

int
main(int argc, char ** argv)
{
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(generic_write_read_le);
    RUN_SUITE(generic_write_read_be);
    RUN_SUITE(generic_mixed_endian);
    GREATEST_MAIN_END();
}
