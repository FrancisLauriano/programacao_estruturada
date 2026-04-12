#include <stdio.h>

void preencherOrdenado(int v[], int t){
    int i, num, pos;

    for(i = 0; i < t; i += 1){
        printf("%d° valor:\n", i + 1);
        scanf("%d", &num);

        pos = i;

        while(pos > 0 && v[pos - 1] > num){
            v[pos] = v[pos - 1];
            pos -= 1;
        }
        v[pos] = num;
    }
}

void qtdRepeticao(int v[], int t){
    int i, j, qtd;
    int tem_repeticao = 0;
   
    for(i = 0; i < t; i += 1){

        if(i > 0 && v[i] == v[i - 1]){
            continue;
        }

        qtd = 0;

        for(j = i + 1; j < t; j += 1){

            if(v[i] == v[j]){
                qtd += 1;
            }
        }

        if(qtd > 0){
            printf("Numero %d tem: %d repeticoes\n", v[i], qtd);
            tem_repeticao = 1;
        }
    }

    if(tem_repeticao == 0){
        printf("Sem valores repetidos\n");

    }
}