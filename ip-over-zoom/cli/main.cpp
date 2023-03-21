#include <iostream>
#include "testlib.hpp"

using namespace std;

int main() {
  test::testlib t{};
  t.saySomething("yo!");
  return 0;
}
