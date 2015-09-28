/**

CENTRO UNIVERSITÁRIO LA SALLE - UNILASALLE
DISCIPLINA DE ESTRUTURA DE DADOS I
Semestre: 2015/2
Professor: Eder Stone Fontoura
Programador:    André Kroetz Berger
                Diógenes Vargas de Bittencourt
                Mauricio Lessa
                Paulo Lopes
                Samuel Guterres

Desenvolver um cadastro de veículoscontendo as funcionalidades descritas abaixo:

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
#include<string.h>

typedef struct Veiculo{
    int codigo;
    char placa[100];
    char marca[100];
    char modelo[100];
    int anoFab;
    float valor;
    struct Veiculo *prox;
    struct veiculo *proximo;
}Veiculo;

Veiculo * cria_elemento(int codigo, char placa[100], char marca[100], char modelo[100], int anoFab, float valor){
        Veiculo *novo;
        novo = (Veiculo *) malloc(sizeof(Veiculo));
        novo->codigo = codigo;
        strcpy(novo->placa, placa);
        strcpy(novo->marca, marca);
        strcpy(novo->modelo, modelo);
        novo->anoFab = anoFab;
        novo->valor = valor;
        novo->proximo = NULL;
        return novo;
}

//Funcao para inserir um elemento na primeira posicao da lista
//Retorna a lista com o elemento inserido como primeiro
//Função ok!!
Veiculo * insere_primeiro(Veiculo * lista, Veiculo * novo){
        novo->proximo = lista;
        return novo;
}
//Insere o novo elemento na ultima posicao da lista
//Retorna a lista com o elemento inserido como ultimo
//Função ok!!
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
Veiculo * inserir_elemento_na_posicao(Veiculo * lista, Veiculo * novo, int posicao){
        Veiculo * aux = lista;
        int cont = 1;
        if (lista == NULL){
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
/** FUNÇÃO PARA REMOVER VEICULO **/
Veiculo * remove_elemento(Veiculo * lista, int posicao){
      Veiculo * aux = lista;
      Veiculo * remove = NULL;
      int cont = 1;
      if (lista == NULL){ //se lista está vazia
         return NULL;
      }
      while(aux->proximo != NULL && cont < (posicao-1)){
        aux = aux->proximo;
        cont++;
      }
      // se eh a segunda posicao entao so deve atualizar o cont
      if (posicao == 2){
         cont++;
      }
      // Testa se a remoção é o primeiro da lista.
      // Neste caso, existem duas possibilidades: (a) ter mais de um na lista.
      //                                          (b) ser o unico na lista.
      // Quando for mais de um, atualizar a lista para o novo primeiro.
      if (cont == 1){
           if (aux->proximo != NULL){
              lista = aux->proximo;
            } // atualiza o inicio.
           else{
              lista = NULL;
            }     // caso só exista na lista o proprio a ser removido
           free(aux);
        }
      else {
            remove = aux->proximo;
            aux->proximo = remove->proximo;
            free(remove);
        }
      return lista;
}
/** FUNÇÃO PARA LISTAR VEICULOS CADASTRADOS **/
void show_veiculo(Veiculo * lista){
  //Percorrendo os elementos da lista
  Veiculo * aux = lista;
  printf("<-- VEICULOS CADASTRADOS -->\n\n");
    while(aux != NULL){
        printf("Codigo: %d \n", aux->codigo);
        printf("Placa: %s \n", aux->placa);
        printf("Marca: %s \n", aux->marca);
        printf("Modelo: %s \n", aux->modelo);
        printf("Ano Fabricacao: %d \n", aux->anoFab);
        printf("Valor Veiculo: R$ %.2f \n", aux->valor);
        printf("\n");
        aux = aux->proximo;
    }
}
/** FUNÇÃO PARA LISTAR VEICULOS CADASTRADOS RESUMIDO **/
void show_veiculo2(Veiculo * lista){
  //Percorrendo os elementos da lista
  Veiculo * aux = lista;
  printf("<-- VEICULOS CADASTRADOS -->\n\n");
    while(aux != NULL){
        printf("Codigo: %d \n", aux->codigo);
        printf("Placa: %s \n", aux->placa);
        printf("\n");
        aux = aux->proximo;
    }
}
/** FUNÇÃO PARA BUSCAR VEICULOS **/
Veiculo * buscar_veiculo(Veiculo * inicio, char placa[])
{
    Veiculo * aux = inicio;
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
        aux = aux->proximo;
    }
    printf("Veiculo nao encontrado!");
    return NULL;
}
/* Verificar e adicionar no inicio do menu o campo para receber o valor */
/*Veiculo * contar_veiculo(Veiculo * inicio, int contar){
Veiculo * aux = inicio;
    while(aux!= NULL){
     contar = contar + 1;
    printf("Total: %d", contar);
   }
}
*/
void contar_veiculo(Veiculo * inicio, int contar){
Veiculo * aux = inicio;
    while(aux!= NULL){
     contar = contar + 1;
     printf("Total: %d", contar);
   }
}
int main()
{
    Veiculo * lista = NULL;

    int opcao;
    int codigo;
    char placa[100];
    char marca[100];
    char modelo[100];
    int anoFab;
    float valor;

    while(opcao != 0)
    {
        system ("CLS");
        printf ("\n\n       Seja Bem Vindos a Loka Dora Aventureira        \n\n");
        printf ("------------------------------------------------------------\n");
        printf ("|  Opcao 1:   Incluir Veiculo                              |\n");
        printf ("------------------------------------------------------------\n");
        printf ("|  Opcao 2:   Vender Veiculo                               |\n");
        printf ("------------------------------------------------------------\n");
        printf ("|  Opcao 3:   Excluir Veiculo                              |\n");
        printf ("------------------------------------------------------------\n");
        printf ("|  Opcao 4:   Listar Veiculos                              |\n");
        printf ("------------------------------------------------------------\n");
        printf ("|  Opcao 5:   Mostrar valor total em Veiculos cadastrados  |\n");
        printf ("------------------------------------------------------------\n");
        printf ("|  Opcao 0:   Sair do Sistema                              |\n");
        printf ("------------------------------------------------------------\n");
        printf ("Digite a opcao desejada: ");
        scanf ("%d",&opcao);

        switch(opcao)
        {
            case 0:
            {
                system("cls"); //Baita balaca
                printf ("\n\n\n\n\n\n\n\n                        FINALIZANDO O SISTEMA AGUARDE!!!!!\n");
            }
            break;
            case 1:
            {   //Incrementa o código do produto automaticamente para não haver intervalos e repetições.
               /** int cod_prod;

                if (lista != NULL)
                {
                    Veiculo * ele_ult_cod = busca_ultimo_codigo(lista);
                    cod_prod = ele_ult_cod->codigo +1;
                }else{
                    cod_prod = 1;
                }
                system ("CLS");

                printf ("\nO codigo do novo produto eh:  %d\n", cod_prod);
                **/
                printf("Cod do Veiculo: ");
                scanf("%d",&codigo);
                fflush(stdin);
                printf("\nPlaca do Veiculo: ");
                gets(placa);
                fflush(stdin);
                printf("\nDigite a marca do veiculo: ");
                gets(marca);
                fflush(stdin);
                printf("\nDigite o modelo do veiculo: ");
                gets(modelo);
                fflush(stdin);
                printf("\nDigite o Ano de Faricacao do Veiculo: ");
                scanf("%d",&anoFab);
                printf("\nDigite o valor do veiculo: ");
                scanf("%f",&valor);

                Veiculo *n = cria_elemento(codigo, placa, marca, modelo, anoFab, valor);
                lista = insere_ultimo(lista, n);
                printf ("\n\nVeiculo cadastrado com Sucesso!!\n\n\n");
                system ("pause");
            }
            break;
    /**
            case 2:
            {    //busca dados do produto pelo código.
                printf ("\nDigite o codigo do produto a ser consultado: ");
                int codigo_busca;
                scanf("%d",&codigo_busca);
                Veiculo * busca_cod = busca_produto_codigo(lista, codigo_busca);
                system ("cls");
                printf ("\n\n          DADOS DO PRODUTO CADASTRADO NO SISTEMA   \n");
                printf("\n Dados do produto de codigo: codigo_busca\n\n");
                printf("Codigo: %d\n", busca_cod->codigo);
                printf("Categoria: %d\n", busca_cod->categoria);
                printf("Descriao: %s\n", busca_cod->descr);
                printf("Preco: R$%10.2f \n\n\n", busca_cod->preco);
                system("pause");
            } **/
            break;
            case 3:
            {
            //Exclui um veiculo pelo codigo
                show_veiculo2(lista);
                fflush(stdin);
                printf("%d", codigo);
                printf ("\nDigite o codigo do veiculo a ser excluido ou 0 para voltar ao menu: ");
                int codigo;
                scanf("%d",&codigo);
                lista = remove_elemento(lista, codigo);
            }
            break;
            case 4:
            {   //Apresenta a lista completa.           //Cópia descarada dos exercícios.
                printf("\n\n");
                show_veiculo(lista);
                system("pause");
            }
            break;
        /** case 5:
            {   //Busca o produto com maior preço da lista.
                Produto * maiorpreco = maior_preco(lista);
                system ("cls");
                printf ("\n\n           LISTA O PRODUTO DE MAIOR PRECO  \n");
                printf("\n O Produto de Maior preco eh: \n\n");
                printf("Codigo: %d\n", maiorpreco->codigo);
                printf("Categoria: %d\n", maiorpreco->categoria);
                printf("Descriao: %s\n", maiorpreco->descr);
                printf("Preco: R$%10.2f \n\n\n", maiorpreco->preco);
                system("pause");
            }
            break;
            case 6:
            {   //Busca o produto de menor preço da lista.
                Produto * menorpreco = menor_preco(lista);
                system ("cls");
                printf ("\n\n           LISTA O PRODUTOS DE MENOR PRECO   \n");
                printf("\n O Produto de Menor preco eh: \n\n ");
                printf("Codigo: %d \n", menorpreco->codigo);
                printf("Categoria: %d \n", menorpreco->categoria);
                printf("Descriao: %s \n", menorpreco->descr);
                printf("Preco: R$%10.2f \n\n\n", menorpreco->preco);
                system("pause");
            }
            break;
            **/
            case 5:
            {   //Apresenta a média de preços dos produtos de uma unica categoria.

            }
            break;
            default:
            {   //Caso no menu seja escolhido uma opção inválida.
                printf ("\n OPCAO INVALIDA - ESCOLHA UMA DAS OPCOES DO MENU \n");
                system("pause");
            }
            break;
        }
    }
    int fim;
    while ( fim != 400000000)
    { //Loop usado pela balaca do final.
          fim++;
    }
	return(0);
}
