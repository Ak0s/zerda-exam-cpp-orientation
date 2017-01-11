//============================================================================
// Name        : decryption.hpp
// Author      : Ak0s
// Description : Exam 3
//============================================================================

#ifndef DECRYPTION_HPP_
#define DECRYPTION_HPP_

#include <string>

class Decryption {
  private:
    std::string decrypted_text;
  public:
    void decrypt_text(std::string source_text, int key);
    std::string get_decrypted_text();
};

#endif /* DECRYPTION_HPP_ */
