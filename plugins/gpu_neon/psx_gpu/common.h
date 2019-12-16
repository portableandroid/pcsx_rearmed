#ifndef COMMON_H
#define COMMON_H

#ifndef PORTANDROID
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long int s64;
typedef unsigned long long int u64;
#else
#include "cb_interface.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "vector_ops.h"
#include "psx_gpu.h"

#define unlikely(x) __builtin_expect((x), 0)

#endif

