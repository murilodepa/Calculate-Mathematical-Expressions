/* DESCRIÇÃO DO PROGRAMA: PROGRAMA REALIZA OPERAÇÕES ALGÉBRICAS COM O AUXILIO DA PILHA
                          FUNCIONANDO CORRETAMENTE CONFORME AS LEIS MATEMÁTICAS E INTERFERÊNCIA
                          DE PARENTES, POIS TEM PRIORIDADE. SEMPRE QUE DIGITADO A EXPRESSÃO, O
                          PROGRAMA VERIFICA SE A OPERAÇÃO É VÁLIDA, SE NÃO, RETORNA QUAL O ERRO COMETIDO.


            PONTIFÍCIA UNIVERSIDADE CATÓLICA DE CAMPINAS
            NOME DO ALUNO: MURILO DE PAULA ARAUJO
            RA: 17747775                       DATA DE ENTREGA: 17/05/2019
            PROFESSORA: ÂNGELA DE MENDONÇA ENGELBRECHT
            CURSO: ENGENHARIA DE COMPUTAÇÃO     PERÍODO: 3º SEMESTRE
            DISCIPLINA CURRICULAR: ALGORÍTMOS E PRGRAMAÇÃO DE COMPUTADORES B

                    TRABALHO QUE REALIZA CONTAS ALGÉBRICAS UTILIZANDO PILHA
*/

//############################ BIBLIOTECAS E DEFINEs ############################
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

using namespace std;

#define Vermelho 12      //12 ou 4
#define Cor_Das_Grades 9 //9 ou 1
#define Verde 10
#define Branco 15
//###############################################################################

//######################## UTILIZANDO A BIBLIOTECA PILHA ########################
typedef int stack_element;
#include "stackld-1.h"
//###############################################################################

//########## DECLARAÇÃO DA STRUCT TERMO, COM CAMPOS DE VARIAVEL E VALOR ##########
struct termo  // Declarando a variável termo do tipo struct
{
    char variavel; // Declarando o campo variavel como char
    int valor;    // Declarando o campo valor como int
};

typedef struct termo elemento; // Declarando a variável elemento do tipo termo
//###############################################################################

//############### DECLARAÇÃO DA STRUCT NOS, COM CAMPO INFO E LINK ###############
struct nos
{
    elemento info;
    struct nos* link;
};

typedef struct nos nos; // Declarando a variável nos, do tipo nos
//###############################################################################

//################## PROTÓTIPO DAS FUNÇÕES UTILIZADAS NA MAIN ###################

// FUNÇÃO PARA MUDAR A COR DOS CARÁCTERES IMPRESSOS
void Muda_Cor (int);

// Retorna null, para inicializar minha lista ligada vazia
nos* criar_vazia();

// Verificar predominância entre os operandos e respeitas as leis da matemática
int hierarquia(char);

// Inserir valor na minha lista, primeiramente só no campo variável, e depois só os valores das variáveis
void inserir_var_lista(nos **, char);

// Lendo os valores que foi preenchido na lista ligada e imprimindo para o usuário
void ler_valores(nos **);

// Verifico se a variável já foi setado o seu valor, para não ficar pedindo para o usuário digitar novamente
int buscar_valor(nos *, char);

// Realiza o cálculo da equação utilizando pilha
int calcular_equacao(nos*, char[]);

// Transforma a equação infixa como estamos acostumados, para pós fixa
void transformar_in_pos(char [], char [], nos **);

// Realiza a leitura da expressão e armazena em um vetor de caractéres
void leitura(char []);

// Verifica se os parentes estão formatados corretamente, se não retorna qual o erro encontrado
int verificar_parenteses_e_numeros(char []);

// Imprime a mensagem na tela de qual erro foi encontrado
int imprime_mensagem_erro (int);

// Imprime a expressão algébrica digita no formato INFIXA E PÓS-FIXA
void imprimir(char [],char []);
//###############################################################################

//#################################### MAIN #####################################
int main()
{
    nos *Lista;

    Lista = criar_vazia();

    int erro;
    int mensagem;
    int Resultado;

    char in[50], pos[50];

    do
    {
        leitura(in);
        erro = verificar_parenteses_e_numeros(in);
        mensagem = imprime_mensagem_erro(erro);
    }
    while (mensagem != 0);

    transformar_in_pos(in, pos, &Lista);
    ler_valores(&Lista);

    imprimir(in, pos);

    Resultado = calcular_equacao(Lista, pos);

    Muda_Cor(Verde);
    cout << endl << endl << " O RESULTADO DA EXPRESSAO: ";
    Muda_Cor(Vermelho);
    cout << Resultado << endl << endl << endl;
    Muda_Cor(Branco);
}
//###############################################################################

