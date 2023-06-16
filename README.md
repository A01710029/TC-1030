# TC-1030
ESte es un programa diseñado para digitalizar y organizar los casos civiles y criminales de un abogado. Permite al usuario, a través de un menu, escoger entre varios comandos que le ayudan a mantener registro de sus casos y determinar cuanto dinero hace. Tiene la opción de ingresar información sobre sus casos, divididos en cuatro tipos: homicidios y hurtos (criminales) y demandas laborales y de lesiones personales (civiles), que se guardan en listas por tipo (criminal y civil). También puede mostrar todos los casos que ha registrado, dependiendo del tipo, tanto las categorías generales de criminal o civil, o los tipos más específicos dentro de estas categorias. Igualmente, puede calcular su ganancia con estas categorias generales o específicas, y su ganancia total entre todos los casos.

Este proyecto está basado y comparte concepto con el proyecto que realicé para la clase TC-1033, pero incluye mejoras y funcionalidades agregadas, al igual que la aplicación de polimorfismo en la estructura del código.  

## Casos de Falla
Se deben de respetar los tipos de datos al ingresar información sobre los casos, al igual que los límites numéricos de las opciones del menú. Si se ingresa un dato que no se alinea con el tipo de dato esperado, o si se ingresa un número que no es una opción dentro del menú, el programa regresará un error. También, se debe considerar que solo se puede ingresar un caso a la vez, y se debe de terminar de ingresar el caso con todos los datos pedidos antes de intentar ingresar otro.  

Además, se debe notar que el menú es quisquilloso sobre como se ingresan los datos. Al especificar un tipo (opciones 3 y 5), se debe escribir el tipo en letras minúsculas. Similarmente, al ingresar casos, se deben seguir las instrucciones dentro del menú para los distintos tipos de dato (por ejemplo, solo ingresar una de las letras dadas para los veredictos, o solo el apellido del cliente para el nombre). Muchos de estos detalles se mencionan dentro de las consideraciones al inicio del programa debajo del menú.

## Correcciones
Se cambió la variable cuenta (originalmente cuenta_crim y cuenta_civ) en "casos" ya que, por ser el mismo tipo de variable, al tratar de sobrecargar el constructor de Casos resultaba en un error. Este cambio se encuentra en la línea 32 del archivo "casos".

Se cambió el tipo de información pedida por el menú para las opciones 10, 12 y 13 (agregar un homicidio, una demanda laboral y una lesion personal) de "t/f" a "1/0", ya que se están igresando valores booleanos en esa parte del código al constructor, e ingresar cualquier otro valor resulta en un error. Este cambio se encuentra en las líneas 174, 210 y 230 del "main". 

Se agregaron clarificaciones e instrucciones para la operación y los tipos de datos pedidos por el menú para la conveniencia del usuario. Este cambio se encuentra en las líneas 40 a 44 del "main". 

Se eliminó el método calcPagoTotal de "casos" y se realizó la suma que originalmente hacia este método dentro del código del main en la opción 9 porque el objeto de Casos creado en main no puede acceder a las dos funciones requeridas para esa suma directamente, lo cual produce un error. Este cambio se encuentra en la línea 158 del "main".

Se agregaron más detalles a la descripción de las funcionalidades del programa en el README. 
