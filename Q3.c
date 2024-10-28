#include <stdio.h>
#include <string.h>

#define TAM_CHAR 256
#define MAX_CONTAS 100

struct Conta{
    int num;
    char nome[TAM_CHAR];
    int cpf;
    char tel[20];
    double saldo;
};

int buscar(struct Conta contas[],int tam,int numConta);
void lerStr(char *str,int tam);
void cadastrar(struct Conta contas[],int *tam,int numConta);
void ConsuSaldo(struct Conta contas[],int tam,int numConta);
void Deposito(struct Conta contas[],int tam,int numConta);
void Saque(struct Conta contas[],int tam,int numConta);
void Exibir(struct Conta contas[],int tam);

int main(){
    struct Conta contasCorrentes[MAX_CONTAS],contasPoupanca[MAX_CONTAS];
    int tam1=0,tam2=0,numConta=0;
    int opcao;
    do{
    printf("MENU\n");
    printf("1-Buscar Conta\n");
    printf("2-Cadastrar uma nova conta\n");
    printf("3-Consultar o saldo de uma conta\n");
    printf("4-Fazer um depósito em uma conta\n");
    printf("5-Fazer um saque em uma conta\n");
    printf("6-Exibir dados de todas as contas de um determinado cadastro\n");
    printf("0-Sair\n");
    printf("Opção: ");
    scanf("%d",&opcao);
    switch(opcao){
        case 1:{
            int a;
            printf("Escolhe o tipo de conta.(1-Corrente ; 2-Poupança): ");
            scanf("%d",&a);
            printf("Informe o número da conta: ");
            scanf("%d",&numConta);
            if (a == 1){
                int a1 = buscar(contasCorrentes,tam1,numConta);
                if (a1>=0){
                    printf("Conta encontrada na posição: %d\n\n",a1);
                } else if(a1==-1){
                    printf("Não existe cadastro\n\n");
                } else{
                    printf("A conta não foi encontrada\n\n");
                }
                break;
            } else if (a == 2){
                int a2 = buscar(contasPoupanca,tam2,numConta);
                if (a2>=0){
                    printf("Conta encontrada na posição: %d\n\n",a2);
                } else if(a2==-1){
                    printf("Não existe cadastro\n\n");
                } else{
                    printf("A conta não foi encontrada\n\n");
                }
                break;
            } else{
                printf("Opção inválida!\n\n");
                break;
            }}
        case 2:
            printf("Escolhe o tipo de conta.(1-Corrente ; 2-Poupança): ");
            int b;
            scanf("%d",&b);
            printf("Informe o número da conta: ");
            scanf("%d",&numConta);
            if (b == 1){
                cadastrar(contasCorrentes,&tam1,numConta);
                break;
            } else if (b == 2){
                cadastrar(contasPoupanca,&tam2,numConta);
                break;
            } else{
                printf("Opção inválida!\n\n");
                break;
            }
        case 3:
            printf("Escolhe o tipo de conta.(1-Corrente ; 2-Poupança): ");
            int c;
            scanf("%d",&c);
            printf("Informe o número da conta: ");
            scanf("%d",&numConta);
            if (c == 1){
                ConsuSaldo(contasCorrentes,tam1,numConta);
                break;
            } else if (c == 2){
                ConsuSaldo(contasPoupanca,tam2,numConta);
                break;
            } else{
                printf("Opção inválida!\n\n");
                break;
            }
        case 4:
            printf("Escolhe o tipo de conta.(1-Corrente ; 2-Poupança): ");
            int d;
            scanf("%d",&d);
            printf("Informe o número da conta: ");
            scanf("%d",&numConta);
            if (d == 1){
                Deposito(contasCorrentes,tam1,numConta);
                break;
            } else if (d == 2){
                Deposito(contasPoupanca,tam2,numConta);
                break;
            } else{
                printf("Opção inválida!\n\n");
                break;
            }
        case 5:
            printf("Escolhe o tipo de conta.(1-Corrente ; 2-Poupança): ");
            int e;
            scanf("%d",&e);
            printf("Informe o número da conta: ");
            scanf("%d",&numConta);
            if (e == 1){
                Saque(contasCorrentes,tam1,numConta);
                break;
            } else if (e == 2){
                Saque(contasPoupanca,tam2,numConta);
                break;
            } else{
                printf("Opção inválida!\n\n");
                break;
            }
        case 6:
            printf("Escolhe o tipo de conta.(1-Corrente ; 2-Poupança): ");
            int f;
            scanf("%d",&f);
            if (f == 1){
                Exibir(contasCorrentes,tam1);
                break;
            } else if (f == 2){
                Exibir(contasPoupanca,tam2);
                break;
            } else{
                printf("Opção inválida!\n\n");
                break;
            }
        default:
            if(opcao!=0){
            printf("Opção inválida!\n\n");}
            else{
                printf("O programa será encerrado!!!\n\n");
            }
            break;
    }}while(opcao!=0);
    return 0;
}

int buscar(struct Conta contas[],int tam,int numConta){
    if (tam == 0){
        return -1;
    }
    for(int i=0;i<tam;++i){
        if (numConta==contas[i].num){
            return i;
        } 
    }
    return -2;
}

void cadastrar(struct Conta contas[],int *tam,int numConta){
    if (*tam<MAX_CONTAS){
        if(buscar(contas,*tam,numConta) >=0){
            printf("Número de conta já cadastrado\n\n");
        }else{
            contas[*tam].num = numConta;
            printf("Informe o nome do titular: ");
            getchar();
            lerStr(contas[*tam].nome,TAM_CHAR);
            printf("Informe o CPF do titular: ");
            scanf("%d",&contas[*tam].cpf);
            printf("Informe o telefone do titular: ");
            getchar();
            lerStr(contas[*tam].tel,TAM_CHAR);
            printf("Informe o saldo da conta: ");
            scanf("%lf",&contas[*tam].saldo);
            (*tam)++;
        }
    } else{
        printf("Limite de contas atingido\n\n");
    }
}

void lerStr(char *str,int tam){
    fgets(str,tam,stdin);
    int len = strlen(str);
    if (str[len-1] == '\n'){
        str[len-1] = '\0';
    }
}

void ConsuSaldo(struct Conta contas[],int tam,int numConta){
    int x = buscar(contas,tam,numConta);
    if(x>=0){
        printf("O saldo na conta é: %.2f\n\n",contas[x].saldo);
    }else{
        printf("A conta não está cadastrada\n\n");
    }
}

void Deposito(struct Conta contas[],int tam,int numConta){
    int x = buscar(contas,tam,numConta);
    double valor;
    if(x>=0){
        printf("Informe o valor a ser depositado: ");
        scanf("%lf",&valor);
        contas[x].saldo += valor;
        printf("\n\n");
    }else{
        printf("A conta não está cadastrada\n\n");
    }
}

void Saque(struct Conta contas[],int tam,int numConta){
    int x = buscar(contas,tam,numConta);
    double valor;
    if(x>=0){
        printf("Informe o valor a ser sacado: ");
        scanf("%lf",&valor);
        if (contas[x].saldo>=valor){
            contas[x].saldo -= valor;
        } else{
            printf("A conta não possui saldo suficiente!");
        }
        printf("\n\n");
    }else{
        printf("A conta não está cadastrada\n\n");
    }
}

void Exibir(struct Conta contas[],int tam){
    for (int i=0;i<tam;++i){
        printf("Número da conta do titular(%d): %d\n",i,contas[i].num);
        printf("Nome do titular(%d): %s\n",i,contas[i].nome);
        printf("Número para contado do titular(%d): %s\n\n",i,contas[i].tel);
    }
}