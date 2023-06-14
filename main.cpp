/*
* Proyecto Archivo de Casos
* Paulina Almada Martínez
* A01710029
* 6/16/2023
* Un programa para organizar los casos civiles y criminales de un
* abogado y determinar cuanto dinero genera de estos casos
*/

#include <iostream>

#include "criminal.h" //biblioteca con objetos Criminal
#include "civil.h" //biblioteca con objetos Civil
#include "casos.h" //biblioteca con operaciones del menu

using namespace std;

//Menu
void menu(){
    //Imprime las opciones del programa
    cout << "Menu:\n";
    cout << "1. Imprime casos criminales \n";
    cout << "2. Imprime casos civiles \n";
    cout << "3. Imprime casos criminales por tipo \n";  
    cout << "4. Imprime casos civiles por tipo \n";
    cout << "5. Calcula pago casos criminales \n";
    cout << "6. Calcula pago casos civiles \n";
    cout << "7. Calcula pago casos criminales por tipo \n";
    cout << "8. Calcula pago casos civiles por tipo \n";
    cout << "9. Calcula pago total \n";
    cout << "10. Agrega homicidio \n";
    cout << "11. Agrega hurto \n";
    cout << "12. Agrega demanda laboral \n";
    cout << "13. Agrega lesion personal \n";
    cout << "14. Salir \n";
}

int main(int argc, char * argv[]) {
    //Declarar objetos Casos para acceder operaciones
    Casos casosCrim;
    Casos casosCiv;
    
    //Ejemplos
    casosCrim.creaEjemplosCrim();
    casosCiv.creaEjemplosCiv();
    cout << endl;

    //Variables para el ciclo
    int opcion = 0;

    //Todos los casos
    string nom;
    char ver; 
    string temp_tipo;
    float temp_total;

    //Casos criminales
    double hrs;
    int grad;
    double tar;
    double val;
    bool invol;

    //Casos civiles
    double ac;
    double dem;
    int cuo; 
    bool cor;
    string deman;
    char dan;

    //Imprime menu
    menu();

    //ciclo para que el menu funcione hasta que se escoga salir
    while(opcion < 14 && opcion > -1){

        cout << "Seleccione un número: ";

        //Pedir al usuario una opcion
        cin >> opcion;

        //Acciones para opciones del menu
        switch(opcion){
            //Opcion 1: Imprime casos criminales
            case 1:
                casosCrim.imprimeCasosCrim(); 
                cout << endl;
            break;
            //Opcion 2: Imprime casos civiles
            case 2:
                casosCiv.imprimeCasosCiv();
                cout << endl;
            break;
            //Opcion 3: Imprime casos criminales por tipo
            case 3:
                cout << "Tipo (homicidio o hurto): ";
                cin >> temp_tipo;
                if(temp_tipo == "homicidio")
                    casosCrim.imprimeCasosCrim("homicidio");
                else
                    casosCrim.imprimeCasosCrim("hurto");
                cout << endl;
            break;
            //Opcion 4: Imprime casos civiles por tipo 
            case 4:
                cout << "Tipo (laborales o lesiones): ";
                cin >> temp_tipo;
                if(temp_tipo == "laborales")
                    casosCiv.imprimeCasosCiv("laborales");
                else
                    casosCiv.imprimeCasosCiv("lesiones");
                cout << endl;
            break;
            //Opcion 5: Calcula pago casos criminales
            case 5:
                cout << casosCrim.calcPagoCrim() << endl;
                cout << endl;
            break;
            //Opcion 6: Calcula pago casos civiles
            case 6: 
                cout << casosCiv.calcPagoCiv() << endl;
                cout << endl;
            break;
            //Opcion 7: Calcula pago casos criminales por tipo
            case 7: 
                cout << "Tipo (homicidio o hurto): ";
                cin >> temp_tipo;
                if(temp_tipo == "homicidio")
                    cout << casosCrim.calcPagoCrim("homicidio") << endl;
                else
                    cout << casosCrim.calcPagoCrim("hurto") << endl;
                cout << endl;
            break;
            //Opcion 8: Calcula pago casos civiles por tipo
            case 8: 
                cout << "Tipo (laborales o lesiones): ";
                cin >> temp_tipo;
                if(temp_tipo == "laborales")
                    cout << casosCiv.calcPagoCiv("laborales") << endl;
                else
                    cout << casosCiv.calcPagoCiv("lesiones") << endl;
                cout << endl;
            break;
            //Opcion 9: Calcula pago total
            case 9: 
                temp_total = casosCrim.calcPagoCrim() + casosCiv.calcPagoCiv();
                cout << temp_total << endl;
            break;
            //Opcion 10: Agrega homicidio
            case 10:
                cout << "Nombre (solo apellido) del cliente: ";
                cin >> nom;
                cout << "Veredicto del caso (i/c): ";
                cin >> ver;
                cout << "Horas dedicadas al caso: ";
                cin >> hrs;
                cout << "Grado del homicidio: ";
                cin >> grad;
                cout << "Tarifa por hora establecida: ";
                cin >> tar;
                cout << "Homicidio involuntario (t/f): ";
                cin >> invol;
                casosCrim.agregaHomicidio(nom, ver, hrs, grad, tar, invol);
                cout << "Homicidio agregado" << endl;
            break;
            //Opcion 11: Agrega hurto
            case 11: 
                cout << "Nombre del cliente: ";
                cin >> nom;
                cout << "Veredicto del caso (i/c): ";
                cin >> ver;
                cout << "Horas dedicadas al caso: ";
                cin >> hrs;
                cout << "Grado del hurto: ";
                cin >> grad;
                cout << "Tarifa por hora establecida: ";
                cin >> tar;
                cout << "Valor robado: ";
                cin >> val;
                casosCrim.agregaHurto(nom, ver, hrs, grad, tar, val);
                cout << "Hurto agregado" << endl;
            break;
            //Opcion 12: Agrega demanda laboral
            case 12:
                cout << "Nombre del cliente: ";
                cin >> nom;
                cout << "Veredicto del caso (g/p): ";
                cin >> ver;
                cout << "Acuerdo conseguido: ";
                cin >> ac;
                cout << "Demanda del cliente: ";
                cin >> dem;
                cout << "Cuota del acuerdo establecida (porcentaje): ";
                cin >> cuo;
                cout << "Fue a corte (t/f): ";
                cin >> cor;
                cout << "Demandando a: ";
                cin >> deman;
                casosCiv.agregaLaborales(nom, ver, ac, dem, cuo, cor, deman);
                cout << "Demanda laboral agregada" << endl;
            break;
            //Opcion 13: Agrega lesion personal
            case 13: 
                cout << "Nombre del cliente: ";
                cin >> nom;
                cout << "Veredicto del caso (g/p): ";
                cin >> ver;
                cout << "Acuerdo conseguido: ";
                cin >> ac;
                cout << "Demanda del cliente: ";
                cin >> dem;
                cout << "Cuota del acuerdo establecida (porcentaje): ";
                cin >> cuo;
                cout << "Fue a corte (t/f): ";
                cin >> cor;
                cout << "Tipo de daño (f/m): ";
                cin >> dan;
                casosCiv.agregaLesiones(nom, ver, ac, dem, cuo, cor, dan);
                cout << "Lesion personal agregada" << endl;
            break;
        }
    }
}
