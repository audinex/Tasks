#include <iostream>
using namespace std;

// Função para realizar a ordenação por Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Encontrar o menor elemento no array não ordenado
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}