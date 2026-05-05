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
		std::vector<std::vector<int>> vettori(100, std::vector<int>(size));
		
		for (int i = 0; i < 100; ++i) {
			rf.fill(vettori[i], -1000, 1000);
		}
		
		
		// faccio la copia dei vettori cosicchè ogni metodo ordina il vettore origile
		std::vector<std::vector<int>> vec_bubble = vettori;
		std::vector<std::vector<int>> vec_insertion = vettori;
		std::vector<std::vector<int>> vec_selection = vettori;
		std::vector<std::vector<int>> vec_sorted = vettori;
		std::vector<std::vector<int>> vec_merge = vettori;
		std::vector<std::vector<int>> vec_quick = vettori;
		std::vector<std::vector<int>> vec_quick_ibrido = vettori;
		
		std::cout<< "Dimensione del vettore = " << size << "\n";
		
		tc.tic(); // inizio
		for (int i = 0; i < 100; ++i) {
			bubble_sort(vec_bubble[i]);
		}
		double tempo_bubble = tc.toc()/100; //fine
		std::cout << "tempo di Bubble sort: " << tempo_bubble << " secondi \n";
		
		tc.tic(); // inizio
		for (int i = 0; i < 100; ++i) {
			insertion_sort(vec_insertion[i]);
		}
		double tempo_insertion = tc.toc()/100; //fine
		std::cout << "tempo di Insertion sort: " << tempo_insertion << " secondi \n";
		
		tc.tic(); // inizio
		for (int i = 0; i < 100; ++i) {
			selection_sort(vec_selection[i]);
		}
		double tempo_selection = tc.toc()/100; //fine
		std::cout << "tempo di Selection sort: " << tempo_selection << " secondi \n";
		
		tc.tic(); // inizio
		for (int i = 0; i < 100; ++i) {
			merge_sort(vec_merge[i], 0, (int)vec_merge[i].size() -1);
		}
		double tempo_merge = tc.toc()/100; //fine
		std::cout << "tempo di Merge sort: " << tempo_merge << " secondi \n";
		
		tc.tic(); // inizio
		for (int i = 0; i < 100; ++i) {
			quick_sort(vec_quick[i], 0, (int)vec_quick[i].size() -1);
		}
		double tempo_quick = tc.toc()/100; //fine
		std::cout << "tempo di Quick sort: " << tempo_quick << " secondi \n";
		
		tc.tic(); // inizio
		for (int i = 0; i < 100; ++i) {
			quick_sort_ibrido(vec_quick_ibrido[i], 0, (int)vec_quick_ibrido[i].size() -1);
		}
		double tempo_quick_ibrido = tc.toc()/100; //fine
		std::cout << "tempo di Quick ibrido sort: " << tempo_quick_ibrido << " secondi \n";
		
		tc.tic(); // inizio
		for (int i = 0; i < 100; ++i) {
			std::sort(vec_sorted[i].begin(), vec_sorted[i].end());
		}
		double tempo_sorted = tc.toc()/100; //fine
		std::cout << "tempo di sorted: " << tempo_sorted << " secondi \n";
		std::cout << "\n";
		
		
	}
	return EXIT_SUCCESS;
}
