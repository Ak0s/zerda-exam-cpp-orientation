//============================================================================
// Name        : argument_manager.cpp
// Author      : Ak0s
// Description : Exam 3
//============================================================================

#include "argument_manager.hpp"

const int FLAG1 = 2;
const int FLAG2 = 4;
const int ARG1 = 1;
const int ARG2 = 3;
const int ARG3 = 5;

ArgumentManager::ArgumentManager(int argc, char* argv[]) {
  this->argc = argc;
  this->argv = argv;
  file_handler = new FileHandling;
  decryption = new Decryption;
  argument_handling();
}

void ArgumentManager::decrypt(std::string source_filename, std::string key, std::string output_filename) {
  file_handler->read_from_file(source_filename);
  decryption->decrypt_text(file_handler->get_input_from_file(), std::stoi(key));
  file_handler->write_to_file(output_filename, decryption->get_decrypted_text());
}

void ArgumentManager::argument_handling() {
  try {
    if (argc == 1) {
      throw "No filename is provided!";
    }
    else if (argv[FLAG1][1] != 's' and argv[FLAG2][1] != 's') {
      throw "No shift provided!";
    }
    else if (argv[ARG2] == 0 or argv[ARG3] == 0) {
      throw "No arguments given!";
    }
    else if (argc == 4) {
      decrypt(argv[ARG1], argv[ARG2], "");
      std::cout << decryption->get_decrypted_text();
    }
    else if (argc == 6) {
      if (argv[FLAG1][1] == 's' and argv[FLAG2][1] == 'o') {
        decrypt(argv[ARG1], argv[ARG2], argv[ARG3]);
      }
      else if (argv[FLAG1][1] == 'o' and argv[FLAG2][1] == 's') {
        decrypt(argv[ARG1], argv[ARG3], argv[ARG2]);
      }
      else {
        throw "Invalid flag!";
      }
    }
    else {
        throw "Too many or too few arguments!";
    }
  }
  catch (const char* excp) {
    std::cout << excp << std::endl;
    std::cout << "Please use the following formats to decrypt something:" << std::endl
              << "a.exe input.txt -s 2 -o output.txt" << std::endl
              << "a.out input.txt -o output.txt -s 2" << std::endl;
  }
}
