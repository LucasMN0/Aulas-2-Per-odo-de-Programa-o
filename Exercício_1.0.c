#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_STR 256
#define QTD_LISTA 50

void lerStr(char *str,int tam);
void cadastrarUsuario();
void atualizarUsuario();
void removerUsuario();
void cadastrarVideo();
void atualizarVideo();
void removerVideo();
void gerarRelatorio();

struct Usuario{
    int id;
    char nome[TAM_STR];
    int lista[QTD_LISTA];
    int qtdFavoritos;
};

struct Video{
    int id;
    char nome[TAM_STR];
    int duracao;
    int likes;
};

int main(){
    struct Usuario usuarios;
    struct Video videos;
    int opcao1,opcao2;
    do{
    printf("\nMENU\n\n");
    printf("1-Opções de usuário\n");
    printf("2-Opções de vídeo\n");
    printf("3-Relatório\n");
    printf("0-Sair\n");
    printf("Digite a sua opção: ");
    scanf("%d",&opcao1);
    getchar();
    switch(opcao1){
        case 1:
            do{
            printf("\nMENU DE USUÁRIO\n\n");
            printf("1-Cadastrar usuário\n");
            printf("2-Atualizar usuário\n");
            printf("3-Remover usuário\n");
            printf("0-Sair\n");
            printf("Digite a sua opção: ");
            scanf("%d",&opcao2);
            getchar();
                switch(opcao2){
                    case 1:
                        cadastrarUsuario();
                        break;
                    case 2:
                        atualizarUsuario();
                        break;
                    case 3:
                        removerUsuario();
                        break;
                    default:
                        break;
                    }
                }while(opcao2!=0);
                break;
        case 2:
            do{
            printf("\nMENU DE VÍDEO\n\n");
            printf("1-Cadastrar vídeo\n");
            printf("2-Atualizar vídeo\n");
            printf("3-Remover vídeo\n");
            printf("0-Sair\n");
            printf("Digite a sua opção: ");
            scanf("%d",&opcao2);
                switch(opcao2){
                    case 1:
                        cadastrarVideo();
                        break;
                    case 2:
                        atualizarVideo();
                        break;
                    case 3:
                        removerVideo();
                        break;
                    default:
                        break;
                    }
                }while(opcao2!=0);
                break;
        case 3:
            gerarRelatorio();
            break;
        default:
            break;
    }
    }while(opcao1!=0);
    return 0;
}

