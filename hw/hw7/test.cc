#include "Game.h"
#include <cassert>
#include <iostream>

using namespace std;

// Reject words containing the letter ‘e’:
bool no_e(string s) {
    return s.find('e') == s.npos;
}

int main() {
    Game g;
    g.add_dict("greek.txt");
    Game ree;
    ree.add_dict("common-words.txt");

    for (auto s : g)
        cout << "all: " << s << "\n";

    g.set_wanted(no_e);
    for (auto s : g)
        cout << "no e: " << s << "\n";

    g.set_wanted([](string s) { return s[0] == 'z';});
    for (auto s : g)
        cout << "z: " << s << "\n";

    g.set_wanted([](string s) { return s[3] == 'm';});
    const auto g2=g;
    // Should only get gamma and sigma:
    for (auto s : g2)
        cout << "m: " << s << "\n";

    Game::iterator it = g2.begin();
    assert(it != ree.begin());
    assert(it == g2.begin());
    assert(!(it != g2.begin()));
    assert(it != g2.end());
    assert(!(it == g2.end()));
    assert(g2.begin() != g2.end());
    assert(*it == "gamma");
    assert(*it == "gamma");
    assert(*it != "DBb");
    assert(!(*it == "1fff"));
    auto it2 = it++;
    assert(*it2 == "gamma");
    assert(*it == "sigma");
    it2 = ++it;
    assert(it2 == it);
    assert(it == g2.end());
    Game::iterator b = g2.begin();
    assert(b == it);

    cout << "Done!\n";

    return 0;
}