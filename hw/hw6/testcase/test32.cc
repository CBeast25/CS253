#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc d;

    string data = "sovetskoe proshloe";
    d += data;
    d[0];

    return 0;
}
