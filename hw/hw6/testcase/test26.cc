#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {

    Doc d;
    string abra = "Abra";
    string kadabra = "Kadabra";
    string test = "Test";
    d += abra;
    d += kadabra;
    d += test;

    const Doc e(d);

    assert(d.size() == e.size());

    Doc f(e);
    assert(d.size() == f.size());
    cout << "Copy " << "33" << "\n";

    return 0;
}
