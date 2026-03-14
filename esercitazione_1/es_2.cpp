// es 2

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char*argv[])
{
	if (argc < 2) {
		std::cout << "Errore: parametro non specificato\n";
		return 1;
	}

	std::string nome_file = argv[1];
	std::ifstream ifs(nome_file);
	
	if(ifs.is_open()) {
		std::string city;
		double t0;
		double t6;
		double t12;
		double t18;
		
		while (ifs >> city >> t0 >> t6 >> t12 >> t18) {
			double media = (t0 + t6 + t12 + t18) / 4.0;
			std:: cout << city << " " << media << "\n";
		}
	}
	else {
		std:: cout << "problema ad aprire il file\n";
		return 1;
	}
	return 0;
}