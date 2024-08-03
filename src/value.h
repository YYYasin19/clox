#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value; // the 'Value' type is internally a 'double' in C world

void printValue(Value value);

// Stores all values (i.e. constants and literals) needed throughout the code
typedef struct {
  int capacity;
  int count;
  Value *values; // points to the values
} ValueArray;

void initValueArray(ValueArray *array);
void writeValueArray(ValueArray *array, Value value);
void freeValueArray(ValueArray *array);

#endif