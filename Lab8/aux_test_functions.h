#ifndef AUX_TEST_FUNCTIONS_H
#define AUX_TEST_FUNCTIONS_H

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
#include "ll.h"
#include "arvbin.h"

	int intcmp(void* arg1, void* arg2);
#ifdef __cplusplus
}
#endif // __cplusplus

void ll_array_para_lista(struct lld* ll, int (*compar)(void*, void*), int dados[], int tam_lista, struct lld_el* elementos[]);
int ll_listas_iguais(struct lld* ll1, struct lld* ll2);
void ll_limpar_lista(struct lld* ll);
void arvbin_array_para_arvore(struct arvbin* arv, int(*compar)(void*, void*), int* dados[], int tam_lista, struct arvbin_no* nos[]);
int arvbin_arvores_iguais(struct arvbin* arv1, struct arvbin* arv2);
void arvbin_limpar_arvore(struct arvbin* arv);
int memoria_foi_liberada(void* arg, int tam);

#endif // AUX_TEST_FUNCTIONS_H
