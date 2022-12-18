#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc d;
    string test1 = "  kasha";
    d += test1;

    const Doc d1(d);

    //Doc e;
    //string test2 = "sudba";
    //e += test2;
    const string test2 = " mecha";

    //Doc f;

    const Doc f = d1 + test2;
    assert(f.size() == 2);
    cout << "indent: " << f[0].indent << ", " << "data: " << f[0].data << "\n";
    cout << "indent: " << f[1].indent << ", " << "data: " << f[1].data << "\n";


    return 0;
}

