#pragma once
#include <vector>
#include <algorithm>

// verifichiamo se il vettore è ordinato
template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
	if (vec.size() < 2) {
		return true; // se il vettore è costituito da 0 o 1 elemento allora il vettore è ordinato
	}
	
	for (size_t i = 1; i < vec.size(); ++i) {
		if (vec[i] < vec[i-1]) {
			return false; // controlliamo se due elementi subito successivi sono ordinati in modo crescente se quest non è verificato allora ritorno false
		}
	}
	return true;
}

// metodo bubble
template<typename T>
void bubble_sort(std::vector<T>& vec)
{
	if(vec.size() < 2) {
		return;
	}
	
	for (size_t i = 0; i < vec.size() - 1; ++i) {
		for (size_t j = vec.size() - 1; j > i; --j) {
			if (vec[j] < vec[j-1]) {
				std::swap(vec[j], vec[j-1]);
			}
		}
	}
}

// metodo insertion
template<typename T>
void insertion_sort(std::vector<T>& vec)
{
	if(vec.size() < 2) {
		return;
	}
	
	for (size_t j = 1; j < vec.size(); ++j) {
		T key = vec[j];
		int i = j-1;
		
		while ( i >= 0 && vec[i] > key) {
			vec[i+1] = vec[i]; 
			i = i-1;
		}
		vec[i+1] = key;
	}
}

// metodo selection
template<typename T>
void selection_sort(std::vector<T>& vec)
{
	if(vec.size() < 2) {
		return;
	}
	
	for (size_t i = 0; i < vec.size() -1; ++i) {
		size_t min = i;
		
		for (size_t j = i + 1; j < vec.size(); ++j) {
			if (vec[j] < vec[min]) {
				min = j;
			}
		}
		std::swap(vec[i], vec[min]);
	}
}
	
// metodo merge
template<typename T>
void merge(std::vector<T>& vec, int p, int q, int r) 
{
	int n1 = q - p + 1; // individuo la metà sinistra
	int n2 = r - q; // individuo la metà destra
	
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	
	for (int i = 0; i < n1; ++i) {
		L[i] = vec[p + i];
	}
	for (int j = 0; j < n2; ++j) {
		R[j] = vec[q + 1 + j];
	}
	
	int i = 0, j = 0, k = p;
	
	// confronto gli elementi di L e R, prendendo il valore minore
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vec[k] = L[i];
			++i;
		}
		else {
			vec[k] = R[j];
			++j;
		}
		++k;
	}
	
	// copio gli elementi rimasti quando uno dei due vettori è finito
	while (i < n1) {
		vec[k] = L[i];
		++i;
		++k;
	}
	while (j < n1) {
		vec[k] = R[j];
		++j;
		++k;
	}
}

template<typename T>
void merge_sort(std::vector<T>& vec, int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		
		merge_sort(vec, p, q);
		merge_sort(vec, q+1, r);
		
		merge(vec, p, q, r);
	}
}

// partition
template<typename T>
int partition(std::vector<T>& vec, int p, int r)
{
	T x = vec[r];
	int i = p-1;
	
	for (int j = p; j < r; ++j) {
		if (vec[j] <= x) {
			++i;
			std::swap(vec[i], vec[j]);
		}
	}
	std::swap(vec[i+1], vec[r]);
	return i+1;
}

// metodo Quicksort
template<typename T>
void quick_sort(std::vector<T>& vec, int p, int r)
{
	if (p<r) {
		int q = partition(vec, p, r);
		quick_sort(vec, p, q-1);
		quick_sort(vec, q+1, r);
	}
}

// modifichiamo quicksort che utilizza il metodo insertion come algoritmo quadratico più veloce 

// insertion sort modificato 
template<typename T>
void insertion_sort_new(std::vector<T>& vec, int p, int r)
{
	if(p >= r) return;
	
	for (int j = p+1; j <= r; ++j) {
		T key = vec[j];
		int i = j-1;
		
		while ( i >= p && vec[i] > key) {
			vec[i+1] = vec[i]; 
			i = i-1;
		}
		vec[i+1] = key;
	}
}

// quick sort ibrido
template<typename T>
void quick_sort_ibrido(std::vector<T>& vec, int p, int r)
{
	const int soglia = 32;
	
	if (p<r) {
		if (r-p+1 <= soglia) {
			insertion_sort_new(vec, p, r);
			return;
		}
		
		int q = partition(vec, p, r);
		quick_sort_ibrido(vec, p, q-1);
		quick_sort_ibrido(vec, q+1, r);
	}
}

