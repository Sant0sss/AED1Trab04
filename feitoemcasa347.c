#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_MAX 1000

int* mostFrequentElements(int* nums, int numsSize, int k, int* returnSize) {
    int* resultado = (int*)malloc(k * sizeof(int));
    int contagens[TAM_MAX + 1] = {0};
    bool emResultado[TAM_MAX + 1] = {false};

    // Conta a frequência de cada elemento no array de entrada
    for (int i = 0; i < numsSize; i++) {
        contagens[nums[i]]++;
    }

    // Encontra os k elementos mais frequentes
    for (int i = 0; i < k; i++) {
        int maxFreq = 0;
        int maxIdx = 0;

    // Itera sobre o array de entrada para encontrar o elemento mais frequente que ainda não foi colocado no resultado
        for (int j = 0; j < numsSize; j++) {
            if (contagens[nums[j]] > maxFreq && !emResultado[nums[j]]) {
                maxFreq = contagens[nums[j]];
                maxIdx = nums[j];
            }
        }
        resultado[i] = maxIdx;
        emResultado[maxIdx] = true;
    }

    *returnSize = k;
    return resultado;

}

    int main() {
    int nums[] = {1};
    int k = 1;
    int tamResultado;
    int* resultado = mostFrequentElements(nums, 1, k, &tamResultado);

    // Imprime o resultado
    printf("Resultado: [");
    for (int i = 0; i < tamResultado; i++) {
        printf("%d", resultado[i]);
        if (i < tamResultado - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(resultado);
    return 0;
}