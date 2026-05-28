#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_TITULO 100
#define TAM_CATEGORIA 50
#define TAM_NOME 100
#define TAM_EMAIL 100

#define MAX_FAVORITOS 10

#define ARQ_VIDEOS "videos.bin"
#define ARQ_USUARIOS "usuarios.bin"


struct Video{
    int id;
    char titulo[TAM_TITULO];
    char categoria[TAM_CATEGORIA];
    int duracao;
};


struct Usuario{
    int id;
    char nome[TAM_NOME];
    char email[TAM_EMAIL];

    int favoritos[MAX_FAVORITOS];
    int qtdFavoritos;
};


void lerString(char s[], int t);
int buscarVideoPorId(int id, struct Video *video);
int buscarUsuarioPorId(int id, struct Usuario *usuario);
void cadastrarVideo();
void listarVideos();
void cadastrarUsuario();
void listarUsuarios();
void relatorioUsuariosFavoritos();
void atualizarVideo();
void atualizarUsuario();
void removerVideo();
void removerUsuario();


int main(){

    int opcao;

    do{

        printf("\n========================\n");
        printf("STREAMING DE VIDEOS\n");
        printf("========================\n");

        printf("1 - Cadastrar video\n");
        printf("2 - Listar videos\n");

        printf("3 - Cadastrar usuario\n");
        printf("4 - Listar usuarios\n");

        printf("5 - Relatorio favoritos\n");

        printf("6 - Atualizar video\n");
        printf("7 - Atualizar usuario\n");

        printf("8 - Remover video\n");
        printf("9 - Remover usuario\n");

        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        getchar(); // limpar buffer

        if(opcao == 1){

            cadastrarVideo();

        }else if(opcao == 2){

            listarVideos();

        }else if(opcao == 3){

            cadastrarUsuario();

        }else if(opcao == 4){

            listarUsuarios();

        }else if(opcao == 5){

            relatorioUsuariosFavoritos();

        }else if(opcao == 6){

            atualizarVideo();

        }else if(opcao == 7){

            atualizarUsuario();

        }else if(opcao == 8){

            removerVideo();

        }else if(opcao == 9){

            removerUsuario();

        }else if(opcao == 0){
            printf("\n========================\n");
            printf("Encerrando programa\n");
            printf("========================\n");

        }else{
            printf("\n========================\n");
            printf("Opcao invalida\n");
            printf("========================\n");
        }

    }while(opcao != 0);

    return 0;
}



void lerString(char s[], int t){

    int tam;

    fgets(s, t, stdin);

    tam = strlen(s);

    if(tam > 0 && s[tam - 1] == '\n'){
        s[tam - 1] = '\0';
    }
}




int buscarVideoPorId(int id, struct Video *video){

    FILE *arq;

    arq = fopen(ARQ_VIDEOS, "rb");

    if(arq == NULL){
        return 0;
    }

    while(fread(video, sizeof(struct Video), 1, arq) == 1){

        if(video->id == id){

            fclose(arq);

            return 1;
        }
    }

    fclose(arq);

    return 0;
}



int buscarUsuarioPorId(int id, struct Usuario *usuario){

    FILE *arq;

    arq = fopen(ARQ_USUARIOS, "rb");

    if(arq == NULL){
        return 0;
    }

    while(fread(usuario, sizeof(struct Usuario), 1, arq) == 1){

        if(usuario->id == id){

            fclose(arq);

            return 1;
        }
    }

    fclose(arq);

    return 0;
}



void cadastrarVideo(){

    FILE *arq;

    struct Video video;
    struct Video aux;

    arq = fopen(ARQ_VIDEOS, "ab");

    if(arq == NULL){
        printf("\n========================\n");
        printf("Erro ao abrir arquivo\n");
        printf("========================\n");

        return;
    }

    printf("\n===== CADASTRAR VIDEO =====\n");

    printf("ID: ");
    scanf("%d", &video.id);

    getchar(); // limpar buffer

    if(buscarVideoPorId(video.id, &aux)){

        printf("\n========================\n");
        printf("ID ja cadastrado\n");
        printf("========================\n");

        fclose(arq);

        return;
    }

    printf("Titulo: ");
    lerString(video.titulo, TAM_TITULO);

    printf("Categoria: ");
    lerString(video.categoria, TAM_CATEGORIA);

    printf("Duracao: ");
    scanf("%d", &video.duracao);

    getchar(); // limpar buffer

    if(fwrite(&video, sizeof(struct Video), 1, arq) != 1){
        printf("\n========================\n");
        printf("Erro ao gravar video\n");
        printf("========================\n");
    }else{
        printf("\n========================\n");
        printf("Video cadastrado com sucesso\n");
        printf("========================\n");
    }

    fclose(arq);

}



void listarVideos(){

    FILE *arq;

    struct Video video;

    arq = fopen(ARQ_VIDEOS, "rb");

    if(arq == NULL){
        printf("\n========================\n");
        printf("Nenhum video cadastrado\n");
        printf("========================\n");

        return;
    }

    printf("\n===== LISTA VIDEOS =====\n");

    while(fread(&video, sizeof(struct Video), 1, arq) == 1){

        printf("\nID: %d\n", video.id);
        printf("Titulo: %s\n", video.titulo);
        printf("Categoria: %s\n", video.categoria);
        printf("Duracao: %d minutos\n", video.duracao);
    }

    fclose(arq);
}



