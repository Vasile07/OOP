#include <stdio.h>
/**
 * 16. Determina toate numerele naturale mai mici decat un numar natural nenul dat n si care sunt relativ prime cu n
 */

void comenzi(){
    /**
     * Afiseaza lista comenzilor
     */
     printf("1 - Citeste un n si afiseaza numerele relativ prime cu n mai mici decat n\n");
     printf("2 - Citeste un n si afiseaza numerele prime mai mici decat n\n");
     printf("3 - Exit\n");
}

void citire(int *n){
    /**
     * Citeste un numar natural n
     * parametru: n - int
     * return: ---
     */
    printf("Dati un numar n:\n>>>");
    scanf("%d", n);
}

int cmmdc(int a , int b){
   /**
    * Determina cel mai mare divizor comun al numerelor a si b
    */
    if ( b == 0 )
        return a;
    int rest = a % b;
    while ( rest != 0)
    {
        a = b;
        b = rest;
        rest = a % b;
    }
    return b;
}
/**
     * Afiseaza toate numerele naturale din intervalul [1,n) care sunt relativ prime cu n
     * parametru: n - int
     * return: numarul de numere relativ prime
     */


/***
 *
 * @param n
 * @return
 */
int afiseazaRelativPrimele(int n){

     printf("Numerele relativ prime cu %d sunt:\n--> ", n);
     int contor = 0;
     for ( int i = 1 ; i < n ; i ++ ){
         if ( cmmdc(i,n) == 1 ) {
             printf("%d ", i);
             contor ++;
         }
     }
     printf("\n");
     return contor;
}

int Prim(int numar){
    /**
     * Returneaza 1 daca numarul e prim si 0 altfel
     */
     if ( numar < 2 )   return 0;
     for ( int d = 2 ; d * d <= numar ; d ++ )
         if ( numar % d == 0 )
             return 0;
     return 1;
}

void AfiseazaNumerePrime(int numar){
    /**
     * Afiseaza toate numerele prime mai mici decat numar
     */
    for ( int nr = 1 ; nr <= numar ; nr ++)
        if ( Prim(nr) )
            printf("%d ", nr);
    printf("\n");
}


int main() {

    int n;
    while (1){
        comenzi();
        int comanda;
        printf("Introduceti comanda:\n>>>");
        scanf("%d", &comanda);
        if (comanda == 1){
            citire(&n);
            afiseazaRelativPrimele(n);
        }
        else
            if (comanda == 2) {
                citire(&n);
                AfiseazaNumerePrime(n);
            }
            else
                if (comanda == 3)
                    return 0;
                else
                    printf("Comanda invalida!\n");
    }
}

