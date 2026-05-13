#include "grafo.hpp"
#include <iostream>
#include <set>
#include <list>

int main() {
	// test form-to
	std::cout << " Test from-to" << "\n";
	unidirected_edge e1(54,24);
	if (e1.from() != 24) {
		std::cout << "Test from-to fallito" << "\n";
	} else {
		std::cout << "Test from-to passato" << "\n";
	}
	
	if (e1.to() != 54) {
		std::cout << "Test fallito: to() di (54,24) dve essere 54" << "\n";
	} else {
		std::cout << "Test passato: to() di (54,24) è 54" << "\n";
	}
	
 	// test operator<, operator==
 	unidirected_edge e2(2,6);
 	unidirected_edge e3(6,2);
 	unidirected_edge e4(5,7);
 	std::cout << "\n";
 	std::cout << "I nodi sono: " << e2 << "," << e3 << "," << e4 << "\n";
 	
 	std::cout << "Test operator<" << "\n";
 	if (e2 < e4) {
	 	std::cout <<"Test operator< passato: " << e2 << "<" << e4 << "\n";
	 }
	 else {
		 std::cout <<"Test operator< fallito: " << e2 << ">" << e4 << "\n";
	}
	std::cout << "Test operator==" << "\n";	 
 	if (e2 == e3) {
	 	std::cout <<"Test operator== passato: " << e2 << "=" << e3 << "\n";
	 }
	 else {
		 std::cout <<"Test operator== fallito: " << e2 << "!=" << e3 << "\n";
	 }
	 if (e2 == e4) {
	 	std::cout <<"Test operator== passato: " << e2 << "=" << e4 << "\n";
	 }
	 else {
		 std::cout <<"Test operator== fallito: " << e2 << "!=" << e4 << "\n";
	 }
	 std::cout << "\n";

	 // test add_edge, all_edge, all_nodes	
	 std::cout << "Test add_edge, all_edge, all_nodes" << "\n";
	 unidirected_graph g;
	 
	 g.add_edge(unidirected_edge(0,4));
	 g.add_edge(unidirected_edge(5,9));
	 g.add_edge(unidirected_edge(11,6));
	 
	 std::cout << "Archi inseriti: ";
	 for (const auto& e : g.all_edges()) {
		 std::cout << e << " ";
	 }
	 std::cout << "\n";
	 
	 std::cout << "Nodi presenti: ";
	 for (int n : g.all_nodes()) {
		 std::cout << n << " ";
	 }
	 std::cout << "\n";
	 
	 // test neighbours
	 std::cout << "\nTest neighbours:\n ";
	 std::cout << "Vicini di 0: ";
	 for (int v : g.neighbours(0)) {
		 std::cout << v << " ";
	 }
	 std::cout << "\n";
	 
	 std::cout <<"Vicini di 6: ";
	 for (int v : g.neighbours(6)) {
		 std::cout << v << " ";
	 }
	 std::cout << "\n";
	 
	 std::cout << "Vinci di nodo inesistente 100: ";
	 for (int v : g.neighbours(100)) {
		 std::cout << v << " ";
	 }
	 std::cout << "vuoto\n";
	 
	 // test edge_number
	 std::cout << "\nTest edge_number:\n ";
	 int indice;
	 if (g.edge_number(unidirected_edge(0,4), indice)) {
		 std::cout << "Test passato: arco (0,4) trovato con indice " << indice << "\n";
	 }
	 else { 
		 std::cout << "Test fallito: arco (0,4) non trovato\n";
	 }
	 
	 if (!g.edge_number(unidirected_edge(100,200), indice)) {
		 std::cout << "Test passato: arco (100,200) non presente nel grafo\n";
	 }
	 else {
		 std::cout << "Test fallito: arco (100,200) non dovrebbe esistere\n";
	 }
	 
	 // test edge_at
	 std::cout << "\nTest edge_at:\n ";
	 unidirected_edge risultato(0,0);
	 
	 if (g.edge_at(0, risultato)) {
		 std::cout << "Test passato: edge_at(0) = " << risultato << "\n";
	 }
	 else {
		 std::cout << "Test fallito: indice 0 non valido\n";
	 }
	 
	 if (!g.edge_at(34, risultato)) {
		 std::cout << "Test passato: indice 34 fuori range\n";
	 }
	 else {
		 std::cout <<"Test fallito:indice 34 non dovrebbe esistere\n";
	 }
	 
	 // test operator-
	 std::cout <<"\nTest operator-\n";
	 unidirected_graph g2;
	 g2.add_edge(unidirected_edge(0,4));
	 g2.add_edge(unidirected_edge(6,11));
	 
	 unidirected_graph differenza = g - g2;
	 
	 std::cout << "Archi in g: ";
	 for (auto e : g.all_edges()) std::cout << e << " ";
	 std::cout << "\n";
	 
	 std::cout << "Archi in g2: ";
	 for (auto e : g2.all_edges()) std::cout << e << " ";
	 std::cout << "\n";
	 
	 std::cout << "Differenza g - g2: ";
	 for (auto e : differenza.all_edges()) std::cout << e << " ";
	 std::cout << "atteso: (5,9)\n";
	 
	 return 0;
}
	 
	 