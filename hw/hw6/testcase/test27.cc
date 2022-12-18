#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {

    Doc d;
    string abra = "Abra";
    string kadabra = "Kadabra";
    string test = "Test";
    d += abra;
    d += kadabra;
    d += test;

    Doc e;
    string kira = "Kira";
    string mira = "Mira";
    string mara = "Mara";
    e += kira;
    e += mira;
    e += mara;

    d = e;
    assert(d[0].data == "Kira");
    assert(d[1].data == "Mira");
    assert(d[2].data == "Mara");

    cout << "Copy " << "443" << "\n";

    return 0;
}
