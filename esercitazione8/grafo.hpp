#include <iostream>
#include <set>
#include <map>
#include <stdexcept>
#include <algorithm>

class unidirected_edge {
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
	bool operator<(const unidirected_edge& other) const {
		if (from_ != other.from_) {
			return from_ < other.from_;
		}
		return to_ < other.to_;
	}
	
	// operator ==
	bool operator==(const unidirected_edge& other) const {
		return from_ == other.from_ && to_== other.to_;
	}
};

// operator <<:
std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) {
	os << "(" << e.from() << "," << e.to() << ")";
	return os;
}

class unidirected_graph {
private:
	// mappa di adiacenza
	std::map<int, std::set<int>> adiacenza;
	// insieme di archi
	std::set<unidirected_edge> edges_;
	
public: 
	// costruttore di default:
	unidirected_graph() = default;
	
	// costruttore di copia:
	unidirected_graph(const unidirected_graph&) = default;

	// metodo neighbours:
	std::set<int> neighbours(int nodo) const {
		auto iteratore = adiacenza.find(nodo);
		if (iteratore == adiacenza.end()) {
			return {};
		}
		return iteratore->second;
	}
	
	// metodo add_edge: 
	void add_edge(const unidirected_edge& e) {
		edges_.insert(e);
		
		int n1 = e.from();
		int n2 = e.to();
		
		adiacenza[n1].insert(n2);
		adiacenza[n2].insert(n1);
	}
	
	// metodo all_edge che restituisce tutti gli archi:
	std::set<unidirected_edge> all_edges() const {
		return edges_;
	}
	
	// metodo all_nodes che restituisce tutti i nodi:
	std::set<int> all_nodes() const {
		std::set<int> nodi;
		
		for (const auto& coppia : adiacenza) {
			nodi.insert(coppia.first);
		}
		return nodi;
	}
	
	//metodo edge_number che, dato un arco, ne restituisce la sua numerazione all’interno del grafo:
	bool edge_number(const unidirected_edge& e, int& indice_fuori) const {
		int indice = 0;
		
		for (const auto& edge : edges_) {
			if (edge == e) {
				indice_fuori = indice;
				return true;
			}
			indice++;
		}
		return false;
	}
	
	// metodo edge_at che, dato un numero d’arco, restituisce il corrispondente oggetto arco
	// all’interno del grafo:
	bool edge_at(int indice, unidirected_edge& result) const {
		if (indice < 0 || indice <= (int)edges_.size()) {
			return false;
		}
		
		int corrente = 0;
		for (const auto& edge : edges_) {
			if (corrente == indice) {
				result = edge;
				return true;
			}
			corrente++;
		}
		return false;
	}
	
	// metodo operator- che permette di calcolare la differenza tra due grafi: dati G e G′, la 			differenza G − G′ `e data dagli archi presenti in G e non presenti in G′
	unidirected_graph operator-(const unidirected_graph& other) const {
		unidirected_graph result; // creo un grafo vuoto dove metterò la differenza
		
		for (const auto& edge : edges_) {
			if (other.edges_.find(edge) == other.edges_.end()) {
				result.add_edge(edge); // aggiungo l'arco che è in G e non in G'
			}
		}
		return result;
	}
};