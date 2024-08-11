#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main() {
  initVM();

  Chunk chunk;
  initChunk(&chunk);

  // write a constant to the value array
  int constIndex = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 19);
  writeChunk(&chunk, constIndex, 19);
  // writeChunk(&chunk, OP_CONSTANT, 19);
  // writeChunk(&chunk, addConstant(&chunk, 5346), 19);

  writeChunk(&chunk, OP_RETURN, 19);
  // disassembleChunk(&chunk, "test chunk");

  // run the interpreter
  interpret(&chunk);

  // clean up

  freeVM();
  freeChunk(&chunk);
  return 0;
}