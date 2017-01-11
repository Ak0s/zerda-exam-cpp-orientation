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

bool is_alphabetic(std::string source_text, int case_min, int case_max, int i);
bool is_overflowing(std::string source_text, int case_min, int case_max, int key, int i);
int overflow_shift_if_key_positive(std::string source_text, int case_min, int case_max, int key, int i);
int overflow_shift_if_key_negative(std::string source_text, int case_min, int case_max, int key, int i);

void Decryption::decrypt_text(std::string source_text, int key) {
  for (unsigned int i = 0; i < source_text.length(); i++) {
    if (is_alphabetic(source_text,UPPER_CASE_MIN, UPPER_CASE_MAX, i)) {
      if (is_overflowing(source_text, UPPER_CASE_MIN, UPPER_CASE_MAX, key, i)) {
        source_text[i] += key;
      }
      else if (key > 0){
        source_text[i] = overflow_shift_if_key_positive(source_text, UPPER_CASE_MIN, UPPER_CASE_MAX, key, i);
      }
      else {
        source_text[i] = overflow_shift_if_key_negative(source_text, UPPER_CASE_MIN, UPPER_CASE_MAX, key, i);
      }
    }
    if (is_alphabetic(source_text,LOWER_CASE_MIN, LOWER_CASE_MAX, i)) {
      if (is_overflowing(source_text, LOWER_CASE_MIN, LOWER_CASE_MAX, key, i)) {
        source_text[i] += key;
      }
      else if (key > 0) {
        source_text[i] = overflow_shift_if_key_positive(source_text, LOWER_CASE_MIN, LOWER_CASE_MAX, key, i);
      }
      else {
        source_text[i] = overflow_shift_if_key_negative(source_text, LOWER_CASE_MIN, LOWER_CASE_MAX, key, i);
      }
    }
  }
  decrypted_text = source_text;
}

bool is_alphabetic(std::string source_text, int case_min, int case_max, int i) {
    return (source_text[i] >= case_min and source_text[i] <= case_max);
}

bool is_overflowing(std::string source_text, int case_min, int case_max, int key, int i) {
  return source_text[i] + key > case_min and source_text[i] + key < case_max;
}

int overflow_shift_if_key_positive(std::string source_text, int case_min, int case_max, int key, int i) {
  return case_min + key - (case_max - source_text[i]) - 1;
}

int overflow_shift_if_key_negative(std::string source_text, int case_min, int case_max, int key, int i) {
  return case_max + (case_min - source_text[i] - key) - 1;
}

std::string Decryption::get_decrypted_text() {
  return decrypted_text;
}

