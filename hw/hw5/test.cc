#include "Game.h"
#include <iostream>

using namespace std;

int main(/* int argc, char *argv[] */) {
    //
    // Instead of hard-coding all the values here, you could
    // adapt your main() from HW3, with all the getopt() processing.
    // That way, you can easily test with 17777 different values,
    // different files, etc.
    // 
    Game g;
    g.set_good("✓"); g.set_wrong("~"); g.set_bad(".");
    g.set_length(5);
    g.add_dict("/dev/null");
    g.add_dict("words.txt");
    try {
        g.add_dict("e");
    } catch (invalid_argument &e) {
        cout << e.what() << '\n';
    }
    try {
        g.set_length(10);
        g.select_target();
    } catch (length_error &e) {
        cout << e.what();
    }
    g.set_length(5);
    g.add_dict("/dev/null");
    g.add_dict("common-words.txt");
    const Game f = g;
    const Game h(g);
    cout << boolalpha << f.contains("hello") << "\n";
    const auto &target = g.select_target();
    cout << "Guess the " << target.size() << "-letter word.\n";

    for (int count=1; count<=6; ++count) {
        cout << "Guess #" << count << ": ";
        if (string guess; !getline(cin, guess))   // end game on end-of-file
            break;
        else if (guess.size() != target.size())
            cout << "“" << guess << "” isn’t length " << target.size() << ".\n";
        else if (!g.contains(guess))
            cout << "“" << guess << "” isn’t in any dictionary.\n";
        else {
            cout << "          " <<  g.feedback(guess) << "\n";
            if (guess == target) {
                cout << "You won!\n";
                return 0;
            }
        }
    }
    cout << "You lost, the word was “" << target << "”.\n";
    return 1;
}