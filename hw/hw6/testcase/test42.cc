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
    string test3 = "            a";
    a += test1;
    a += test2;
    a += test3;



    cout << "operator[] works: " << a[5].data << "\n";
    return 0;
}

