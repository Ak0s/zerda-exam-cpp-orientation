//============================================================================
// Name        : file_handling.cpp
// Author      : Ak0s
// Description : Exam 3
//============================================================================

#include "file_handling.hpp"

void FileHandling::read_from_file(std::string filename) {
  std::ifstream source;
  source.open(filename);
  if (source.is_open()) {
    std::string lines;
    while (getline(source, lines)) {
      input_from_file += lines + '\n';
    }
    source.close();
  }
  else {
    std::cerr << "Could open" << filename << "!" << std::endl;
  }
}

void FileHandling::write_to_file(std::string filename, std::string content) {
  std::ofstream file_to_write;
  file_to_write.open(filename);
  file_to_write << content;
  file_to_write.close();
}

std::string FileHandling::get_input_from_file() {
  return input_from_file;
}
