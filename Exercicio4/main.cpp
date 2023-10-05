#include <iostream>
#include <stdlib.h>
#include <iomanip>
#define TAM 6

using namespace std;

struct aluno
{
    int ra;
    char nome[30];
    float nota;
};

aluno* leitura(int *n)
{
    cout << "Quantidade de alunos: ";
    cin >> *n;
    aluno *A;
    A = (aluno*)calloc(*n, sizeof(aluno));
    for(int i = 0; i < *n; i++)
    {
        cout << endl;
        cout << "Aluno " << i + 1 << endl;
        cout << "RA: ";
        cin >> A[i].ra;

        cout << "Nome: ";
        cin >> A[i].nome;

        cout << "Nota: ";
        cin >> A[i].nota;
    }
    return A;
}

float mediaNotas(int n, aluno *A)
{
    float media;
    for(int i = 0; i < n; i++)
        media += A[i].nota;
    return media / n;
}

void imprimirAlunos(int n, aluno *A, float media)
{
    cout << endl;
    cout << setw(20) << "-------------------" << endl;
    cout << setw(TAM) << "RA" << setw(TAM) << "NOME" << setw(TAM) << "NOTA" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "\n";
        cout << setw(TAM) << A[i].ra
             << setw(TAM) << A[i].nome
             << setw(TAM) << A[i].nota;
    }
    cout << endl;
    cout << setw(20) << "-------------------" << endl;
    cout << "MEDIA TOTAL: " << media;
}

int main()
{
    aluno *al;
    int N;
    float media;
    al = leitura(&N);
    media = mediaNotas(N, al);
    imprimirAlunos(N, al, media);

    return 0;
}
