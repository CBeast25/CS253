#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "Game.h"

using namespace std;

Game::iterator::iterator() = default;
Game::iterator::iterator(const Game *g, size_t ind) : gp(g), pos(ind) { 
    ++*this;
}

Game::iterator::iterator(const Game::iterator&) = default;
Game::iterator& Game::iterator::operator=(const Game::iterator&) = default;
Game::iterator::~iterator() = default;

Game::iterator& Game::iterator::operator++() {
    while(pos < gp->words.size()) {
        // cout << "Test: " << gp->words[pos] << '\n';
        if (!isFirst)
            pos++;
        else
            isFirst = false;
        if(wanted())
            return *this;
    }
    gp = nullptr;
    return *this;
}

bool Game::iterator::wanted() {
    return (gp->words[pos].size() == gp->size)
            && (gp->wanted_function_pointer != nullptr ? gp->wanted_function_pointer(gp->words[pos]) : true);
}

Game::iterator Game::iterator::operator++(int) {
    Game::iterator old = *this;
    ++*this;
    return old;
}

std::string Game::iterator::operator*() const { 
    return gp->words[pos]; 
}
bool Game::iterator::operator==(const iterator &rhs) const { return gp == rhs.gp; }
bool Game::iterator::operator!=(const iterator &rhs) const { return !(*this == rhs); }

Game::iterator Game::begin() const { return iterator(this, 0); }
Game::iterator Game::end() const { return iterator(this, words.size()); }

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

void Game::set_wanted(bool (*p)(string)) {
    wanted_function_pointer = p;
}
