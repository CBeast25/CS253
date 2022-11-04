#include <iostream>
#include <vector>
#include <string>

class Doc {
	public:
		Doc();
		Doc(const Doc &);
		~Doc();
		Doc(const std::string &);
		Doc(std::istream &);
		void read(const std::string &);
		void read(std::istream &);
		void write(const std::string &);
		void write(std::ostream &);
		void add(const std::string &);
		size_t size() const; 
		bool empty() const;
		size_t indent(size_t) const;
		std::string data(size_t) const;
		void trimlines();
	private:
		std::vector<std::string> lines;
		std::vector<size_t> ind;
};