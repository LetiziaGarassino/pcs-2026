#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "sorted.hpp"
#include "randfiller.hpp"
#include "timecounter.hpp"

int main()
{
	randfiller rf;
	timecounter tc;
	
	for (int size = 4; size <= 8192; size *= 2) {
		std::vector<int> vec;
		vec.resize(size);
		rf.fill(vec, -1000, 1000);
		
		// faccio la copia dei vettori cosicchè ogni metodo ordina il vettore origile
		std::vector<int> vec_bubble = vec;
		std::vector<int> vec_insertion = vec;
		std::vector<int> vec_selection = vec;
		std::vector<int> vec_sorted = vec;
		
		tc.tic(); // inizio
		bubble_sort(vec_bubble);
		double tempo_bubble = tc.toc(); //fine
		std::cout << "tempo di Bubble sort: " << tempo_bubble << " secondi \n";
		
		tc.tic(); // inizio
		insertion_sort(vec_insertion);
		double tempo_insertion = tc.toc(); //fine
		std::cout << "tempo di Insertion sort: " << tempo_insertion << " secondi \n";
		
		tc.tic(); // inizio
		selection_sort(vec_selection);
		double tempo_selection = tc.toc(); //fine
		std::cout << "tempo di Selection sort: " << tempo_selection << " secondi \n";
		
		tc.tic(); // inizio
		std::sort(vec_sorted.begin(), vec_sorted.end());
		double tempo_sorted = tc.toc(); //fine
		std::cout << "tempo di sorted: " << tempo_sorted << " secondi \n";
	}
	return EXIT_SUCCESS;
}
		