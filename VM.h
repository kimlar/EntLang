#pragma once

#include "Bytecode.h"

#include <vector>

class VM
{
public:
	VM(std::vector<int> code, int main, int datasize);
	~VM();

	void cpu();

	bool trace;		// Debug show stuff

private:
	void disassemble();

	std::vector<int> code;
	std::vector<int> data;
	std::vector<int> stack;

	int ip;			// Instruction Pointer (current instruction. I.e: Where on the code instruction)
	int sp = -1;	// Stack Pointer (current stack item/element. I.e: Where on the stack)
	int fp;			// Frame Pointer (frame)
};
