#include <stdio.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_UF 26

struct Estado{
    char nome[TAM_NOME];
    int qtd_veiculos;
    int qtd_acidentes;
};


void receberString(char s[], int t);
void preencherEstado(struct Estado *e);
void preencherEstados(struct Estado ve[], int t);
int maiorNumAcidentes(struct Estado ve[], int t);
int menorNumAcidentes(struct Estado ve[], int t);
double percentualVeiculosAcidente(struct Estado e);
double mediaAcidentes(struct Estado ve[], int t);
void estadoAcimaDaMedia(struct Estado ve[], int t, double mediaN);




int main(){
    struct Estado estados[TAM_UF];
    int i, maior, menor;
    double percentual_acidentes, media_acidentes;

    printf("PREENCHA OS DADOS SOLICITADOS:\n\n");
    preencherEstados(estados, TAM_UF);
    printf("____________________________________________________________________\n");

    maior = maiorNumAcidentes(estados, TAM_UF);
    
    printf("====================== Maior Numero Acidentes ======================\n");
    printf("Numero Acidentes: %d\n", estados[maior].qtd_acidentes);
    printf("Estado: %s\n", estados[maior].nome);
    printf("____________________________________________________________________\n");


    menor = menorNumAcidentes(estados, TAM_UF);
    printf("====================== Menor Numero Acidentes ======================\n");
    printf("Numero Acidentes: %d\n", estados[menor].qtd_acidentes);
    printf("Estado: %s\n", estados[menor].nome);
    printf("____________________________________________________________________\n");
   
    
    printf("====== Percentual de veiculos envolvidos acidentes por estado ======\n");
    for(i = 0; i < TAM_UF; i += 1){
        percentual_acidentes = percentualVeiculosAcidente(estados[i]);
        printf("UF: %s - Percentual: %.2lf\n", estados[i].nome, percentual_acidentes);
    }
    printf("____________________________________________________________________\n");


    media_acidentes = mediaAcidentes(estados, TAM_UF);
   
    printf("==================== Media Nacional de Acidentes ====================\n");
    printf("%.2lf\n", media_acidentes);
    printf("____________________________________________________________________\n");

   
    printf("================= Estados acima da media nacional ==================\n");
    estadoAcimaDaMedia(estados, TAM_UF, media_acidentes);
    printf("____________________________________________________________________\n");


    return 0;
}



void receberString(char s[], int t){
    int tam;

    fgets(s, t, stdin);
    tam = strlen(s);

    if(tam > 0 && s[tam - 1] == '\n'){
        s[tam - 1] = '\0';

    }
}

void preencherEstado(struct Estado *e){
    
    // char tempStr[TAM_NOME]; // limpar buffer teclado

    printf("Nome:\n");
    receberString(e -> nome, TAM_NOME);

    printf("Quantidade Veiculos:\n");
    scanf("%d", &e -> qtd_veiculos);

    printf("Quantidade Acidentes:\n");
    scanf("%d", &e -> qtd_acidentes);

    getchar(); // limpar enter do buffer do teclado

    // receberString(tempStr, TAM_NOME); // limpar buffer teclado
}


void preencherEstados(struct Estado ve[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("===== ESTADO %d =====\n", i + 1);
        preencherEstado(&ve[i]);
    }
}


int maiorNumAcidentes(struct Estado ve[], int t){
    int i, maior = 0;

    for(i = 1; i < t; i += 1){
        if(ve[i].qtd_acidentes > ve[maior].qtd_acidentes){
            maior = i;
        }
    }

    return maior;
}

int menorNumAcidentes(struct Estado ve[], int t){
    int i, menor = 0;

    for(i = 1; i < t; i += 1){
        if(ve[i].qtd_acidentes < ve[menor].qtd_acidentes){
            menor = i;
        }
    }

    return menor;
}

double percentualVeiculosAcidente(struct Estado e){
    double percentual;

    percentual = ((double)e.qtd_acidentes / e.qtd_veiculos) * 100;

    return percentual;

}


double mediaAcidentes(struct Estado ve[], int t){
    int i, soma = 0;

    for(i = 0; i < t; i += 1){
        soma += ve[i].qtd_acidentes;

    }
    return (double)soma / t;
}

void estadoAcimaDaMedia(struct Estado ve[], int t, double mediaN){
    int i;

    for(i = 0; i < t; i += 1){
        if(ve[i].qtd_acidentes > mediaN){
            printf("UF: %s - Qtd Acidentes: %d\n", ve[i].nome, ve[i].qtd_acidentes);
        }
    }
}
