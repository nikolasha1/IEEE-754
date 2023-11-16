#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

double log2(double arg) {
  int x = ceil(log(arg)/log(2));
  return x;
}


int main() {
  float number;
  printf("Enter float number: ");
  scanf("%f", &number);
  printf("%zu\n", sizeof(number));

  char str[16];
  snprintf(str, sizeof(str), "%f", number);
  printf("%s\n", str);

  int len = strlen(str);
  int pointer;

  for(int i = 0; i<len; i++) {
    if(str[i] == '.') {
      pointer = i;
    }
  }

  char whole[16];
  char fraction[16];

  for(int i = 0; i<pointer; i++) {
    whole[i] = str[i];
  }
  printf("%s\n", whole);

  for(int i=(pointer+1); i<len; i++) {
    int j = i-(pointer+1);
    fraction[j] = str[i];
  }
  printf("%s\n", fraction);

  //To binary
  int whole_part = strtol(whole, NULL, 10);

  int iterations = log2(whole_part);
  printf("Iterations: %d\n", iterations);

  int *whole_binary = calloc(iterations, sizeof(int));

  if(whole_binary != NULL) {
    for(int i=(iterations-1); i>=0; i--) {
    printf("%d\n", i);
    printf("Do deleniya: %d\n", whole_part);
    *(whole_binary + i) = whole_part%2;
    printf("Ostatok ot deleniya: %d\n", *(whole_binary + i));
    printf("Posle deleniya: %d\n", whole_part/2);
    whole_part /= 2;
    }
  } else {
    return 0; 
  }
  printf("Array: \n");

  for(int i=0; i<iterations; i++) {
    printf("%d\n", *(whole_binary + i));
  }
  //FREE UP YOUR MEMORY!!!
}