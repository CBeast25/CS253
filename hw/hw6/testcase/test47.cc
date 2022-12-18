#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc a;
    string test1 = " There is no peace";
    a += test1;

    ofstream out("outputTest47");
    out << a;
    return 0;
}

