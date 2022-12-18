#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc d;
    string data = "pelmeni";
    d += data;
    d.empty();

    return 0;
}
