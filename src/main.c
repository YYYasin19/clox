#include "chunk.h"
#include "common.h"
#include "debug.h"

int main() {
  Chunk chunk;
  initChunk(&chunk);

  // write a constant to the value array
  int constantIndex = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, constantIndex); // add opcode & constant to 'stack'

  writeChunk(&chunk, OP_RETURN);
  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}