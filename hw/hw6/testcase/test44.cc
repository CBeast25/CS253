#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc a;
    string test1 = "  Lok'tar Ogar, ";
    string test2 = " Chief!";
    string test3 = "            Argh Mara!   ";
    a += test1;
    a += test2;
    a += test3;



    cout << a;
    return 0;
}

