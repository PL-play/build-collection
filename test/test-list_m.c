
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "help_test/framework.h"

#include "list/linked_list_m.h"

DECLARE_LINKED_LIST(void* ,M_)

DEFINE_LINKED_LIST(void*,NULL,M_)

void display_list(M_LinkedListNode *head) {
  printf("\nContents of your linked list: \n");
  M_LinkedListNode *temp;
  temp = head;
  if (head != NULL) {
    while (M_next_node_linked_list(temp) != head) {
      printf("%p -> %d\n", M_data_of_node_linked_list(temp), *(int *) (M_data_of_node_linked_list(temp)));
      temp = M_next_node_linked_list(temp);
    }
    if (M_next_node_linked_list(temp) == head) {
      printf("%p -> %d\n", M_data_of_node_linked_list(temp), *(int *) (M_data_of_node_linked_list(temp)));
    }
  } else {
    printf("The list is empty");
  }
  printf("\n");
}
int int_equal(void *vlocation1, void *vlocation2) {
  int *location1;
  int *location2;

  location1 = (int *) vlocation1;
  location2 = (int *) vlocation2;
  if (*location1 == *location2) {
    return 0;
  } else if (*location1 > *location2) {
    return 1;
  } else {
    return -1;
  }

}
int int_compare(void *vlocation1, void *vlocation2) {
  int *location1;
  int *location2;

  location1 = (int *) vlocation1;
  location2 = (int *) vlocation2;

  if (*location1 < *location2) {
    return -1;
  } else if (*location1 > *location2) {
    return 1;
  } else {
    return 0;
  }
}

int variable1 = 50, variable2, variable3, variable4;

/* Returns a list containing four entries */

M_LinkedList *generate_list(void) {
  M_LinkedList *list = M_new_linked_list();

  assert(M_append_list(list, &variable1) == 1);
  assert(M_append_list(list, &variable2) == 1);
  assert(M_append_list(list, &variable3) == 1);
  assert(M_append_list(list, &variable4) == 1);

  return list;
}

void test_append_linked_list(void) {
  M_LinkedList *list = M_new_linked_list();

  assert(M_append_list(list, &variable1));
  assert(M_append_list(list, &variable2));
  assert(M_append_list(list, &variable3));
  assert(M_append_list(list, &variable4));

  assert(M_list_size(list) == 4);

  assert(M_get_list_data(list, 0) == &variable1);
  assert(M_get_list_data(list, 1) == &variable2);
  assert(M_get_list_data(list, 2) == &variable3);
  assert(M_get_list_data(list, 3) == &variable4);

  M_free_linked_list(list, NULL);
}

void test_prepend_linked_list(void) {
  M_LinkedList *list = M_new_linked_list();
  printf("add v1:%p\n", &variable1);
  fflush(stdout);
  assert(M_prepend_list(list, &variable1));
  printf("add v2:%p\n", &variable2);
  fflush(stdout);
  assert(M_prepend_list(list, &variable2));
  printf("add v3:%p\n", &variable3);
  fflush(stdout);
  assert(M_prepend_list(list, &variable3));
  printf("add v4:%p\n", &variable4);
  fflush(stdout);
  assert(M_prepend_list(list, &variable4));
  display_list(M_head_of_list(list));
  fflush(stdout);
  assert(M_get_list_data(list, 0) == &variable4);
  assert(M_get_list_data(list, 1) == &variable3);
  assert(M_get_list_data(list, 2) == &variable2);
  assert(M_get_list_data(list, 3) == &variable1);

  /* Test out of memory scenario */

  M_free_linked_list(list, NULL);
}

void test_free_linked_list(void) {
  M_LinkedList *list = generate_list();

  /* Create a list and free it */

  M_free_linked_list(list, NULL);

  /* Check the empty list frees correctly */
}

void test_node_of_linked_list(void) {
  M_LinkedList *list = generate_list();

  /* Check all values in the list */

  assert(M_data_of_node_linked_list(M_node_of_list(list, 0)) == &variable1);
  assert(M_data_of_node_linked_list(M_node_of_list(list, 1)) == &variable2);
  assert(M_data_of_node_linked_list(M_node_of_list(list, 2)) == &variable3);
  assert(M_data_of_node_linked_list(M_node_of_list(list, 3)) == &variable4);

  /* Check out of range values */

  assert(M_node_of_list(list, 4) == NULL);
  assert(M_node_of_list(list, 400) == NULL);

  M_free_linked_list(list, NULL);
}

