/**

CENTRO UNIVERSITÁRIO LA SALLE - UNILASALLE
DISCIPLINA DE ESTRUTURA DE DADOS I
Semestre: 2015/2
Professor: Eder Stone Fontoura

Desenvolver um cadastro de veículos contendo as funcionalidades descritas abaixo:

1 – Inclusão

- Criar uma função de inclusão de veículos no cadastro. A inclusão deve ser em ordem crescente de valor do veículo,
sendo responsabilidade da função manter esta ordem.
- O cada str o não pode permitir a inclusão de um veículo com placa igual a outro já existente no cadastro.

2 – Vender veículo

- Criar uma função para vender um veículo cadastrado. Deve - se solicitar ao usuário a placa doveículo que ele deseja
vender e este veículo deve ser removido fisicamente do cadastro. Exibir mensagem caso não exista um veículo com a placa especificada.

3 – Valor total

- Criar função para exibir o valor total em veículos cadastrados.

4 – Listar veículos cadastrados.

5 – No menu, ao lado da opção para cadastro de um veículo, deve estar sempre visível a quantidade de veículos existente no cadastro.

6 – No menu, ao lado da opção para venda de veículo, deve estar sempre visível o valor total em veículos vendidos no dia.

Observações Importantes:

1º) Deve - se utilizar lista de encadeamento simples ou duplo.
2º) O programa deve apresentar um menu ao usuário contendo todas as opções disponíveis para o usuário.

CENTRO UNIVERSITÁRIO LASALLE - ESTRUTURA DE DADOS 1

**/
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

typedef struct veiculo{
    int codigo;
    char placa[100];
    char marca[100];
    char modelo[100];
    int anoFab;
    float valor;
    struct veiculo *prox;
}veiculo;

Veiculo * cria_elemento(int codigo, char placa[100], char marca[100], char modelo[100], int anoFab, float valor){
        Veiculo *novo;
        novo = (Veiculo *) malloc(sizeof(Veiculo));
        novo->codigo = codigo;
        novo->categoria = categoria;
        strcpy (novo->descr, descr);
        novo->preco = preco;
        novo->proximo = NULL;
        return novo;
}

//Funcao para inserir um elemento na primeira posicao da lista
//Retorna a lista com o elemento inserido como primeiro
//Função ok!!
//Copia descarada dos exercicios.
Produto * insere_primeiro(Produto * lista, Produto * novo){
        novo->proximo = lista;
        return novo;
}

//Insere o novo elemento na ultima posicao da lista
//Retorna a lista com o elemento inserido como ultimo
//Função ok!!
//Copia descarada dos exercicios.
Produto * insere_ultimo(Produto * lista, Produto * novo){
        if (lista != NULL) {
           Produto * aux = lista;
                   while (aux->proximo != NULL){
                         aux = aux->proximo;}
                   aux->proximo = novo;
                   return lista;}
        else{
             return novo;}}

//Insere o novo elemento na posição da lista
//Retorna a lista com o elemento inserido na posição informada
//Função ok!!
//Copia descarada dos exercicios.
Produto * inserir_elemento_na_posicao(Produto * lista, Produto * novo, int posicao){
        Produto * aux = lista;
        int cont = 1;
        if (lista == NULL){
           return novo;}
        while(aux->proximo!= NULL && cont < (posicao-1)){
                             aux = aux->proximo;
                             cont++;}
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        if (posicao == 1){
           return novo;}
        else{
             return lista;}}







/** FUNÇÃO PARA LISTAR VEICULOS CADASTRADOS **/
void show_veiculo(veiculo * lista){
  //Percorrendo os elementos da lista
  veiculo * aux = lista;
  printf("<-- VEICULOS CADASTRADOS -->\n\n");
    while(aux != NULL){
        printf("Código: %d \n", aux->codigo);
        printf("Placa: %s \n", aux->placa);
        printf("Marca: %s \n", aux->marca);
        printf("Modelo: %s \n", aux->modelo);
        printf("Ano Fabricacao: %d \n", aux->anoFab);
        printf("Valor Veiculo: R$ %.2f \n", aux->valor);
        printf("\n");
        aux = aux->prox;
    }
}
/** FUNÇÃO PARA BUSCAR VEICULOS **/
veiculo * buscar_veiculo(veiculo * inicio, char placa[])
{
    veiculo * aux = inicio;
    while(aux != NULL){

        if(strcmp(aux->placa,placa) == 0)
        {

            printf("Código: %d \n", aux->codigo);
            printf("Placa: %s \n", aux->placa);
            printf("Marca: %s \n", aux->marca);
            printf("Modelo: %s \n", aux->modelo);
            printf("Ano Fabricacao: %d \n", aux->anoFab);
            printf("Valor Veiculo: R$ %.2f \n", aux->valor);
            printf("\n");
            return aux;
        }
        aux = aux->prox;
    }
    printf("Veiculo nao encontrado!");
    return NULL;
}
