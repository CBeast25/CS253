#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    //ofstream("dataTest52") << "\t here is";
    //Doc d;

    //ifstream in("dataTest52");
    //in >> d;

    //cout << "done" << "\n";
    //return 0;
    ofstream("dataTest52") << "\t here is";
    Doc d;

    try {
      ifstream in("dataTest52");
      in >> d;
    }
    catch (const runtime_error& rte) {
      cerr << "Runtime error: " << rte.what() << '\n';
    }

    return 0;

}

