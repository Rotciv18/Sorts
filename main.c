#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

int main(int argc, char *argv[])
{
  FILE* file = fopen (argv[1], "r"); //abre o arquivo passado como argumento
  if (file == NULL)
  {
      printf ("Falha ao tentar ler arquivo.");
      printf (
              "Escolha qual o arquivo de entrada\n\n"
              "Selecione qual algoritmo de ordenacao usar de acordo com o menu:\n\n"
              "1: Selection Sort\n2: Insertion Sort\n3: MergeSort\n4: QuickSort\n5: HeapSort\n6: CountingSort\n");
      return 1;
  }
  int j = 0;
  int i = 0;
  int tam = 0;
  int esc = 0;
    i = 0;
    fscanf (file, "%d", &i);    //Lê o primeiro valor como número de elementos no arquivo
    tam = i;
    int array[tam];
    fscanf(file, "%d", &i);
    while (!feof (file)) //Passa os outros valores para o array
    {
      array[j] = i;
      j++;
      fscanf (file, "%d", &i);
    }
    esc = atoi(argv[2]); //converte caracter passado como argumento para inteiro
    switch (esc)
    {
        case 1:
            selectionSort(array, tam);
            break;
        case 2:
            insertionSort(array, tam);
            break;
        case 3:
            mergeSort(array, 0, (tam-1));
            break;
        case 4:
            quickSort(array, 0, (tam-1));
            break;
        case 5:
            heapSort (array, tam);
            break;
        case 6:
            countingSort (array, tam);
            break;
        default:
            printf ("Escolha invalida!\n\n"
                    "Selecione qual algoritmo de ordenacao usar de acordo com o menu:\n\n"
                    "1: Selection Sort\n2: Insertion Sort\n3: MergeSort\n4: QuickSort\n5: HeapSort\n6: CountingSort\n");
            return 1;
    }
    fclose(file);
    FILE* fooile = fopen ("saida.out", "w");
    for (i = 0; i<tam; i++){                   //Copia array para arquivo de saída
        fprintf (fooile, "%d\n", array[i]);
    }
    fclose(fooile);
    printf ("\nArquivo de saida gerado.");
}
