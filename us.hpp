/*
 * UnStandard is a single header standard library "replacement" for C++. "us"
 * for short.
 *
 * It is intended to be quick to compile (no templates), quick to run, and easy
 * to work with.
 *
 * Most of all, however, it's my own personal toolkit. You probably shouldn't
 * be using it unless you REALLY like me.
 */

/*
 * Conventions
 *
 * Naming:
 * - Primitive types as `type`
 * - Non-primitive (structs, enums, function pointer types) as `Type` (or
 *   `ExampleType`)
 * - Acronyms in typenames should always be in uppercase (eg. `URL`,
 *   `URLParser`)
 * - Everything is prefixed with `us_`.
 * - If a function is relevant to a particular type, it should be prefixed with
 *   that type (eg. an "init" function for a "MemoryPool" struct should be
 *   named `us_MemoryPool_init`.
 *
 * Comments:
 * - Comments about specific lines/statements should be done with `//`
 * - Comments on a section of a code (ie. this Convetions section) should be
 *   done with a `/ *`
 */

// TODO(harrison): Platform detection

/*
 * Types
 *
 * C++ by default has some really weird naming conventions (WTF does a `long
 * long unsigned int` mean exactly?). It's much clearer to just have a number
 * right next to the type that informs its size, instead of a set of ambiguous
 * words.
 *
 * Some people prefer to use ridiculously short names (i8, u8, r32, etc.) but I
 * don't think these add much value, and tend to make the source code much
 * harder to read.
 */

#include <stddef.h>
#include <stdint.h>

typedef int8_t    int8;
typedef int16_t   int16;
typedef int32_t   int32;
typedef int64_t   int64;
typedef uint8_t   uint8;
typedef uint16_t  uint16;
typedef uint32_t  uint32;
typedef uint64_t  uint64;
typedef float     real32;
typedef double    real64;

// As much as I'd like to shorten `size_t` to `size`, it isn't practical
// because of how often `size` gets used as a variable name in my codebases.
//
// `psize` represents a good middleground: the "p" stands for "pointer".
typedef size_t psize;

// TODO(harrison): Memory helpers

void us_memcpy(void* from, void* to, psize len);
void us_memset(void *to, int value, psize len);

// TODO(harrison): Memory allocation

void* us_alloc(psize size);
void us_free(void* mem);

// TODO(harrison): Memory pools

struct us_MemoryPool;

void us_MemoryPool_init(us_MemoryPool* pool);

// TODO(harrison): Number helpers
bool us_abs(float a) {
  if (a < 0) {
    a *= -1;
  }

  return a;
}
bool us_equals(float a, float b, real32 e=0.001) {
  return us_abs(b - a) < e;
}

// TODO(harrison): Rune helpers
bool us_isSpace(char c) {
  // TODO(harrison): handle other types of spaces

  return c == ' ';
}

bool us_isDigit(char c) {
  return c >= '0' && c <= '9';
}

bool us_isLetter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool us_isNewline(char c) {
  return c == '\n';
}

// TODO(harrison): String manipulation

// TODO(harrison): String parsing

int us_parseInt(char* start, psize len) {
  int num = 0;
  psize i = 0;

  bool negative = false;

  while (i < len) {
    char c = start[i];

    if (i == 0 && c == '-') {
      negative = true;

      i += 1;

      continue;
    }

    if (!us_isDigit(c)) {
      // TODO(harrison): implement some sort of failure case

      return 0;
    }

    int digit = c - '0';

    num = (num * 10) + digit;

    i += 1;
  }

  if (negative) {
    num *= -1;
  }

  return num;
}
