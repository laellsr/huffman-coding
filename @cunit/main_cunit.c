#include "../@functions/default.h"
#include "../@data_structures/binary_tree.h"
#include "../@data_structures/hash_table.h"
#include "../@data_structures/heap.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/* gcc -o cunit main_cunit.c -lcunit */

void test_tree();
void test_heap();
void test_hash_table();

int main()
{
	CU_pSuite pSuite1 = NULL;

    if(CUE_SUCCESS != CU_initialize_registry() )
    {
        return CU_get_error();
    }

    /* suite to register */
    pSuite1 = CU_add_suite("Data Structures Test", init_suite, clean_suite);
    if (NULL == pSuite1)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
   /* pSuite2 = CU_add_suite("Data Structures Test 2", init_suite, clean_suite); if (NULL == pSuite2) { CU_cleanup_registry(); return CU_get_error(); }*/

    /* test to suite */
    if(NULL == CU_add_test(pSuite1, "Binary Tree Test", test_tree)){
        CU_cleanup_registry();
        return CU_get_error();
    }
    if(NULL == CU_add_test(pSuite1, "Heap Test", test_heap)){
        CU_cleanup_registry();
        return CU_get_error();
    }
    if(NULL == CU_add_test(pSuite1, "Hash Table Test", test_hash_table)){
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    CU_cleanup_registry();
    return CU_get_error();
}

void test_tree()
{
	unsigned char byte = '*';
	binary_tree *bt = create_empty_binary_tree();
	CU_ASSERT_PTR_NULL(bt); /* Assert that pointer value == NULL */
	/* CU_ASSERT_PTR_NOT_NULL(bt);*/
	bt = create_binary_tree(&byte, 1, NULL, NULL);
	CU_ASSERT_PTR_NOT_NULL(bt);
	CU_ASSERT(get_binary_tree_frequency(bt) == 1); /*Assert that expression is TRUE*/
	CU_ASSERT_PTR_NULL(bt_right(bt));
	CU_ASSERT_TRUE(is_leaf(bt)); /* Assert that value is TRUE */


}
void test_heap()
{
	unsigned char byte = '*';
	heap *heap = create_heap();
	CU_ASSERT_PTR_NULL(heap);
	binary_tree *bt = create_binary_tree(&byte, 1, NULL, NULL);
	enqueue(heap, bt);
	CU_ASSERT_PTR_NOT_NULL(heap);
	CU_ASSERT(get_heap_size(heap) == 1);
	

}
void test_hash_table()
{
	unsigned char byte = '*';
	hash_table *hash = create_hash_table();
	CU_ASSERT_PTR_NULL(hash);
	put_hash(hash, &byte);
	put_hash(hash, &byte);
	element_hash *eh = get_hash_data(hash);
	CU_ASSERT_PTR_NOT_NULL(eh);
	CU_ASSERT(get_element_hash_frequency(eh)==2);
}
