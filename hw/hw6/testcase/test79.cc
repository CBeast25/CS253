#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {

    Doc d;
    string test2 = "   Lorem IPSUM\n Here We stay\n  Hope?";
    string test1 = "Fish\n CAT DOG\n BEAR BEER\n MARA";
    d += test2;
    d += test1;

    cout << d;
    assert(d.size() == 2);
    assert(d[0].indent == 3);
    assert(d[1].indent == 0);

    assert(d[0].data == "Lorem IPSUM\n Here We stay\n  Hope?");
    assert(d[1].data == "Fish\n CAT DOG\n BEAR BEER\n MARA");
    return 0;
}

