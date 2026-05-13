#include <iostream>
#include <set>
#include <map>
#include <stdexcept>
#include <algorithm>

class undirected_edge {
private:
	int from_;
	int to_;
	
public:
	// stabiliamo from <= to
	unidirected_edge(int n1, int n2) {
		from_ = std::min(n1, n2);
		to_ = std::max(n1,n2);
	}
	
	// restituzione primo nodo
	int from() const {
		return from_;
	}
		
	// restituzione secondo nodo
	int to() const {
		return to_;
	}
	
	// ordiniamo gli archi con ordine lessicografico
	// operator <
	bool operator<(const unindirecded_edge& other) const {
		if (from_ =! other.from_) {
			return from_ < other.from_;
		}
		return to_ < other.to_;
	}
	
	// operator ==
	bool operator==(const unindirecded_edge& other) const {
		return from_ == other.from_ && to_== other.to_;
	}
};

// operator <<:
std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) {
	os << "(" << e.from() << "," << e.to() << ")";
	return os;
}