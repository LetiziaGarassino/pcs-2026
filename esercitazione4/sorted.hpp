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
	