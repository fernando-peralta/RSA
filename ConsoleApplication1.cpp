#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;


int resto(int a, int n) { //funcion resto recibe a (dividendo) y n )(divisor)
    int r; // Las dos salidas a entregar en la division: q (cociente) y r (resto)
    if (a < 0) {//en caso a sea negativo
        r = a - (((a / n) - 1) * n); //realizamos la operacion original del resto pero se le aumenta 1 al cociente para exceder y obtener el resto positivo.
        return r; //basicamente es siguiendo la logica de Galo
    }
    else {// En caso a sea positivo
        r = a - ((a / n) * n);// simplemente la diferencia entre a y la multiplicacion
        return r;
    }
}

int Euclides_extendido(int a, int b, int* d, int* x, int* y) {
    int x1, y1;//variables auxiliares para el desarrollo del algoritmo

    if (a % b == 0) {//Caso base o final de Euclides normal
        *d = b;//Sabemos cual es el gcd(a,b)
        *x = 0;//Valores para el caso base
        *y = 1;
    }
    else {//En caso aun no se encuentre un b que cumpla la condicion (un gcd)
        Euclides_extendido(b, a % b, d, x, y);//Aplicamos recursividad con la teoria vista en clase
        x1 = *x; y1 = *y; *x = y1;//Los valores x1 y y1 los guardamos para el calculo de y mientras el valor de x pasa a ser el almacenado en y1
        *y = x1 - (a / b) * y1;//Calculamos y con la formula vista en clase donde (a/b) es q y y1
    }

    return *d;
}

int inversa(int e, int N) {
    int d, x, y;

    int inversa = Euclides_extendido(e, N, &d, &x, &y);
    if (inversa == 1) {
        return resto(x, N);
    }
    else {
        return 0;
    }
}

int euc(int x, int y) {
    return (!y) ? x : euc(y, x % y);
}






int main() {
    int p, q;
    srand(time(NULL));
    cout << "Programa para hallar la inversa multiplicativa de dos numeros" << endl;
    cout << "Ingrese p: "; cin >> q;
    cout << "Ingrese q: "; cin >> p;
    int n = p * q;
    cout << "N: " << n << endl;

    //Calculamos phi(n);

    int phi_n = (p - 1) * (q - 1);

    cout << "phi(n): " << phi_n << endl;
    
    //Calculamos e;
    int e;
    while (true) {
        e =2+rand()%(n-2);
        int gcd = euc(e, phi_n);
        if (gcd == 1) {
            break;
        }
    }

    int d = inversa(e, phi_n);
    cout << "d: " << d<<endl;
    
    cout << "Alice publica (e,n) (" << e << "," << n << ")" << endl;

    cout << "Bob quiere enviar un mensaje entre " << 1 << " y " << n - 1<<": ";

    int m;
    cin >> m;

    long c = resto(pow(m, e), n);
    cout << pow(m, e)<<endl;

    cout << "Mensaje cifrado c=P_A(m): " << c << endl;
    long des = resto(pow(c, d), n);
    cout << "Mensaje descifrado: " << des<<endl;



}