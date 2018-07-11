#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_arvores_iguais, ArvoresVaziasComparIgual)
{
	struct arvbin arv1, arv2;

	arvbin_array_para_arvore(&arv1, intcmp, NULL, 0, NULL);
	arvbin_array_para_arvore(&arv2, intcmp, NULL, 0, NULL);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoresVaziasComparDiferente)
{
	struct arvbin arv1, arv2;

	arvbin_array_para_arvore(&arv1, intcmp, NULL, 0, NULL);
	arvbin_array_para_arvore(&arv2, NULL, NULL, 0, NULL);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoresUmElementoIguais)
{
	struct arvbin arv1, arv2;
	int temp1[1] = { 1 }, temp2[1] = { 1 };
	int* dados1[1] = { &temp1[0] };
	int* dados2[1] = { &temp2[0] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoresUmElementoDiferentes)
{
	struct arvbin arv1, arv2;
	int temp1[1] = { 0 }, temp2[1] = { 1 };
	int* dados1[1] = { &temp1[0] };
	int* dados2[1] = { &temp2[0] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreDoisElementosRaizEsquerdaIguais)
{
	struct arvbin arv1, arv2;
	int temp1[2] = { 1, 0 }, temp2[2] = { 1, 0 };
	int* dados1[2] = { &temp1[0], &temp1[1] };
	int* dados2[2] = { &temp2[0], &temp2[1] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreDoisElementosRaizEsquerdaDiferentesNaRaiz)
{
	struct arvbin arv1, arv2;
	int temp1[2] = { 1, 0 }, temp2[2] = { 2, 0 };
	int* dados1[2] = { &temp1[0], &temp1[1] };
	int* dados2[2] = { &temp2[0], &temp2[1] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreDoisElementosRaizEsquerdaDiferentesNaEsquerda)
{
	struct arvbin arv1, arv2;
	int temp1[2] = { 2, 1 }, temp2[2] = { 2, 0 };
	int* dados1[2] = { &temp1[0], &temp1[1] };
	int* dados2[2] = { &temp2[0], &temp2[1] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreDoisElementosRaizEsquerdaDiferentesEmAmbos)
{
	struct arvbin arv1, arv2;
	int temp1[2] = { 2, 1 }, temp2[2] = { 1, 0 };
	int* dados1[2] = { &temp1[0], &temp1[1] };
	int* dados2[2] = { &temp2[0], &temp2[1] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreDoisElementosRaizEsquerdaUmElemento)
{
	struct arvbin arv1, arv2;
	int temp1[2] = { 1, 0 }, temp2[1] = { 1 };
	int* dados1[2] = { &temp1[0], &temp1[1] };
	int* dados2[1] = { &temp2[0] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}


TEST(arvbin_arvores_iguais, ArvoreDoisElementosRaizDireitaIguais)
{
	struct arvbin arv1, arv2;
	int temp1[2] = { 1, 2 }, temp2[2] = { 1, 2 };
	int* dados1[3] = { &temp1[0], NULL, &temp1[1] };
	int* dados2[3] = { &temp2[0], NULL, &temp2[1] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreDoisElementosRaizDireitaDiferentesNaRaiz)
{
	struct arvbin arv1, arv2;
	int temp1[2] = { 2, 0 }, temp2[2] = { 1, 0 };
	int* dados1[3] = { &temp1[0], NULL, &temp1[1] };
	int* dados2[3] = { &temp2[0], NULL, &temp2[1] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreDoisElementosRaizDireitaDiferentesNaDireita)
{
	struct arvbin arv1, arv2;
	int temp1[2] = { 2, 1 }, temp2[2] = { 2, 0 };
	int* dados1[3] = { &temp1[0], NULL, &temp1[1] };
	int* dados2[3] = { &temp2[0], NULL, &temp2[1] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreDoisElementosRaizDireitaDiferentesEmAmbos)
{
	struct arvbin arv1, arv2;
	int temp1[2] = { 2, 1 }, temp2[2] = { 1, 0 };
	int* dados1[3] = { &temp1[0], NULL, &temp1[1] };
	int* dados2[3] = { &temp2[0], NULL, &temp2[1] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos1Iguais)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 1, 0, 2 }, temp2[3] = { 1, 0, 2 };
	int* dados1[3] = { &temp1[0], &temp1[1], &temp1[2] };
	int* dados2[3] = { &temp2[0], &temp2[1], &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos1DiferentesNaRaiz)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 1, 0, 3 }, temp2[3] = { 2, 0, 3 };
	int* dados1[3] = { &temp1[0], &temp1[1], &temp1[2] };
	int* dados2[3] = { &temp2[0], &temp2[1], &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos1DiferentesNaEsquerda)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 2, 0, 3 }, temp2[3] = { 2, 1, 3 };
	int* dados1[3] = { &temp1[0], &temp1[1], &temp1[2] };
	int* dados2[3] = { &temp2[0], &temp2[1], &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos1DiferentesNaDireita)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 1, 0, 2 }, temp2[3] = { 1, 0, 3 };
	int* dados1[3] = { &temp1[0], &temp1[1], &temp1[2] };
	int* dados2[3] = { &temp2[0], &temp2[1], &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos1DiferentesNaEsquerdaEDireita)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 2, 0, 4 }, temp2[3] = { 2, 1, 3 };
	int* dados1[3] = { &temp1[0], &temp1[1], &temp1[2] };
	int* dados2[3] = { &temp2[0], &temp2[1], &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos1DiferentesEmTodos)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 1, 0, 2 }, temp2[3] = { 2, 1, 3 };
	int* dados1[3] = { &temp1[0], &temp1[1], &temp1[2] };
	int* dados2[3] = { &temp2[0], &temp2[1], &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos2Iguais)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 2, 1, 0 }, temp2[3] = { 2, 1, 0 };
	int* dados1[4] = { &temp1[0], &temp1[1], NULL, &temp1[2] };
	int* dados2[4] = { &temp2[0], &temp2[1], NULL, &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos2DiferentesNaRaiz)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 2, 1, 0 }, temp2[3] = { 3, 1, 0 };
	int* dados1[4] = { &temp1[0], &temp1[1], NULL, &temp1[2] };
	int* dados2[4] = { &temp2[0], &temp2[1], NULL, &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos2DiferentesNoMeio)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 3, 2, 0 }, temp2[3] = { 3, 1, 0 };
	int* dados1[4] = { &temp1[0], &temp1[1], NULL, &temp1[2] };
	int* dados2[4] = { &temp2[0], &temp2[1], NULL, &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos2DiferentesNaFolha)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 3, 2, 1 }, temp2[3] = { 3, 2, 0 };
	int* dados1[4] = { &temp1[0], &temp1[1], NULL, &temp1[2] };
	int* dados2[4] = { &temp2[0], &temp2[1], NULL, &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}

TEST(arvbin_arvores_iguais, ArvoreTresElementos2DiferentesEmTodos)
{
	struct arvbin arv1, arv2;
	int temp1[3] = { 3, 2, 1 }, temp2[3] = { 4, 3, 2 };
	int* dados1[4] = { &temp1[0], &temp1[1], NULL, &temp1[2] };
	int* dados2[4] = { &temp2[0], &temp2[1], NULL, &temp2[2] };
	struct arvbin_no* nos1[sizeof(dados1)/sizeof(int*)];
	struct arvbin_no* nos2[sizeof(dados2)/sizeof(int*)];

	arvbin_array_para_arvore(&arv1, intcmp, dados1, sizeof(dados1)/sizeof(int*), nos1);
	arvbin_array_para_arvore(&arv2, intcmp, dados2, sizeof(dados2)/sizeof(int*), nos2);

	ASSERT_NE(0, arvbin_arvores_iguais(&arv1, &arv1));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv1, &arv2));
	ASSERT_EQ(0, arvbin_arvores_iguais(&arv2, &arv1));
	ASSERT_NE(0, arvbin_arvores_iguais(&arv2, &arv2));

	arvbin_limpar_arvore(&arv1);
	arvbin_limpar_arvore(&arv2);
}