void cadastrarUsuario(){

    FILE *arq;

    struct Usuario usuario;
    struct Usuario aux;

    struct Video video;

    int i;
    int idVideo;

    arq = fopen(ARQ_USUARIOS, "ab");

    if(arq == NULL){
        printf("\n========================\n");
        printf("Erro ao abrir arquivo\n");
        printf("========================\n");
        return;
    }

    printf("\n===== CADASTRAR USUARIO =====\n");

    printf("ID: ");
    scanf("%d", &usuario.id);

    getchar(); // limpar buffer

    if(buscarUsuarioPorId(usuario.id, &aux)){
        printf("\n========================\n");
        printf("ID ja cadastrado\n");
        printf("========================\n");

        fclose(arq);

        return;
    }

    printf("Nome: ");
    lerString(usuario.nome, TAM_NOME);

    printf("Email: ");
    lerString(usuario.email, TAM_EMAIL);

    printf("Quantidade favoritos maximo %d: ", MAX_FAVORITOS);
    scanf("%d", &usuario.qtdFavoritos);

    getchar(); // limpar buffer

    if(usuario.qtdFavoritos > MAX_FAVORITOS){
        usuario.qtdFavoritos = MAX_FAVORITOS;
    }

    if(usuario.qtdFavoritos < 0){
        usuario.qtdFavoritos = 0;
    }

    for(i = 0; i < usuario.qtdFavoritos; i += 1){

        printf("Informe ID favorito %d: ", i + 1);
        scanf("%d", &idVideo);

        getchar(); // limpar buffer

        if(buscarVideoPorId(idVideo, &video)){

            usuario.favoritos[i] = idVideo;

        }else{
            printf("\n========================\n");
            printf("Video nao encontrado\n");
            printf("========================\n");

            i -= 1;
        }
    }

    if(fwrite(&usuario, sizeof(struct Usuario), 1, arq) != 1){
        printf("\n========================\n");
        printf("Erro ao gravar usuario\n");
        printf("========================\n");
    }else{
        printf("\n===============================\n");
        printf("Usuario cadastrado com sucesso\n");
        printf("===============================\n");
    }

    fclose(arq);
}



void listarUsuarios(){

    FILE *arq;

    struct Usuario usuario;

    arq = fopen(ARQ_USUARIOS, "rb");

    if(arq == NULL){
        printf("\n==========================\n");
        printf("Nenhum usuario cadastrado\n");
        printf("==========================\n");

        return;
    }

    printf("\n===== LISTA USUARIOS =====\n");

    while(fread(&usuario, sizeof(struct Usuario), 1, arq) == 1){

        printf("\nID: %d\n", usuario.id);
        printf("Nome: %s\n", usuario.nome);
        printf("Email: %s\n", usuario.email);
    }

    fclose(arq);
}


void atualizarUsuario(){

    FILE *arq;

    struct Usuario usuario;

    struct Video video;

    int id;
    int encontrado = 0;

    int i;
    int idVideo;

    arq = fopen(ARQ_USUARIOS, "rb+");

    if(arq == NULL){
        printf("\n========================\n");
        printf("Arquivo nao encontrado\n");
        printf("========================\n");
        return;
    }

    printf("Informe ID do usuario: ");
    scanf("%d", &id);

    getchar();

    while(fread(&usuario, sizeof(struct Usuario), 1, arq) == 1){

        if(usuario.id == id){

            encontrado = 1;

            printf("Novo nome: ");
            lerString(usuario.nome, TAM_NOME);

            printf("Novo email: ");
            lerString(usuario.email, TAM_EMAIL);

            printf("Quantidade favoritos: ");
            scanf("%d", &usuario.qtdFavoritos);

            getchar();

            if(usuario.qtdFavoritos > MAX_FAVORITOS){
                usuario.qtdFavoritos = MAX_FAVORITOS;
            }

            if(usuario.qtdFavoritos < 0){
                usuario.qtdFavoritos = 0;
            }

            for(i = 0; i < usuario.qtdFavoritos; i += 1){

                printf("Informe ID favorito %d: ", i + 1);
                scanf("%d", &idVideo);

                getchar();

                if(buscarVideoPorId(idVideo, &video)){

                    usuario.favoritos[i] = idVideo;

                }else{
                    printf("\n========================\n");
                    printf("Video nao encontrado\n");
                    printf("========================\n");
                    i -= 1;
                }
            }

            fseek(arq, -(long)sizeof(struct Usuario), SEEK_CUR);

            if(fwrite(&usuario, sizeof(struct Usuario), 1, arq) != 1){
                printf("\n==========================\n");
                printf("Erro ao atualizar usuario\n");
                printf("==========================\n");
            }else{
                printf("\n========================\n");
                printf("Usuario atualizado\n");
                printf("========================\n");
            }

            break;
        }
    }

    if(!encontrado){
        printf("\n========================\n");
        printf("Usuario nao encontrado\n");
        printf("========================\n");
    }

    fclose(arq);
}



