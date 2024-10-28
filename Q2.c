#include <stdio.h>
#include <string.h>
#define QTD_PRODUTOS 40
#define TAM_STRING 256

struct Produto{
    int codigo;
    char descricao[TAM_STRING];
    double valor;
    int qtdEstoque;
};

void Cadastrar(struct Produto *produtos, int *tam);
void lerStr(char *str,int tam);
void AlterarValor(struct Produto produtos[],int tam, int codigo);
void ObterValor(struct Produto produtos[],int tam,int codigo);
void ObterQtd(struct Produto produtos[],int tam,int codigo);
void Vender(struct Produto produtos[],int tam,int codigo);
void Atualizar(struct Produto produtos[],int tam,int codigo);
void ExibirDescricao(struct Produto produtos[],int tam);
void ExibirDescricaoComZero(struct Produto produtos[],int tam);


int main(){
    struct Produto produtos[QTD_PRODUTOS];
    int tam = 0;
    int opcao;
    printf("Escolha uma das opções do MENU\n");
    do{
    printf("1-Cadastrar um novo produto\n");
    printf("2-Alterar valor de um produto\n");
    printf("3-Obter valor unitário do produto\n");
    printf("4-Obter quantidade em estoque do produto\n");
    printf("5-Vender um produto\n");
    printf("6-Atualizar a quantidade em estoque do produto\n");
    printf("7-Exibir o código e a descrição de todos os produtos\n");
    printf("8-Exibir o código e a descrição de todos os produtos com estoque zero\n");
    printf("0-Encerrar programa\n");
    printf("Opção: ");
    scanf("%d",&opcao);
    printf("\n");
    switch (opcao)
        {
        case 1:
            Cadastrar(produtos,&tam);
            break;
        case 2:
            printf("Informe o código do produto: ");
            int b;
            scanf("%d",&b);
            AlterarValor(produtos,tam,b); 
            break;
        case 3:
            printf("Informe o código do produto: ");
            int c;
            scanf("%d",&c);
            ObterValor(produtos,tam,c); 
            break;
        case 4:
            printf("Informe o código do produto: ");
            int d;
            scanf("%d",&d);
            ObterQtd(produtos,tam,d);
            break;
        case 5:
            printf("Informe o código do produto: ");
            int e;
            scanf("%d",&e);
            Vender(produtos,tam,e);
            break;
        case 6:
            printf("Informe o código do produto: ");
            int f;
            scanf("%d",&f);
            Atualizar(produtos,tam,f);
            break;
        case 7:
            ExibirDescricao(produtos,tam);
            break;
        case 8:
            ExibirDescricaoComZero(produtos,tam);
            break;
        default:
            if (opcao!=0){
            printf("Opção inválida!\n\n");}
            else{
                printf("O programa será encerrado!!!\n");
            }
            break;
    } 
    }while (opcao!=0);
    return 0;
}
void Cadastrar(struct Produto *produtos, int *tam){
    if(*tam<QTD_PRODUTOS){
        printf("Digite o código do produto: ");
        scanf("%d",&produtos[*tam].codigo);
        getchar();
        printf("Informe a descrição do produto: ");
        lerStr(produtos[*tam].descricao,TAM_STRING);
        printf("Informe o valor unitário do produto: ");
        scanf("%lf",&produtos[*tam].valor);
        printf("Informe a quantidade do produto em estoque: ");
        scanf("%d",&produtos[*tam].qtdEstoque);
        (*tam)++;
        printf("\n");
    }else{
        printf("O programa não possui mais espaço para um novo cadastro\n\n");
    }
}

void lerStr(char *str,int tam){
    fgets(str,tam,stdin);
    int len = strlen(str);
    if (str[len-1] == '\n'){
        str[len-1] = '\0';
    }
}

void AlterarValor(struct Produto produtos[],int tam, int codigo){
    for (int i=0;i<tam;++i){
        if (codigo == produtos[i].codigo){
            printf("Informe o novo valor: ");
            scanf("%lf",&produtos[i].valor);
            break;
        }
    }
}

void ObterValor(struct Produto produtos[],int tam,int codigo){
    for (int i=0;i<tam;++i){
        if (codigo == produtos[i].codigo){
            printf("O valor do produto é: %.2f\n\n",produtos[i].valor);
            break;
        }
    }
}
void ObterQtd(struct Produto produtos[],int tam,int codigo){
    for (int i=0;i<tam;++i){
        if (codigo == produtos[i].codigo){
            printf("A quantidade em estoque do produto é: %d\n\n",produtos[i].qtdEstoque);
            break;
        }
    }
}

void Vender(struct Produto produtos[],int tam,int codigo){
    int x;
    double valor;
    printf("Informe a quantidade desejada: ");
    scanf("%d",&x);
    getchar();
    
    for (int i=0;i<tam;++i){
        if (codigo == produtos[i].codigo){
            
            if (produtos[i].qtdEstoque == 0){
                printf("O produto está com o estoque zerado\n\n");
                break;
            }else if(produtos[i].qtdEstoque<x){
                char resp[3];
                printf("O produto possui no estoque: %d, deseja continuar a compra? (S/N): ",produtos[i].qtdEstoque);
                lerStr(resp,3);
                
                if (resp[0] == 'S'){
                    valor = produtos[i].qtdEstoque * produtos[i].valor;
                    produtos[i].qtdEstoque = 0;
                    printf("Valor a ser pago: %.2f\n\n",valor);
                    break;
                }
            } else {
                valor = x * produtos[i].valor;
                produtos[i].qtdEstoque = produtos[i].qtdEstoque - x;
                printf("Valor a ser pago: %.2f\n\n",valor);
                break;
            }
        }
    }
}

void Atualizar(struct Produto produtos[],int tam,int codigo){
    for (int i=0;i<tam;++i){
        if (codigo == produtos[i].codigo){
            printf("Informe a nova quantidade em estoque do produto: ");
            scanf("%d",&produtos[i].qtdEstoque);
            break;
        }
    }
}

void ExibirDescricao(struct Produto produtos[],int tam){
    for (int i=0;i<tam;++i){
        printf("Código do produto: %d\n",produtos[i].codigo);
        printf("Descrição do produto: %s\n\n",produtos[i].descricao);
    }
}

void ExibirDescricaoComZero(struct Produto produtos[],int tam){
    for (int i=0;i<tam;++i){
        if (produtos[i].qtdEstoque == 0){
            printf("Código do produto: %d\n",produtos[i].codigo);
            printf("Descrição do produto: %s\n\n",produtos[i].descricao);
        }
    }
}
