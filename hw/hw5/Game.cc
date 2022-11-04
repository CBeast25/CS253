#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "Game.h"

using namespace std;

Game::Game() = default;
Game::Game(const Game&) = default;
Game::~Game() = default;
Game& Game::operator=(const Game&) = default;

void Game::set_length(size_t l) { size = l; }
void Game::add_dict(const string& d) {
    ifstream file(d);
    if (!file) 
        throw invalid_argument(d + " could not be opened for reading");
    string s;
    while (getline(file, s))
        words.push_back(s);
}

void Game::set_good(const string& g) { good = g; }
void Game::set_wrong(const string& w) { wrong = w; }
void Game::set_bad(const string& b) { bad = b; }

string Game::select_target() { 
    vector<string> templist;
    for (string s : words)
        if (s.length() == size)
            templist.push_back(s);
    if (templist.size() < 1) 
        throw length_error("Dictionaries contained no " + to_string(size) + " letter words\n");
    random_device rd;
    target = templist[rd() % templist.size()];
    return target;
}

bool Game::contains(const string& word) const {
    return find(words.begin(), words.end(), word) != words.end();
}

string Game::feedback(const string& guess) const {
    string out;
    for (size_t i = 0; i < size; i++) {
        if (target[i] == guess[i])
            out += good;
        else if (target.find(guess[i]) != string::npos)
            out += wrong;
        else
            out += bad;
    }
    return out;
}