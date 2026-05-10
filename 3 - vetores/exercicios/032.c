#include <stdio.h>


void soma(int v1[], int v2[], int v3[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        v3[i] = v1[i] + v2[i];
    }
}

void produto(int v1[], int v2[], int v3[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        v3[i] = v1[i] * v2[i];
    }
}

int diferenca(int v1[], int v2[], int v3[], int t){
    int i, j, existe;
    int l = 0;

    for(i = 0; i < t; i += 1){
        if(i > 0 && v1[i] == v1[i - 1]){
            continue;
        }

        existe = 0;

        for(j = 0; j < t; j += 1){

            if(v1[i] == v2[j]){
                existe = 1;
                break;
            }
        }

        if(existe == 0){
            v3[l] = v1[i];
            l += 1;
        }  
    }
    return l;
}


int interSeccao(int v1[], int v2[], int v3[], int t){
    int i, j;
    int l = 0;

    for(i = 0; i < t; i += 1){
        if(i > 0 && v1[i] == v1[i + 1]){
            continue;
        }

        for(j = 0; j < t; j += 1){
            if(v1[i] == v2[j]){
                v3[l] = v1[i];
                l += 1;
                break;
            }
        }
    }
    return l;
}

int uniao(int v1[], int v2[], int v3[], int t){
    int i, j, existe;
    int l = 0;

    for(i = 0; i < t; i += 1){
        if(i > 0 && v1[i] == v1[i - 1]){
            continue;
        }

        v3[l] = v1[i];
        l += 1;
    }

    for(i = 0; i < t; i += 1){
        if(i > 0 && v2[i] == v2[i + 1]){
            continue;
        }

        existe = 0;

        for(j = 0; j < t; j += 1){
            if(v2[j] == v3[l]){
                existe = 1;
                break;
            }
        }

        if(existe == 0){
            v3[l] = v2[j];
            l += 1;
        }

    }
    return l;
    
}