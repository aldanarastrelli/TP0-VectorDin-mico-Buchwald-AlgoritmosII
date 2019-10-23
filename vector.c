#include "vector.h"

size_t vector_largo(vector_t* vector){
    /* Devuelve el tamaño del vector
    Pre: el vector fue creado */

    return vector->tam;
}

bool vector_guardar(vector_t* vector, size_t pos, int valor){
    /* Almacena el valor en la posición pos
    Pre: el vector fue creado
    Post: se almacenó el valor en la posición pos. Devuelve false si la posición
    es inválida (fuera del rango del vector, que va de 0 a tamaño-1) y true si
    se guardó el valor con éxito. */

    if ( pos >= vector->tam){
        return false;
    }
    *(vector->datos + pos) = valor;
    return true;
}

bool vector_obtener(vector_t* vector, size_t pos, int* valor){
    /* Almacena en valor el dato guardado en la posición pos del vector
    Pre: el vector fue creado
    Post: se almacenó en valor el dato en la posición pos. Devuelve false si la
    posición es inválida (fuera del rango del vector, que va de 0 a tamaño-1) */

    if (pos >= vector->tam){
        return false;
    }

    *valor = *(vector->datos + pos);
    return true;
}

void vector_destruir(vector_t* vector){
    /* Destruye el vector
    Pre: el vector fue creado
    Post: se eliminaron todos los elementos del vector */

    free(vector->datos);
    free(vector);
    return;
}

// Funciones implementadas por la catedra.

vector_t* vector_crear(size_t tam) {
    vector_t* vector = malloc(sizeof(vector_t));

    if (vector == NULL) {
        return NULL;
    }
    vector->datos = malloc(tam * sizeof(int));

    if (tam > 0 && vector->datos == NULL) {
        free(vector);
        return NULL;
    }
    vector->tam = tam;
    return vector;
}

bool vector_redimensionar(vector_t* vector, size_t tam_nuevo) {
    
    int* datos_nuevo = realloc(vector->datos, tam_nuevo * sizeof(int));

    // Cuando tam_nuevo es 0, es correcto si se devuelve NULL.
    // En toda otra situación significa que falló el realloc.
    if (tam_nuevo > 0 && datos_nuevo == NULL) {
        return false;
    }

    vector->datos = datos_nuevo;
    vector->tam = tam_nuevo;
    return true;
}
