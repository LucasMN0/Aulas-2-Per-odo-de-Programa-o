#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 2000000000

void VetorDesordenado(int v1[], int tam);
void VetorCrescente(int v2[],int tam);
void VetorDecrescente(int v3[], int tam);
void BubbleSort(int v[], int tam);
void InsertionSort(int v[], int tam);
void SelectionSort(int v[], int tam);

int main() {
    int *numeros = (int *) malloc(TAM * sizeof(int));

    if (numeros == NULL) {
        printf("Falha na alocação da memoria!\n");
        return 1;
    }
    int opcao1,opcao2;
    printf("%d",TAM);
    do {
        printf("MENU\n\n");
        printf("1 - Vetor Desordenado\n");
        printf("2 - Vetor Crescente\n");
        printf("3 - Vetor Decrescente\n");
        printf("0 - Sair\n");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao1);
        printf("Digite o tipo de ordenação\n\n");
        printf("1 - BubbleSort\n");
        printf("2 - InsertionSort\n");
        printf("3 - SelectionSort\n");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao2);
        switch (opcao1)
        {
        case 1:
            VetorDesordenado(numeros,TAM);
            if (opcao2 == 1){
                BubbleSort(numeros,TAM);
            } else if(opcao2 == 2){
                InsertionSort(numeros,TAM);
            } else if (opcao2 == 3){
                SelectionSort(numeros,TAM);
            }
            break;
        case 2:
            VetorCrescente(numeros,TAM);
            if (opcao2 == 1){
                BubbleSort(numeros,TAM);
            } else if(opcao2 == 2){
                InsertionSort(numeros,TAM);
            } else if (opcao2 == 3){
                SelectionSort(numeros,TAM);
            } break;
        case 3:
            VetorDecrescente(numeros,TAM);
            if (opcao2 == 1){
                BubbleSort(numeros,TAM);
            } else if(opcao2 == 2){
                InsertionSort(numeros,TAM);
            } else if (opcao2 == 3){
                SelectionSort(numeros,TAM);
            }
        default:
            break;
        }
    } while (opcao1 != 0);


    free(numeros);
    return 0;
}

void VetorDesordenado(int v1[], int tam){
    for(int i=0;i<tam;++i){
        v1[i] = rand()%tam;
    }
}

void VetorCrescente(int v2[],int tam){
    for(int i=0;i<tam;++i){
        v2[i]= i;
    }
}

void VetorDecrescente(int v3[], int tam){
    for (int i=0;i<tam;++i){
        v3[i]= tam-i;
    }
}

void BubbleSort(int v[], int tam){
    clock_t start,end;
    start=clock();
    for(int i=1;i<=tam-1;++i){
        int trocou=1;
        for(int j=0;j<tam-1-i;++j){
            if(v[j]>v[i]){
                int aux=v[i];
                v[i]=v[i+i];
                v[i+1]=aux;
            }trocou=0;
        }if(!trocou){
            break;
        }
    }end=clock();
    double tempo = ((double)(end-start)/CLOCKS_PER_SEC)*1000;
    printf("Tempo de execução: %f ms \n",tempo);
}

void InsertionSort(int v[], int tam){
    clock_t start,end;
    start = clock();
    int x;
    for(int i=1;i<tam;++i){
        x = v[i];
        int j = i-1;
        while(j>=0 && v[j]>x){
            v[j+1]=v[j];
            j = j-1;
        }v[j+1] = x;
    }end = clock();
    double tempo = ((double)(end-start)/CLOCKS_PER_SEC)*1000;
    printf("Tempo de execução: %f ms \n",tempo);
}

void SelectionSort(int v[], int tam){
    clock_t start,end;
    int x,menor,aux;
    start=clock();
    for(int i=0;i<tam-1;++i){
        menor = i;
        for(int j=i+1;j<tam;++j){
            if(v[j]<menor){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[i]=aux;
    }end=clock();
    double tempo = ((double)(end-start)/CLOCKS_PER_SEC)*1000;
    printf("Tempo de execução: %f ms \n",tempo);
}
