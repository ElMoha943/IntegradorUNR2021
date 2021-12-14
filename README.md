# Objetivo
Brindar al estudiante la posibilidad de diseñar el algoritmo solución de un problema y crear
un programa en lenguaje C que sirva de guía práctica y modelo del correcto uso de los
contenidos de la asignatura desarrollados hasta la fecha.

# Condiciones generales
● Grupo de trabajo de 4 o 5 estudiantes.
<br>● Entrega del informe en formato PDF y el archivo con el programa .c en página de Comunidades. Un informe por cada grupo en PDF y el nombre del archivo debe contener los apellidos de los integrantes del grupo ordenados alfabéticamente.
<br>● En el informe (Ejemplo de Informe) debe tener:
<br>  ○ Carátula con legajo, nombre y apellido de los integrantes del grupo, número de comisión, docentes y año.
<br>  ○ Enunciado de la situación problemática a resolver.
<br>  ○ Análisis del problema que consiste en: describir los datos del archivo, dibujar la/s estructura/s de datos a utilizar indicando nombre/s y tipos de datos, y, diagrama de resolución, es decir, los módulos y sus conexiones (subalgoritmos y parámetros).
<br>  ○ Codificación del algoritmo en lenguaje C correctamente indentado.
<br>  ○ Verificación del correcto funcionamiento del programa con capturas de pantallas de salida
  
  
# Situación problemática
A los 2884 mts. de altura del Cerro Champaquí (su punto más alto), se colocó un
anemómetro para medir la velocidad del viento en metros por segundo (m/s), un
pluviómetro para medir la cantidad de agua precipitada en milímetros (mm) y un barómetro
para medir la presión atmosférica en hectoPascales (hPa), con el objetivo de poder realizar
un análisis exhaustivo sobre las condiciones para escalar dicho cerro.

Durante el año 2020 se registraron dichas magnitudes. No se conoce la cantidad de días en
los que se realizaron las mediciones, pero se asegura que se midieron los tres valores varias
veces por mes, una única vez al día. Durante todo el año se fue guardando la información
sobre las mediciones sin orden alguno en un archivo denominado “Champaqui2020.txt“.
Cada registro del archivo contiene la siguiente información:

<br>● Número de mes: número entero (1 al 12)
<br>● Número de día: número entero
<br>● Velocidad: número Real (> 0)
<br>● Precipitación: número Real (>=0)
<br>● Presión: número entero (> 0)

Por ejemplo, el archivo podría contener la siguiente información:
```
3 2 2.80 4.00 1010
1 11 2.10 1.30 1013
8 26 3.00 8.90 1020
8 14 1.10 9.10 1018
9 13 18.20 1.00 1021
...
12 18 12.40 7.20 1020
6 25 14.80 8.20 1016
```

Se debe realizar un programa que muestre en pantalla el siguiente menú:
V - Velocidad promedio del viento
L - Mes más lluvioso
C - Condiciones
P - Presión mensual
S - Salir

Dónde:
<br>**V - Velocidad promedio del viento**<br>
Se deberá solicitar al usuario (en el algoritmo principal) que ingrese un número de
trimestre (validarlo, sólo valores del 1 al 4). Luego se tendrá que invocar a la función
VELOCIDAD-PROM, la cual, a partir de la información obtenida por CARGA (detalles
mas abajo) y el dato ingresado por el usuario, devuelva al algoritmo principal la
velocidad promedio del viento en dicho trimestre. Una vez devuelto ese valor al
algoritmo principal, se mostrará por pantalla cuáles fueron los meses de ese
trimestre en los cuales se superó dicho promedio.

<br>**L - Mes más lluvioso**<br>
Se deberá calcular por medio de una función de nombre MAS_LLUVIA con
parámetros adecuados el mes más lluvioso, considerando como tal, a aquel que
tenga mayor promedio de precipitaciones. Suponer que existe un único máximo.
Luego, mostrar en el algoritmo principal, el número de mes devuelto por la función,
junto al promedio de precipitaciones correspondiente

<br>**C - Condiciones**<br>
Se deberá mostrar por pantalla, por medio de una subrutina CONDICIONES, para los
4 trimestres del año, si la condición para escalar el Cerro Champaquí es “Mala”,
“Buena” o “Muy Buena”
Para esto, se sabe que hay 3 condiciones climáticas bien diferenciadas para evaluar
si es factible o no escalar el cerro

```
- Buena
  o 4.5mm < Promedio precipitaciones <= 5mm
  o 10m/s < = Promedio viento < 11m/s
  o 1013 <= Promedio presión <= 1020
- Muy buena
  o Promedio precipitaciones <= 4.5mm
  o Promedio viento < 10m/s
  o 1020 < Promedio presión < 1025
- Mala
  o Cualquier otro caso
```
<br>**P - Presión mensual**<br>
Se deberá generar un archivo de nombre “Presion_mensual2020.txt”, en el cual figure
un listado ordenado en forma ascendente (por presión promedio mensual) que
contenga el mes y la presión. Para ello, realizar el ordenamiento mediante un
subalgoritmo de nombre PRESIONES con parámetros adecuados.

<br>**S - Salir**<br>

**IMPORTANTE!** Para resolver esta situación problemática, se deberá procesar la información
del archivo a través de la invocación a una subrutina CARGA al iniciar el programa, que
deberá devolver al principal, la/s estructura/s de datos apropiada/s para la resolución del
problema. **Una vez invocada CARGA no se debe volver a acceder al archivo fuera de dicha
subrutina**.
