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
    string test = "test";
    d += abra;
    d += kadabra;
    d += test;

    Doc e(d);

    assert(d.size() == e.size());

    cout << "Copy " << "3" << "\n";

    return 0;
}
