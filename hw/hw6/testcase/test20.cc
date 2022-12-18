#include "Doc.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream("data") << "Lorem Ipsum\n";   
    Doc d;
    ifstream in("data");
    in >> d;

    cout << "Read from istream to the Doc!" << "\n";

    return 0;
}
