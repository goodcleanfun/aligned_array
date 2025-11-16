#ifndef ALIGNED_ARRAY_H
#define ALIGNED_ARRAY_H

#include <assert.h>
#include <stdint.h>
#include "aligned/aligned.h"

#endif

#ifndef ARRAY_DATA_MALLOC
#define ARRAY_DATA_MALLOC_DEFINED
#ifndef ARRAY_ALIGNMENT
#define ARRAY_DATA_MALLOC(size) cache_line_aligned_malloc(size)
#else
#define ARRAY_DATA_MALLOC(size) aligned_malloc(size, ARRAY_ALIGNMENT)
#endif
#endif

#define ARRAY_DATA_REALLOC_NEEDS_PREV_SIZE

#ifndef ARRAY_DATA_REALLOC
#define ARRAY_DATA_REALLOC_DEFINED
#ifndef ARRAY_ALIGNMENT
#define ARRAY_DATA_REALLOC(a, prev_size, new_size) cache_line_aligned_resize(a, prev_size, new_size)
#else
#define ARRAY_DATA_REALLOC(a, prev_size, new_size) aligned_resize(a, prev_size, new_size, ARRAY_ALIGNMENT)
#endif
#endif

#ifndef ARRAY_DATA_FREE
#define ARRAY_DATA_FREE_DEFINED
#define ARRAY_DATA_FREE(a) default_aligned_free(a)
#endif

#include "array/array.h"

#ifdef ARRAY_DATA_MALLOC_DEFINED
#undef ARRAY_DATA_MALLOC
#undef ARRAY_DATA_MALLOC_DEFINED
#endif

#undef ARRAY_DATA_REALLOC_NEEDS_PREV_SIZE

#ifdef ARRAY_DATA_REALLOC_DEFINED
#undef ARRAY_DATA_REALLOC
#undef ARRAY_DATA_REALLOC_DEFINED
#endif

#ifdef ARRAY_DATA_FREE_DEFINED
#undef ARRAY_DATA_FREE
#undef ARRAY_DATA_FREE_DEFINED
#endif
