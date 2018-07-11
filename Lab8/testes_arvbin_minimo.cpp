#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_minimo, ArvoreVazia)
{
	struct arvbin arv;

	arvbin_array_para_arvore(&arv, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, arvbin_minimo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_minimo, ArvoreUmElemento)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_minimo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_minimo, ArvoreDoisElementosRaizEsquerda)
{
	struct arvbin arv;
	int temp[2] = { 1, 0 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[1], arvbin_minimo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_minimo, ArvoreDoisElementosRaizDireita)
{
	struct arvbin arv;
	int temp[2] = { 0, 1 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_minimo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_minimo, ArvoreTresElementosRaizEsquerdaDireita)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[1], arvbin_minimo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_minimo, ArvoreTresElementosRaizEsquerdaEsquerda)
{
	struct arvbin arv;
	int temp[3] = { 2, 1, 0 };
	int* dados[4] = { &temp[0], &temp[1], NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[3], arvbin_minimo(&arv));

	arvbin_limpar_arvore(&arv);
}