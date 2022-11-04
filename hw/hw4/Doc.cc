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
	lines.insert(lines.begin(), d.lines.begin(), d.lines.end());
	ind.insert(ind.begin(), d.ind.begin(), d.ind.end());
	return *this;
}

Doc& Doc::operator+=(const std::string& s) {
	add(s);
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