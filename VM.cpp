#include "VM.h"

#include <iostream>
#include <iomanip>
#include <string>


VM::VM(std::vector<int> code, int main, int datasize)
{
	this->code = code;
	this->ip = main;
	this->data.reserve(datasize);
	this->stack.reserve(100);
}

VM::~VM()
{
}

void VM::cpu()
{
	while ( ip < (int)code.size() )
	{
		int opcode = code[ip]; // Fetch
		if (trace)
			disassemble();
		ip++;
		int v;
		int w;

		switch (opcode) // Decode, then Execute (inside case)
		{
		case IADD:
			v = stack[sp];			
			sp--;
			stack.pop_back();
			w = stack[sp];
			sp--;
			stack.pop_back();
			sp++;
			stack.push_back(v + w);
			break;
		case ICONST:
			v = code[ip];
			ip++;
			sp++;
			stack.push_back(v); //stack[sp] = v;
			break;
		case PRINT:
			v = stack[sp];
			sp--;
			stack.pop_back();			
			std::cout << std::to_string(v)  << std::endl;
			break;
		case HALT:
			return;
		}
	}
}

void VM::disassemble()
{
	int opcode = code[ip];
	std::string opName = instructions[opcode].name;
	int nOpnds = instructions[opcode].nOpnds;
	
	// print opcode
	std::cout << std::setfill('0') << std::setw(4) << ip << ": " << opName;

	// print opnds
	if (nOpnds == 1)
	{
		std::cout << " " << code[ip + 1];
	}
	else if (nOpnds == 2)
	{
		std::cout << " " << code[ip + 1] << " " << code[ip + 2];
	}

	// print stack
	std::cout << "\t\t[";
	for (int i = 0; i <= sp; i++)
	{
		std::cout << " " << stack[i];
	}
	std::cout << " ]";

	std::cout << std::endl;
}
