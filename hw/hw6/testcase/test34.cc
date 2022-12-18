#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc a;
    string test1 = "test1 ";
    string test2 = " test3";
    string test3 = "    fasdfds: ";
    a += test1;
    a += test2;
    a += test3;

    const Doc d(a);

    cout << "Low Ground Size " << d.size() << "\n";

    return 0;
}
