#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc d;
    string test1 = "natsume";
    d += test1;

    Doc e;
    string test2 = "   shin";
    e += test2;

    //Doc f;

    const Doc f = d + e;
    assert(f.size() == 2);
    cout << "indent: " << f[0].indent << ", " << "data: " << f[0].data << "\n";
    cout << "indent: " << f[1].indent << ", " << "data: " << f[1].data << "\n";
    //assert(test2 == " mecha");
    //assert(d[0].indent == 2);
    //assert(d[0].data == "kasha");
    //cout << "String is not modified!" << "\n";

    return 0;
}

