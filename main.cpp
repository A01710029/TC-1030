/*
* Proyecto Archivo de Casos
* Paulina Almada Martínez
* A01710029
* 6/4/2023
* Un programa para organizar los casos civiles y criminales de un
* abogado y determinar cuanto dinero genera de estos casos
*/

#include <iostream>

#include "criminal.h" //biblioteca con objetos Criminal
#include "civil.h" //biblioteca con objetos Civil
#include "casos.h" //biblioteca con operaciones del menu

using namespace std;

int main(int argc, char * argv[]) {
    //Declarar objetos Casos para acceder operaciones
    Casos casosCrim;
    Casos casosCiv;
    
    //Ejemplos
    cout << "Casos ejemplo \n";
    casosCrim.creaEjemplosCrim();
    casosCiv.creaEjemplosCiv();
    cout << endl;
    
    //Demostrar distintas operaciones
    cout << "Operaciones Criminal \n";
    casosCrim.imprimeCasosCrim("homicidio");
    cout << "Pago Criminales: " << casosCrim.calcPagoCrim() << endl;

    casosCrim.agregaHomicidio("Colin", 'c', 400, 4, 67.3, false);
    casosCrim.agregaHurto("Lira", 'i', 34.54, 2, 67.4, 349.0);

    casosCrim.imprimeCasosCrim("homicidio");

    cout << endl;
    
    cout << "Operaciones Civil \n";
    casosCiv.imprimeCasosCiv("laborales");
    cout << "Pago Civiles: " << casosCiv.calcPagoCiv() << endl;

    casosCiv.agregaLaborales("Medina", 'p', 493.9, 9243.5, 5, true, "Nava");
    casosCiv.agregaLesiones("Molina", 'g', 2495.0, 239.84, 10, false, 'f');

    casosCiv.imprimeCasosCiv();
}