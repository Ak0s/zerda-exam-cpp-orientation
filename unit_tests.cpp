//============================================================================
// Name        : unit_tests.cpp
// Author      : Ak0s
// Description : Exam 3
//============================================================================

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "file_handling.hpp"
#include "decryption.hpp"
#include "argument_manager.hpp"

using namespace std;

TEST_CASE("Testing read_from_file function") {
  FileHandling test;
  test.read_from_file("source.txt");
  REQUIRE(test.get_input_from_file() == "Welcome to the jungle!\n");
}

TEST_CASE("Testing write_to_file function") {
  FileHandling test;
  test.write_to_file("test.txt", "ALMA");
  test.read_from_file("test.txt");
  REQUIRE(test.get_input_from_file() == "ALMA");
}

TEST_CASE("Testing decrypt_text function") {
  Decryption test;
  test.decrypt_text("A a Z z", 1);
  REQUIRE(test.get_decrypted_text() == "B b A a");
  test.decrypt_text("A a Z z", -1);
  REQUIRE(test.get_decrypted_text() == "Z z Y y");
}

TEST_CASE("Testing decrypt function") {
  char** akarmi;
  ArgumentManager test_am(3, akarmi);
  Decryption test_dc;
  test_am.decrypt("test.txt", "2", "output.txt");
  REQUIRE(test_dc.get_decrypted_text() == "BMNB");
}

