#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_inserir_elemento, ListaVazia)
{
	struct lld ll, ll_depois;
	int dados[1] = { 0 }, dados_depois[1] = { 0 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	struct lld_el* a_inserir;

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	a_inserir = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir->dado = &dados[0];
	ll_inserir_elemento(&ll, NULL, a_inserir);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_elemento, ListaDoisElementosInsereInicio)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	struct lld_el* a_inserir[2];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	a_inserir[0] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[1] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[0]->dado = &dados[1];
	a_inserir[1]->dado = &dados[0];

	ll_inserir_elemento(&ll, NULL, a_inserir[0]);
	ll_inserir_elemento(&ll, NULL, a_inserir[1]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_elemento, ListaDoisElementosInsereFim)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	struct lld_el* a_inserir[2];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	a_inserir[0] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[1] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[0]->dado = &dados[0];
	a_inserir[1]->dado = &dados[1];

	ll_inserir_elemento(&ll, NULL, a_inserir[0]);
	ll_inserir_elemento(&ll, ll.inicio, a_inserir[1]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_elemento, ListaTresElementosInsereInicioInicio)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	struct lld_el* a_inserir[3];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	a_inserir[0] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[1] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[2] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[0]->dado = &dados[2];
	a_inserir[1]->dado = &dados[1];
	a_inserir[2]->dado = &dados[0];

	ll_inserir_elemento(&ll, NULL, a_inserir[0]);
	ll_inserir_elemento(&ll, NULL, a_inserir[1]);
	ll_inserir_elemento(&ll, NULL, a_inserir[2]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_elemento, ListaTresElementosInsereInicioMeioFim)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	struct lld_el* a_inserir[3];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	a_inserir[0] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[1] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[2] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[0]->dado = &dados[0];
	a_inserir[1]->dado = &dados[2];
	a_inserir[2]->dado = &dados[1];

	ll_inserir_elemento(&ll, NULL, a_inserir[0]);
	ll_inserir_elemento(&ll, ll.fim, a_inserir[1]);
	ll_inserir_elemento(&ll, ll.inicio, a_inserir[2]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_elemento, ListaTresElementosInsereMeio)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 2, 1 }, dados_depois[3] = { 0, 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	struct lld_el* a_inserir[1];

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	a_inserir[0] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[0]->dado = &dados[2];

	ll_array_para_lista(&ll, intcmp, dados, 2, elementos);
	ll_inserir_elemento(&ll, ll.inicio, a_inserir[0]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_inserir_elemento, ListaQuatroElementosInserePrimeiroSegundoTerceiroQuarto)
{
	struct lld ll, ll_depois;
	int dados[4] = { 0, 1, 2, 3 }, dados_depois[4] = { 0, 1, 2, 3 };
	struct lld_el* elementos_depois[sizeof(dados_depois)/sizeof(int)];
	struct lld_el* a_inserir[4];

	ll.inicio = ll.fim = NULL;
	ll.compar = intcmp;

	a_inserir[0] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[1] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[2] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[3] = (struct lld_el*)malloc(sizeof(struct lld_el));
	a_inserir[0]->dado = &dados[0];
	a_inserir[1]->dado = &dados[1];
	a_inserir[2]->dado = &dados[2];
	a_inserir[3]->dado = &dados[3];

	ll_inserir_elemento(&ll, NULL, a_inserir[0]);
	ll_inserir_elemento(&ll, ll.inicio, a_inserir[1]);
	ll_inserir_elemento(&ll, ll.inicio->prox, a_inserir[2]);
	ll_inserir_elemento(&ll, ll.fim, a_inserir[3]);

	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}
