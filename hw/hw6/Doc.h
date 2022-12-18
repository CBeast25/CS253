#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <sstream>

#ifndef DOC_INCLUDED
#define DOC_INCLUDED

class Doc {
	struct Total {
		size_t indent;
		std::string data;
	};
	public:
		Doc();
		Doc(const Doc &);
		Doc& operator=(const Doc&);
		~Doc();
		Doc(const std::string&);
		Doc(std::istream &);
		bool read(std::istream &);
		bool write(std::ostream &) const;
		void add(const std::string &);
		[[nodiscard]]
		size_t size() const;
		[[nodiscard]] 
		bool empty() const;
		size_t indent(size_t) const;
		std::string data(size_t) const;
		Doc& operator+=(const Doc&);
		Doc& operator+=(const std::string&);
		[[nodiscard]]
		Total operator[](size_t) const;
		explicit operator bool() const;
		void erase(size_t start, size_t count = {});
		void append(const Doc&);
		void insert(const Doc&, size_t);
		void replace(const Doc& d, size_t start, size_t count = {});
		template <typename T>
		void append(T a, T b) {
			for (auto it = a; it != b; ++it)
				basic_add(*it);
		}
		template <typename T>
		void insert(T a, T b, size_t start) {
			if (start > size()) {
				std::stringstream t;
				t << "Line " << start << " for .insert(iter, iter, " 
					<< start << ") is out of range for a " 
					<< lines.size() << "-line Doc"; 
				throw std::out_of_range(t.str());
			}
			Doc temp;
			for (auto it = a; it != b; ++it)
				temp.basic_add(*it);
			insert(temp, start);
		}
		template <typename T>
		void replace(T a, T b, size_t start, size_t count = {}) {
			if (count == 0ULL)
				count = size()-start;
			if ((start + count) > size()) {
				std::stringstream t;
				t << "Line " << start + count << " for .replace(Doc d, " 
					<< start << "," << count << ") is out of range for a " 
					<< lines.size() << "-line Doc"; 
				throw std::out_of_range(t.str());
			}
			Doc temp;
			for (auto it = a; it != b; ++it)
				temp.basic_add(*it);
			replace(temp, start, count);
		}
	private:
		void basic_add(std::string);
		std::vector<std::string> lines;
		std::vector<size_t> ind;
};

bool operator>>(std::istream& in, Doc& d);
std::ostream& operator<<(std::ostream& out, const Doc& d);
Doc operator+(const Doc&, const Doc&);
Doc operator+(const Doc&, const std::string&);
Doc operator+(const std::string&, const Doc&);

#endif