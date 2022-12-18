#include "Doc.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //ofstream("data") << "Lorem Ipsum\n";    
    Doc d;
    Doc e;
    //ifstream in("data");
    //in >> d;

    string orda = "Lok'tar Ogar!";
    d += orda;

    string hello = "Hello";
    e = d + hello;

    cout << "d1 + string worked" << "\n";

    return 0;
}

