#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_inserir_antes, ListaVazia)
{
	struct lld ll, ll_depois;
	int dados[1] = { 0 }, dados_depois[1] = { 0 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	ll_inserir_antes(&ll, NULL, &dados[0]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_antes, ListaDoisElementosInsereInicio)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	ll_inserir_antes(&ll, NULL, &dados[1]);
	ll_inserir_antes(&ll, ll.inicio, &dados[0]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_antes, ListaDoisElementosInsereFim)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	ll_inserir_antes(&ll, NULL, &dados[0]);
	ll_inserir_antes(&ll, NULL, &dados[1]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_antes, ListaTresElementosInsereInicioInicio)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	ll_inserir_antes(&ll, NULL, &dados[2]);
	ll_inserir_antes(&ll, ll.inicio, &dados[1]);
	ll_inserir_antes(&ll, ll.inicio, &dados[0]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_antes, ListaTresElementosInsereInicioMeioFim)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	ll_inserir_antes(&ll, NULL, &dados[0]);
	ll_inserir_antes(&ll, NULL, &dados[2]);
	ll_inserir_antes(&ll, ll.fim, &dados[1]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}
