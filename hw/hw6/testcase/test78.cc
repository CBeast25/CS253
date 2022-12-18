#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {

    Doc d;
    string test2 = " Kartoshka s kotletkoy123";
    string test1 = "A takzhe mozho dobavki!";
    d += test2;
    d += test1;

    const Doc d1(d);

    Doc v;

    const Doc v1(v);

    assert(!d1.empty() && d1);
    assert(d1);
    assert(!v1);

    cout << "operator bool seems to work" << "\n";

    return 0;
}

