#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED
#include "funcoes.h"
/*######################################
########### SELECTION SORT ###########*/
void selectionSort(int num[], int tam)
{
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min])
         min = j;
     }
     if (i != min) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}


/*############################################
############## INSERTION SORT ##############*/
int * insertionSort(int original[], int length) {
	int i, j, atual;

	for (i = 1; i < length; i++) {
		atual = original[i];
		j = i - 1;

		while ((j >= 0) && (atual < original[j])) {
			original[j + 1] = original[j];
			j = j - 1;
		}

		original[j + 1] = atual;
	}

	return (int * )original;
}

/*#########################################################
################### MERGE SORT ##########################*/
void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;

    if(posicaoInicio == posicaoFim) return;


    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);


    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) {
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}


/*##########################################
################ QUICK SORT ##############*/
void quickSort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quickSort(a, left, j);
    }
    if(i < right) {
        quickSort(a, i, right);
    }
}


/*###########################
######## COUNTINGSORT #######*/
void countingSort(int * vetor, int n){

  int i = 0;
  int offset = 0;
  //int max = maximum(vetor, n);
  int maxi = 0;
  for (i = 0; i < n; i++){   //Checa o menor número negativo e guarda
    if (vetor[i] < offset)
        offset = vetor[i];
  }

  offset = offset * -1;

  for (i = 0; i < n; i++){   //Soma TODOS os elementos com o offset para evitar que existam números negativos
    vetor[i] = vetor[i] + offset;
  }

  for(i = 0; i < n; i++){
    if(vetor[i] > maxi){
      maxi = vetor[i];
      }
  }
  i = 0;
  int * counting_array = calloc(maxi, sizeof(int)); // Zera todo o vetor
  //printf ("%d\n", maxi);
  for(i = 0; i < n; i++){
    counting_array[vetor[i]]++;
  }
  int num = 0;
  i = 0;
  while(i <= n){
    while(counting_array[num] > 0){
      vetor[i] = num - offset; // '- offset' para retornar os valores ao "normal" (com números negativos)
      counting_array[num]--;
      i++;
      if(i > n){ break; }
    }
    num++;
  }
 /* for (i = 0; i < n; i++){   //Soma TODOS os elementos com o offset para evitar que existam números negativos
    vetor[i] = vetor[i] - offset;
  }*/
}

/*###########################
######## HEAPSORT #########*/
void heapSort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}
#endif // SORTS_H_INCLUDED