// Mudar a cor dos carácteres impressos
void Muda_Cor (int cor)
{
    /*
    0 = Preto		8 = Cinza
    1 = Azul		9 = Azul Claro
    2 = Verde		10 = Verde Claro
    3 = Verde-Agua	11= Verde-Agua Claro
    4 = Vermelho	12 = Vermelho Claro
    5 = Roxo		13 = Lilas
    6 = Amarelo		14 = Amarelo Claro
    7 = Branco		15 = Branco Brilhante
    */
    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Saida,cor);
}
//###############################################################################

// Retorna null, para inicializar minha lista ligada vazia
nos* criar_vazia()
{
    return NULL;
}
//###############################################################################

// Verificar predominância entre os operandos e respeitas as leis da matemática
int hierarquia(char c)
{
    switch(c)
    {
    case '(':
        return 0;

    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;
    }
    return 0;
}
//###############################################################################

// Inserir valor na minha lista, primeiramente só no campo variável, e depois só os valores das variáveis
void inserir_var_lista(nos **Lista, char var)
{
    int aux=1;
    nos* pri, *novo;

    pri = *Lista;

    novo = (nos*) malloc(sizeof(nos));

    novo->info.variavel=var;
    novo->info.valor=0;
    novo->link=NULL;

    aux=1;

    if((*Lista) == NULL)
    {
        (*Lista) = novo;
    }

    else
    {
        aux=1;

        while(pri!=NULL)
        {
            if(pri->info.variavel == var)
            {
                aux=0;
            }

            if(aux==1 && pri->link==NULL)
            {
                pri->link=novo;
            }

            pri=pri->link;
        }
    }

    pri = *Lista;
}
//###############################################################################

// Lendo os valores que foi preenchido na lista ligada e imprimindo para o usuário
void ler_valores(nos **Lista)
{
    nos* pri;

    pri = *Lista;

    cout << endl;

    while((pri) != NULL)
    {
        Muda_Cor(Verde);
        cout <<" DIGITE O VALOR DE " << (pri)->info.variavel << ": ";
        Muda_Cor(Branco);
        cin >> (pri)->info.valor;
        pri=pri->link;
    }

    pri = *Lista;

    while(pri!=NULL)
    {
        Muda_Cor(Cor_Das_Grades);
        cout << "\n A VARIAVEL (" << pri->info.variavel << ") RECEBEU O VALOR: ";
        Muda_Cor(Vermelho);
        cout << pri->info.valor;
        pri=pri->link;
    }
}
//###############################################################################

// Verifico se a variável já foi setado o seu valor, para não ficar pedindo para o usuário digitar novamente
int buscar_valor(nos *Lista, char c)
{
    while(Lista!=NULL)
    {
        if(c == Lista->info.variavel)
            return Lista->info.valor;

        Lista=Lista->link;
    }
    return (-1);
}

// Realiza o cálculo da equação utilizando pilha
int calcular_equacao(nos*Lista, char pos[])
{
    Stack P;
    initStack(P);

    int i=0;
    stack_element valor;
    stack_element op1;
    stack_element op2;
    stack_element res;

    while(pos[i]!='\0')
    {
        if(isalpha(pos[i]))
        {
            valor = buscar_valor(Lista, pos[i]);
            push(P, valor);
        }

        else
        {
            op1 = pop(P);
            op2 = pop(P);

            switch(pos[i])
            {
            case '+':
                res = op2+op1;
                break;

            case '-':
                res = op2-op1;
                break;

            case '*':
                res = op2*op1;
                break;

            case '/':
                res= op2/op1;
                break;
            }

            push(P, res);

        }
        i=(i+1);
    }

    return res;
}
//###############################################################################

// Transforma a equação infixa como estamos acostumados, para pós fixa
void transformar_in_pos(char in[], char pos[], nos **Lista)
{
    Stack P;
    initStack(P);
    stack_element V;

    int i;
    int k=0;

    for(i=0; in[i] != '\0'; i++)
    {
        if(!isspace(in[i]))
        {
            if(isalpha(in[i]))
            {
                inserir_var_lista(Lista, in[i]);
                pos[k++]=in[i];
            }
            else
            {
                if(in[i]=='(')
                {
                    V = '(';
                    push(P,V);
                }
                else
                {
                    if(in[i]==')')
                    {
                        while(peek(P)!='(')
                        {
                            pos[k++] = pop(P);
                        }
                        pop(P); //Descartando o '('
                    }
                    else
                    {

                        while(!isEmpty(P) && hierarquia(in[i]) <= hierarquia(peek((P))))
                        {
                            pos[k++] = pop(P);
                        }
                        push(P, in[i]);
                    }
                }
            }
        }
    }

    while(!isEmpty(P)) // Enquanto for diferente de vazia
    {
        pos[k++] = pop(P);
    }
    pos[k] = '\0';
}
//###############################################################################

