#include <stdio.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

int lerDentroIntervalo(int min, int max);
void lerMatriz(int mat[][QTD_COLUNAS],int lin,int col);
void imprimir(int mat[][QTD_COLUNAS], int lin, int col);
void multiplicarMatrizes(int matrizA[QTD_LINHAS][QTD_COLUNAS], int linA, int colA, int matrizB[QTD_LINHAS][QTD_COLUNAS], int linB, int colB, int matrizC[QTD_LINHAS][QTD_COLUNAS]); 
int main(){
    
    int qtdlinhasA, qtdcolunasA,qtdlinhasB, qtdcolunasB;
    int matrizA[QTD_LINHAS][QTD_COLUNAS];
    int matrizB[QTD_COLUNAS][QTD_LINHAS];
    int matrizC[QTD_LINHAS][QTD_COLUNAS];

    printf("Digite a quantidade de linhas da 1° matriz (1-%d): ",QTD_LINHAS);
    qtdlinhasA = lerDentroIntervalo(1,QTD_LINHAS);

    printf("Digite a quantidade de colunas da 1° matriz (1-%d): ",QTD_COLUNAS);
    qtdcolunasA = lerDentroIntervalo(1,QTD_COLUNAS);
    
    lerMatriz(matrizA,qtdlinhasA,qtdcolunasA);
    printf("\n----------------\n");
    imprimir(matrizA,qtdlinhasA,qtdcolunasA);
    
    printf("Digite a quantidade de linhas da 2° matriz (1-%d): ",QTD_LINHAS);
    qtdlinhasB = lerDentroIntervalo(1,QTD_LINHAS);

    printf("Digite a quantidade de colunas da 2° matriz (1-%d): ",QTD_COLUNAS);
    qtdcolunasB = lerDentroIntervalo(1,QTD_COLUNAS);
    
    lerMatriz(matrizB,qtdlinhasB,qtdcolunasB);
    printf("\n----------------\n");
    imprimir(matrizB,qtdlinhasB,qtdcolunasB);

    multiplicarMatrizes(matrizA,qtdlinhasA,qtdcolunasA,matrizB,qtdlinhasB,qtdcolunasB,matrizC);
    
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
void multiplicarMatrizes(int matrizA[QTD_LINHAS][QTD_COLUNAS], int linA, int colA, int matrizB[QTD_LINHAS][QTD_COLUNAS], int linB, int colB, int matrizC[QTD_LINHAS][QTD_COLUNAS]){
    int opcao=0;
    while (opcao != 1 && opcao != 2){
        printf("Qual a ordem de multiplicação ?\n");
        printf("1-MatrizA * MatrizB\n");
        printf("2-MatrizB * MatrizA\n");
        printf("Opção: ");
        scanf("%d",&opcao);
        printf("\n-----------------------\n");
        if (opcao == 1){
            if (colA == linB){
                int v = colA;
                for (int i=0;i<linA;++i){
                    for (int j=0;j<colB;++j){
                        for (int x=0;x<v;++x){
                            matrizC[i][j] += matrizA[i][x] * matrizB[x][j];
                        }
                    }
                }
            } else{
                printf("É impossível realizar essa multiplicação!\n");
                break;
            }
            imprimir(matrizC,linA,colB);
        } else if (opcao == 2){
            if (colB == linA){
                int v = colB;
                for (int i=0;i<linB;++i){
                    for (int j=0;j<colA;++j){
                        for (int x=0;x<v;++x){
                            matrizC[i][j] += matrizB[i][x] * matrizA[x][j];
                        }
                    }
                }
            } else{
                printf("É impossível realizar essa multiplicação!\n");
                break;
            }
            imprimir(matrizC,linB,colA);
        } else{
            printf("Essa opção é inválida!");
        }    
    }
}
