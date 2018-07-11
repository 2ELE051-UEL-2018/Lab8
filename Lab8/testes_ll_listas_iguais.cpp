#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_listas_iguais, ListasVaziasComparIgual)
{
	struct lld ll1, ll2;

	ll_array_para_lista(&ll1, intcmp, NULL, 0, NULL);
	ll_array_para_lista(&ll2, intcmp, NULL, 0, NULL);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasVaziasComparDiferente)
{
	struct lld ll1, ll2;

	ll_array_para_lista(&ll1, intcmp, NULL, 0, NULL);
	ll_array_para_lista(&ll2, NULL, NULL, 0, NULL);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasUmElementoIguais)
{
	struct lld ll1, ll2;
	int dados1[1] = { 1 }, dados2[1] = { 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasUmElementoDiferentes)
{
	struct lld ll1, ll2;
	int dados1[1] = { 0 }, dados2[1] = { 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasDoisElementosIguais)
{
	struct lld ll1, ll2;
	int dados1[2] = { 0, 1 }, dados2[2] = { 0, 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasDoisElementosDiferentesPrimeiro)
{
	struct lld ll1, ll2;
	int dados1[2] = { 1, 1 }, dados2[2] = { 0, 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasDoisElementosDiferentesSegundo)
{
	struct lld ll1, ll2;
	int dados1[2] = { 0, 0 }, dados2[2] = { 0, 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasTresElementosIguais)
{
	struct lld ll1, ll2;
	int dados1[3] = { 0, 1, 2 }, dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasTresElementosDiferentesPrimeiro)
{
	struct lld ll1, ll2;
	int dados1[3] = { 1, 1, 2 }, dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasTresElementosDiferentesSegundo)
{
	struct lld ll1, ll2;
	int dados1[3] = { 0, 2, 2 }, dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasTresElementosDiferentesTerceiro)
{
	struct lld ll1, ll2;
	int dados1[3] = { 0, 1, 0 }, dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasVaziaUmElemento)
{
	struct lld ll1, ll2;
	int dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, NULL, 0, NULL);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasUmElementoDoisElementos)
{
	struct lld ll1, ll2;
	int dados1[1] = { 0 }, dados2[2] = { 0, 0 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasUmElementoTresElementos)
{
	struct lld ll1, ll2;
	int dados1[1] = { 0 }, dados2[3] = { 0, 0, 0 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}

TEST(ll_listas_iguais, ListasDoisElementosTresElementos)
{
	struct lld ll1, ll2;
	int dados1[2] = { 0, 0 }, dados2[3] = { 0, 0, 0 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	ll_array_para_lista(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	ll_array_para_lista(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_NE(0, ll_listas_iguais(&ll1, &ll1));
	ASSERT_EQ(0, ll_listas_iguais(&ll1, &ll2));
	ASSERT_EQ(0, ll_listas_iguais(&ll2, &ll1));
	ASSERT_NE(0, ll_listas_iguais(&ll2, &ll2));

	ll_limpar_lista(&ll1);
	ll_limpar_lista(&ll2);
}
