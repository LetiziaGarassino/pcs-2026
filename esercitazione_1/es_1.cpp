#include <iostream>

int main(int argc, const char *argv[])
{
    std::cout << "Numero di parametri: " << argc << "\n";

    for (int i = 0; i < argc; i++) {
        std::cout << "Parametro " << i << " = " << argv[i] << "\n";
    }

    return 0;
}


/* 
Esermpio di esecuzione:

input: ./es_1 oggi è il 14 marzo 2026

output: Numero di parametri: 7
Parametro 0 = ./es_1
Parametro 1 = oggi
Parametro 2 = è
Parametro 3 = il
Parametro 4 = 14
Parametro 5 = marzo
Parametro 6 = 2026

argc: conta i parametri passati al programma. In questo caso sono 7
argv: è un vettore che contiente gli argomenti, quindi accede agli argomenti tramite un indice che ndica la loro posizione.
*/