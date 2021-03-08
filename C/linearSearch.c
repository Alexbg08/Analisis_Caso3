#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_ELEM 100000000
#define LIST_NUM 0
#define SRCH_NUM 1

int memUsage = 0;

typedef struct sNode {
	int value;
	struct sNode* next;
} Node;

typedef struct sList{
	Node* first;
} List;

void makeList(List* pList, int pCantElements){
	for(int cont = 0 ; cont<pCantElements; cont++){
		Node* nuevo = (Node*)malloc(sizeof(Node));
		if (nuevo != NULL){
			memUsage+=sizeof(Node);
			nuevo->value = LIST_NUM;
			Node* primero = pList->first;
			if(primero != NULL){
				nuevo->next = primero;
			}else{
				nuevo->next = NULL;
				
			}
			pList->first = nuevo;
		}
	}
}

void deleteList(List* pList){
	Node* aux = pList->first;
	while(aux != NULL){
		pList->first = aux->next;
		free(aux);
		memUsage-=sizeof(Node);
		aux = pList->first;
	}
	free(pList);
}

int linearSearch(List* pList, int pSearchNum){
	Node* aux = pList->first;
	while(aux != NULL){
		if(aux->value == pSearchNum){
			return 1; //Se encontró
		}
		aux = aux->next;
	}
	return 0; //No se encontró
}

int main(){
	List* mainList = (List*)malloc(sizeof(List));
	memUsage+=sizeof(List);
	
	clock_t start = clock(); //Inicio
	makeList(mainList, CANT_ELEM); //Crea lista de CANT_ELEM ceros
	clock_t end = clock(); //Final
	double elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Tarda %lf segundos en crear la lista de 0´s\n", elapsedSeconds);
	
	start = clock(); //Inicio
	linearSearch(mainList, SRCH_NUM); //Busca un 1 en la lista
	end = clock(); //Final
	elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Se utilizan %d bytes del heap\n", memUsage);
	printf("Tarda %lf segundos en recorrer toda la lista\n", elapsedSeconds);
	
	start = clock(); //Inicio
	deleteList(mainList);
	end = clock(); //Final
	printf("Tarda %lf segundos en eliminar la lista\n", elapsedSeconds);
	return 0;
}