void test_size_of_linked_list(void) {
  M_LinkedList *list = generate_list();

  /* Generate a list and check that it is four entries long */

  assert(M_list_size(list) == 4);

  /* Add an entry and check that it still works properly */

  assert(M_prepend_list(list, &variable1));

  assert(M_list_size(list) == 5);

  M_free_linked_list(list, NULL);

}

void test_remove_node_linked_list(void) {
  M_LinkedListNode *empty_list = NULL;
  M_LinkedListNode *entry;

  M_LinkedList *list = generate_list();

  /* Remove the third entry */

  entry = M_node_of_list(list, 2);
  M_ListValue *data = M_data_of_node_linked_list(entry);
  assert(M_remove_list(list, 2) == data);
  assert(M_list_size(list) == 3);
  /* Remove the first entry */

  entry = M_node_of_list(list, 0);
  data = M_data_of_node_linked_list(entry);
  assert(M_remove_list(list, 0) == data);
  assert(M_list_size(list) == 2);

  /* Try some invalid removes */

  /* Removing NULL from an empty list */

  M_free_linked_list(list, NULL);

  /* Test removing the last entry */

  list = generate_list();
  entry = M_node_of_list(list, 3);
  data = M_data_of_node_linked_list(entry);
  assert(M_remove_list(list, 3) == data);
  M_free_linked_list(list, NULL);
}

void test_remove_data_linked_list(void) {
  int entries[] = {89, 4, 23, 42, 4, 16, 15, 4, 8, 99, 50, 30, 4};
  unsigned int num_entries = sizeof(entries) / sizeof(int);
  int val;
  M_LinkedList *list = M_new_linked_list();
  unsigned int i;

  /* Generate a list containing all the entries in the array */

  for (i = 0; i < num_entries; ++i) {
    assert(M_prepend_list(list, &entries[i]));
  }

  /* Test removing invalid data */

  val = 0;
  assert(M_remove_list_equals_to(list, &val, int_equal) == 0);
  val = 56;
  assert(M_remove_list_equals_to(list, &val, int_equal) == 0);

  /* Remove the number 8 from the list */

  val = 8;
  assert(M_remove_list_equals_to(list, &val, int_equal) == 1);
  assert(M_list_size(list) == num_entries - 1);

  /* Remove the number 4 from the list (occurs multiple times) */

  val = 4;
  display_list(M_head_of_list(list));
  fflush(stdout);
  int c = M_remove_list_equals_to(list, &val, int_equal);
  assert(c == 4);
  assert(M_list_size(list) == num_entries - 5);

  /* Remove the number 89 from the list (first entry) */

  val = 89;
  assert(M_remove_list_equals_to(list, &val, int_equal) == 1);
  assert(M_list_size(list) == num_entries - 6);

  M_free_linked_list(list, NULL);
}

void test_linked_list_to_array(void) {
  M_LinkedList *list;
  void **array;

  list = generate_list();

  array = M_value_array(list);

  assert(array[0] == &variable1);
  assert(array[1] == &variable2);
  assert(array[2] == &variable3);
  assert(array[3] == &variable4);

  free(array);

  /* Test out of memory scenario */

  M_free_linked_list(list, NULL);
}

void test_remove_head_tail_linked_list(void) {
  M_LinkedList *list = generate_list();
  assert(M_list_size(list) == 4);
  assert(M_data_of_node_linked_list(M_head_of_list(list)) == &variable1);
  assert(M_remove_list_first(list) == 1);

  assert(M_list_size(list) == 3);
  assert(M_data_of_node_linked_list(M_head_of_list(list)) == &variable2);

  assert(M_remove_list_last(list) == 1);
  assert(M_list_size(list) == 2);
  assert(M_data_of_node_linked_list(M_prev_node_linked_list(M_head_of_list(list))) == &variable3);

  assert(M_remove_list_last(list) == 1);
  assert(M_list_size(list) == 1);
  assert(M_data_of_node_linked_list(M_prev_node_linked_list(M_head_of_list(list))) == &variable2);

  assert(M_remove_list_first(list) == 1);
  assert(M_list_size(list) == 0);
  assert(M_data_of_node_linked_list(M_prev_node_linked_list(M_head_of_list(list))) == NULL);

  M_free_linked_list(list, NULL);

}

/* Test that the iterator functions can survive removal of the current
 * value using the normal remove functions. */


static UnitTestFunction tests[] = {
    test_append_linked_list,
    test_prepend_linked_list,
    test_free_linked_list,
    test_node_of_linked_list,
    test_node_of_linked_list,
    test_size_of_linked_list,
    test_remove_node_linked_list,
    test_remove_data_linked_list,
    test_linked_list_to_array,
    test_remove_head_tail_linked_list,
    NULL
};

int main(int argc, char *argv[]) {
  run_tests(tests);

  return 0;
}

