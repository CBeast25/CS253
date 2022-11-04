#include "Doc.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    ofstream("data") << "\r \r  \n\n Peter  \n   Ray\r \nEgon  \n \n\r\n\n";
    Doc d;
    Doc f("\r \r  \n\n Peter  \n   Ray\r \nEgon  \n \n\r\n\n");
    assert(d.empty() && !d);
    ifstream in("data");
    in >> d;
    cout << d;
    cout << f;
    assert(d && !d.empty());
    assert(d.size()==3);
    assert(d[0].indent == 1);
    assert(d[1].indent == 3);
    assert(d[2].indent == 0);
    assert(d[0].data == "Peter");
    assert(d[1].data == "Ray");
    assert(d[2].data == "Egon");

    d += "      Winston     ";
    assert(d.size() == 4);
    assert(d[3].indent == 6);
    assert(d[3].data == "Winston     ");

    for (size_t n=0; n<d.size(); n++) {
        const auto stuff = d[n];
        cout << n << ": " << stuff.indent << ' ' << stuff.data << '\n';
    }
    cout << "---\n" << d << "---\n";

    d += "";
    assert(d.size() == 5);
    assert(d[4].indent == 0);
    assert(d[4].data == "");

    const Doc vacant;
    assert(vacant.empty() && !vacant && vacant.size()==0);
    d = vacant;
    assert(d.empty() && !d && d.size()==0);

    cout << d + f  << "---\n";
    cout << f + "a" << "---\n";
    cout << "a" + f << "---\n";
    Doc ree("aodjaosfjoiasd\n gd \n");
    f += "b";
    cout << f;
    f += ree;

    cout << f << "---\nDone.\n";

    return 0;
}
