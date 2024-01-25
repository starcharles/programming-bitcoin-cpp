#include "field_element.h"
#include <iostream>

using namespace std;

int main() {
  const FieldElement f1(1, 7);
  const FieldElement f2(2, 7);

  cout << boolalpha;
  cout << (f1 == f1) << endl;
  cout << (f1 != f1) << endl;
  cout << (f1 == f2) << endl;
  cout << (f1 != f2) << endl;
}