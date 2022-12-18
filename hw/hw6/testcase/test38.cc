#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc a;
    string test1 = "  What what what";
    string test2 = " sadness bs";
    a += test1;
    a += test2;

    const Doc d(a);


    cout << "operator[] works: " << d[1].indent << " " << d[1].data << "\n";
    return 0;
}

