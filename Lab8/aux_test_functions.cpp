#include <cstddef>
#include <cstdlib>

extern "C"
{
#include "ll.h"
}
#include "aux_test_functions.h"

int intcmp(void* arg1, void* arg2)
{
	int* a1 = (int*)arg1;
	int* a2 = (int*)arg2;

	return *a1 - *a2;
}

void ll_array_para_lista(struct lld* ll, int (*compar)(void*, void*), int dados[], int tam_lista, struct lld_el* elementos[])
{
	int i;

	ll->compar = compar;

	for (i = 0; i < tam_lista; i++)
	{
		elementos[i] = NULL;
	}

	if (tam_lista == 0)
	{
		ll->inicio = ll->fim = NULL;
		return;
	}
	else
	{
		elementos[0] = (struct lld_el*)malloc(sizeof(struct lld_el));
		elementos[tam_lista-1] = (struct lld_el*)malloc(sizeof(struct lld_el));
		ll->inicio = elementos[0];
		ll->fim = elementos[tam_lista-1];
	}

	if (tam_lista > 1)
	{
		if (elementos[1] == NULL)
		{
			elementos[1] = (struct lld_el*)malloc(sizeof(struct lld_el));
		}
		elementos[0]->prox = elementos[1];

		for (i = 1; i < tam_lista-1; i++)
		{
			elementos[i]->ant = elementos[i-1];
			elementos[i]->dado = &dados[i];
			if (elementos[i+1] == NULL)
			{
				elementos[i+1] = (struct lld_el*)malloc(sizeof(struct lld_el));
			}
			elementos[i]->prox = elementos[i+1];
		}

		elementos[tam_lista-1]->ant = elementos[tam_lista-2];
	}

	elementos[0]->ant = NULL;
	elementos[0]->dado = &dados[0];
	elementos[tam_lista-1]->dado = &dados[tam_lista-1];
	elementos[tam_lista-1]->prox = NULL;
}

int ll_listas_iguais(struct lld* ll1, struct lld* ll2)
{
	struct lld_el *el1, *el2;

	if (ll1->compar != ll2->compar)
		return 0;

	el1 = ll1->inicio;
	el2 = ll2->inicio;

	while (el1 != NULL && el2 != NULL)
	{
		if (ll1->compar(el1->dado, el2->dado) != 0)
		{
			return 0;
		}

		el1 = el1->prox;
		el2 = el2->prox;
	}

	if (el1 != el2)
	{
		return 0;
	}

	return 1;
}

void ll_limpar_lista(struct lld* ll)
{
	struct lld_el* el = ll->inicio;

	while (el != NULL)
	{
		struct lld_el* aux = el->prox;
		free(el);
		el = aux;
	}
}

static void arvbin_array_para_arvore_rec(struct arvbin_no* no, struct arvbin_no* pai, int indice_no, int* dados[], int tam_lista, struct arvbin_no* nos[])
{
	int indice_prox;

	no->pai = pai;
	no->dado = dados[indice_no];

	indice_prox = 2*indice_no + 1;
	if (indice_prox < tam_lista && dados[indice_prox] != NULL)
	{
		nos[indice_prox] = (struct arvbin_no*)malloc(sizeof(struct arvbin_no));
		no->esq = nos[indice_prox];
		arvbin_array_para_arvore_rec(no->esq, no, indice_prox, dados, tam_lista, nos);
	}
	else
	{
		no->esq = NULL;
	}

	indice_prox = 2*indice_no + 2;
	if (indice_prox < tam_lista && dados[indice_prox] != NULL)
	{
		nos[indice_prox] = (struct arvbin_no*)malloc(sizeof(struct arvbin_no));
		no->dir = nos[indice_prox];
		arvbin_array_para_arvore_rec(no->dir, no, indice_prox, dados, tam_lista, nos);
	}
	else
	{
		no->dir = NULL;
	}
}

void arvbin_array_para_arvore(struct arvbin* arv, int(*compar)(void*, void*), int* dados[], int tam_lista, struct arvbin_no* nos[])
{
	arv->compar = compar;

	if (tam_lista == 0)
	{
		arv->raiz = NULL;
	}
	else
	{
		nos[0] = (struct arvbin_no*)malloc(sizeof(struct arvbin_no));
		arv->raiz = nos[0];
		arvbin_array_para_arvore_rec(arv->raiz, NULL, 0, dados, tam_lista, nos);
	}
}

static int arvbin_arvores_iguais_rec(struct arvbin_no* no1, struct arvbin_no* no2, int(*compar)(void*, void*))
{
	if (no1 == NULL && no2 == NULL)
	{
		return 1;
	}
	else if ((no1 == NULL && no2 != NULL) || (no1 != NULL && no2 == NULL))
	{
		return 0;
	}
	else
	{
		if (compar(no1->dado, no2->dado) != 0)
		{
			return 0;
		}
		else
		{
			return arvbin_arvores_iguais_rec(no1->esq, no2->esq, compar) && arvbin_arvores_iguais_rec(no1->dir, no2->dir, compar);
		}
	}
}

int arvbin_arvores_iguais(struct arvbin* arv1, struct arvbin* arv2)
{
	if (arv1->compar != arv2->compar)
	{
		return 0;
	}
	else
	{
		return arvbin_arvores_iguais_rec(arv1->raiz, arv2->raiz, arv1->compar);
	}
}

static void arvbin_limpar_arvore_rec(struct arvbin_no* no)
{
	if (no != NULL)
	{
		arvbin_limpar_arvore_rec(no->esq);
		arvbin_limpar_arvore_rec(no->dir);
	}

	free(no);
}

void arvbin_limpar_arvore(struct arvbin* arv)
{
	arvbin_limpar_arvore_rec(arv->raiz);
}

int memoria_foi_liberada(void* arg, int tam)
{
	int i;
	unsigned char* arg_char = (unsigned char*)arg;
	for (i = 0; i < tam; i++)
	{
		if (arg_char[i] != 0xDD)
		{
			return 0;
		}
	}

	return 1;
}