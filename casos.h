/*
* Proyecto Archivo de Casos
* Paulina Almada Martínez
* A01710029
* 6/16/2023
* Esta clase define el objeto Casos que contiene las
* operaciones para crear perfiles de casos y calcular
* pagos y ganancias utilizadas por el menu main.
*/

#ifndef CASOS_H_
#define CASOS_H_

#include <string>

#include <iostream>

#include <sstream>

#include "criminal.h" //biblioteca con objetos tipo Criminal
#include "civil.h" //biblioteca con objetos tipo Civil

using namespace std;

const int MAX = 1000; //constante de tamaño de arreglos

class Casos {
  //Variables de instancia
  private:
    Criminal * crim[MAX]; //apuntador para objetos tipo Criminal
    Civil * civ[MAX]; //apuntador para objetos tipo Civil
    int cuenta;

  public:
  //Constructores
  Casos(): cuenta(0) {};
  
  //Metodos
  //Para crear ejemplos
  void creaEjemplosCrim();
  void creaEjemplosCiv();
  
  //Para imprimir objetos
  void imprimeCasosCrim();
  void imprimeCasosCiv();

  void imprimeCasosCrim(string tipo);
  void imprimeCasosCiv(string tipo);

  //Para calcular pagos
  float calcPagoCrim();
  float calcPagoCiv();

  float calcPagoCrim(string tipo);
  float calcPagoCiv(string tipo);

  float calcPagoTotal();

  //Para crear objetos
  void agregaHomicidio(string nombre, char veredicto, float horas, \
  int grado, float tarifa, bool involuntario);
  void agregaHurto(string nombre, char veredicto, float horas, int grado, \
  float tarifa, float valor_robado);

  void agregaLaborales(string nombre, char veredicto, float acuerdo, \
  float demanda, int cuota, bool corte, string demandado);
  void agregaLesiones(string nombre, char veredicto, float acuerdo, \
  float demanda, int cuota, bool corte, char dano);

};

/**
 * creaEjemplosCrim genera objetos Criminal
 *
 * genera 1 objeto de tipo Homicidio y Hurto
 * y los guarda en la variable crim[] (arreglo de casos)
 * para poder demostrar las habilidades del programa. 
 *
 * @param
 * @return
 */
void Casos::creaEjemplosCrim() {

  //utilizamos new para usar polimorfismo
  crim[cuenta] = new Homicidio(cuenta, "Medina", 'i', 200, 1, 35.0, false);
  cuenta++;
  crim[cuenta] = new Hurto(cuenta, "Molina", 'c', 156.2, 2, 18.0, 1800.0);
  cuenta++;
}

/**
 * creaEjemplosCiv genera objetos Civil
 *
 * genera 1 objeto de tipo Laborales y Lesiones
 * y los guarda en la variable civ[] (arreglo de casos)
 * para poder demostrar las habilidades del programa. 
 *
 * @param
 * @return
 */
void Casos::creaEjemplosCiv() {
  civ[cuenta] = new Laborales(cuenta, "Nava", 'g', 1200.0, 1600.0, 6.0, false, "Padilla");
  cuenta++;
  civ[cuenta] = new Lesiones(cuenta, "Colin", 'p', 24000.0, 4000.0, 3.0, true, 'm');
  cuenta++;
}

/**
 * imprimeCasosCrim imprime los casos criminales guardados
 * utiliza el arreglo crim[] y el número de cuenta para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método toString().
 *
 * @param
 * @return
 */
void Casos::imprimeCasosCrim() {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < cuenta; i++)
    cout << crim[i] -> toString();
}

/**
 * imprimeCasosCiv imprime los casos civiles guardados
 * utiliza el arreglo civ[] y el número de cuenta para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método toString().
 *
 * @param
 * @return
 */
void Casos::imprimeCasosCiv() {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < cuenta; i++)
    cout << civ[i] -> toString();
}

/**
 * imprimeCasosCrim imprime casos criminales de un tipo específico (sobrecarga)
 *
 * utiliza el arreglo crim[] y el número de cuenta para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos  que coinciden con el
 * string tipo (homicidio o hurto).
 *
 * @param string tipo debe ser: "homicidio" o "hurto"
 * @return
 */
void Casos::imprimeCasosCrim(string tipo) {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < cuenta; i++) {
    if (crim[i] -> get_tipo() == tipo)
      cout << crim[i] -> toString();
  }
}

/**
 * imprimeCasosCiv imprime casos civiles de un tipo específico (sobrecarga)
 *
 * utiliza el arreglo civ[] y el número de cuenta para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos  que coinciden con el
 * string tipo (laborales o lesiones).
 *
 * @param string tipo debe ser: "laborales" o "lesiones"
 * @return
 */
void Casos::imprimeCasosCiv(string tipo) {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < cuenta; i++) {
    if (civ[i] -> get_tipo() == tipo)
      cout << civ[i] -> toString();
  }
}

/**
 * calcPagoCrim suma la paga total de todos los casos criminales
 *
 * utiliza el arreglo crim[] y el número de cuenta para recorrer todo el
 * arreglo acumulando el pago de todos los casos.
 *
 * @param
 * @return float con la suma de todos los pagos resultando de los casos
 */
