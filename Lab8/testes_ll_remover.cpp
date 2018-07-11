#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_remover, Lista1Elemento)
{
	struct lld ll, ll_depois;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	ll_array_para_lista(&ll_depois, intcmp, NULL, 0, NULL);

	ll_remover(&ll, ll.inicio);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el)));

	_CrtSetDbgFlag(tmpFlagOld);

	ll_limpar_lista(&ll);
	ll_limpar_lista(&ll_depois);
}

TEST(ll_remover, Lista2ElementosRemovePrimeiro)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 },  dados_depois[1] = { 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el)));

	_CrtSetDbgFlag(tmpFlagOld);

	ll_limpar_lista(&ll);
}

TEST(ll_remover, Lista2ElementosRemoveUltimo)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.fim);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el)));

	_CrtSetDbgFlag(tmpFlagOld);

	ll_limpar_lista(&ll);
}

TEST(ll_remover, Lista3ElementosRemovePrimeiro)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el)));

	_CrtSetDbgFlag(tmpFlagOld);

	ll_limpar_lista(&ll);
}

TEST(ll_remover, Lista3ElementosRemovePrimeiroPrimeiro)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[1] = { 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio);
	ll_remover(&ll, ll.inicio);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el)));
	ASSERT_NE(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el)));

	_CrtSetDbgFlag(tmpFlagOld);

	ll_limpar_lista(&ll);
}

TEST(ll_remover, Lista3ElementosRemoveUltimo)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.fim);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[2], sizeof(struct lld_el)));

	_CrtSetDbgFlag(tmpFlagOld);

	ll_limpar_lista(&ll);
}

TEST(ll_remover, Lista3ElementosRemoveUltimoUltimo)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.fim);
	ll_remover(&ll, ll.fim);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el)));
	ASSERT_NE(0, memoria_foi_liberada(elementos[2], sizeof(struct lld_el)));

	_CrtSetDbgFlag(tmpFlagOld);

	ll_limpar_lista(&ll);
}

TEST(ll_remover, Lista3ElementosRemoveMeio)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	ll_array_para_lista(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	ll_array_para_lista(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio->prox);

	ASSERT_NE(0, ll_listas_iguais(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el)));

	_CrtSetDbgFlag(tmpFlagOld);

	ll_limpar_lista(&ll);
}
