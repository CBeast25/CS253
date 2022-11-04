#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "usage: " << argv[0] << " file\n";
        return 1;
    }
    fstream f(argv[1], f.out | f.in);
    if (!f.is_open()) {
        cerr << argv[0] << ": can't open " << argv[1] << '\n';
        return 2;
    }

    for (string line; getline(f, line); ) {
        size_t offset = f.tellg();
        offset -= (line.length() + 1);
        for (size_t pos=0; (pos=line.find("Trump", pos)) != line.npos; ) {
            f.seekp(offset + pos);
            f << "Biden";
            pos += 5;
        }
    }

    return 0;
}

// Note that line.npos ≡ string::npos.
// It’s a static constant, part of the string class.
// It’s a number that means “Sorry, I couldn’t find that.”
