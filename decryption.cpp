//============================================================================
// Name        : decryption.cpp
// Author      : Ak0s
// Description : Exam 3
//============================================================================

#include "decryption.hpp"

const int UPPER_CASE_MIN = 65;
const int UPPER_CASE_MAX = 90;
const int LOWER_CASE_MIN = 97;
const int LOWER_CASE_MAX = 122;

void Decryption::decrypt_text(std::string source_text, int key) {
  for (unsigned int i = 0; i < source_text.length(); i++) {
    if (source_text[i] >= UPPER_CASE_MIN and source_text[i] <= UPPER_CASE_MAX) {
      if (source_text[i] + key > UPPER_CASE_MIN and source_text[i] + key < UPPER_CASE_MAX) {
        source_text[i] += key;
      }
      else if (key > 0){
        source_text[i] = UPPER_CASE_MIN + key - (UPPER_CASE_MAX - source_text[i]) - 1;
      }
      else {
        source_text[i] = UPPER_CASE_MAX + (UPPER_CASE_MIN - source_text[i] - key) - 1;
      }
    }
    if (source_text[i] >= LOWER_CASE_MIN and source_text[i] <= LOWER_CASE_MAX) {
      if (source_text[i] + key > LOWER_CASE_MIN and source_text[i] + key < LOWER_CASE_MAX) {
        source_text[i] += key;
      }
      else if (key > 0) {
        source_text[i] = LOWER_CASE_MIN + key - (LOWER_CASE_MAX - source_text[i]) - 1;
      }
      else {
        source_text[i] = LOWER_CASE_MAX + (LOWER_CASE_MIN - source_text[i] - key) - 1;
      }
    }
  }
  decrypted_text = source_text;
}

std::string Decryption::get_decrypted_text() {
  return decrypted_text;
}

