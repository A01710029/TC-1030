/*
* Proyecto Archivo de Casos
* Paulina Almada Martínez
* A01710029
* 6/16/2023
* Esta clase define el objeto Criminal que contiene las
* clases heredadas Homicidio y Hurto
*/

#ifndef CRIMINAL_H_
#define CRIMINAL_H_

#include <string>
#include <sstream>

using namespace std;

//Declaración de clase Criminal
class Criminal {
    //Variables de instancia
    protected:
    int id;
    string tipo;
    string nombre;
    char veredicto;
    float horas;
    int grado;
    float tarifa;

    //Métodos
    public:
    //Constructores
    //Default
    Criminal(): id(0), tipo(""), nombre(""), veredicto('i'), horas(0.0), grado(0), tarifa(0.0) {}; 

    //Con parámetros
    Criminal(int id_num, string tip, string nom, char ver, float hr, int grad, float tar):
    id(id_num), tipo(tip), nombre(nom), veredicto(ver), horas(hr), grado(grad), tarifa(tar) {};

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
        
        float get_horas() {
            return horas;
        }
        
        int get_grado() {
            return grado;
        }
        
        float get_tarifa() {
            return tarifa;
        }

        //Método abstracto
        virtual string toString() = 0; //para sobreescribir
        virtual float calcularPago() = 0; 
};

//Declaración de clase Homicidio (hereda de Criminal)
class Homicidio: public Criminal {
    //Variables de instancia
    private: 
    bool involuntario;

    //Métodos
    public:
    //Constructores
    Homicidio(): Criminal(0, "homicidio", "", 'i', 0.0, 0, 0.0), involuntario(false) {};

    Homicidio(int id, string nombre, char veredicto, float horas, \
    int grado, float tarifa, char invol): Criminal(id, "homicidio", nombre, \
    veredicto, horas, grado, tarifa), involuntario(invol) {};

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
        
    float get_horas() {
        return horas;
    }
        
    int get_grado() {
        return grado;
    }
        
    float get_tarifa() {
        return tarifa;
    }

    bool get_involuntario() {
        return involuntario;
    }

    //Otras funciones
    float calcularPago();
    string toString();
};

/**
* calcularPago define el valor de pago para cada caso
* basado en el grado y las horas, calcula el pago que recibe
* el abogado por su trabajo, multiplicando por la tarifa definida
*
* @param
* @return valor total de pago (float) 
*/
float Homicidio::calcularPago() {
    float total;
    if (grado ==  1) {
        total = tarifa * 1.05 * horas;
    } else if (grado == 2) {
        total = tarifa * 1.02 * horas;
    } else if (veredicto == 'c' || involuntario == true){
        total = tarifa * 0.5 * horas;
    } 
    return total;
}

/**
* toString convierte atributos a string
* concatena todos los valores de los atributos en un string
* para imprimirlos
*
* @param
* @return string con los valores y texto
*/

//sobreescritura de toString en Criminal (padre)
string Homicidio::toString(){
    stringstream aux;
    aux << "Defendiendo a " << nombre << " contra un cargo de homicidio en " \
    << grado << " grado con un veredicto de " << veredicto << \
    " dedicando " << horas << " horas al caso con una tarifa de " \
    << tarifa << ". Involuntario: " << involuntario << "\n";
    return aux.str();
}

//Declaración de clase Hurto (hereda de Criminal)
class Hurto: public Criminal {
    //Variables de instancia
    private: 
    float valor_robado;

    //Métodos
    public:
    //Constructores
    Hurto(): Criminal(0, "hurto", "", 'i', 0.0, 0, 0.0), valor_robado(0.0) {};

    Hurto(int id, string nombre, char veredicto, float horas, \
    int grado, float tarifa, float vr): Criminal(id, "hurto", nombre, \
    veredicto, horas, grado, tarifa), valor_robado(vr) {};

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
        
    float get_horas() {
        return horas;
    }
        
    int get_grado() {
        return grado;
    }
        
    float get_tarifa() {
        return tarifa;
    }

    float get_valor_robado() {
        return valor_robado;
    }

    //Otras funciones
    float calcularPago();
    string calcularTipo();
    string toString();
};

/**
* calcularPago define el valor de pago para cada caso
* basado en el grado y las horas, calcula el pago que recibe
* el abogado por su trabajo, multiplicando por la tarifa definida
*
* @param
* @return valor total de pago (float) 
*/
float Hurto::calcularPago() {
    float total;
    if (grado ==  1) {
        total = tarifa * 1.05 * horas;
    } else if (grado == 2) {
        total = tarifa * 1.02 * horas;
    } else if (veredicto == 'c'){
        total = tarifa * 0.5 * horas;
    }
    return total;
}

/**
* calcularTipo define el tipo de hurto cometido
* al verificar si el valor del objeto robado (valor_robado)
* sobrepasa un número fijo
*
* @param
* @return valor tipo (string) 
*/
string Hurto::calcularTipo(){
    string tipo;
    if(valor_robado > 500){
        tipo = "menor";
    } else {
        tipo = "mayor";
    }
    return tipo;
}

/**
* toString convierte atributos a string
* concatena todos los valores de los atributos en un string
* para imprimirlos
*
* @param
* @return string con los valores y texto
*/
//sobreescritura de toString en Criminal (padre)
string Hurto::toString(){
    stringstream aux;
    aux << "Defendiendo a " << nombre << " contra un cargo de hurto de tipo " \
    << Hurto::calcularTipo() << " en " << grado << " grado con un veredicto de " \
    << veredicto << " dedicando " << horas << " horas al caso con una tarifa de " \
    << tarifa << " Valor robado: " << valor_robado << "\n";
    return aux.str();
}

#endif // CRIMINAL_H_
