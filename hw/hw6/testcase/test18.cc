#include "Doc.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    Doc d;
    string example = "Example";
    d += example;
    cout << "String is added to an empty Doc!" << "\n";

    return 0;
}

