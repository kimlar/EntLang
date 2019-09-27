#pragma once

#include <iostream>
#include <vector>


enum Opcode {
	IADD = 1,	// int add
	ISUB,		// int sub
	IMUL,		// int mul
	ILT,		// int less then
	IEQ,		// int equal
	BR,			// branch
	BRT,		// branch if true
	BRF,		// branch if false
	ICONST,		// push constant int
	LOAD,		// load from local ...
	GLOAD,		// load from global ...
	STORE,		// store in local ...
	GSTORE,		// store in global ...
	PRINT,		// print stack top
	POP,		// throw away top of ...
	HALT,		// stop the program execution. I.e: quit the program
};

struct Instruction
{
	char* name; // E.g., "iadd", "call"
	int nOpnds;
};

const Instruction instructions[] = {
	{ nullptr, 0 },
	{ "iadd", 0 },
	{ "isub", 0 },
	{ "imul", 0 },
	{ "ilt", 0 },
	{ "ieq", 0 },
	{ "br", 1 },
	{ "brt", 1 },
	{ "brf", 1 },
	{ "iconst", 1 },
	{ "load", 1 },
	{ "gload", 1 },
	{ "store", 1 },
	{ "gstore", 1 },
	{ "print", 0 },
	{ "pop", 0 },
	{ "halt", 0 },
};
