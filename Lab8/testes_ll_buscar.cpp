#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_buscar, ListaVazia)
{
	struct lld ll;

	ll_array_para_lista(&ll, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, ll_buscar(&ll, NULL));

	ll_limpar_lista(&ll);
}

TEST(ll_buscar, UmElementoNaoExiste)
{
	struct lld ll;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int buscado = 1;

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(NULL, ll_buscar(&ll, &buscado));

	ll_limpar_lista(&ll);
}

TEST(ll_buscar, UmElementoExiste)
{
	struct lld ll;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int buscado = 0;

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll_buscar(&ll, &buscado));

	ll_limpar_lista(&ll);
}

TEST(ll_buscar, DoisElementosExisteSegundoElemento)
{
	struct lld ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int buscado = 1;

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[1], ll_buscar(&ll, &buscado));

	ll_limpar_lista(&ll);
}

TEST(ll_buscar, DoisElementosNaoExiste)
{
	struct lld ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int buscado = 2;

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(NULL, ll_buscar(&ll, &buscado));

	ll_limpar_lista(&ll);
}
