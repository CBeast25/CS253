#include "Directory.h"
#include <iostream>

using namespace std;

// The directory iterator pre-fetches the name.  That is, readdir()
// is called when you first create the iterator, and upon ++.
//
// An end() iterator is designated by a null pointer for its DIR *.
// When readdir() fails, we set our pointer to null.

// Fix #3
DirectoryIterator::DirectoryIterator(DIR *dp_arg, string s) : dp(dp_arg), match(s) {
    ++*this;				// get that first entry
}

// Get the next entry in the directory (that we like) and
// put it in the member variable name.

DirectoryIterator &DirectoryIterator::operator++() {	// pre-increment
    while (auto p = readdir(dp)) {	// Read a directory entry.
	    name = p->d_name;		// C-string ⇒ C++ string
    // Fix #2
	// if (name == ".")		// Stupid entry for current directory?
	//     continue;			// Nobody wants that.
	// if (name == "..")		// Stupid entry for parent directory?
	//     continue;			// Nobody wants that.
        if (!wanted())
            continue;
        return *this;			// Everything else, I like!
    }
    dp = nullptr;			// readdir failed; don’t try again.
    return *this;
}

// Fix #2
bool DirectoryIterator::wanted() {
    // Fix #3
    return (match == "" ? true : (name.find(match) != string::npos)) 
        && (name != ".") && (name != ".."); 
}

string DirectoryIterator::operator*() const {
    return name;			// Fetched in a previous ++.
}

bool DirectoryIterator::operator!=(const DirectoryIterator &rhs) const {
    return dp != rhs.dp;
}



//////////////// Directory methods

Directory::Directory(const char dirname[], string s) : dp(opendir(dirname)), match(s) { 
    // FIX #1
    if (!dp)
        throw(runtime_error("Could not open "s + dirname));
}

Directory::~Directory() {
    if (dp)				// Only if opendir() succeeded:
	closedir(dp);			//   should we close it.
}

Directory::iterator Directory::begin() const {
    return iterator(dp, match);
}

Directory::iterator Directory::end() const {
    return iterator();
}
