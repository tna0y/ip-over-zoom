#include "testlib/testlib.hpp"

#include <zlib.h>

#include <iostream>

using namespace test;

int32_t testlib::saySomething(const std::string &something) const noexcept {
  std::cout << something << '\n';
  std::cout << zlibVersion() << '\n';
  return 0;
}
