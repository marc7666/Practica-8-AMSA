#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Sleeping...\n");
	sleep(10);
	printf("Resumed\n");
	int cont = 0;
	for(int i = 0; i < 1000000000; i++){
		cont = cont + i;
	}
	printf("Resultat: %i\n", cont);
}
