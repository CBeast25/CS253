#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc d;

    string test = "Ya ne znayu chto tut";
    d += test;

    d.size();

    return 0;
}
