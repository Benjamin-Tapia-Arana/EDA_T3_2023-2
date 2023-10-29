# INFORME TAREA 3: Calculadora Interactiva

**Integrantes**
- Benjamin A. Tapia Arana
- Tomás F. Aspee Carrasco

## Estructura del Proyecto

El proyecto consta de las siguientes carpetas:

- **build**: Carpeta donde se generará el ejecutable (debe crearse)
- **include**: Carpeta donde se encuentran todos los archivos HPP
- **src**: Carpeta donde se encuentran todos los archivos CPP necesarios para el maze
- **test**: Carpeta donde se encuentra el archivo CPP para testear el funcionamiento de la calculadora

## Compilación

Sigue estos pasos para compilar el proyecto:

1. Asegúrate de tener instalado el compilador `g++` y la herramienta `CMake` en tu sistema

2. Crea la carpeta `build` en el directorio principal del proyecto

3. Desde el directorio `build` ejecua el siguiente comando `cmake ..`
   
4. Compila el proyecto con `make`


## Ejecución

Una vez compilado el proyecto, puedes ejecutar el programa con el siguiente comando: `./calculator`

## Uso

El programa te mostrará un menú con las opciones disponibles:

 - Type an expression or a variable assignment to begin
 - Type 'vars' to see all assigned variables
 - Type 'exit' to exit the program
 - Type 'tree' to see the decision tree of the postfix expression
 - Type 'vars + tree' to see both
