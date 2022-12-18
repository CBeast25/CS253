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
    Doc e;
    e += d;

    cout << "Doc is added to an empty Doc!" << "\n";

    return 0;
}
