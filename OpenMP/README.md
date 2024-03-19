## Postman Sort
El Postman's sort es una variante del bucket sort que aprovecha una estructura jerárquica de elementos,
típicamente descrita por un conjunto de atributos. Es el algoritmo que utilizan las máquinas clasificadoras
de cartas de las oficinas de correos: el correo se clasifica primero entre nacional e internacional;
luego por estado, provincia o territorio; después por oficina de correos de destino; luego por rutas, etc.
Como las claves no se comparan entre sí, el tiempo de clasificación es O(cn), donde c depende del tamaño de la clave y del número de cubos.
Esto es similar a una ordenación radix que funciona "de arriba abajo", o "primero el dígito más significativo".

El código utiliza el algoritmo de "Postman Sort" para ordenar un conjunto de números enteros introducidos por el usuario,
paralelizando algunas partes del proceso utilizando OpenMP para mejorar la eficiencia en sistemas con múltiples núcleos de procesamiento.

Para ejecutar este programa es necesario entrar a <strong>guaneExa</strong>
```
ssh guaneExa
```
