#include "chunk.h"
#include "common.h"
#include "debug.h"

int main() {
  Chunk chunk;
  initChunk(&chunk);

  // write a constant to the value array
  int constIndex = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 19);
  writeChunk(&chunk, constIndex, 19);

  writeChunk(&chunk, OP_RETURN, 19);
  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}