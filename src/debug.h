#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

void disassembleChunk(Chunk *chunk, const char *name);

/* For the instruction at 'offset':
print a readable repr and return next offset. */
int disassembleInstruction(Chunk *chunk, int offset);

void printStack(Value *stack, Value *stackTop);

#endif