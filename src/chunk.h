/*
 *  A chunk is a series of byte-code
 */
#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

// defines the type 'enum { ...}' as 'OpCode'
typedef enum {
  OP_CONSTANT,
  OP_RETURN,
} OpCode;

// A chunk is a (dynamic) array of bytes
typedef struct {
  int count;
  int capacity;
  uint8_t *code;
  int *lines; // LOC that this chunk was generated from
  ValueArray constants;
} Chunk;

// initialize a chunk
void initChunk(Chunk *chunk);

// add bytes to chunk
void writeChunk(Chunk *chunk, uint8_t byte, int line);

// free a chunk
void freeChunk(Chunk *chunk);

int addConstant(Chunk *chunk, Value value);

#endif