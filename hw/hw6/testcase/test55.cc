#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc d;
    string test1 = "   kirasa";

    d += test1;
    cout << "indent: " << d[0].indent << ", " << "data: " << d[0].data << "\n";
    cout << test1 << "\n";
    return 0;
}
