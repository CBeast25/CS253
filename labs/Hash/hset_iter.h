#ifndef HSET_ITER_H_INCLUDED
#define HSET_ITER_H_INCLUDED

#include <iostream>
#include <list>
#include <vector>
#include <iterator>	// for next()

// Each hset_iter contains a reference to its associated hash,
// and an size_t indicating progress within the hash.

template <typename T>
class hset_iter {
    using table_t = typename std::vector<std::list<T>>;
    const table_t *parent;  // pointer to the hash table we’re iterating over
    size_t vector_index;		    // how far along we are.  0=first item
    size_t list_index;
  public:
    hset_iter(const table_t *table, size_t vi, size_t li) : parent(table), vector_index(vi), list_index(li) { }

    bool operator==(const hset_iter &rhs) const {
	return (vector_index == rhs.vector_index) && (list_index == rhs.list_index);
    }

    bool operator!=(const hset_iter &rhs) const {
	return !(*this == rhs);
    }

    // Return a pointer to the num'th element,
    // where num==0 is the first element.

    T operator*() const {
	// // First, find the right list:
	// auto remaining = num;
	// size_t index;
	// for (index=0; (*parent)[index].size() <= remaining; index++)
	//     remaining -= (*parent)[index].size();

	// // Second, find the right slot within that list:
	// return *next((*parent)[index].begin(), remaining);
        return *next((*parent)[vector_index].begin(), list_index);
    }

    // Pre-increment (usually returns a reference to the iterator)
    void operator++() {
        if (vector_index == ((*parent).size()-1)){
            ++list_index;
        }
	    else if((list_index + 1) >= (*parent)[vector_index].size()) {
            ++vector_index;
            while((*parent)[vector_index].empty() && vector_index != ((*parent).size()-1))
                ++vector_index;
            list_index = 0;
        }
        else    
            ++list_index;
        // std::cout << "SIZE: " << (*parent).size() << " " << (*parent)[vector_index].size() << "\n";
        // std::cout << "POSITION: " << vector_index << " " << list_index << "\n";
    }
};

#endif /* HSET_ITER_H_INCLUDED */
