/*
A - scrivere la seguente funzione:

implementare una funzione che calcola la serie di Fibonacci:

unsigned long fibonacci(unsigned int n);

dove:
fibonacci(0) = 0
fibonacci(1) = 1
fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)  per n > 1

provare a scoprire quale è il valore massimo di n per cui fibonacci(n) restituisce un valore della serie corretto


B - scrivere la seguente funzione:

unsigned long * fibonacci_array(unsigned int n);

questa funzione restituisce un array di unsigned long di dimensione n+1 (n è l'argomento della funzione)
dove la cella i-ma contiene il valore di fibonacci(i).


C - main() fa queste operazioni:

calcola fibonacci_array(39) e lo assegna alla varibile 'fibonacci_result'  // fibonacci(39) = 63245986

fare una copia dell'array fibonacci_result in 'fibonacci_result_copy' (i due array devono avere aree di memoria distinte)

fibonacci_result_copy: fare il 'reverse' dell'array ('copiare' da esempio 004.1arrays-operations)

su fibonacci_result_copy: applicare bubble_sort ('copiare' da esempio 004.1arrays-operations)

confrontare fibonacci_result e fibonacci_result_copy, verificare che i due array siano uguali (scrivere su stdout il risultato).
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

unsigned long fibonacci(unsigned int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n>1)
		return fibonacci(n-1) + fibonacci(n-2);
	else
		exit(EXIT_FAILURE);
}

unsigned long * fibonacci_array(unsigned int n)
{
	unsigned long * f;
	f = calloc(n+1, sizeof(long));

	if (f == NULL)
	{
		perror("Calloc error!");
		exit(EXIT_FAILURE);
	}

	for(int i=0; i<=n; i++)
		f[i]=fibonacci(i);

	return f;
}

void swap_long(long unsigned int *x,long unsigned int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

long unsigned * reverse_long(unsigned long * array, unsigned int i, unsigned int j)
{
	while (i < j)
		swap_long(&array[i++], &array[--j]);

	return array;
}

long unsigned * complete_reverse_long(unsigned long * array, unsigned int array_len)
{
	return reverse_long(array, 0, array_len);
}

void bubble_sort(unsigned long * array, int array_dimension)
{
  for (int i=0; i<array_dimension-1; i++)
  {
	  for (int j=0; j<array_dimension-i-1; j++)
	  {
		  if (array[j] > array[j+1])
			  swap_long(&array[j], &array[j+1]);
      }

  }
}

int main(int argc, char *argv[]) {

unsigned long *fibonacci_result;
int dimension = 39;

fibonacci_result = calloc(dimension+1,sizeof(long));
fibonacci_result = fibonacci_array(dimension);

printf("FIBONACCI ARRAY:");
for (int i = 0; i <= dimension; i++) {
		printf("[%d] -> %lu\n", i ,fibonacci_result[i]);
	}


unsigned long * fibonacci_result_copy;

fibonacci_result_copy = malloc((dimension+1) * sizeof(long));

if (fibonacci_result_copy == NULL)
	{
		perror("Calloc error!");
		exit(EXIT_FAILURE);
	}

memcpy(fibonacci_result_copy, fibonacci_result , (dimension+1) * sizeof(long));

if (fibonacci_result_copy == NULL) {
		perror("memcpy ERROR");
		exit(EXIT_FAILURE);
	}

complete_reverse_long(fibonacci_result_copy, dimension+1);

	printf("FIBONACCI ARRAY AFTER complete_reverse():\n");
	for (int i = 0; i < dimension+1; i++) {
		printf("[%d] -> %lu\n", i, fibonacci_result_copy[i]);
	}
	printf("\n");


bubble_sort(fibonacci_result_copy, dimension+1);

printf("FIBONACCI ARRAY AFTER bubblesort():\n");
	for (int i = 0; i < dimension+1; i++) {
		printf("[%d] -> %lu\n", i, fibonacci_result_copy[i]);
	}
	printf("\n");



int result;
result = memcmp(fibonacci_result_copy, fibonacci_result, (dimension+1) * sizeof(long));
if (result==0)
printf("EQUAL ARRAY");
else
printf("NOT EQUAL ARRAY");
	
free(fibonacci_result);
free(fibonacci_result_copy);

return 0;


}
