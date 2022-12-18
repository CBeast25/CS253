#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ofstream("dataTest51") << "";
    Doc d;

    ifstream in("dataTest51");
    in >> d;
    assert(d.size()==0);

    cout << "done" << "\n";
    return 0;
}

