#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc a;
    string test1 = " There is no peace";
    string test2 = " Through power";
    string test3 = " My chains are broken";
    a += test1;
    a += test2;
    a += test3;


    cout << a;
    return 0;
}

