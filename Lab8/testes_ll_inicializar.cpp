#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_inicializar, Inicializar)
{
	struct lld ll;

	ll_inicializar(&ll, intcmp);

	ASSERT_EQ(NULL, ll.inicio);
	ASSERT_EQ(NULL, ll.fim);
	ASSERT_EQ(&intcmp, ll.compar);

	ll_limpar_lista(&ll);
}
