/* 
 * C Program to Implement Postman Sort Algorithm
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

// Declaración de funciones
void arrange(int, int);
int generateRandom();

// Variables globales
int array[100000], array1[100000]; // Arreglos para almacenar los números y su copia
int i, j, temp, max, count = 100000, maxdigits = 0, c = 0; // Variables de control y temporales
double start, end; // Variables para medir el tiempo de ejecución

int main()
{
    start = omp_get_wtime(); // Iniciar el cronómetro

    int t1, t2, k, t, n = 1;

    // Generar números aleatorios y almacenarlos en array1 y array
    srand(time(NULL)); // Inicializar la semilla del generador de números aleatorios
    for (int i = 0; i < 100000; i++) {
        array1[i] = generateRandom(); // Generar un número aleatorio
        array[i] = array1[i]; // Almacenar el mismo número en array
    }

    // Calcular el número máximo de dígitos en los números del arreglo
    for (i = 0; i < count; i++)
    {
        t = array[i]; // Primer elemento en t
        while (t > 0)
        {
            c++;
            t = t / 10; // Encontrar el dígito más significativo (MSB)
        }
        if (maxdigits < c)
            maxdigits = c; // Número de dígitos de cada número
        c = 0;
    }
    while (--maxdigits)
        n = n * 10;

    // Ordenar los números utilizando el algoritmo de "Postman sort"
    for (i = 0; i < count; i++)
    {
        max = array[i] / n; // MSB - Dividir por la base particular
        t = i;
        for (j = i + 1; j < count; j++)
        {
            if (max > (array[j] / n))
            {
                max = array[j] / n; // Mayor MSB
                t = j;
            }
        }
        // Intercambiar elementos en array1
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        // Intercambiar elementos en array
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }

    // Ordenar números con la misma base
    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++);
            arrange(i, j); // Llamar a la función arrange para ordenar
            i = j;
        }
        n = n / 10;
    }

    end = omp_get_wtime(); // Detener el cronómetro
    printf("Work took %f seconds\n", end - start); // Imprimir el tiempo de ejecución

    return 0;
}

// Función para ordenar secuencias con la misma base
void arrange(int k, int n)
{
    for (i = k; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array1[i] > array1[j])
            {
                // Intercambiar elementos en array1
                temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                // Intercambiar elementos en array
                temp = (array[i] % 10);
                array[i] = (array[j] % 10);
                array[j] = temp;
            }
        }
    }
}

// Función para generar un número aleatorio entre 0 y 9999
int generateRandom()
{
    int number = rand() % 10000;
    return number;
}
