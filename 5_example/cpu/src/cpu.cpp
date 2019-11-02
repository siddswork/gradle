//============================================================================
// Name        : cpu.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef CPU_H_
	#include "cpu.h"
#endif
#include <iostream>
using namespace std;

void cpu::Freeze() {
	cout << "cpu:Freeze" << endl;
}
void cpu::Jump(long position) {
	cout << "cpu:Jump to " << position << endl;
}
void cpu::Execute() {
	cout << "Cpu:Execute" << endl;
}

