#include <iostream>
#include <stdlib.h>

using namespace std;

float *lerVetor(int *n)
{
    cout << "Quantidade de elementos: ";
    cin >> *n;

    float *val = (float*)calloc(*n, sizeof(float));

    for (int i = 0; i < *n; i++)
    {
        cout << "Float do elemento na posicao " << i + 1 << ": ";
        cin >> val[i];
    }
    return val;
}

void encontraP(int n, float *Pmaior, float *Pmenor, float val)
{

    for (int i = 1; i < n; i++)
    {
        if (val[i] > *Pmaior)
            *Pmaior = val[i];

        else if (val[i] < *Pmenor)
            *Pmenor = val[i];

    }

    cout << "Maior numero: " << *Pmaior << endl;
    cout << "Menor numero: " << *Pmenor << endl;
}

int main()
{
    int N;
    float *Pmaior, *Pmenor;
    float *val = lerVetor(&N);
    encontraP(N, &Pmaior, &Pmenor, val);

    return 0;
}
