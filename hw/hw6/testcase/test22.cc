#include "Doc.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //ofstream("data") << "Lorem Ipsum\n";    
    Doc d;
    Doc c;
    Doc e;
    //ifstream in("data");
    //in >> d;
    string orda = "Lok'tar Ogar!";
    string frie = "Friend"; 
    d += orda;
    c += frie;
    e = d + c;


    cout << "d1 + d2 worked" << "\n";

    return 0;
}

