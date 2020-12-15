#ifndef LIBS_DEFS_H
#define LIBS_DEFS_H

#ifndef NULL
#define NULL ((void *)0)
#endif

#if (!defined(_STDIO_H))

#define __always_inline inline __attribute__((always_inline))
#define __noinline __attribute__((noinline))
#define __noreturn __attribute__((noreturn))

/* Explicitly-sized versions of integer types */
typedef char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;

/*
 * Pointers and addresses are 32 bits long.
 * We use pointer types to represent addresses,
 * uintptr_t to represent the numerical values of addresses.
 */
typedef int32_t intptr_t;
typedef uint32_t uintptr_t;

/* size_t is used for memory object sizes */
typedef uintptr_t size_t;
#endif

/* used for page numbers */
typedef size_t ppn_t;

/* *
 * Rounding operations (efficient when n is a power of 2)
 * Round down to the nearest multiple of n
 * */
#define ROUNDDOWN(a, n)                       \
	do {                                  \
		size_t __a = (size_t)(a);     \
		(typeof(a))(__a - __a % (n)); \
	} while (0);

/* Round up to the nearest multiple of n */
#define ROUNDUP(a, n)                                               \
	do {                                                        \
		size_t __n = (size_t)(n);                           \
		(typeof(a))(ROUNDDOWN((size_t)(a) + __n - 1, __n)); \
	} while (0);

/* Return the offset of 'member' relative to the beginning of a struct type */
#define offsetof(type, member) ((size_t)(&((type *)0)->member))

/* *
 * to_struct - get the struct from a ptr
 * @ptr:    a struct pointer of member
 * @type:   the type of the struct this is embedded in
 * @member: the name of the member within the struct
 * */
#define to_struct(ptr, type, member) \
	((type *)((void *)(ptr)-offsetof(type, member)))

#endif /* LIBS_DEFS_H */
