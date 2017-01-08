[![Build Status](https://travis-ci.org/JayKickliter/cursor.svg?branch=master)](https://travis-ci.org/JayKickliter/cursor)
[![Coverage Status](https://coveralls.io/repos/github/JayKickliter/cursor/badge.svg?branch=master)](https://coveralls.io/github/JayKickliter/cursor?branch=master)

# `cursor`

A simple iterator for packing/unpacking primitive c types to/from a provided buffer.

## Example

See [simple.c](examples/simple.c)

## Prerequisites

`cursor` makes use of c11's generic selection expression feature. These are the minimum `gcc` and `clang` versions that support it:

* clang >= 3.8
* gcc  >= 4.9

Feel free to open an issue if you'd like to use `cursor` but you're compiler is not compatible. The generic pack/unpack function calls are just sugar, and a configuration step could `ifdef` them out when not supported.
