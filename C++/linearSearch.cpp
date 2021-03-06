#include <stdio.h>
#include <stdlib.h>

#define CANT_ELEM 10000
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
	printf("Se utilizan %d bytes del heap\n", memUsage);
	List* mainList = (List*)malloc(sizeof(List));
	memUsage+=sizeof(List);
	makeList(mainList, CANT_ELEM); //Crea lista de CANT_ELEM ceros
	//Ver tiempo
	printf("%d" , linearSearch(mainList, SRCH_NUM)); //Busca un 1 en la lista
	printf("Se utilizan %d bytes del heap\n", memUsage);
	//Comprobar tiempo
	//Mostrar datos
	deleteList(mainList);
	return 0;
}
