#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
int maximum(int * array, int n){

  int i = 0;
  int max = 0;

  for(i = 0; i < n; i++){
    if(array[i] > max){ max = array[i]; }
  }

  return max;
}



#endif // FUNCOES_H_INCLUDED
