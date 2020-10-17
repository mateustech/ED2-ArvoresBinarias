#include <stdio.h>
#include <stdlib.h>
typedef struct arvno ArvNo;

struct arvno {
	char info;
	ArvNo* esq;
	ArvNo* dir;
};

typedef struct arv Arv;
struct arv {
	ArvNo* raiz;
};
//Criar no na arvore
ArvNo* arv_criano(char c, ArvNo* esq, ArvNo* dir){
	ArvNo* no = (ArvNo*) malloc(sizeof(ArvNo));
	no->info = c;
	no->esq = esq;
	no->dir = dir;
	return no;
}
//Criar arvore
Arv* arv_cria(ArvNo* r){
	Arv* a = (Arv*) malloc(sizeof(Arv));
	a->raiz = r;
	return a;
}
//Imprimir arvore
static void imprime(ArvNo* no){
	if(no != NULL){
		printf("%c ", no->info);
		imprime(no->esq);
		imprime(no->dir);
	}
}
//libera no
static void libera(ArvNo* no){
	if(no != NULL){
		libera(no->esq);
		libera(no->dir);
		free(no);
	}
}
void arv_libera(Arv* a){
	libera(a->raiz);
	free(a);
}
void arv_imprime(Arv* a){
	imprime(a->raiz);
}
int main(){
	puts("Hello world");
	Arv* a = arv_cria(arv_criano('a',arv_criano('b', NULL, arv_criano('d', NULL, NULL)),arv_criano('c', arv_criano('e', NULL, NULL),arv_criano('f',NULL,NULL))));
	arv_imprime(a);
}
