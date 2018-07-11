#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_contar, ListaVazia)
{
	struct lld ll;

	ll_array_para_lista(&ll, intcmp, NULL, 0, NULL);

	ASSERT_EQ(0, ll_contar(&ll));

	ll_limpar_lista(&ll);
}

TEST(ll_contar, ListaUmElemento)
{
	struct lld ll;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(1, ll_contar(&ll));

	ll_limpar_lista(&ll);
}

TEST(ll_contar, ListaDoisElementos)
{
	struct lld ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(2, ll_contar(&ll));

	ll_limpar_lista(&ll);
}

TEST(ll_contar, ListaTresElementos)
{
	struct lld ll;
	int dados[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(3, ll_contar(&ll));

	ll_limpar_lista(&ll);
}

TEST(ll_contar, ListaQuatroElementos)
{
	struct lld ll;
	int dados[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(4, ll_contar(&ll));

	ll_limpar_lista(&ll);
}