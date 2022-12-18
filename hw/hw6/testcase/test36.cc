#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc a;
    string test1 = "  What what what";
    a += test1;
    const Doc d(a);
    assert(!(d.empty()));

    cout << "Not empty!" << "\n";

    return 0;
}
