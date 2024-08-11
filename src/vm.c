#include "vm.h"
#include "common.h"
#include "debug.h"
#include <stdio.h>

VM vm; // global vm

void initVM() {}

void freeVM() {}

// reads the instruction at the current 'ip' and increments the 'ip'
static uint8_t read_byte() { return (*vm.ip++); }

// read the next constant
static Value read_constant() {
  uint8_t constOffset = read_byte();
  return vm.chunk->constants.values[constOffset];
}

static InterpretResult run() {

  for (;;) {

#ifdef DEBUG_MODE
    int relativeOffset = (int)(vm.ip - vm.chunk->code);
    disassembleInstruction(vm.chunk, relativeOffset);
#endif

    uint8_t instr;
    switch (instr = read_byte()) {

    case OP_CONSTANT: {
      Value constant = read_constant();
      printValue(constant);
      printf("\n");
      break;
    }

    case OP_RETURN: {
      return INTERPRET_OK;
    }
    }
  }
}

InterpretResult interpret(Chunk *chunk) {
  vm.chunk = chunk;
  vm.ip = vm.chunk->code; // points to the first instruction
  return run();
}