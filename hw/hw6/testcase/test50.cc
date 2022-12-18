#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ofstream("dataTest50") << "  My chains are broken\n Peace is a lie\n";
    Doc d;
    string test1 = "pelmeni";
    string test2 = "vilka";
    string test3 = "glaz";
    d += test1;
    d += test2;
    d += test3;

    ifstream in("dataTest50");
    in >> d;
    assert(d.size()==2);
    assert(d[0].indent == 2);
    assert(d[0].data == "My chains are broken");
    assert(d[1].indent == 1);
    assert(d[1].data == "Peace is a lie");

    cout << "done" << "\n";
    return 0;
}

