#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {

    string test1 = "     Tenjou Tenge";

    Doc d;
    string test2 = " Peace Keeper Layer 3";
    d += test2;

    //const Doc d1(d);

    //Doc e;
    //string test2 = "   shin";
    //e += test2;

    //const Doc d1(d);
    //const Doc e1(e);


    Doc f;

    f = test1 + d;
    assert(f.size() == 2);
    //cout << "indent: " << f[0].indent << ", " << "data: " << f[0].data << "\n";
    //cout << "indent: " << f[1].indent << ", " << "data: " << f[1].data << "\n"; 

    assert(d.size() == 1);
    assert(d[0].indent == 1);
    assert(d[0].data == "Peace Keeper Layer 3");
    cout << "Doc1 is not modified!" << "\n";

    return 0;
}
