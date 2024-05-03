#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

FILE* OpenFile(char* filePath) {
	FILE* ptr;

	ptr = fopen(filePath,"rt");
	if (ptr == NULL)
	{
		printf("non riesco ad aprire il file");
		return NULL;	
	}

	retunr ptr;
	
}

int CloseFile(FILE* fPtr) {
	
	if (fPtr != NULL){ 
		fclose(fPtr);
		return 1;
	}
	else{
		printf(""); 
		return -1;
	}
}

//stringtoken strtok. gli do un token e restituirìsce quanti elementi token ci sono nella stringa
