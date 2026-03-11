#include <stdio.h>
#include <assert.h>
#include "dynamic-array.h"

void test_create() {
    DynamicArray* arr = create_array(4);
    assert(arr != NULL);
    assert(arr->size == 0);
    assert(arr->capacity == 4);
    destroy_array(arr);

    // Default capacity when 0 is passed
    DynamicArray* arr2 = create_array(0);
    assert(arr2->capacity == 4);
    destroy_array(arr2);

    printf("test_create passed\n");
}

void test_insert_append() {
    DynamicArray* arr = create_array(4);

    // Append to end
    assert(insert(arr, 10, 0) == 0);
    assert(insert(arr, 20, 1) == 0);
    assert(insert(arr, 30, 2) == 0);
    assert(arr->size == 3);

    int val;
    get(arr, 0, &val); assert(val == 10);
    get(arr, 1, &val); assert(val == 20);
    get(arr, 2, &val); assert(val == 30);

    destroy_array(arr);
    printf("test_insert_append passed\n");
}

void test_insert_middle() {
    DynamicArray* arr = create_array(4);
    insert(arr, 10, 0);
    insert(arr, 30, 1);
    insert(arr, 20, 1); // insert between 10 and 30

    int val;
    get(arr, 0, &val); assert(val == 10);
    get(arr, 1, &val); assert(val == 20);
    get(arr, 2, &val); assert(val == 30);

    destroy_array(arr);
    printf("test_insert_middle passed\n");
}

void test_insert_out_of_bounds() {
    DynamicArray* arr = create_array(4);
    insert(arr, 10, 0);
    assert(insert(arr, 99, 5) == -1); // gap would be created
    assert(arr->size == 1);           // size unchanged

    destroy_array(arr);
    printf("test_insert_out_of_bounds passed\n");
}

void test_resize() {
    DynamicArray* arr = create_array(2);
    insert(arr, 1, 0);
    insert(arr, 2, 1);
    assert(arr->capacity == 2);

    insert(arr, 3, 2); // triggers resize
    assert(arr->capacity == 4);
    assert(arr->size == 3);

    int val;
    get(arr, 2, &val); assert(val == 3);

    destroy_array(arr);
    printf("test_resize passed\n");
}

void test_remove() {
    DynamicArray* arr = create_array(4);
    insert(arr, 10, 0);
    insert(arr, 20, 1);
    insert(arr, 30, 2);

    // Remove middle element
    assert(remove_at(arr, 1) == 0);
    assert(arr->size == 2);

    int val;
    get(arr, 0, &val); assert(val == 10);
    get(arr, 1, &val); assert(val == 30);

    // Remove last
    assert(remove_at(arr, 1) == 0);
    assert(arr->size == 1);

    destroy_array(arr);
    printf("test_remove passed\n");
}

void test_remove_edge_cases() {
    DynamicArray* arr = create_array(4);

    // Remove from empty
    assert(remove_at(arr, 0) == -1);

    insert(arr, 42, 0);
    // Out of bounds remove
    assert(remove_at(arr, 5) == 1);
    assert(arr->size == 1); // unchanged

    destroy_array(arr);
    printf("test_remove_edge_cases passed\n");
}

void test_get_set() {
    DynamicArray* arr = create_array(4);
    insert(arr, 100, 0);

    int val;
    assert(get(arr, 0, &val) == 0 && val == 100);
    assert(get(arr, 5, &val) == -1); // out of bounds

    assert(set(arr, 0, 200) == 0);
    get(arr, 0, &val); assert(val == 200);
    assert(set(arr, 5, 999) == -1); // out of bounds

    destroy_array(arr);
    printf("test_get_set passed\n");
}

int main() {
    test_create();
    test_insert_append();
    test_insert_middle();
    test_insert_out_of_bounds();
    test_resize();
    test_remove();
    test_remove_edge_cases();
    test_get_set();

    printf("\nAll tests passed.\n");
    return 0;
}
