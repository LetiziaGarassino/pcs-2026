#include <iostream>
#include <cmath>
#include <algorithm>


int main()
{
	static const int N = 10;
	double arr[N] = {2.4, 7.1, 3.9, 7.4, 2.2, 4.2, 24.6, 124.7, 99.2, 53.8};
	
	double massimo = arr[0];
	double minimo = arr[0];
	double somma = 0.0;
	double somma_scarti_quadrati = 0.0;
	
	// calcoliamo il valore massimo e minimo e la somma dell'array, scorrendo tutto il vettore
	for (int i = 0; i < N; i++) {
		massimo = std::max(massimo, arr[i]);
		minimo = std:: min(minimo, arr[i]);
		somma = somma + arr[i];
	}
		
	// calcoliamo la media
	double media = somma/N;
	
	// calcoliamo la deviazione standard
	for (int i = 0; i < N; i++) {
		double scarto = arr[i] - media;
		somma_scarti_quadrati += scarto*scarto;
	}
	double varianza = somma_scarti_quadrati/N;
	double deviazione_standard = std::sqrt(varianza);
	
	// stampo i risultati
	std::cout <<"Minimo = " << minimo << "\n";
	std::cout <<"Massimo = " << massimo <<"\n";
	std::cout << "Media = " << media << "\n";
	std::cout <<"Deviazione standard = " << deviazione_standard << "\n";
	
	return 0;
}
	
	
		
	
	
	
	
	
	
	