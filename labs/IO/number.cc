#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Number {
  public:
    Number() = default;
    Number(const Number &) = default;
    Number(int v) : value(v) {}
    Number& operator=(int n) { value = n; return *this; }
    operator int() const { return value; }
  private:
    int value = 0;			// default value unless otherwise given
};

istream& operator>>(istream &is, Number &rhs) {
    int n;
    is >> n;
    if (is.fail()) {
      is.clear();
      string current;
      is >> current;
      if (current == "one")
        n = 1;
      else if (current == "two")
        n = 2;
      else if (current == "three")
        n = 3;
      else if (current == "four")
        n = 4;
      else if (current == "five")
        n = 5;
      else
        is.setstate(ios::failbit);
    }
    rhs = n;
    return is;
}

int main() {
    Number n = 666;
    istringstream ss("12 34 three 789 five six 10");

    while (ss >> n)
	    cout << n << ' ';
    cout << '\n';
}