// Realiza a leitura da expressão e armazena em um vetor de caractéres
void leitura(char in[])
{
    // printf("\n DIGITE UMA EXPRESSAO MATEMATICA(SOMENTE LETRAS): ");
    // scanf(" %[^\n]", in);

    Muda_Cor(Verde);
    cout << endl <<  " DIGITE UMA EXPRESSAO MATEMATICA (SOMENTE LETRAS OU PARENTESES): ";
    Muda_Cor(Branco);
    cin >> in;
}
//###############################################################################

// Verifica se os parentes estão formatados corretamente, se não retorna qual o erro encontrado
int verificar_parenteses_e_numeros (char in[])
{
    int i=0;
    Stack P;
    initStack (P);

    while(in[i]!='\0')
    {
        if(in[i] == '(')
        {
            push (P,in[i]);
        }
        else
        {
            if(in[i] == ')')
            {
                if(!isEmpty(P))
                {
                    pop (P);
                }
                else
                    return 1;     // ERRO FALTA DE ABERTURA DE PARENTESES
            }
            else
            {
                if(isdigit(in[i]))
                {
                    return 3; // ERRO FOI DIGITADO NUMERO NA EXPRESSAO
                }
            }
        }

        i++;
    }

    if(!isEmpty(P))
    {
        return 2; // ERRO FALTA FECHAMENTO DE PARENTESES;
    }
    else
        return 0; // EXPRESSAO MATEMATICA DIGITADA CORRETAMENTE
}
//###############################################################################

// Imprime a mensagem na tela de qual erro foi encontrado
int imprime_mensagem_erro (int x)
{
    int j=0;

    switch (x)
    {
    case 0:
        Muda_Cor(Cor_Das_Grades);
        cout << "\n    \332\304";
        for(j=0; j<5; j++)
            cout << "\304\304\304\304\304\304\304\304";
        cout << "\277\n    \263    ";

        Muda_Cor(Vermelho);
        cout << " A EXPRESSAO DIGITADA EH VALIDA!";

        Muda_Cor(Cor_Das_Grades);
        cout << "     \263\n    \300\304";
        for(j=0; j<5; j++)
            cout << "\304\304\304\304\304\304\304\304";
        cout << "\331" << endl;
        return 0;

    case 1:
        Muda_Cor(Cor_Das_Grades);
        cout << "\n \332\304";
        for(j=0; j<5; j++)
            cout << "\304\304\304\304\304\304\304\304\304\304";
        cout << "\304\304\277\n \263";

        Muda_Cor(Vermelho);
        cout << " ERRO: FALTA DE ABERTURA DE PARENTESES NA EXPRESSAO!";
        Muda_Cor(Cor_Das_Grades);
        cout << " \263\n \300\304";
        for(j=0; j<5; j++)
            cout << "\304\304\304\304\304\304\304\304\304\304";
        cout << "\304\304\331" << endl;
        return 1;

    case 2:
        Muda_Cor(Cor_Das_Grades);
        cout << "\n \332\304";
        for(j=0; j<5; j++)
        cout << "\304\304\304\304\304\304\304\304\304\304";
        cout << "\304\304\304\304\277\n \263";

        Muda_Cor(Vermelho);
        cout << " ERRO: FALTA DE FECHAMENTO DE PARENTESES NA EXPRESSAO!";
        Muda_Cor(Cor_Das_Grades);
        cout << " \263\n \300\304";
        for(j=0; j<5; j++)
        cout << "\304\304\304\304\304\304\304\304\304\304";
        cout << "\304\304\304\304\331" << endl;
        return 2;

    case 3:
        Muda_Cor(Cor_Das_Grades);
        cout << "\n \332\304";
        for(j=0; j<5; j++)
        cout << "\304\304\304\304\304\304\304\304\304\304\304\304";
        cout << "\304\304\304\304\277\n \263";

        Muda_Cor(Vermelho);
        cout << " ERRO: POR FAVOR, DIGITE APENAS LETRAS, NA EXPRESSAO MATEMATICA!";
        Muda_Cor(Cor_Das_Grades);
        cout << " \263\n \300\304";
        for(j=0; j<5; j++)
        cout << "\304\304\304\304\304\304\304\304\304\304\304\304";
        cout << "\304\304\304\304\331" << endl;
        return 3;
    }
    return 0;
}
//###############################################################################

// Imprime a expressão algébrica digita no formato INFIXA E PÓS-FIXA
void imprimir(char in[],char pos[])
{
    Muda_Cor(Cor_Das_Grades);
    cout << endl << endl << " EXPRESSAO INFIXA: ";
    Muda_Cor(Vermelho);
    cout << in;
    Muda_Cor(Cor_Das_Grades);
    cout << endl << " EXPRESSAO POS-FIXA: ";
    Muda_Cor(Vermelho);
    cout << pos;
}
//###############################################################################
