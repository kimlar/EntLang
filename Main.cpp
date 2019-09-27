#include <iostream>
#include <vector>

#include "VM.h"

//
// Fetch -> Decode -> Execute
//

int main(int argc, char* argv[])
{
	std::vector<int> program = {
		Opcode::ICONST, 2,
		Opcode::ICONST, 1,
		Opcode::IADD,
		Opcode::ICONST, 5,
		Opcode::IADD,
		Opcode::PRINT,
		Opcode::HALT
	};
	
	VM* vm = new VM(program, 0, 0);
	vm->trace = true;
	vm->cpu();

	delete vm;
	system("pause>nul");
	return 0;
}
