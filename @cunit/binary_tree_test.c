#include "../@data_structures/binary_tree.c"
#include "../@data_structures/binary_tree.h"
#include "../@functions/default.h"
#include "../@functions/default.c"
#include "CUnit/Basic.h"

void create_binary_tree_test()
{
	binary_tree* new = create_empty_binary_tree();
	unsigned char c;
	c = 'b';
	new = create_binary_tree(&c,5,NULL,NULL);

	if(new != NULL)
	{
		CU_PASS("Ok!");
	}
	else
	{
		CU_FAIL("create_binary_tree com erro!");
	}
}

void destruct_binary_tree_test()
{
	binary_tree* new = create_empty_binary_tree();
	unsigned char c;
	unsigned char d;
	c = 'b';
	d = 'c';
	new = create_binary_tree(&c,5,create_binary_tree(&d,4,NULL,NULL),NULL);

	c = (unsigned char*)new->left->value;

	if(new->left != NULL)
	{
		CU_PASS("Ok!");
	}
	else
	{
		CU_FAIL("create_binary_tree com erro!");
	}

	destruct_binary_tree(new->left);

	printf("%d\n", new->left->frequency);

	if(new->left == NULL)
	{
		CU_PASS("OK!");
	}
	else
	{
		CU_FAIL("destruct_binary_tree com erro!");
	}
}

void get_binary_tree_frequency_test()
{
	binary_tree* new = create_empty_binary_tree();
	unsigned char c;
	c = 'b';
	new = create_binary_tree(&c,5,NULL,NULL);
	int freq;

	freq = get_binary_tree_frequency(new);

	if(freq == 5)
	{
		CU_PASS("Ok!");
	}
	else
	{
		CU_FAIL("get_binary_tree_frequency com erro!");
	}
}

void is_leaf_test()
{
	binary_tree* new = create_empty_binary_tree();
	unsigned char c;
	c = 'b';
	new = create_binary_tree(&c,5,NULL,NULL);

	if(is_leaf(new))
	{
		CU_PASS("Ok!");
	}
	else
	{
		CU_FAIL("is_leaf com erro!");
	}
}

void get_binary_tree_value_test()
{
	binary_tree* new = create_empty_binary_tree();
	unsigned char c;
	c = 'b';
	new = create_binary_tree(&c,5,NULL,NULL);

	if(get_binary_tree_value(new) == 'b')
	{
		CU_PASS("Ok!");
	}
	else
	{
		CU_FAIL("get_binary_tree_value com erro!");
	}
}

void bt_right_test()
{
	binary_tree* new = create_empty_binary_tree();
	unsigned char c;
	c = 'b';
	new = create_binary_tree(&c,5,NULL,NULL);

	if(bt_right(new) == NULL)
	{
		CU_PASS("Ok!");
	}
	else
	{
		CU_FAIL("bt_right com erro!");
	}
}

void binary_tree_size_test()
{
	binary_tree* new = create_empty_binary_tree();
	unsigned char c,d,e;
	c = 'b';
	d = 'c';
	e = 'd';
	new = create_binary_tree(&c,5,create_binary_tree(&d,0,NULL,create_binary_tree(&e,0,NULL,NULL)),NULL);

	if(binary_tree_size(new) == 3)
	{
		CU_PASS("Ok!");
	}
	else
	{
		CU_FAIL("bt_right com erro!");
	}
}

int main() {

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

  	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite("binary_tree_test_suite", 0, 0);

	if (NULL == pSuite) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

	// Adiciona testes a suite
	if (NULL == CU_add_test(pSuite, "create_binary_tree_test", create_binary_tree_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (NULL == CU_add_test(pSuite, "destruct_binary_tree_test", destruct_binary_tree_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (NULL == CU_add_test(pSuite, "get_binary_tree_frequency_test", get_binary_tree_frequency_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (NULL == CU_add_test(pSuite, "is_leaf_test", is_leaf_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (NULL == CU_add_test(pSuite, "get_binary_tree_value_test", get_binary_tree_value_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (NULL == CU_add_test(pSuite, "bt_right_test", bt_right_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}
	if (NULL == CU_add_test(pSuite, "binary_tree_size_test", binary_tree_size_test)) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}


   CU_basic_set_mode(CU_BRM_VERBOSE);

   CU_basic_run_tests();
   return CU_get_error();
}
