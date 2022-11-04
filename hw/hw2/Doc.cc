#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Doc.h"

using namespace std;

Doc::Doc() {}

Doc::Doc(const Doc &d) : lines(d.lines), ind(d.ind) {}

Doc::~Doc() {}

Doc::Doc(const string &s) {Doc::read(s);}

Doc::Doc(istream &in) {Doc::read(in);}

void Doc::read(const string &s) {
	ifstream f(s);
	if (f)
		Doc::read(f);
	else
		cerr << "Could not read " << s << '\n';
}

void Doc::read(istream &in) {
	lines.clear();
	ind.clear();
	for (string line; getline(in, line); ) {
		string temp = "";
		size_t wspace = 0;
		for (char c : line) {
			if ((temp == "") && (c == ' '))
				wspace++;
			else if (c == '\t') {
				cerr << "Cannot read tab characters\n";
				exit(1);
			}
			else if (c == '\r') {}
			else
				temp.push_back(c);
		}
		if (temp.find_last_not_of(" \r") != string::npos)
			temp = temp.substr(0,temp.find_last_not_of(" ") + 1);
		lines.push_back(temp);
		ind.push_back(wspace);
	}
	trimlines();
}

void Doc::write(const string &s) {
	ofstream f(s);
	if (f)
		write(f);
	else
		cerr << "Could not write to " << s << '\n';
}

void Doc::write(ostream &file) {
	if (!lines.empty()) {
		for (size_t i = 0; i < lines.size(); i++) {
			file << string(ind.at(i), ' ') << lines.at(i) << '\n';
		}	
	}
}

void Doc::add(const string &s) {
	string temp = "";
	size_t wspace = 0;
	for (char c : s) {
		if ((temp == "") && (c == ' '))
			wspace++;
		else if (c == '\t') {
			cerr << "Cannot read tab characters\n";
			exit(1);
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
	return size() == 0;
}

size_t Doc::indent(size_t i) const {
	if (i > (ind.size() - 1)) {
		cerr << "Bad line number. Object has " << ind.size() << " lines\n";
		exit(1);
	}
	return ind.at(i);
}

string Doc::data(size_t i) const {
	if (i > (lines.size() - 1)) {
		cerr << "Bad line number. Object has " << ind.size() << " lines\n";
		exit(1);
	}
	return lines.at(i);
}

void Doc::trimlines() {
	vector<string> ltemp;
	vector<size_t> itemp;
	if (!lines.empty()) {
		size_t i=0,j=0;
		for (; i < lines.size(); i++) {
			if (lines.at(i) != "")
				break;
		}
		for (j = (lines.size()-1); j > i; j--) {
			if (lines.at(j) != "")
				break;
		}
		for (; i <= j; i++) {
			ltemp.push_back(lines.at(i));
			itemp.push_back(ind.at(i));
		}
	}
	lines = ltemp;
	ind = itemp;
}