#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc a;
    string test1 = "  What what what";
    string test2 = " sadness b";
    a += test1;
    a += test2;

    //const Doc d(a);


    cout << "operator[] works: " << a[1].indent << " " << a[1].data << "\n";

    return 0;
}

