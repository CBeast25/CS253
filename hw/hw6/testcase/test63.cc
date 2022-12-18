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

    //Doc e;
    //string test2 = "sudba";
    //e += test2;
    string test2 = " mecha";

    Doc f;

    f = d + test2;
    assert(f.size() == 2);
    //cout << "indent: " << f[0].indent << ", " << "data: " << f[0].data << "\n";
    //cout << "indent: " << f[1].indent << ", " << "data: " << f[1].data << "\n"; 
    assert(d.size() == 1);
    assert(d[0].indent == 2);
    assert(d[0].data == "kasha");
    cout << "Doc1 is not modified!" << "\n";

    return 0;
}

