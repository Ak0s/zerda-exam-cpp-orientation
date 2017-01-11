//============================================================================
// Name        : file_handling.hpp
// Author      : Ak0s
// Description : Exam 3
//============================================================================

#ifndef FILE_HANDLING_HPP_
#define FILE_HANDLING_HPP_

#include <iostream>
#include <fstream>
#include <string>

class FileHandling {
  private:
    std::string input_from_file;
  public:
    void read_from_file(std::string filename);
    void write_to_file(std::string filename, std::string content);
    std::string get_input_from_file();
};




#endif /* FILE_HANDLING_HPP_ */
