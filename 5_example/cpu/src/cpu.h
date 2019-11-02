/*
 * cpu.h
 *
 *  Created on: 30-Oct-2019
 *      Author: sidd
 */

#ifndef CPU_H_
#define CPU_H_

class cpu {
 public:
  void Freeze();
  void Jump(long position);
  void Execute();
};



#endif /* CPU_H_ */
