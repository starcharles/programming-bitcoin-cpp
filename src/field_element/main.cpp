#include <iostream>
#include "field_element.h"

using namespace std;

int main() {
    const FieldElement f1 = FieldElement(1, 7);
    const FieldElement f2 = FieldElement(2, 7);

    cout << (f1 == f1) << endl;
    cout << (f1 != f1) << endl;
    cout << (f1 == f2) << endl;
    cout << (f1 != f2) << endl;
}