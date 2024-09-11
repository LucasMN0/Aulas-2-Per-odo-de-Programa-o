#include <stdio.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

int lerDentroIntervalo(int min, int max);
void lerMatriz(int mat[][QTD_COLUNAS],int lin,int col);
void imprimir(int mat[][QTD_COLUNAS], int lin, int col);
int QtdImpares(int mat[][QTD_COLUNAS],int lin,int col);
int AcharElemento(int mat[][QTD_COLUNAS],int lin,int col, int valor, int *linha, int *coluna);
int SomaMatriz(int mat[][QTD_COLUNAS],int lin,int col);
double MediaMatriz(int mat[][QTD_COLUNAS],int lin,int col);
void MediaLinha(int mat[][QTD_COLUNAS],int lin,int col);

int main(){
    
    int qtdlinhas, qtdcolunas;
    int matriz[QTD_LINHAS][QTD_COLUNAS];

    printf("Digite a quantidade de linhas (1-%d): ",QTD_LINHAS);
    qtdlinhas = lerDentroIntervalo(1,QTD_LINHAS);

    printf("Digite a quantidade de colunas (1-%d): ",QTD_COLUNAS);
    qtdcolunas = lerDentroIntervalo(1,QTD_COLUNAS);
    
    lerMatriz(matriz,qtdlinhas,qtdcolunas);
    printf("\n----------------\n");
    imprimir(matriz,qtdlinhas,qtdcolunas);
    printf("\n");

    int opcao;
    while(opcao !=6){
        printf("Escolha uma das opções:\n");
        printf("1-Quantidade de números ímpares dentro da matriz \n");
        printf("2-Achar um elemento na matriz\n");
        printf("3-Somatório de todos os elementos na matriz\n");
        printf("4-Média de todos os elementos na matriz\n");
        printf("5-Média de todos os elementos de cada linha da matriz\n");
        printf("6-Sair\n");
        scanf("%d",&opcao);
        
        if (opcao == 1){
            int R = QtdImpares(matriz,qtdlinhas,qtdcolunas);
            printf("A quantidade de impares na matriz é: %d\n\n",R);
        }
        else if (opcao == 2){
            int valor;
            printf("Insira o elemento para procurar: ");
            scanf("%d",&valor);
            int linha,coluna;
            int R = AcharElemento(matriz,qtdlinhas,qtdcolunas,valor,&linha,&coluna);
            if (R == 0){
                printf("Valor encontrado na posição: [%d] [%d]\n\n",linha,coluna);
            } else{
                printf("Valor não encontrado\n\n");
            }
        }else if (opcao == 3){
            int R = SomaMatriz(matriz,qtdlinhas,qtdcolunas);
            printf("A soma de todos os elementosda matriz é: %d\n\n",R);
        }
        else if (opcao == 4){
            double R = MediaMatriz(matriz,qtdlinhas,qtdcolunas);
            printf("A média dos elementos da matriz é: %f\n\n",R);
        }
        else if (opcao == 5){
            MediaLinha(matriz,qtdlinhas,qtdcolunas);
        }
        else if (opcao == 6){
            printf("Ok, o programa será encerrado.");
        }
        else {
            printf("Opção inválida, por favor, digite uma das opções.");
        }
    }
    return 0;
}

void lerMatriz(int mat[][QTD_COLUNAS],int lin,int col){   
    for (int i=0;i<lin;++i){
        for (int j=0;j<col;++j){
            printf("Digite mat[%d][%d]:",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
}

void imprimir(int mat[][QTD_COLUNAS],int lin,int col){
    for (int i=0;i<lin;++i){
        for (int j=0;j<col;++j){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }

}
int lerDentroIntervalo(int min, int max){ 
    int valor;
    scanf("%d",&valor);
    while(valor < min || valor > max){
        printf("Valor incálido! Digite um outro valor: ");
        scanf("%d",&valor);
    }
    return valor;
}

int QtdImpares(int mat[][QTD_COLUNAS],int lin,int col){
    int r=0;
    for (int i=0;i<lin;++i){
        for (int j=0;j<col;++j){
          if (mat[i][j]%2!=0){
            r++;
          }
        }
    }
    return r;
}

int AcharElemento(int mat[][QTD_COLUNAS],int lin,int col, int valor, int *linha, int *coluna){
    for (int i=0;i<lin;++i){
        for (int j=0;j<col;++j){
            if (mat[i][j] == valor){
                *linha = i;
                *coluna = j;
                return 0;
            }
        }
    }
    return -1;
}   

int SomaMatriz(int mat[][QTD_COLUNAS],int lin,int col){
    int soma=0;
    for (int i=0;i<lin;++i){
        for (int j=0;j<col;++j){
            soma += mat[i][j];
        }
    }
    return soma;
}

double MediaMatriz(int mat[][QTD_COLUNAS],int lin,int col){
    double soma=0;
    double media;
    for (int i=0;i<lin;++i){
        for (int j=0;j<col;++j){
            soma += mat[i][j];
        }
    }
    media = soma/(lin*col);
    return media;
}

void MediaLinha(int mat[][QTD_COLUNAS],int lin,int col){
    double soma;
    double mediaLinha;
    for(int i=0;i<lin;++i){
        mediaLinha=0,soma=0;
        for(int j=0;j<col;++j){
            soma += mat[i][j];
        }
        mediaLinha = soma/col;
        printf("A média da %d° linha é: %f\n",i+1,mediaLinha);
    }
    printf("\n");
}
