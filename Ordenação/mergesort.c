#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort(int *v, int tam);
void dividir(int *v, int i, int f, int tam);
void conquistar(int *v, int i, int f, int m, int tam);

int main()
{
    int i, f, tam, *v;
    scanf("%d",&tam);
    for (i = 0; i < tam; i++)
    {
        scanf("%d",&v[i]);
    }
    mergeSort(v, tam-1);
    printf("|");
    for (i = 0; i < tam; i++)
    {
        printf(" %d", v[i]);
    }
    printf(" |\n");
    return 0;
}

void mergeSort(int *v, int tam)
{
    dividir(v, 0, tam, tam);
}

void dividir(int *v, int i, int f, int tam)
{
    int m;
    if (i < f)
    {
        m = (i + f) / 2;
        dividir(v, i, m, tam);
        dividir(v, m + 1, f, tam);
        conquistar(v, i, f, m, tam);
    }
}

void conquistar(int *v, int i, int f, int m, int tam)
{
    int *vAux, in = i, fim = f, mid = m + 1, cont = 0, k;
    vAux = malloc(f - i + 1 * sizeof(int));
    while ((in <= fim) && (mid <= f))
    {
        if (v[in] > v[mid])
        {
            vAux[cont] = v[mid];
            mid++;
        }
        else
        {
            vAux[cont] = v[in];
            in++;
        }
        cont++;
    }
    while (in <= mid)
    {
        vAux[cont] = v[in];
        in++;
        cont++;
    }
    while (mid <= f)
    {
        vAux[cont] = v[mid];
        mid++;
        cont++;
    }
    for (k = i, cont = 0; k <= f; ++k, cont++)
    {
        v[k] = vAux[cont];
    }
    free(vAux);
}