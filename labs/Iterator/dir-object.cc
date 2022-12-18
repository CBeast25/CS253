#include <iostream>
#include "Directory.h"

using std::cout;

int main() {
    Directory dir("gfhf", "obj");
    for (auto name : dir)
	    cout << "Filename: " << name << '\n';
}