float Casos::calcPagoCrim() {

  float total = 0;
  for (int i = 0; i < cuenta; i++)
    total = total + crim[i] -> calcularPago();
  return total;
}

/**
 * calcPagoCiv suma la paga total de todos los casos civiles
 *
 * utiliza el arreglo civ[] y el número de cuenta para recorrer todo el
 * arreglo acumulando el pago de todos los casos.
 *
 * @param
 * @return float con la suma de todos los pagos resultando de los casos
 */
float Casos::calcPagoCiv() {

  float total = 0;
  for (int i = 0; i < cuenta; i++)
    total = total + civ[i] -> calcularPago();
  return total;
}

/**
 * calcPagoCrim suma la paga total de todos los casos criminales de un tipo
 *
 * utiliza el arreglo crim[] y el número de cuenta para recorrer todo el
 * arreglo acumulando el pago mensual de todos los casos cuyo string
 * get_tipo() coincida con el tipo recibido como parámentro.
 *
 * @param string tipo debe ser: "homicidio" o "hurto"
 * @return float con la suma de todos los pagos
 */
float Casos::calcPagoCrim(string tipo) {

  int total = 0;
  for (int i = 0; i < cuenta; i++) {
    if (crim[i] -> get_tipo() == tipo)
      total = total + crim[i] -> calcularPago();
  }
  return total;
}

/**
 * calcPagaCiv suma la paga total de todos los casos civiles de un tipo
 *
 * utiliza el arreglo civ[] y el número de cuenta para recorrer todo el
 * arreglo acumulando el pago mensual de todos los casos cuyo string
 * get_tipo() coincida con el tipo recibido como parámentro.
 *
 * @param string tipo debe ser: "laborales" o "lesiones"
 * @return float con la suma de todos los pagos
 */
float Casos::calcPagoCiv(string tipo) {

  int total = 0;
  for (int i = 0; i < cuenta; i++) {
    if (civ[i] -> get_tipo() == tipo)
      total = total + civ[i] -> calcularPago();
  }
  return total;
}

/**
 * agregaHomicidio crea un objeto Homicidio y lo agrega al
 * arreglo de crim[]
 *
 * crea un objeto Homicidio y lo agrega a arreglo de casos criminales usando
 * como indice el número de cuenta, el cuál después incrementa en 1.
 *
 * @param string nombre del cliente, veredicto del caso, horas dedicadas al caso,
 * grado del homicidio, tarifa definida para el abogado, y si el homicidio
 * se considera voluntario o involuntario
 * @return
 */

void Casos::agregaHomicidio(string nombre, char veredicto, float horas, \
  int grado, float tarifa, bool involuntario) {
    //new crea el objeto para usar polimorfismo
    crim[cuenta] = new Homicidio(cuenta, nombre, veredicto, horas, grado, tarifa, involuntario);
    cuenta++;
}

/**
 * agregaHurto crea un objeto Hurto y lo agrega al
 * arreglo de crim[]
 *
 * crea un objeto Hurto y lo agrega a arreglo de casos criminales usando
 * como indice el número de cuenta, el cuál después incrementa en 1.
 *
 * @param string nombre del cliente, veredicto del caso, horas dedicadas al caso,
 * grado del homicidio, tarifa definida para el abogado, y si el homicidio
 * se considera voluntario o involuntario
 * @return
 */
void Casos::agregaHurto(string nombre, char veredicto, float horas, int grado, \
  float tarifa, float valor_robado) {
    //new crea el objeto para usar polimorfismo
    crim[cuenta] = new Hurto(cuenta, nombre, veredicto, horas, grado, tarifa, valor_robado);
    cuenta++;
}

/**
 * agregaLaborales crea un objeto Laborales y lo agrega al
 * arreglo de civ[]
 *
 * crea un objeto Laborales y lo agrega a arreglo de casos civiles usando
 * como indice el número de cuenta, el cuál después incrementa en 1.
 *
 * @param string nombre del cliente, veredicto del caso, acuerdo conseguido,
 * demanda original, cuota definida para el abogado, si el caso fue a corte,
 * y el nombre de la entidad demandada
 * @return
 */
void Casos::agregaLaborales(string nombre, char veredicto, float acuerdo, \
  float demanda, int cuota, bool corte, string demandado) {
    //new crea el objeto para usar polimorfismo
    civ[cuenta] = new Laborales(cuenta, nombre, veredicto, acuerdo, demanda, cuota, corte, demandado);
    cuenta++;
}

/**
 * agregaLesiones crea un objeto Lesiones y lo agrega al
 * arreglo de civ[]
 *
 * crea un objeto Lesiones y lo agrega a arreglo de casos civiles usando
 * como indice el número de cuenta, el cuál después incrementa en 1.
 *
 * @param string nombre del cliente, veredicto del caso, acuerdo conseguido,
 * demanda original, cuota definida para el abogado, si el caso fue a corte,
 * y si el daño se considera monetario o fisico
 * @return
 */
void Casos::agregaLesiones(string nombre, char veredicto, float acuerdo, \
  float demanda, int cuota, bool corte, char dano) {
    //new crea el objeto para usar polimorfismo
    civ[cuenta] = new Lesiones(cuenta, nombre, veredicto, acuerdo, demanda, cuota, corte, dano);
    cuenta++;
}

#endif // CASOS_H_