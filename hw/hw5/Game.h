#include <string>
#include <vector>

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

class Game {
    public:
        Game();
        Game(const Game&);
        Game& operator=(const Game&);
        ~Game();
        void set_length(size_t);
        void add_dict(const std::string&);
        void set_good(const std::string&);
        void set_wrong(const std::string&);
        void set_bad(const std::string&);
        std::string select_target();
        bool contains(const std::string&) const;
        std::string feedback(const std::string&) const;
    private:
        size_t size = 5;
        std::string good = "=";
        std::string wrong = "-";
        std::string bad = " ";
        std::vector<std::string> words;
        std::string target;
};

#endif