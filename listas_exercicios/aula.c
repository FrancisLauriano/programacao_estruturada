#include <stdio.h>
#include <string.h>

#define TAM 10
#define TAM_PESSOAS 3

struct Pessoa{
    char nome[TAM];
    int idade;
    double peso;
    double altura;
};


int tamanhoStr(char s[]);
void receberStr(char s[], int t);
void preencherPessoa(struct Pessoa *p);
void preencherPessoas(struct Pessoa vp[], int t);
void imprimirPessoa(struct Pessoa p);
void imprimirPessoas(struct Pessoa vp[], int t);
double mediaAltura(struct Pessoa vp[], int t);
int buscaSequencialNome(struct Pessoa vp[], int t, char n[]);
void pesquisarNome(struct Pessoa vp[], int t);
int maiorIdade(struct Pessoa vp[], int t);





int main(){
    // struct Pessoa pessoa;
    struct Pessoa pessoas[TAM_PESSOAS];
    double media_altura;
    int mais_velho;

    printf("----- PREENCHER -----\n");
    preencherPessoas(pessoas, TAM_PESSOAS);

    printf("----- IMPRIMIR -----\n");
    imprimirPessoas(pessoas, TAM_PESSOAS);

    printf("----- Media Altura -----\n");
    media_altura = mediaAltura(pessoas, TAM_PESSOAS);
    printf("%.2lf\n", media_altura);


    mais_velho = maiorIdade(pessoas, TAM_PESSOAS);
    printf("Idade do mais velho: %d anos\n", mais_velho);



    return 0;
}


int tamanhoStr(char s[]){
    int qtd = 0;

    while(s[qtd] != '\0'){
        qtd += 1;
    }
    return qtd;
}

void receberStr(char s[], int t){
    int tamanho_s;

    fgets(s, t, stdin);

    tamanho_s = tamanhoStr(s);

    
    if(tamanho_s > 0 && s[tamanho_s - 1] == '\n'){
        s[tamanho_s - 1] = '\0';
    }
}

void preencherPessoa(struct Pessoa *p){
    char temStr[TAM];

    printf("Nome: ");
    receberStr(p -> nome, TAM);

    printf("Idade: ");
    scanf("%d", &p -> idade);

    printf("Peso: ");
    scanf("%lf", &p -> peso);

    printf("Altura: ");
    scanf("%lf", &p -> altura);

    receberStr(temStr, TAM);
}

void preencherPessoas(struct Pessoa vp[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("----- Pessoa N° %d -----\n", i + 1);
        preencherPessoa(&vp[i]);
        
    }
}

void imprimirPessoa(struct Pessoa p){

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d anos\n", p.idade);
    printf("Peso: %.2lf KG\n", p.peso);
    printf("Altura: %.2lf M\n", p.altura);
}


void imprimirPessoas(struct Pessoa vp[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("----- Pessoa N° %d -----\n", i + 1);
        imprimirPessoa(vp[i]);

    }
}


double mediaAltura(struct Pessoa vp[], int t){
    int i;
    double soma = 0.00;

    for(i = 0; i < t; i += 1){
        soma += vp[i].altura;
    }
    return soma / t;
}

int maiorIdade(struct Pessoa vp[], int t){
    int i;
    int maior = 0;

    for(i = 0; i < t; i += 1){
        if(vp[i].idade > vp[maior].idade){
            maior = i;
        }
    }

    return vp[maior].idade;
}

int buscaSequencialNome(struct Pessoa vp[], int t, char n[]){
    int i;

    for(i = 0; i < t; i += 1){
        if(strcmp(vp[i].nome, n) == 0){
            return i;
        }
    }
    return -1;
}

void pesquisarNome(struct Pessoa vp[], int t){
   char nome[TAM], tempStr[TAM];
   char opcao;
   int indice;

    printf("----- PESQUISAR -----\n");

    do{
        printf("Informe nome: ");

        receberStr(nome, TAM);

        indice = buscaSequencialNome(vp, t, nome);

        if(indice != -1){
            printf("Encontrado %s em: %d\n", vp[indice].nome, indice);

        }else{
            printf("Nome não encontrado\n");
        }


        printf("Deseja realizar nova pesquisa? [s/n]");
        scanf("%c", &opcao);
        receberStr(tempStr, TAM);

    }while(opcao == 's' || opcao == 'S');

}


// bubble sort por nome
void bubbleSortNome(struct Pessoa vp[], int t){
    int i;
    int troca = 1;
    struct Pessoa aux;

    while(troca){
        troca = 0;

        for(i = 0; i < t - 1; i += 1){
            if(strcmp(vp[i].nome, vp[i + 1].nome) > 0){
                aux = vp[i];
                vp[i] = vp[i + 1];
                vp[i + 1] = aux;
                troca = 1;
            }
        }
        t -= 1;
    }
}


// insert sort por nome
void insertSortNome(struct Pessoa vp[], int t){
    int i, j;
    struct Pessoa aux;

    for(i = 1; i < t; i += 1){
        j = i;
        aux = vp[j];

        while(j > 0 && strcmp(aux.nome, vp[j - 1].nome) < 0 ){
            vp[j] = vp[j - 1];
            j -= 1;
        }
        vp[j] = aux;
    }
}


// select sort por nome
void selectSortNome(struct Pessoa vp[], int t){
    int i, j, menor;
    struct Pessoa aux;

    for(i = 0; i < t - 1; i += 1){
        menor = i;

        for(j = i + 1; j < t; j += 1){
            if(strcmp(vp[j].nome, vp[menor].nome) < 0){
                menor = j;
            }
        }
        aux = vp[i];
        vp[i] = vp[menor];
        vp[menor] = aux;
    }
}

////////////////////////

// bubble sort por ordem decrescente de idade. Caso tenha mesma idade, ordena de forma crescente por nome
void bubbleSortIdadeDesc(struct Pessoa vp[], int t){
    int i;
    int troca = 1;
    struct Pessoa aux;

    while(troca){
        troca = 0;

        for(i = 0; i < t - 1; i += 1){
            if((vp[i].idade < vp[i + 1].idade) || (vp[i].idade == vp[i + 1].idade && strcmp(vp[i].nome, vp[i + 1].nome) > 0) ){
                aux = vp[i];
                vp[i] = vp[i + 1];
                vp[i + 1] = aux;
                troca = 1;
            }
        }
        t -= 1;
    }
}


// insert sort por idade
void insertSortNome(){

}


// select sort por idade
void selectSortNome(){
 
}

// busca binaria por nome
int buscaBinariaNome(struct Pessoa vp[], int t, char n[]){
    int meio;
    int inicio = 0;
    int fim = t - 1;

    do{
        meio = (inicio + fim) / 2;

        if(strcmp(vp[meio].nome, n) > 0){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }

    }while(strcmp(vp[meio].nome, n) != 0 && inicio <= fim);

    if(strcmp(vp[meio].nome, n) == 0){
        return meio;
    }

    return -1;
}




// busca binaria por idade
int buscaBinariaIdade(){
    
}
