/*
 * harddrive.h
 *
 *  Created on: 30-Oct-2019
 *      Author: sidd
 */

#ifndef HARDDRIVE_H_
#define HARDDRIVE_H_

#include <string>

class harddrive {
 public:
  const char* Read(long lba, int size);

  static const std::string dataInFile;
};


#endif /* HARDDRIVE_H_ */
