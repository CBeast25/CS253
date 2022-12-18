#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<short> pi = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4};
    string alpha="abcdefghijklmnopqrstuvwxyz", digits="0123456789";
    char cbuf[100] = { };	// contains 100 '\0' chars
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    short powers[] = {1,2,4,8,16,32,64};
    int ibuf[100];		// contains unknown values

    cout << "Exercise 0\n";
    copy(alpha.begin(), alpha.end(), cbuf);
    cout << cbuf << '\n';

    cout << "Exercise 1\n";
    reverse(begin(cbuf), begin(cbuf)+26);
    cout << cbuf << '\n';

    cout << "Exercise 2\n";
    transform(primes.begin(), primes.end(), begin(ibuf), [](int x){ return x+1; });
    for (int i = 0; i < 10; i++)
        cout << ibuf[i] << ' ';
    cout << '\n';

    cout << "Exercise 3\n";
    if (any_of(primes.begin(), primes.end(), [](int x){ return x % 2 == 0; }))
        cout <<  "div 2\n";
    if (any_of(primes.begin(), primes.end(), [](int x){ return x % 42 == 0; }))
        cout <<  "div 42\n";

    cout << "Exercise 4\n";
    cout << *(++find(primes.begin(), primes.end(), 13)) << '\n';

    cout << "Exercise 5\n";
    cout << count(pi.begin(), pi.end(), 3) << '\n';

    cout << "Exercise 6\n";
    cout << count_if(pi.begin(), pi.end(), [](int x){ return x < 5; }) << '\n';\

    cout << "Exercise 7\n";
    cout << *max_element(pi.begin(), pi.end()) << '\n';

    cout << "Exercise 8\n";
    sort(pi.begin(), pi.end());
    for (auto x : pi)
        cout << x << ' ';
    cout << '\n';

    cout << "Exercise 9\n";
    auto d = lower_bound(pi.begin(), pi.end(), 7);
    cout << distance(pi.begin(), d) << '\n';

    cout << "Exercise 10\n";
    auto it = set_intersection(pi.begin(), pi.end(), 
        begin(powers), end(powers), begin(ibuf));
    for (auto i = &ibuf[0]; i != it; ++i)
        cout << *i << ' ';
    cout << '\n';
}
