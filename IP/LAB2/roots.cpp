/* Scrivere un programma che prende in input tre numeri reali, a, b e c 
e stampa le radici dell’equazione di secondo grado
ax2 + bx + c. Attenzione alle radici immaginarie. [ File roots.cpp ]
[SUGGERIMENTO: Radice di x: sqrt(x); aggiungere in testa al file: #include <cmath> ] */

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{

int a, b, c;

cout << "inserisci 3 numeri: "; 

cin >> a >>b >>c;


cout << "la prima soluzione e': " << (((((-1*b) + (sqrt(pow(b, 2))))	-	(4 * a* c))) 	/ (2*a)) << endl;

cout << "la seconda soluzione e': " << (((((-1*b) - (sqrt(pow(b, 2))))	-	(4 * a* c))) 	/ (2*a)) << endl;

//BAH NON HO CAPITO MOLTO SINC

}

/* #include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    
    // Input dei coefficienti dell'equazione
    std::cout << "Inserisci il coefficiente a: ";
    std::cin >> a;
    std::cout << "Inserisci il coefficiente b: ";
    std::cin >> b;
    std::cout << "Inserisci il coefficiente c: ";
    std::cin >> c;
    
    // Calcolo del discriminante
    double discriminante = b * b - 4 * a * c;
    
    if (discriminante > 0) {
        // Due radici reali distinte
        double radice1 = (-b + sqrt(discriminante)) / (2 * a);
        double radice2 = (-b - sqrt(discriminante)) / (2 * a);
        std::cout << "Le radici reali dell'equazione sono: " << radice1 << " e " << radice2 << std::endl;
    } else if (discriminante == 0) {
        // Una radice reale (radice doppia)
        double radice = -b / (2 * a);
        std::cout << "L'equazione ha una radice reale (radice doppia): " << radice << std::endl;
    } else {
        // Radici immaginarie
        double parteReale = -b / (2 * a);
        double parteImmaginaria = sqrt(-discriminante) / (2 * a);
        std::cout << "Le radici sono complesse: " << parteReale << " + " << parteImmaginaria << "i e " << parteReale << " - " << parteImmaginaria << "i" << std::endl;
    }
    
    return 0;
}
*/