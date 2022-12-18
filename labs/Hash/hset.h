#ifndef HSET_H_INCLUDED
#define HSET_H_INCLUDED

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include "hasher.h"
#include "hset_iter.h"

template <typename T, typename H = Hasher>
class hset {
  private:
    std::vector<std::list<T>> table;

  public:
    using iterator = hset_iter<T>;
    using value_type = T;
    using size_type = size_t;

    // Exercise 1
    hset(int size = 5) : table(size) { }
    hset(const hset &) = default;
    hset& operator=(const hset &) = default;
    ~hset() = default;

    void insert(const T &datum) {
	auto hashval = H()(datum) % table.size();
	auto &lr = table[hashval];
	if (find(lr.begin(), lr.end(), datum) == lr.end())
	    lr.push_back(datum);
    }

    // Walk down the hash table, adding up all the sizes.
    size_type size() const {
	size_type total = 0;
	for (const auto &row : table)
	    total += row.size();
	return total;
    }

    // Exercise 4
    iterator begin() const {
	return iterator(&table, 0, 0);
    }

    // Exercise 4
    iterator end() const {
	return iterator(&table, table.size() - 1, table[table.size()-1].size());
    }

    void dump() const {
	for (size_t i=0; i<table.size(); i++) {	    // loop over the vector
	    std::cout << "table[" << i << "]";
	    for (const auto &v : table[i])	    // loop over one list
		std::cout << ' ' << v;
	    std::cout << '\n';
	}
    }

    // Exercise 2
    bool empty() {
        for (const auto &row : table)
            if (!row.empty())
                return false;
        return true;
    }
};

#endif /* HSET_H_INCLUDED */
