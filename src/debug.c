#include <stdio.h>

#include "debug.h"
#include "value.h"

void disassembleChunk(Chunk *chunk, const char *name) {
  printf("== %s ==\n", name);

  for (int offset = 0; offset < chunk->count;) {
    // because instructions can have different sizes, we let the disassembler
    // tell us the index of the next one
    offset = disassembleInstruction(chunk, offset);
  }
}

static int simpleInstruction(const char *name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

static int constantInstruction(const char *name, Chunk *chunk, int offset) {
  uint8_t constantOffset =
      chunk->code[offset + 1]; // retrieve from code the offset
  printf("%-16s %6d '", name, constantOffset);
  Value constantValue = chunk->constants.values[constantOffset];
  printValue(constantValue);
  printf("'\n");
  return offset + 2;
}

int disassembleInstruction(Chunk *chunk, int offset) {
  printf("%06d ", offset);

  // print the lines (in source) where this chunk came from
  if ((offset > 0) && (chunk->lines[offset] == chunk->lines[offset - 1])) {
    printf("     . "); // from the same line
  } else {
    printf("%6d ", chunk->lines[offset]); // from seperate lines
  }

  uint8_t instr = chunk->code[offset];
  switch (instr) {
  case OP_RETURN:
    return simpleInstruction("OP_RETURN", offset);
  case OP_CONSTANT:
    return constantInstruction("OP_CONSTANT", chunk, offset);
  default:
    printf("Unknown OPCODE %d\n", instr);
    return offset + 1;
  }
}

void printStack(Value *stack, Value *stackTop) {
  printf("          ");
  for (Value *slot = stack; slot < stackTop; slot++) {
    printf("[ ");
    printValue(*slot);
    printf(" ]");
  }
  printf("\n");
}