#include <stdio.h>
#include <string.h>

#define QTD_ESTADOS 26
#define TAM_STRING 50

struct Estado{
    char nome[TAM_STRING];
    int qtdVeiculos;
    int qtdAcidentes;
};

void lerEstados(struct Estado estados[],int tam);
void coletarDados(struct Estado *estados);
void lerString(char *str,int tam);
void IndiceDeAcidente(struct Estado estados[],int tam, int *IndMaiorAci, int *IndMenorAci);
double PercentualDeAcid(struct Estado estados[],int ind);
double MediaDeAci(struct Estado estados[],int tam);
void EstadosComMediaDeAci(struct Estado estados[],int tam,double media);

int main(){
    struct Estado estados[QTD_ESTADOS];
    lerEstados(estados,QTD_ESTADOS);
    
    int IndMaiorAci=0,IndMenorAci=0;
    IndiceDeAcidente(estados,QTD_ESTADOS,&IndMaiorAci,&IndMenorAci);
    printf("\n\nO estado com o maior número de acidentes é: %s\n",estados[IndMaiorAci].nome);
    printf("Quantidade de acidentes: %d\n\n",estados[IndMaiorAci].qtdAcidentes);
    printf("O estado com o menor número de acidentes é: %s\n",estados[IndMenorAci].nome);
    printf("Quantidade de acidentes: %d\n\n",estados[IndMenorAci].qtdAcidentes);
    
    for(int indice=0;indice<QTD_ESTADOS;++indice){
            double Percentual = PercentualDeAcid(estados,indice);
            printf("Nome do Estado: %s\n",estados[indice].nome);
            printf("Percentual de acidentes: %.2f%%\n\n",Percentual);
    }
         printf("\n");
    double Media = MediaDeAci(estados,QTD_ESTADOS);
    printf("A média de acidentes no país é de: %.2f\n\n",Media);
    EstadosComMediaDeAci(estados,QTD_ESTADOS,Media);
    return 0;
}

void lerEstados(struct Estado estados[],int tam){
    for (int i=0;i<tam;++i){
        printf("Digite os dados do %dº estado\n",i+1);
        coletarDados(&estados[i]);
    }
}


void coletarDados(struct Estado *estados){
    printf("Digite o nome do Estado: ");
    lerString(estados->nome,TAM_STRING);
    printf("Digite número de veículos que circulam no estado: ");
    scanf("%d",&estados->qtdVeiculos);
    printf("Digite o número de acidentes de trânsito: ");
    scanf("%d",&estados->qtdAcidentes);
    getchar(); 
    }

void lerString(char *str,int tam){
    fgets(str,tam,stdin);
    int len = strlen(str);
    if (str[len-1] == '\n'){
        str[len-1] = '\0';
    }
}

void IndiceDeAcidente(struct Estado estados[],int tam, int *IndMaiorAci, int *IndMenorAci){
    for (int i=0;i<tam;++i){
        if (estados[*IndMaiorAci].qtdAcidentes < estados[i].qtdAcidentes){
            *IndMaiorAci = i;
        } else if (estados[*IndMenorAci].qtdAcidentes > estados[i].qtdAcidentes){
            *IndMenorAci = i;
        }
    }
}

double PercentualDeAcid(struct Estado estados[],int ind){
    double qtdAcidentes = estados[ind].qtdAcidentes;
    double qtdVeiculos = estados[ind].qtdVeiculos;
    double Percentual = (qtdAcidentes/qtdVeiculos) * 100;
    return (Percentual);
}

double MediaDeAci(struct Estado estados[],int tam){
    int Total=0;
    for (int i=0;i<tam;++i){
        Total += estados[i].qtdAcidentes;
    }
    double Media = Total/tam;
    return Media;
}

void EstadosComMediaDeAci(struct Estado estados[],int tam,double media){
    for (int i=0;i<tam;++i){
        if(estados[i].qtdAcidentes>media){
            printf("O Estado: %s tem o número de acidentes acima da média nacional\n",estados[i].nome);
        }
    }
}