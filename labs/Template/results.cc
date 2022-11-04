#include <iomanip>	// for right, setw
#include <iostream>
#include <map>
#include <string>
#include <array>

using namespace std;

template <typename T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    friend ostream& operator<<(ostream& os, const BarGraph bar) {
        for (const auto &val : bar.data)
            os << right << setw(10) << val.first << ' '
            << string(val.second, '*') << '\n';
        os << '\n';
        return os;
    }
  private:
    map<T, unsigned> data;
};

template <>
class BarGraph<bool> {
    unsigned false_count = 0, true_count = 0;
  public:
    void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
    }
    friend ostream& operator<<(ostream& os, const BarGraph bar) {
        os << "     false " << string(bar.false_count, '*') << "\n"
                "      true " << string(bar.true_count,  '*') << "\n\n";
        return os;
    }
};

template <>
class BarGraph<char> {
        array<int, 128> data = {};
    public:
        void operator+=(char c) {
            data[c]++;
        }
        void operator+=(string datum) {
            for (char c : datum)
                data[c]++;
        }
        friend ostream& operator<<(ostream& os, const BarGraph bar) {
            for (size_t i = 0; i < bar.data.size(); i++)
                if(bar.data[i] > 0)
                    os << right << setw(10) << char(i) << ' '
                    << string(bar.data[i], '*') << '\n';
            os << '\n';
            return os;
        }
};

int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    cout << alpha;

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    cout << beta;

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    cout << gamma;

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    delta += "Colorado";
    cout << delta;

    return 0;
}
