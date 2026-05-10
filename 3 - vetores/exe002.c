#include <stdio.h>

#define QTD_MINIMO 2
#define QTD_MAXIMO 5
#define IDADE_MINIMA 0
#define IDADE_MAXIMA 130

int definirTamanhoVetor(int min, int max);
void preecherIdades(int nums[], int tam, int min, int max);
double mediaIdades(int nums[], int tam);
void maiorIgualMedia(int nums[], int tam, double media);
int buscaSequencial(int nums[], int tam, int n);
void pesquisarIdade(int nums[], int tam);
void imprimirIdades(int nums[], int tam);
void inserirNovaIdade(int nums[], int tam);



int main(){
    int tamanho;
    double media_idade;

    tamanho = definirTamanhoVetor(QTD_MINIMO, QTD_MAXIMO);

    int idades[tamanho];

    preecherIdades(idades, tamanho, IDADE_MINIMA, IDADE_MAXIMA);

    media_idade = mediaIdades(idades, tamanho);
    printf("Media das idades: %.2lf\n", media_idade);

    printf("Idades maiores ou iguais a média:\n");
    maiorIgualMedia(idades, tamanho, media_idade);

    pesquisarIdade(idades, tamanho);

    printf("Idades:\n");
    imprimirIdades(idades, tamanho);
    
    inserirNovaIdade(idades, tamanho);
    
    return 0;
}

int definirTamanhoVetor(int min, int max){
    int tam;

    do{
        printf("Informe tamanho valido entre 2-5:\n");
        scanf("%d", &tam);
    }while(tam > max || tam < min);

    return tam;
}

void preecherIdades(int nums[], int tam, int min, int max){
    int i;

    for(i = 0; tam > i; i += 1){
        do{
            printf("%d° idade:\n", i + 1);
            scanf("%d", &nums[i]);

        }while(nums[i] < min || nums[i] > max );
    }
}


double mediaIdades(int nums[], int tam){
    int i;
    int soma = 0;

    for(i = 0; tam > i; i += 1){
        soma += nums[i];
    }

    return soma / tam;
}

void maiorIgualMedia(int nums[], int tam, double media){
    int i;

    for(i = 0; tam > i; i += 1){
        if(nums[i] >= media){
            printf("%d ", nums[i]);
        }
    }
    printf("\n");

}

int buscaSequencial(int nums[], int tam, int n){
    int i;

    for(i = 0; tam > i; i += 1){
        if(nums[i] == n){
            return i;
        }
    }
    return -1;

}

void pesquisarIdade(int nums[], int tam){
    int num, pos;

    do{
        printf("Informe uma idade ou valor <0 para finalizar pesquisa:\n");
        scanf("%d", &num);

        pos = buscaSequencial(nums, tam, num);

        if(pos == -1){
            printf("Idade %d não encontrada\n", num);
        }else{
            printf("Idade %d encontrada da posição %d\n", num, pos);
        }

    }while(num >= 0);

}

void inserirNovaIdade(int nums[], int tam){
    int pos, valor, i;
    char opcao;

    do{
        if(tam > QTD_MAXIMO){
            printf("Vetor lotado. Quantidade maxima de elementos: %d", tam);
            break;
        }

        do{
            printf("Inserir idades entre %d e %d:\n", IDADE_MINIMA, IDADE_MAXIMA);
            scanf("%d", &valor);
        }while(valor < IDADE_MINIMA || valor > IDADE_MAXIMA);

        do{
            printf("Inserir posição entre 0 e %d:\n", tam - 1);
            scanf("%d", &pos);

        }while(pos < 0 || pos >= tam);

        for(i = tam - 1; i >= pos; i -= 1){
            nums[i + 1] = nums[i];

        }
        nums[pos] = valor;


        printf("Para inserir mais idades informe [S]:\n");
        scanf("%c", &opcao);

    }while(opcao == 's' || opcao == 'S');

    // printf("Idades após inserir novas idades:\n");
    // imprimirIdades(nums, tam);
    
}

void imprimirIdades(int nums[], int tam){
    int i;

    for(i = 0; tam > i; i += 1){
        printf("%d ", nums[i]);
    }
    printf("\n");
}