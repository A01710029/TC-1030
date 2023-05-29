/*
* Proyecto Archivo de Casos
* Paulina Almada Martínez
* A01710029
* 5/26/2023
* Esta clase define el objeto Civil que contiene las
* clases heredadas Laborales y Lesiones
*/

#ifndef CIVIL_H_
#define CIVIL_H_

#include <string>
#include <sstream>

using namespace std;

//Declaración de clase Civil
class Civil {
    //Variables de instancia
    protected:
    int id;
    string nombre;
    char veredicto;
    double acuerdo;
    double demanda;
    int cuota;
    bool corte;

    //Métodos
    public:
    //Constructores
    //Default
    Civil(): id(0), nombre(""), veredicto('g'), acuerdo(0.0), demanda (0.0), cuota(0), corte(false) {}; 

    //Con parámetros
    Civil(int id_num, string nom, char ver, double ac, double dem, int cuo, bool cor):
    id(id_num), nombre(nom), veredicto(ver), acuerdo(ac), demanda(dem), cuota(cuo), corte(cor) {};

    //Métodos del objeto
        //Getters
        int get_id() {
            return id;
        }

        string get_nombre() {
            return nombre;
        }

        char get_veredicto() {
            return veredicto;
        }
        
        double get_acuerdo() {
            return acuerdo;
        }
        
        int get_demanda() {
            return demanda;
        }
        
        double get_cuota() {
            return cuota;
        }

        bool get_corte(){
            return corte;
        }

        //Método abstracto
        virtual string toString() = 0; //para sobreescribir
};

//Declaración de clase Laborales (hereda de Civil)
class Laborales: public Civil {
    //Variables de instancia
    private: 
    string demandado;

    //Métodos
    public:
    //Constructores
    Laborales(): Civil(0, "", 'g', 0.0, 0.0, 0, false) {};

    Laborales(int id, string nombre, char veredicto, double acuerdo, \
    double dem, int cuo, bool cor, string deman): Civil(id, nombre, \
    veredicto, acuerdo, demanda, cuota, corte), demandado(deman) {};

    //Getters
    int get_id() {
        return id;
    }

    string get_nombre() {
        return nombre;
    }

    char get_veredicto() {
        return veredicto;
    }

    double get_acuerdo() {
            return acuerdo;
    }
        
    int get_demanda() {
        return demanda;
    }
        
    double get_cuota() {
        return cuota;
    }

    bool get_corte(){
        return corte;
    }

    string get_demandado(){
        return demandado;
    }

    //Otras funciones
    double calcularPago();
    double calcularGana_Cliente();
    string toString();
};

/*
* calcularPago define el valor de pago para cada caso
* basado en el veredicto, calcula el pago que recibe
* el abogado por su trabajo, multiplicando por la cuota definida
*
* @param
* @return valor total de pago (double) 
*/
double Laborales::calcularPago() {
    double total;
    if (veredicto == 'p'){
        total = cuota * acuerdo * 0.5;
    } else if (acuerdo / demanda > 0.50 || corte == true) {
        total = cuota * acuerdo * 1.05;
    } else if (acuerdo / demanda < 0.50) {
        total = cuota * acuerdo * 1.02;
    } 
    return total;
}

/* 
* calcularGana_Cliente calcula la diferencia entre
* lo que pidio el cliente y lo que se gano
* al final del caso
* 
* @param
* @return valor de la ganancia (double)
*/
double Laborales::calcularGana_Cliente(){
    double ganancia;
    ganancia = acuerdo - demanda;
    return ganancia;
}

/*
* toString convierte atributos a string
* concatena todos los valores de los atributos en un string
* para imprimirlos
*
* @param
* @return string con los valores y texto
*/

//sobreescritura de toString en Civil (padre)
string Laborales::toString(){
    stringstream aux;
    aux << "Defendiendo a " << nombre << " en una demanda contra " << demandado << \
    " por " << demanda << " con un veredicto de " << veredicto << \
    " consiguiendo un acuerdo de " << acuerdo << " con una cuota de " \
    << cuota << ". Fue a corte: " << corte << "\n";
    return aux.str();
}

//Declaración de clase Lesiones (hereda de Civil)
class Lesiones: public Civil {
    //Variables de instancia
    private: 
    char dano;

    //Métodos
    public:
    //Constructores
    Lesiones(): Civil(0, "", 'g', 0.0, 0.0, 0, false) {};

    Lesiones(int id, string nombre, char veredicto, double acuerdo, \
    double demanda, int cuota, bool corte, char dan): Civil(id, nombre, \
    veredicto, acuerdo, demanda, cuota, corte), dano(dan) {};

    //Otras funciones
    double calcularPago();
    double calcularGana_Cliente();
    string toString();
};

/*
* calculaPago calcula el pago del cliente
* basado en la cuota, lo ganado para el cliente,
* que tipo de daño sufrio el cliente
* y si el caso fue a corte
* 
* @param
* @return valor total (double)
*/
double Lesiones::calcularPago() {
    double total;
    if (veredicto == 'p'){
        total = cuota * acuerdo * 0.5;
    } else if (acuerdo / demanda > 0.50 || corte == true) {
        total = cuota * acuerdo * 1.05;
    } else if (acuerdo / demanda < 0.50 || dano == 'm') {
        total = cuota * acuerdo * 1.02;
    }
    return total;
}

/*
* calcularGana_Cliente calcula la diferencia entre
* lo que pidio el cliente y lo que se gano
* al final del caso
* @param
* @return double ganancia
*/
double Lesiones::calcularGana_Cliente(){
    double ganancia;
    ganancia = acuerdo - demanda;
    return ganancia;
}

/*
* toString convierte atributos a string
* concatena todos los valores de los atributos en un string
* para imprimirlos
*
* @param
* @return string con los valores y texto
*/
//sobreescritura de toString en Civil (padre)
string Lesiones::toString(){
    stringstream aux;
    aux << "Defendiendo a " << nombre << " en una demanda por daños de tipo " << dano << \
    " por " << demanda << " con un veredicto de " << veredicto << \
    " consiguiendo un acuerdo de " << acuerdo << " con una cuota de " \
    << cuota << ". Fue a corte: " << corte << "\n";
    return aux.str();
}

#endif // CIVIL_H_
