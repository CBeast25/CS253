#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Doc d;
    
    string asoka = " Asoka";
    string lord = "  Lord";
    string sith = "   Sith";     

    d += asoka;
    d += lord;
    d += sith;


    cout << "High Ground Size " << d.size() << "\n";

    return 0;
}
