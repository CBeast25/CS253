#include <string>
#include <vector>

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

class Game {
    public:
        class iterator {
          public:
            iterator();
            iterator(const Game *, size_t);
            iterator(const Game::iterator&);
            iterator& operator=(const Game::iterator&);
            ~iterator();
            iterator& operator++();
            iterator operator++(int);
            [[nodiscard]]
            std::string operator*() const;
            bool operator==(const iterator &) const;
            bool operator!=(const iterator &) const;
          private:
            const Game *gp = nullptr;
            size_t pos = 0;
            bool isFirst = true;
            bool wanted();
        };
        [[nodiscard]]
        iterator begin() const;
        [[nodiscard]]
        iterator end() const;

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
        [[nodiscard]]
        bool contains(const std::string&) const;
        [[nodiscard]]
        std::string feedback(const std::string&) const;

        void set_wanted(bool (*p)(std::string));
    private:
        size_t size = 5;
        std::string good = "=";
        std::string wrong = "-";
        std::string bad = " ";
        std::vector<std::string> words;
        std::string target;
        Game *gp;
        bool (*wanted_function_pointer)(std::string) = nullptr;
};

#endif