#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {

    Doc d;
    string yoda = "Yoda";
    string karat = "Karat";
    string vozkik = "Vozkik";
    d += yoda;
    d += karat;
    d += vozkik;

    auto info = d[5].indent;
    cout << info << "\n";
    cout << "Hello World!" << "\n";

    return 0;
}
