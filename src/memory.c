#include "memory.h"
#include <stdlib.h>

void *reallocate(void *pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer); // discard the memory starting at 'pointer'
    return NULL;
  }

  // realloc() resizes memory, copying old data if needed. (cf. `man 3 realloc`)
  void *result = realloc(pointer, newSize);
  if (result == NULL) // realloc() failed
    exit(1);
  return result;
}