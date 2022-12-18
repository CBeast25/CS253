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

    //const Doc f(e);

    d += e;
    assert(d.size() == 2);
    cout << "indent: " << d[0].indent << ", " << "data: " << d[0].data << "\n";
    cout << "indent: " << d[1].indent << ", " << "data: " << d[1].data << "\n";

    assert(e.size() == 1);
    assert(e[0].indent == 0);
    assert(e[0].data == "sudba");
    cout << "e is the same" << "\n";

    return 0;
}

