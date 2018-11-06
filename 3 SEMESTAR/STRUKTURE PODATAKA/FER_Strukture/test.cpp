#include <stdio.h>
#include <stdlib.h>


void quick(long polje[], int l, int d) {
    int i,j;
    long pom;
    i = l+1;
    j = d;

    if (l>=d) return;

    while ((i <= j) && (i<=d) && (j>l)) {
        while ((polje[i] < polje[l]) && (i<=d)) i++;
        while ((polje[j] > polje[l]) && (j>l)) j--;
        if (i<j) {
            pom = polje[i];
            polje[i] = polje[j];
            polje[j] = pom;
        }
    }
    if (i>d) { // stožer je najveæi u polju
        pom = polje[d];
        polje[d] = polje[l];
        polje[l] = pom;
        quick(polje, l, d-1);
    }
    else if (j<=l) { // stožer je najmanji u polju
        quick(polje, l+1, d);
    }
    else { // stožer je negdje u sredini
        pom = polje[j];
        polje[j] = polje[l];
        polje[l] = pom;
        quick(polje, l, j-1);
        quick(polje, j+1, d);
    }
}



void main(){

    long polje[] = {16, 10, 28, 5, 3, 31, 12, 8};
    int br = 8;

    printf("\nIspis polja prije sortiranja:");
    for (int i =0; i<br; i++) printf("%ld ", polje[i]);

    quick(polje, 0, br-1);

    printf("\n\nIspis polja poslije sortiranja:");
    for (int i =0; i<br; i++) printf("%ld ", polje[i]);
}