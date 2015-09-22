/**

CENTRO UNIVERSITÁRIO LA SALLE - UNILASALLE
DISCIPLINA DE ESTRUTURA DE DADOS I
Semestre: 2015/2
Professor: Eder Stone Fontoura
Programador: André Kroetz Berger
	     Diógens Vargas de Bittencourt
	Samuel Guterres 

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

typedef struct Veiculo{
    int codigo;
    char placa[100];
    char marca[100];
    char modelo[100];
    int anoFab;
    float valor;
    struct Veiculo *prox;
}Veiculo;

Veiculo * cria_elemento(int codigo, char placa[100], char marca[100], char modelo[100], int anoFab, float valor){
        Veiculo *novo;
        novo = (Veiculo *) malloc(sizeof(Veiculo));
        novo->codigo = codigo;
        strcpy(novo->placa, placa);
        strcpy(novo->marca, marca);
        strcpy(novo->modelo, modelo);
        novo->valor = valor;
        novo->proximo = NULL;
        return novo;
}

//Funcao para inserir um elemento na primeira posicao da lista
//Retorna a lista com o elemento inserido como primeiro
//Função ok!!
//Copia descarada dos exercicios.
Veiculo * insere_primeiro(Veiculo * lista, Veiculo * novo){
        novo->proximo = lista;
        return novo;
}

//Insere o novo elemento na ultima posicao da lista
//Retorna a lista com o elemento inserido como ultimo
//Função ok!!
//Copia descarada dos exercicios.
Veiculo * insere_ultimo(Veiculo * lista, Veiculo * novo){
        if (lista != NULL) {
           Veiculo * aux = lista;
                   while (aux->proximo != NULL){
                         aux = aux->proximo;}
                   aux->proximo = novo;
                   return lista;}
        else{
             return novo;}
}

//Insere o novo elemento na posição da lista
//Retorna a lista com o elemento inserido na posição informada
//Função ok!!
//Copia descarada dos exercicios.
Veiculo * inserir_elemento_na_posicao(Veiculo * lista, Veiculo * novo, int posicao){
        Veiculo * aux = lista;
        int cont = 1;
        if (lista == NUL
        L){
           return novo;}
        while(aux->proximo!= NULL && cont < (posicao-1)){
                             aux = aux->proximo;
                             cont++;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        if (posicao == 1){
           return novo;}
        else{
             return lista;}
}
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






int main ()
{
    Veiculo * lista = NULL;

    int opcao;

    while(opcao != 0)
    {
        system ("CLS");
        printf ("\n\n            Bem Vindo ao Sistema TED-1-G1           \n\n");
        printf ("--------------------------------------------------------\n");
        printf ("|  Opcao 1:   Incluir Produtos - Falta concluir        |\n");
        printf ("--------------------------------------------------------\n");
              printf ("|  Opcao 2:   Consultar Produtos -OK                   |\n");
              printf ("--------------------------------------------------------\n");
              printf ("|  Opcao 3:   Excluir Produtos - OK                    |\n");
              printf ("--------------------------------------------------------\n");
              printf ("|  Opcao 4:   Listar Produto Cadastrados - OK          |\n");
              printf ("--------------------------------------------------------\n");
              printf ("|  Opcao 5:   Listar Produto de Maiogit push -u origin masterr Preco - OK       |\n");
              printf ("--------------------------------------------------------\n");
              printf ("|  Opcao 6:   Listar Produto de Menor Preco - OK       |\n");
              printf ("--------------------------------------------------------\n");
              printf ("|  Opcao 7:   Listar Media de Preco por Categoria - OK |\n");
              printf ("--------------------------------------------------------\n");
              printf ("|  Opcao 0:   Sair do Sistema                          |\n");
              printf ("--------------------------------------------------------\n\n");
              printf ("Digite a opcao desejada:");
	          scanf ("%d",&opcao);
	          switch(opcao) {
                          case 0:{
                               system("cls"); //Baita balaca
                               printf ("\n\n\n\n\n\n\n\n                        FINALIZANDO O SISTEMA AGUARDE!!!!!\n");}
                               break;
                          case 1:{   //Incrementa o código do produto automaticamente para não haver intervalos e repetições.
                               int cod_prod;
                               if (lista != NULL){
                                  Produto * ele_ult_cod = busca_ultimo_codigo(lista);
                                  cod_prod = ele_ult_cod->codigo +1;}
                               else {
                                     cod_prod = 1;}
                                system ("CLS");
                                printf ("\nO codigo do novo produto eh:  %d\n", cod_prod);
                                printf ("\nDigite a categoria do novo produto: ");
                                int categ;
                                scanf("%d",&categ);
                                printf ("\nDigite a descricao do novo produto: ");
                                char descr[35];
                                setbuf(stdin, NULL);
                                scanf ("%[a-z A-Z 0-9]s", descr);
                                setbuf(stdin, NULL);
                                printf ("\nDigite o valor do produto: ");
                                float preco;
                                scanf ("%f", &preco);
                                Produto *n = cria_elemento(cod_prod, categ, descr, preco);
                                lista = insere_ultimo(lista, n);
                                printf ("\n\nProduto cadastrado com Sucesso!!\n\n\n");
                                system ("pause");}
                                break;
                          case 2:{    //busca dados do produto pelo código.
                                printf ("\nDigite o codigo do produto a ser consultado: ");
                                int codigo_busca;
                                scanf("%d",&codigo_busca);
                                Produto * busca_cod = busca_produto_codigo(lista, codigo_busca);
                                system ("cls");
                                printf ("\n\n          DADOS DO PRODUTO CADASTRADO NO SISTEMA   \n");
                                printf("\n Dados do produto de codigo: codigo_busca\n\n");
                                printf("Codigo: %d\n", busca_cod->codigo);
	                            printf("Categoria: %d\n", busca_cod->categoria);
	                            printf("Descriao: %s\n", busca_cod->descr);
                                printf("Preco: R$%10.2f \n\n\n", busca_cod->preco);
                                system("pause");}
                                break;
                          case 3:{    //Exclui um produto pelo código.
                                printf ("\nDigite o codigo do produto a ser excluido: ");
                                int cod_prod_ex;
                                scanf("%d",&cod_prod_ex);
                                lista = remove_elemento(lista, cod_prod_ex);}
                                break;
                          case 4:{    //Apresenta a lista completa.           //Cópia descarada dos exercícios.
                                printf("\n\n");
                                apresenta_lista(lista);
                                system("pause");}
                                break;
                          case 5:{    //Busca o produto com maior preço da lista.
                                Produto * maiorpreco = maior_preco(lista);
                                system ("cls");
                                printf ("\n\n           LISTA O PRODUTO DE MAIOR PRECO  \n");
                                printf("\n O Produto de Maior preco eh: \n\n");
                                printf("Codigo: %d\n", maiorpreco->codigo);
	                            printf("Categoria: %d\n", maiorpreco->categoria);
	                            printf("Descriao: %s\n", maiorpreco->descr);
                                printf("Preco: R$%10.2f \n\n\n", maiorpreco->preco);
                                system("pause");}
                                break;
                          case 6: {   //Busca o produto de menor preço da lista.
                                Produto * menorpreco = menor_preco(lista);
                                system ("cls");
                                printf ("\n\n           LISTA O PRODUTOS DE MENOR PRECO   \n");
                                printf("\n O Produto de Menor preco eh: \n\n ");
                                printf("Codigo: %d \n", menorpreco->codigo);
	                            printf("Categoria: %d \n", menorpreco->categoria);
	                            printf("Descriao: %s \n", menorpreco->descr);
                                printf("Preco: R$%10.2f \n\n\n", menorpreco->preco);
                                system("pause");}
                                break;
                          case 7:{    //Apresenta a média de preços dos produtos de uma unica categoria.
                                float media;
                                int categ;
                                system ("cls");
                                printf ("\n\n           LISTA MEDIA DE PRECO POR CATEGORIA         \n");
                                printf ("\nDigite a categoria a ser consultada: ");
                                scanf ("%d", &categ);
                                media = media_preco(lista, categ);
                                printf ("\n\n A media de preco da categoria: %d \n", categ);
                                printf ("\n Foi de: R$ %10.2f \n", media);
                                system("pause");}
                                break;
                          default: {    //Caso no menu seja escolhido uma opção inválida.
                               printf ("\n OPCAO INVALIDA - ESCOLHA UMA DAS OPCOES DO MENU \n");
                               system("pause");}
                               break;}}
    int fim;
    while ( fim != 400000000){ //Loop usado pela balaca do final.
          fim++;}
	return(0);
}
