#include "testlib.hpp"

#include <iostream>

using namespace test;

int32_t testlib::saySomething(const std::string &something) const noexcept {
  if (something.empty()) {
    std::cerr << "No value passed\n";
    return 1;
  }

  std::cout << something << '\n';
  return 0;
}
