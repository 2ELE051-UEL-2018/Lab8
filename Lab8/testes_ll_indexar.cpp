#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_indexar, ListaVaziaAcessaPrimeiroElemento)
{
	struct lld ll;

	ll_array_para_lista(&ll, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, ll_indexar(&ll, 0));

	ll_limpar_lista(&ll);
}

TEST(ll_indexar, ListaUmElementoAcessaPrimeiroElemento)
{
	struct lld ll;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll_indexar(&ll, 0));

	ll_limpar_lista(&ll);
}

TEST(ll_indexar, ListaUmElementoAcessaSegundoElemento)
{
	struct lld ll;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(NULL, ll_indexar(&ll, 1));

	ll_limpar_lista(&ll);
}

TEST(ll_indexar, ListaUmElementoAcessaTerceiroElemento)
{
	struct lld ll;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(NULL, ll_indexar(&ll, 2));

	ll_limpar_lista(&ll);
}
TEST(ll_indexar, ListaDoisElementosAcessaPrimeiroElemento)
{
	struct lld ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll_indexar(&ll, 0));

	ll_limpar_lista(&ll);
}

TEST(ll_indexar, ListaDoisElementosAcessaSegundoElemento)
{
	struct lld ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[1], ll_indexar(&ll, 1));

	ll_limpar_lista(&ll);
}

TEST(ll_indexar, ListaDoisElementosAcessaTerceiroElemento)
{
	struct lld ll;
	int dados[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(NULL, ll_indexar(&ll, 2));

	ll_limpar_lista(&ll);
}

TEST(ll_indexar, ListaTresElementosAcessaPrimeiroElemento)
{
	struct lld ll;
	int dados[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll_indexar(&ll, 0));

	ll_limpar_lista(&ll);
}

TEST(ll_indexar, ListaTresElementosAcessaSegundoElemento)
{
	struct lld ll;
	int dados[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[1], ll_indexar(&ll, 1));

	ll_limpar_lista(&ll);
}

TEST(ll_indexar, ListaTresElementosAcessaTerceiroElemento)
{
	struct lld ll;
	int dados[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[2], ll_indexar(&ll, 2));

	ll_limpar_lista(&ll);
}

TEST(ll_indexar, ListaTresElementosAcessaQuartoElemento)
{
	struct lld ll;
	int dados[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(NULL, ll_indexar(&ll, 3));

	ll_limpar_lista(&ll);
}