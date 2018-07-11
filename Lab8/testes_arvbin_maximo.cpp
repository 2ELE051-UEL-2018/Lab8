#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_maximo, ArvoreVazia)
{
	struct arvbin arv;

	arvbin_array_para_arvore(&arv, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, arvbin_maximo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_maximo, ArvoreUmElemento)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_maximo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_maximo, ArvoreDoisElementosRaizDireita)
{
	struct arvbin arv;
	int temp[2] = { 0, 1 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[2], arvbin_maximo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_maximo, ArvoreDoisElementosRaizEsquerda)
{
	struct arvbin arv;
	int temp[2] = { 0, 1 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_maximo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_maximo, ArvoreTresElementosRaizEsquerdaDireita)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[2], arvbin_maximo(&arv));

	arvbin_limpar_arvore(&arv);
}

TEST(arvbin_maximo, ArvoreTresElementosRaizDireitaDireita)
{
	struct arvbin arv;
	int temp[3] = { 0, 1, 2 };
	int* dados[7] = { &temp[0], NULL, &temp[1], NULL, NULL, NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	arvbin_array_para_arvore(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[6], arvbin_maximo(&arv));

	arvbin_limpar_arvore(&arv);
}
