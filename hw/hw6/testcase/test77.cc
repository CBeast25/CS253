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

    Doc v;

    assert(!d.empty() && d);
    assert(d);
    assert(!v);

    cout << "operator bool seems to work" << "\n";

    return 0;
}

