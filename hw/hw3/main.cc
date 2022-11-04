#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <unistd.h>
#include <algorithm>
using namespace std;



int main(int argc, char **argv) {
    bool valid = false;
    int turns = 6;
    string good = "=";
    string meh = "-";
    string bad = " ";
    size_t length = 5;
    bool tu = false, g = false, w = false, b = false, n = false;
    int opt;
    while ((opt = getopt(argc, argv, "+vt:g:w:b:3456789")) != -1) {
        switch (opt) {
            case 'v':
                valid = true;
                break;
            case 't':
                if (tu) {
                    cerr << argv[0] << " option t can only be given once\n";
                    return 1;
                }
                char* p;
                strtol(optarg, &p, 10);
                if (*p) {
                    cerr << argv[0] << " option t given invalid argument " << optarg << "\n";
                    return 1;
                }
                turns = atoi(optarg);
                tu = true;
                break;
            case 'g':
                if (g) {
                    cerr << argv[0] << " option g can only be given once\n";
                    return 1;
                }
                good = optarg;
                g = true;
                break;
            case 'w':
                if (w) {
                    cerr << argv[0] << " option w can only be given once\n";
                    return 1;
                }
                meh = optarg;
                w = true;
                break;
            case 'b':
                if (b) {
                    cerr << argv[0] << " option b can only be given once\n";
                    return 1;
                }
                bad = optarg;
                b = true;
                break;
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (n) {
                    cerr << argv[0] << " length option can only be given once\n";
                    return 1;
                } 
                length = opt - '0';
                n = true;
                break;
            case ':':
                cerr << argv[0] << " option "  << opt << " missing arugment\n";
                return 1;
            default:
                cerr << argv[0] << " bad option " << opt << "\n";
                return 1;
        }
    }
    vector<string> words;
    while (optind < argc) {
        ifstream file(argv[optind]);
        if (!file) {
            cerr << argv[0] << " could not read " << argv[optind] << '\n';
            return 1;
        }
        optind++;
        string s;
        while (getline(file, s))
            if (s.size() == length)
                words.push_back(s);
    }
    if (words.size() < 1) {
        cerr << argv[0] << " dictionaries contained no " << length << " letter words\n";
        return 1;
    }
    cout << "I am thinking of a " << length << "-letter word.\n";
    random_device rd;
    int c = 0;
    string t;
    string word = words[rd() % words.size()];
    if (c >= turns) {
        cout << "You lost, the word was \"" << word << "\".\n";
        return 0;
    }
    cout << "Guess: ";
    while (cin >> t) {
        c++;
        if (t.size() != length) {
            cerr << argv[0] << " guess must be exactly " << length <<  " characters long\n";
            return 1;
        }
        if (valid && (find(words.begin(), words.end(), t) == words.end())) {
            cerr << argv[0] << " word not in dictionaries\n";
            return 1;
        }
        cout << "       ";
        for (size_t i = 0; i < length; i++) {
            if (t[i] == word[i])
                cout << good;
            else if (word.find(t[i]) != string::npos)
                cout << meh;
            else
                cout << bad;
        }
        cout << '\n';
        if (word == t) {
            cout << "You won!\n";
            return 0;
        }
        if (c >= turns) {
            cout << "You lost, the word was \"" << word << "\".\n";
            return 0;
        }
        cout << "Guess: ";
    }
    return 0;
}