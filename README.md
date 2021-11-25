# RSA

En este repositorio se encuentra el codigo pedido para la tarea de RSA, el cual esta en el archivo de nombre ConsoleApplication1.cpp.

1. Primero pedimos que se ingresen dos numeros primos.
2. Luego de ello calculamos n, n=p*q.
3. Calculamos phi de n como vimos en clase, phi_n=(p-1)*(q-1).
4. Seguido de ello generamos aleatoriamente una e entre 2 y n-1 que se mantendra en bucle mientras no se cumpla que gcd(e,phi_n)==1.
5. Cuando lo hemos calculado y se ha roto el bucle lo siguiente que hacemos es encontrar d aplicando el algoritmo de inversa desarrollado en un trabajo anterior.
6. Con ello obtenemos los valores de n, e y d.

Todo el desarrollo de este algoritmo lo hice en la funcion main por ende no se requeria un return.

Tabla de contenido de valores del mensaje cifrado y descifrado para los siguientes valores {e,d,n} {11,11,33}.

|Variables|resultados|
|-----------|---------|
|m | 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32|
|c|0, 1, 2, 3, 4, 5, 6, 7, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31|
|m|0, 1, 2, 3, 4, 5, 6, 7, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31|


Se repite que m^e mod n =m en los 32 casos.

Observaciones:

1. El programa al parecer presenta fallos con el tipo de variable declarado para realizar los algoritmos y por ello que se observa que para esos datos obtenemos continuamente 31.
