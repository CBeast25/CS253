#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include "Doc.h"

using namespace std;

Doc::Doc() = default;

Doc::Doc(const Doc &d) : lines(d.lines), ind(d.ind) {}

Doc& Doc::operator=(const Doc&) = default;

Doc::~Doc() = default;

Doc::Doc(const string& str) {
	stringstream s(str);
	read(s);
}

Doc::Doc(istream &in) {read(in);}

bool Doc::read(istream &in) {
	lines.clear();
	ind.clear();
	for (string s; getline (in, s); ) {
		for (char c : s)
			if (c == '\t')
				throw runtime_error("Tab Character");
		while (!s.empty() && (s.back() == ' ' || s.back() == '\r'))
			s.pop_back();
		size_t leading = 0;
		while (leading < s.size() && s[leading] == ' ') 
			leading++;
		if (!(s.empty() && lines.empty())) {
			ind.push_back(leading);
			lines.push_back(s.substr(leading));
		}
	}
	while (!lines.empty() && lines.back().empty()) {
		lines.pop_back();
		ind.pop_back();
	}
	return true;
}

bool Doc::write(ostream &file) const{
	if (lines.empty())
		return false;
	for (size_t i = 0; i < lines.size(); i++) {
		file << string(ind.at(i), ' ') << lines[i] << '\n';
	}
	return true;
}

void Doc::add(const string &s) {
	string temp = "";
	size_t wspace = 0;
	for (char c : s) {
		if ((temp == "") && (c == ' '))
			wspace++;
		else if (c == '\t') {
			throw runtime_error("Tab Character Read");
		}
		else if (c == '\r') {}
		else
			temp.push_back(c);
	}
	ind.push_back(wspace);
	lines.push_back(temp);
}

size_t Doc::size() const {
	return lines.size();
}

bool Doc::empty() const {
	return lines.size() == 0;
}

Doc& Doc::operator+=(const Doc& d) {
	lines.insert(lines.end(), d.lines.begin(), d.lines.end());
	ind.insert(ind.end(), d.ind.begin(), d.ind.end());
	return *this;
}

Doc& Doc::operator+=(const string& s) {
	basic_add(s);
	return *this;
}

Doc::Total Doc::operator[](size_t n) const {
	if (n > (lines.size() - 1)) {
		stringstream t;
		t << "Given line " << n << " but Doc only contains " 
			<< lines.size() << " lines"; 
		throw out_of_range(t.str());
	}
	return {ind[n], lines[n]}; 
}

Doc::operator bool() const {
	return !empty();
}

void Doc::basic_add(string s) {
	size_t leading = 0;
	while (leading < s.size() && s[leading] == ' ') 
		leading++;
	ind.push_back(leading);
	lines.push_back(s.substr(leading));
}

void Doc::erase(size_t start, size_t count) {
	if (count == 0ULL)
		count = size()-start;
	if ((start + count) > size()) {
		stringstream t;
		t << "Line " << start + count << " for .erase(" 
			<< start << ", " << count << ") is out of range for a " 
			<< lines.size() << "-line Doc"; 
		throw out_of_range(t.str());
	}
	lines.erase(lines.begin()+start, lines.begin()+start+count);
	ind.erase(ind.begin()+start, ind.begin()+start+count);
}

void Doc::append(const Doc& d) {
	*this += d;
}

void Doc::insert(const Doc& d, size_t start) {
	if (start > size()) {
		stringstream t;
		t << "Line " << start << " for .insert(Doc d, " 
			<< start << ") is out of range for a " 
			<< lines.size() << "-line Doc"; 
		throw out_of_range(t.str());
	}
	lines.insert(lines.begin()+start, d.lines.begin(), d.lines.end());
	ind.insert(ind.begin()+start, d.ind.begin(), d.ind.end());
}

void Doc::replace(const Doc& d, size_t start, size_t count) {
	if (count == 0ULL)
		count = size()-start;
	if ((start + count) > size()) {
		stringstream t;
		t << "Line " << start + count << " for .replace(Doc d, " 
			<< start << "," << count << ") is out of range for a " 
			<< lines.size() << "-line Doc"; 
		throw out_of_range(t.str());
	}
	erase(start, count);
	lines.insert(lines.begin()+start, d.lines.begin(), d.lines.end());
	ind.insert(ind.begin()+start, d.ind.begin(), d.ind.end());
}

bool operator>>(istream& in, Doc& d) {
	return d.read(in);
}

ostream& operator<<(ostream& out, const Doc& d) {
	d.write(out);
	return out;
}

Doc operator+(const Doc& a, const Doc& b) {
	stringstream out;
	out << a; 
	out << b;
	return out.str();
}

Doc operator+(const Doc& a, const string& b) {
	return a + Doc(b);
}

Doc operator+(const string& a, const Doc& b) {
	return Doc(a) + b;
}