/*
* Proyecto Archivo de Casos
* Paulina Almada Martínez
* A01710029
* 6/16/2023
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
    string tipo;
    string nombre;
    char veredicto;
    float acuerdo;
    float demanda;
    float cuota;
    bool corte;

    //Métodos
    public:
    //Constructores
    //Default
    Civil(): id(0), tipo(""), nombre(""), veredicto('g'), acuerdo(0.0), demanda (0.0), cuota(0.0), corte(false) {}; 

    //Con parámetros
    Civil(int id_num, string tip, string nom, char ver, float ac, float dem, float cuo, bool cor):
    id(id_num), tipo(tip), nombre(nom), veredicto(ver), acuerdo(ac), demanda(dem), cuota(cuo), corte(cor) {};

    //Métodos del objeto
        //Getters
        int get_id() {
            return id;
        }

        string get_tipo() {
            return tipo;
        }

        string get_nombre() {
            return nombre;
        }

        char get_veredicto() {
            return veredicto;
        }
        
        float get_acuerdo() {
            return acuerdo;
        }
        
        int get_demanda() {
            return demanda;
        }
        
        float get_cuota() {
            return cuota;
        }

        bool get_corte(){
            return corte;
        }

        //Métodos abstractos
        virtual string toString() = 0; //para sobreescribir
        virtual float calcularPago() = 0;
        virtual float calcularGanaCliente() = 0; 
};

//Declaración de clase Laborales (hereda de Civil)
class Laborales: public Civil {
    //Variables de instancia
    private: 
    string demandado;

    //Métodos
    public:
    //Constructores
    Laborales(): Civil(0, "laborales", "", 'g', 0.0, 0.0, 0.0, false), demandado("") {};

    Laborales(int id, string nombre, char veredicto, float acuerdo, \
    float dem, float cuo, bool cor, string deman): Civil(id, "laborales", nombre, \
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

    float get_acuerdo() {
            return acuerdo;
    }
        
    int get_demanda() {
        return demanda;
    }
        
    float get_cuota() {
        return cuota;
    }

    bool get_corte(){
        return corte;
    }

    string get_demandado(){
        return demandado;
    }

    //Otras funciones
    float calcularPago();
    float calcularGanaCliente();
    string toString();
};

/**
* calcularPago define el valor de pago para cada caso
* basado en el veredicto, calcula el pago que recibe
* el abogado por su trabajo, multiplicando por la cuota definida
*
* @param
* @return valor total de pago (float) 
*/
float Laborales::calcularPago() {
    float total;
    if (veredicto == 'p'){
        total = cuota * acuerdo * 0.5;
    } else if (acuerdo / demanda > 0.50 || corte == true) {
        total = cuota * acuerdo * 1.05;
    } else if (acuerdo / demanda < 0.50) {
        total = cuota * acuerdo * 1.02;
    } 
    return total;
}

/** 
* calcularGanaCliente calcula la diferencia entre
* lo que pidio el cliente y lo que se gano
* al final del caso
* 
* @param
* @return valor de la ganancia (float)
*/
float Laborales::calcularGanaCliente(){
    float ganancia;
    ganancia = acuerdo - demanda;
    return ganancia;
}

/**
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
    Lesiones(): Civil(0, "lesiones", "", 'g', 0.0, 0.0, 0.0, false), dano('m') {};

    Lesiones(int id, string nombre, char veredicto, float acuerdo, \
    float demanda, float cuota, bool corte, char dan): Civil(id, "lesiones", nombre, \
    veredicto, acuerdo, demanda, cuota, corte), dano(dan) {};

    //Otras funciones
    float calcularPago();
    float calcularGanaCliente();
    string toString();
};

/**
* calculaPago calcula el pago del cliente
* basado en la cuota, lo ganado para el cliente,
* que tipo de daño sufrio el cliente
* y si el caso fue a corte
* 
* @param
* @return valor total (float)
*/
float Lesiones::calcularPago() {
    float total;
    if (veredicto == 'p'){
        total = cuota * acuerdo * 0.5;
    } else if (acuerdo / demanda > 0.50 || corte == true) {
        total = cuota * acuerdo * 1.05;
    } else if (acuerdo / demanda < 0.50 || dano == 'm') {
        total = cuota * acuerdo * 1.02;
    }
    return total;
}

/**
* calcularGanaCliente calcula la diferencia entre
* lo que pidio el cliente y lo que se gano
* al final del caso
* @param
* @return float ganancia
*/
float Lesiones::calcularGanaCliente(){
    float ganancia;
    ganancia = acuerdo - demanda;
    return ganancia;
}

/**
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
