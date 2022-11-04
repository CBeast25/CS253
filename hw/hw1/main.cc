#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << argv[0] << " was not given exactly one argument\n"; 
        return 1;
    }
    ifstream file(argv[1]);
    if (!file) {
        cerr << argv[0] << " could not read " << argv[1] << '\n';
        return 1;
    }
    string s;
    vector<string> words;
    while (getline(file, s))
        if (s.size() == 5)
            words.push_back(s);
    if (words.size() < 1) {
        cerr << argv[0] << " " << argv[1] << " contained no 5 letter words\n";
        return 1;
    }
    cout << "I am thinking of a 5-letter word.\n";
    random_device rd;
    int c = 0;
    string t;
    string word = words[rd() % words.size()];
    cout << "Guess: ";
    while (cin >> t) {
        c++;
        if (t.size() != 5) {
            cerr << argv[0] << " guess must be exactly 5 characters long\n";
            return 1;
        }
        cout << "       ";
        for (size_t i = 0; i < 5; i++) {
            if (t[i] == word[i])
                cout << "=";
            else if (word.find(t[i]) != string::npos)
                cout << "-";
            else
                cout << " ";
        }
        cout << '\n';
        if (word == t) {
            cout << "You won!\n";
            return 0;
        }
        if (c >= 6) {
            cout << "You lost, the word was \"" << word << "\".\n";
            return 0;
        }
        cout << "Guess: ";
    }
    return 0;
}
