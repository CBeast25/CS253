#include "Doc.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //ofstream("data") << "Lorem Ipsum\n";    
    Doc d;
    //ifstream in("data");
    //in >> d;
    string orda = "Lok'tar Ogar!";
    d += orda;
    cout << d;

    return 0;
}

