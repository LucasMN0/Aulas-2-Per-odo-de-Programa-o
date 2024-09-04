#include <stdio.h>

void ordenarValor(int vetor[],int *tamAgora,int valor){ 
  int i = *tamAgora - 1;
  
  while(i>=0 && vetor[i]> valor){
    vetor[i+1] = vetor[i];
    i--;
  }
  vetor[i+1] = valor;
  (*tamAgora)++;
}

void imprimir(int vetor[], int tam){
  for (int i=0; i < tam; i++){
    printf("Vetor %d: %d ", i+1, vetor[i]);
  }
  printf("\n");
}

int buscaBinaria(int v[], int tam, int valor){
    int esq = 0, dir = tam -1, meio;
    while (esq <= dir){
        meio = (esq + dir) /2;
        if (valor < v[meio]){
            dir = meio-1;
        }
        else if (valor > v[meio]){
            esq = meio+1;
        }
        else{
            return meio;
        }
    }
    return -1;
}

void remover(int vetor[], int *tamAgora, int valor) {
    int posicao = buscaBinaria(vetor, *tamAgora, valor);
    if (posicao == -1) {
        printf("Elemento não encontrado.\n");
        return;
    }
    for (int i = posicao; i < *tamAgora - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamAgora)--;
}


int main() {
int tam, valor, opcao;
int vetor[50];

do{
 printf("Digite o tamanho do vetor entre 3 e 50: ");
 scanf("%d", &tam);
}while(tam < 3 || tam > 50);

int tamAgora = 0;

  for (int i = 0; i < tam; i++){
  printf("Digite o valor %d: ", i+1);
  scanf("%d",&valor);
  ordenarValor(vetor,&tamAgora, valor);
  }

do{
  printf("\nEscolha uma das opções:\n");
  printf("1- Imprimir vetor\n");
  printf("2- Consultar número\n");
  printf("3- Remover número\n");
  printf("4- Adicionar número\n");
  printf("5- Sair\n");
  scanf("%d",&opcao);

  if (opcao == 1){
    imprimir(vetor, tamAgora);
  }
  if (opcao == 2){
    printf("Digite o valor que deseja consultar: ");
    scanf("%d",&valor);
    int posicao = buscaBinaria(vetor, tamAgora, valor);
    if(posicao == -1){
      printf("Elemento não encontrado");
    } else {
      printf("Valor encontrado na posição: %d\n", posicao);
    }

  }
  if (opcao == 3){
    printf("Digite o valor para ser removido: ");
    scanf("%d",&valor);
    remover(vetor, &tamAgora, valor);

  }
  if (opcao == 4){
    if (tamAgora < 50){
      printf("Digite o número que deseja adicionar: ");
      scanf("%d",&valor);
      ordenarValor(vetor,&tamAgora, valor);
    } else {
      printf("Limite do vetor atingindo, remova um valor para poder usar essa opção.");
    }

  }
  if (opcao == 5){
    break;
  }
  }while(opcao != 5);
  return 0;
}
