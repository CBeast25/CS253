#include <iostream>
#include <vector>
#include <string>

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
		size_t size() const; 
		bool empty() const;
		size_t indent(size_t) const;
		std::string data(size_t) const;
		Doc& operator+=(const Doc&);
		Doc& operator+=(const std::string&);
		Total operator[](size_t) const;
		explicit operator bool() const;
	private:
		std::vector<std::string> lines;
		std::vector<size_t> ind;
};

bool operator>>(std::istream& in, Doc& d);
std::ostream& operator<<(std::ostream& out, const Doc& d);
Doc operator+(const Doc&, const Doc&);
Doc operator+(const Doc&, const std::string&);
Doc operator+(const std::string&, const Doc&);