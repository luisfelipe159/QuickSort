/*
Escolha um pivô: selecione um elemento da matriz como pivô. A escolha do pivô pode variar 
(por exemplo, primeiro elemento, último elemento, elemento aleatório ou mediana).

Particione o Array usando Hoare's partition scheme: Reorganize o array em torno do pivô. Após o particionamento, 
todos os elementos menores que o pivô estarão à sua esquerda e todos os elementos maiores 
que o pivô estarão à sua direita. O pivô estará então em sua posição correta e obtemos o índice do pivô.



Chamada recursiva: aplique recursivamente o mesmo processo aos dois subarrays particionados (esquerda e direita do pivô).

Caso base: a recursão paara quando há apenas um elemento restante na submatriz, pois um único elemento já está classificado.
*/




#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;


// Esta função toma o primeiro elemento como pivô, coloca o elemento pivô em sua posição correta 
// posiciona na matriz classificada e coloca todos os elementos menores (menores que o pivô) 
// à esquerda do pivô e todos os elementos maiores à direita
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {

        // Encontre o elemento mais à esquerda maior ou igual ao pivô
        do {
            i++;
        } while (arr[i] < pivot);

        // Encontre o elemento mais à direita menor ou igual ao pivô
        do {
            j--;
        } while (arr[j] > pivot);

        // Se os dois ponteiros se cruzam
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

// Gera o Pivô Aleatório, troca o pivô pelo elemento low e chama a função de partição 
// Na partição Hoare o elemento low é selecionado como primeiro pivô
int partition_r(int arr[], int low, int high)
{
   
    srand(time(NULL));
    int random = low + rand() % (high - low);

  
    swap(arr[random], arr[low]);

    return partition(arr, low, high);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition_r(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

// Imprime um array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5, 14, 17, 22, 54, 53, 67, 54, 87, 3, 98};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Array Ordenado: \n");
    printArray(arr, n);
    return 0;
}