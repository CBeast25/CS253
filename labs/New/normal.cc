#include <iostream>

using namespace std;

class Foo {
  public:
    double datum;
};

int main() {
    cout << "sizeof(double) = " << sizeof(double) << '\n'
	 << "sizeof(Foo) = " << sizeof(Foo) << '\n';
    Foo *p;
    int adasd = 100000000;
	while (adasd > 0) {
		p = new Foo;
		adasd--;
	}
    return 0;
}
