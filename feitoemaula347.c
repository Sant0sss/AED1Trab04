#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_MAX 1000

int* mostFrequentElements(int* nums, int numsSize, int k, int* returnSize) {
    int* resultado = (int*)malloc(k * sizeof(int));
    int contagens[TAM_MAX + 1] = {0};
    bool emResultado[TAM_MAX + 1] = {false};

    for (int i = 0; i < numsSize; i++) {
        contagens[nums[i]]++;
    }

    for (int i = 0; i < k; i++) {
        int maxFreq = 0;
        int maxIdx = 0;
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