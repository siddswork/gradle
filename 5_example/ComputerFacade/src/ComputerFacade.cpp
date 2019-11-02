//============================================================================
// Name        : ComputerFacade.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "cpu.h"
#include "harddrive.h"
#include "memory.h"
#include <iostream>
using namespace std;

class ComputerFacade {
 public:
	ComputerFacade() {
		cpu_ = new cpu();
		memory_ = new memory();
		hard_drive_ = new harddrive();
	}
	~ComputerFacade() {
		delete cpu_;
		delete memory_;
		delete hard_drive_;
	}
	void Start() {
		long int kBootAddress = 10;
		long int kBootSector = 10;
		int kSectorSize = 10;
		cpu_->Freeze();
		memory_->Load(kBootAddress, hard_drive_->Read(kBootSector, kSectorSize));
		cpu_->Jump(kBootAddress);
		cpu_->Execute();
	}

 private:
  /*
  std::unique_ptr<cpu> cpu_ = std::make_unique<cpu>();
  std::unique_ptr<memory> memory_ = std::make_unique<memory>();
  std::unique_ptr<harddrive> hard_drive_ = std::make_unique<harddrive>();
  */
	cpu *cpu_;
	memory *memory_;
	harddrive *hard_drive_;
};

int main()
{
	ComputerFacade computer;
	computer.Start();
}
