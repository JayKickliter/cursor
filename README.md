[![Build Status](https://travis-ci.org/JayKickliter/cursor.svg?branch=master)](https://travis-ci.org/JayKickliter/cursor)
[![Coverage Status](https://coveralls.io/repos/github/JayKickliter/cursor/badge.svg?branch=master)](https://coveralls.io/github/JayKickliter/cursor?branch=master)

# `cursor`

A simple iterator for packing/unpacking primitive c types to/from a provided buffer.

## Example

```c
    /* A buffer to store packed data */
    uint8_t buf[6];

    /* Construct a new writer cursor with the buffer we just defined */
    struct cursor_wtr wtr = cursor_wtr_new(buf, sizeof(buf));

    uint16_t written_u16 = 0x0123;
    uint32_t written_u32 = 0x456789AB;

    /* Write written_u16 to buf little-endian */
    cursor_pack_le_u16(&wtr, written_u16);

    /* Write written_u32 to buf big-endian */
    cursor_pack_be_u32(&wtr, written_u32);

    /* Construct a reader cursor */
    struct cursor_rdr rdr = cursor_rdr_new(buf, sizeof(buf));

    uint16_t read_u16 = 0;
    uint32_t read_u32 = 0;

    /* Read a packed little-endian uint16_t out of buf */
    cursor_unpack_le_u16(&rdr, &read_u16);

    /* Read a packed big-endian uint32_t out of buf */
    cursor_unpack_be_u32(&rdr, &read_u32);

    assert(read_u16 == written_u16);
    assert(read_u32 == written_u32);
```

See the full [example](examples/simple.c).
