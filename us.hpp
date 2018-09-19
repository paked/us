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

// TODO(harrison): Memory allocation

void* us_alloc(psize size);
void us_free(void* mem);

// TODO(harrison): Memory pools

struct us_MemoryPool;

void us_MemoryPool_init(us_MemoryPool* pool);

// TODO(harrison): String manipulation

// TODO(harrison): Rune helpers
bool us_is_space(char c);
