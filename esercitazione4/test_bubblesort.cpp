#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "sorted.hpp"
#include "randfiller.hpp"

int main()
{
	randfiller rf;
	
	for (int i = 0; i < 100; ++i) {
		int size = 1 + (std::rand() %1000); //creo vettori con dimensione casuale da 1 a 1000
		std::vector<int> vec(size);
		rf.fill(vec, -1000, 1000); // ripempo i vettori con numeri casuali
		
		bubble_sort(vec);
		
		if (!is_sorted(vec)) {
			std::cerr << "Errore: il metodo bubble sort non ha ordinato corretamente il vettore \n";
			return EXIT_FAILURE;
		}
	}
	
	// creo un vettore riempito con parole che deve essere ordinato in modo alfabetico
	std::vector<std::string> parole = {
		"cravatta", "mela", "nave", "gatto", "tavolo", "giacca", "lampada", "balena", "lavagna", 			"coltello"
	};
	
	bubble_sort(parole);
	
	if (!is_sorted(parole)) {
		std::cerr << "Errore: il metodo bubble sort non ha ordinato corretamente il vettore \n";
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
	