void removerUsuario(){

    FILE *arqAntigo;
    FILE *arqNovo;

    struct Usuario usuario;

    int id;
    int encontrado = 0;

    arqAntigo = fopen(ARQ_USUARIOS, "rb");
    arqNovo = fopen("tempUsuarios.bin", "wb");

    if(arqAntigo == NULL || arqNovo == NULL){
        printf("\n========================\n");
        printf("Erro ao abrir arquivos\n");
        printf("========================\n");

        return;
    }

    printf("Informe ID do usuario: ");
    scanf("%d", &id);

    getchar();

    while(fread(&usuario, sizeof(struct Usuario), 1, arqAntigo) == 1){

        if(usuario.id == id){

            encontrado = 1;

        }else{

            fwrite(&usuario, sizeof(struct Usuario), 1, arqNovo);
        }
    }

    fclose(arqAntigo);
    fclose(arqNovo);

    remove(ARQ_USUARIOS);

    rename("tempUsuarios.bin", ARQ_USUARIOS);

    if(encontrado){
        printf("\n========================\n");
        printf("Usuario removido\n");
        printf("========================\n");

    }else{
        printf("\n========================\n");
        printf("Usuario nao encontrado\n");
        printf("========================\n");
    }
}




void relatorioUsuariosFavoritos(){

    FILE *arq;

    struct Usuario usuario;
    struct Video video;

    int i;

    arq = fopen(ARQ_USUARIOS, "rb");

    if(arq == NULL){
        printf("\n==========================\n");
        printf("Nenhum usuario cadastrado\n");
        printf("==========================\n");
        return;
    }

    printf("\n===== RELATORIO =====\n");

    while(fread(&usuario, sizeof(struct Usuario), 1, arq) == 1){

        printf("\nUsuario: %s\n", usuario.nome);
        printf("Email: %s\n", usuario.email);

        printf("Favoritos:\n");

        if(usuario.qtdFavoritos == 0){
            printf("\n========================\n");
            printf("Nenhum favorito\n");
            printf("========================\n");

        }else{

            for(i = 0; i < usuario.qtdFavoritos; i += 1){

                if(buscarVideoPorId(usuario.favoritos[i], &video)){

                    printf("- %s\n", video.titulo);
                }
            }
        }
    }

    fclose(arq);
}


void atualizarVideo(){

    FILE *arq;

    struct Video video;

    int id;
    int encontrado = 0;

    arq = fopen(ARQ_VIDEOS, "rb+");

    if(arq == NULL){
        printf("\n========================\n");
        printf("Arquivo nao encontrado\n");
        printf("========================\n");

        return;
    }

    printf("Informe ID do video: ");
    scanf("%d", &id);

    getchar(); // limpar buffer

    while(fread(&video, sizeof(struct Video), 1, arq) == 1){

        if(video.id == id){

            encontrado = 1;

            printf("Novo titulo: ");
            lerString(video.titulo, TAM_TITULO);

            printf("Nova categoria: ");
            lerString(video.categoria, TAM_CATEGORIA);

            printf("Nova duracao: ");
            scanf("%d", &video.duracao);

            getchar(); // limpar buffer

            fseek(arq, -(long)sizeof(struct Video), SEEK_CUR);

            if(fwrite(&video, sizeof(struct Video), 1, arq) != 1){
                printf("\n========================\n");
                printf("Erro ao atualizar video\n");
                printf("========================\n");
            }else{
                printf("\n========================\n");
                printf("Video atualizado\n");
                printf("========================\n");
            }

            break;
        }
    }

    if(!encontrado){
        printf("\n========================\n");
        printf("Video nao encontrado\n");
        printf("========================\n");
    }

    fclose(arq);
}



void removerVideo(){

    FILE *arqAntigo;
    FILE *arqNovo;

    struct Video video;

    int id;
    int encontrado = 0;

    arqAntigo = fopen(ARQ_VIDEOS, "rb");
    arqNovo = fopen("tempVideos.bin", "wb");

    if(arqAntigo == NULL || arqNovo == NULL){
        printf("\n========================\n");
        printf("Erro ao abrir arquivos\n");
        printf("========================\n");

        return;
    }

    printf("Informe ID do video: ");
    scanf("%d", &id);

    getchar(); // limpar buffer

    while(fread(&video, sizeof(struct Video), 1, arqAntigo) == 1){

        if(video.id == id){

            encontrado = 1;

        }else{

            fwrite(&video, sizeof(struct Video), 1, arqNovo);
        }
    }

    fclose(arqAntigo);
    fclose(arqNovo);

    remove(ARQ_VIDEOS);

    rename("tempVideos.bin", ARQ_VIDEOS);

    if(encontrado){
        printf("\n========================\n");
        printf("Video removido\n");
        printf("========================\n");

    }else{
        printf("\n========================\n");
        printf("Video nao encontrado\n");
        printf("========================\n");
    }
}