void lerStr(char *str,int tam){
    fgets(str,tam,stdin);
    int len = strlen(str);
    if (str[len-1]=='\n'){
        str[len-1]='\0';
    }
}
void cadastrarUsuario(){
    struct Usuario usuarios;
    FILE *arqU = fopen("usuarios.bin","ab");
    if (arqU == NULL){
        printf("Erro na abertura do arquivo!\n");
        return;
    }
    printf("Digite o ID do Usuário: ");
    scanf("%d",&usuarios.id);
    getchar();
    printf("Digite o nome do Usuário: ");
    lerStr(usuarios.nome,TAM_STR);
    usuarios.qtdFavoritos=0;

    fwrite(&usuarios,sizeof(struct Usuario),1,arqU);
    fclose(arqU);
}
void atualizarUsuario(){
    struct Usuario usuarios;
    struct Video videos;
    int id, encontrado=0;
    FILE *arqU = fopen("usuarios.bin","r+b");
    FILE *arqV = fopen("videos.bin","rb");
    if (arqU == NULL){
        printf("Erro na abertura do arquivo usuarios!\n");
        return;
    }
    if (arqV == NULL){
        printf("Erro na abertura do arquivo videos!\n");
        return;
    }
    printf("Digite o ID do usuário para fazer uma busca: ");
    scanf("%d",&id);
    getchar();
    while(fread(&usuarios,sizeof(struct Usuario),1,arqU)){
        if(usuarios.id == id){
            encontrado=1;
            printf("Usuário encontrado: %s (ID: %d)\n", usuarios.nome, usuarios.id);
            int opcao;
            do {
                printf("\nAtualizar Usuário:\n\n");
                printf("1-Adicionar vídeo aos favoritos\n");
                printf("2-Remover vídeo dos favoritos\n");
                printf("3-Listar de vídeos favoritos atuais\n");
                printf("4-Atualizar nome do usuário\n");
                printf("0 - Sair\n");
                printf("Digite a sua opção: ");
                scanf("%d", &opcao);
                getchar();
                 switch (opcao) {
                    case 1: {
                        if (usuarios.qtdFavoritos < QTD_LISTA) {
                            char nomeVideo[TAM_STR];
                            printf("Digite o nome do vídeo para adicionar aos favoritos: ");
                            lerStr(nomeVideo, TAM_STR);

                            int idVideoEncontrado = -1;
                            rewind(arqV);
                            while (fread(&videos, sizeof(struct Video), 1, arqV)) {
                                if (strcmp(videos.nome, nomeVideo) == 0) {
                                    idVideoEncontrado = videos.id;
                                    break;
                                }
                            }

                            if (idVideoEncontrado != -1) {

                                int jaExiste = 0;
                                for (int i = 0; i < usuarios.qtdFavoritos; i++) {
                                    if (usuarios.lista[i] == idVideoEncontrado) {
                                        jaExiste = 1;
                                        break;
                                    }
                                }

                                if (!jaExiste) {
                                    usuarios.lista[usuarios.qtdFavoritos] = idVideoEncontrado;
                                    usuarios.qtdFavoritos++;
                                    printf("Vídeo '%s' (ID: %d) adicionado aos favoritos!\n", nomeVideo, idVideoEncontrado);
                                } else {
                                    printf("O vídeo '%s' já está nos favoritos.\n", nomeVideo);
                                }
                            } else {
                                printf("Vídeo '%s' não encontrado.\n", nomeVideo);
                            }
                        } else {
                            printf("A lista de favoritos está cheia!\n");
                        }
                        break;
                    }

                    case 2: {
                        if (usuarios.qtdFavoritos > 0) {
                            char nomeVideo[TAM_STR];
                            printf("Digite o nome do vídeo para remover dos favoritos: ");
                            lerStr(nomeVideo, TAM_STR);
                            int idVideoEncontrado = -1;
                            rewind(arqV);
                            while (fread(&videos, sizeof(struct Video), 1, arqV)) {
                                if (strcmp(videos.nome, nomeVideo) == 0) {
                                    idVideoEncontrado = videos.id;
                                    break;
                                }
                            }

                            if (idVideoEncontrado != -1) {
                                int encontrado = 0;
                                for (int i = 0; i < usuarios.qtdFavoritos; i++) {
                                    if (usuarios.lista[i] == idVideoEncontrado) {
                                        encontrado = 1;
                                        for (int j = i; j < usuarios.qtdFavoritos - 1; j++) {
                                            usuarios.lista[j] = usuarios.lista[j + 1];
                                        }
                                        usuarios.qtdFavoritos--;
                                        printf("Vídeo '%s' (ID: %d) removido dos favoritos!\n", nomeVideo, idVideoEncontrado);
                                        break;
                                    }
                                }

                                if (!encontrado) {
                                    printf("O vídeo '%s' não está nos favoritos.\n", nomeVideo);
                                }
                            } else {
                                printf("Vídeo '%s' não encontrado.\n", nomeVideo);
                            }
                        } else {
                            printf("A lista de favoritos está vazia!\n");
                        }
                        break;
                    }

                    case 3: {
                        printf("Vídeos favoritos:\n");
                        if (usuarios.qtdFavoritos > 0) {
                            for (int i = 0; i < usuarios.qtdFavoritos; i++) {
                                rewind(arqV);
                                while (fread(&videos, sizeof(struct Video), 1, arqV)) {
                                    if (videos.id == usuarios.lista[i]) {
                                        printf("- %s (ID: %d, Duração: %d min, Likes: %d)\n",
                                               videos.nome, videos.id, videos.duracao, videos.likes);
                                        break;
                                    }
                                }
                            }
                        } else {
                            printf("Nenhum vídeo favoritado.\n");
                        }
                        break;
                    }
                    case 4:
                        printf("Digite o novo nome: ");
                        char novoNome[TAM_STR];
                        lerStr(novoNome,TAM_STR);
                        strcpy(usuarios.nome,novoNome);
                        break;
                    default:
                        break;
                }
            } while (opcao != 0);

            fseek(arqU, -sizeof(struct Usuario), SEEK_CUR);
            fwrite(&usuarios, sizeof(struct Usuario), 1, arqU);
            printf("Usuário atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário com ID %d não encontrado.\n", id);
    }

    fclose(arqU);
    fclose(arqV);
}
        
void removerUsuario() {
    struct Usuario usuarios;
    int id, encontrado = 0;

    FILE *arqU = fopen("usuarios.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    if (!arqU || !temp) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    printf("Digite o ID do usuário a ser removido: ");
    scanf("%d", &id);

    while (fread(&usuarios, sizeof(struct Usuario), 1, arqU)) {
        if (usuarios.id != id) {
            fwrite(&usuarios, sizeof(struct Usuario), 1, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arqU);
    fclose(temp);

    if (encontrado) {
        remove("usuarios.bin");
        rename("temp.bin", "usuarios.bin");
        printf("Usuário removido com sucesso!\n");
    } else {
        printf("Usuário com ID %d não encontrado.\n", id);
        remove("temp.bin");
    }
}

void cadastrarVideo() {
    struct Video videos;
    FILE *arqV = fopen("videos.bin", "ab");
    if (!arqV) {
        printf("Erro ao abrir arquivo de vídeos!\n");
        return;
    }

    printf("Digite o ID do vídeo: ");
    scanf("%d", &videos.id);
    getchar();
    printf("Digite o nome do vídeo: ");
    lerStr(videos.nome, TAM_STR);
    printf("Digite a duração do vídeo (em minutos): ");
    scanf("%d", &videos.duracao);
    printf("Digite a quantidade de likes do vídeo: ");
    scanf("%d",&videos.likes);

    fwrite(&videos, sizeof(struct Video), 1, arqV);
    fclose(arqV);

    printf("Vídeo cadastrado com sucesso!\n");
}

void atualizarVideo() {
    struct Video videos;
    int id,opcao, encontrado = 0;

    FILE *arqV = fopen("videos.bin", "r+b");
    if (!arqV) {
        printf("Erro ao abrir arquivo de vídeos!\n");
        return;
    }

    printf("Digite o ID do vídeo a ser atualizado: ");
    scanf("%d", &id);
    getchar();


    while (fread(&videos, sizeof(struct Video), 1, arqV)) {
        if (videos.id == id) {
            encontrado = 1;
            printf("Vídeo encontrado: %s (ID: %d)\n", videos.nome, videos.id);
            do {
                printf("\nAtualizar Vídeo:\n\n");
                printf("1-Atualizar o nome do Vídeo\n");
                printf("2-Atualizar a duração do Vídeo\n");
                printf("3-Atualizar a quantidade de likes do Vídeo\n");
                printf("0 - Sair\n");
                printf("Digite a sua opção: ");
                scanf("%d", &opcao);
                getchar();
                switch (opcao) {
                    case 1:
                        printf("Digite o novo nome: ");
                        char novoNome[TAM_STR];
                        lerStr(novoNome,TAM_STR);
                        strcpy(videos.nome,novoNome);
                        break;
                    case 2:
                        printf("Digite a nova duração(em minutos): ");
                        int novaDuracao;
                        scanf("%d",&novaDuracao);
                        getchar();
                        videos.duracao=novaDuracao;
                        break;
                    case 3:
                        printf("Digite a nova quantidade de likes do vídeo: ");
                        int qtdLikes;
                        scanf("%d",&qtdLikes);
                        getchar();
                        videos.likes=qtdLikes;
                        break;
                    default:
                        break;
                }
            }while(opcao!=0);
            fseek(arqV, -sizeof(struct Video), SEEK_CUR);
            fwrite(&videos, sizeof(struct Video), 1, arqV);
            printf("Vídeo atualizado com sucesso!\n");
            break;
        }
    if (!encontrado) {
        printf("Vídeo com ID %d não encontrado.\n", id);
    }fclose(arqV);
    }
}

void removerVideo() {
    struct Video videos;
    int id, encontrado = 0;

    FILE *arqV = fopen("videos.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    if (!arqV || !temp) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    printf("Digite o ID do vídeo a ser removido: ");
    scanf("%d", &id);

    while (fread(&videos, sizeof(struct Video), 1, arqV)) {
        if (videos.id != id) {
            fwrite(&videos, sizeof(struct Video), 1, temp);
        } else {
            encontrado = 1;
        }

    fclose(arqV);
    fclose(temp);

    if (encontrado) {
        remove("videos.bin");
        rename("temp.bin", "videos.bin");
        printf("Vídeo removido com sucesso!\n");
    } else {
        printf("Vídeo com ID %d não encontrado.\n", id);
        remove("temp.bin");
    }
}
}
void gerarRelatorio() {
    struct Usuario usuarios;
    struct Video videos;

    FILE *arqU = fopen("usuarios.bin", "rb");
    FILE *arqV = fopen("videos.bin", "rb");

    if (!arqU || !arqV) {
        printf("Erro ao abrir arquivos para relatório!\n");
        return;
    }
    printf("\nRelatório de Usuários e Vídeos Favoritados:\n");
    while (fread(&usuarios, sizeof(struct Usuario), 1, arqU)) {
        printf("\nUsuário: %s (ID: %d)\n", usuarios.nome, usuarios.id);
        printf("Vídeos Favoritados:\n");
        for (int i = 0; i < usuarios.qtdFavoritos; i++) {
            rewind(arqV);
            while (fread(&videos, sizeof(struct Video), 1, arqV)) {
                if (videos.id == usuarios.lista[i]) {
                    printf("- %s (ID: %d, Duração: %d min, Likes: %d)\n",
                           videos.nome, videos.id, videos.duracao, videos.likes);
                    break;
                }
            }
        }
        if (usuarios.qtdFavoritos == 0) {
            printf("Nenhum vídeo favoritado.\n");
        }
    }
    fclose(arqU);
    fclose(arqV);
}
