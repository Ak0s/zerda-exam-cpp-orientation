//============================================================================
// Name        : argument_manager.hpp
// Author      : Ak0s
// Description : Exam 3
//============================================================================

#ifndef ARGUMENT_MANAGER_HPP_
#define ARGUMENT_MANAGER_HPP_

#include <iostream>
#include <string>
#include "file_handling.hpp"
#include "decryption.hpp"

class ArgumentManager {
  private:
    int argc;
    char** argv;
    FileHandling* file_handler;
    Decryption* decryption;
  public:
    ArgumentManager(int argc, char** argv);
    void argument_handling();
    void decrypt(std::string source_filename, std::string key, std::string output_filename);
};



#endif /* ARGUMENT_MANAGER_HPP_ */
