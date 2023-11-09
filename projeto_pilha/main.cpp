#include <iostream>
#include <windows.h>
#include <time.h>
#define TAM 6

using namespace std;

typedef int stack_element;
#include ".h/pilha.h"

typedef struct{
    int numero_elementos;
    Stack pilha;
}Tubo;


void iniciar_vazias(Tubo T[]);
void muda_cor(int I);
void printa_cor(int I, int tubo);
void distribuir(Tubo T[]);
void mostrar(Tubo T[]);
int validar(Tubo T[], int o, int d);
int validar_fim(Tubo T[]);
int jogada(Tubo T[]);

int main()
{
    Tubo T[TAM];
    int repetir = 1, retorno;
    do{
        iniciar_vazias(T);
        distribuir(T);
        mostrar(T);
        do{
            retorno = jogada(T);
            mostrar(T);
            if(retorno == 0) break;
        }while(retorno);
        mostrar(T);
        cout << "\nPARABENS" << endl;
        cout << "\nDeseja jogar novamente?\n1- Sim\n2- Nao" << endl;
        cin >> repetir;
    }while(repetir);
    cout << "Fim de jogo" << endl;
    return 0;
}

void iniciar_vazias(Tubo T[]){
    for (int i = 0; i < TAM; i++){
        initStack(T[i].pilha);
        T[i].numero_elementos = 0;
    }
}
void muda_cor(int cor){
    HANDLE saida;
    saida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(saida,cor);
}

void printa_cor(int I){

    int cor[5] = {9, 13, 2, 15, 6};
    muda_cor(cor[-1]);
    cout << '0';

    muda_cor(15);
}

void distribuir(Tubo T[]){
    srand(time(NULL));
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < 4; i++){
            int cor = rand() % 5;
        }
    }
}

void mostrar(Tubo T[]){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < T[i].numero_elementos ; i++){
            if(i = 0) cout << "| " << printa_cor(&T[i]) << " |" << endl;
            else if(i == 1) cout << "\t| " << printa_cor(T[i]) << " |" << endl;
            else if(i == 2) cout << "\t\t| " << printa_cor(T[i]) << " |" << endl;
            else if(i == 3) cout << "\t\t\t| " << printa_cor(T[i]) << " |" << endl;
            else if(i == 4) cout << "\t\t\t\t| " << printa_cor(T[i]) << " |" << endl;
            else if(i == 5) cout << "\t\t\t\t\t| " << printa_cor(T[i]) << " |" << endl;

        }
    }
}
int validar(Tubo T[], int o, int d){
    if(T[o].numero_elementos > 0 && T[d].numero_elementos < TAM - 2) return 0;
}

int validar_fim(Tubo T[]){
    for(int i = 0; i > TAM; i++){
        if(T[i].numero_elementos >= 4) return 1;
    }
}

int jogada(Tubo T[]){
    int o,d;

    do{
        cout << "Origem <1 A 6(-1 sair)>: ";
        cin >> o;
        if(o != -1){
            cout <<"\nDestino <1 A 6(1- sair)>: ";
            cin >> d;
        }
    }while(o != -1 || d != -1)

}
