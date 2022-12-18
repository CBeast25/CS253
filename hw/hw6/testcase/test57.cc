#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc d;
    string test1 = " chetki";
    d += test1;

    Doc e;
    string test2 = "sudba";
    e += test2;

    const Doc f(e);

    d += f;
    assert(d.size() == 2);
    cout << "indent: " << d[0].indent << ", " << "data: " << d[0].data << "\n";
    cout << "indent: " << d[1].indent << ", " << "data: " << d[1].data << "\n";

    return 0;
}

