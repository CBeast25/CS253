#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ofstream("dataTest48") << "My chains are broken\n";
    Doc d;

    ifstream in("dataTest48");
    in >> d;
    assert(d.size()==1);
    assert(d[0].indent == 0);
    assert(d[0].data == "My chains are broken");

    cout << "done" << "\n";
    return 0;
}

