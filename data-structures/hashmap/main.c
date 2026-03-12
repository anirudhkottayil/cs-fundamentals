#include <stdio.h>
#include <assert.h>
#include "hashmap.h"
#include <string.h>

void test_create() {
    HashMap* map = create_hashmap(4);
    assert(map != NULL);
    assert(map->size == 0);
    assert(map->capacity == 4);
    destroy_map(map);

    HashMap* map2 = create_hashmap(0);
    assert(map2->capacity == 4);
    destroy_map(map2);

    printf("test_create passed\n");
}

void test_insert_and_get() {
    HashMap* map = create_hashmap(4);

    assert(insert(1, "one", map) == HM_SUCCESS);
    assert(insert(2, "two", map) == HM_SUCCESS);
    assert(insert(3, "three", map) == HM_SUCCESS);
    assert(map->size == 3);

    char* res;
    assert(get(1, map, &res) == HM_SUCCESS);
    assert(strcmp(res, "one") == 0);

    assert(get(2, map, &res) == HM_SUCCESS);
    assert(strcmp(res, "two") == 0);

    assert(get(99, map, &res) == HM_FAIL); // key doesn't exist

    destroy_map(map);
    printf("test_insert_and_get passed\n");
}

void test_update() {
    HashMap* map = create_hashmap(4);

    insert(1, "one", map);
    assert(map->size == 1);

    insert(1, "ONE", map); // update existing key
    assert(map->size == 1); // size should not change

    char* res;
    get(1, map, &res);
    assert(strcmp(res, "ONE") == 0);

    destroy_map(map);
    printf("test_update passed\n");
}

void test_collision() {
    // capacity 4: keys 1 and 5 both hash to index 1
    HashMap* map = create_hashmap(4);

    insert(1, "one", map);
    insert(5, "five", map);
    assert(map->size == 2);

    char* res;
    assert(get(1, map, &res) == HM_SUCCESS);
    assert(strcmp(res, "one") == 0);

    assert(get(5, map, &res) == HM_SUCCESS);
    assert(strcmp(res, "five") == 0);

    destroy_map(map);
    printf("test_collision passed\n");
}

void test_remove() {
    HashMap* map = create_hashmap(4);

    insert(1, "one", map);
    insert(2, "two", map);
    insert(3, "three", map);

    assert(remove_pair(2, map) == HM_SUCCESS);
    assert(map->size == 2);

    char* res;
    assert(get(2, map, &res) == HM_FAIL); // should be gone

    assert(remove_pair(99, map) == HM_FAIL); // key doesn't exist

    destroy_map(map);
    printf("test_remove passed\n");
}

void test_remove_collision_chain() {
    HashMap* map = create_hashmap(4);

    // 1 and 5 collide at index 1
    insert(1, "one", map);
    insert(5, "five", map);

    // remove head of chain
    assert(remove_pair(5, map) == HM_SUCCESS);

    char* res;
    assert(get(1, map, &res) == HM_SUCCESS); // tail still accessible
    assert(strcmp(res, "one") == 0);

    destroy_map(map);
    printf("test_remove_collision_chain passed\n");
}

void test_contains() {
    HashMap* map = create_hashmap(4);

    insert(42, "hello", map);
    assert(contains(42, map) == HM_SUCCESS);
    assert(contains(99, map) == HM_FAIL);

    destroy_map(map);
    printf("test_contains passed\n");
}

void test_resize() {
    HashMap* map = create_hashmap(4);
    // load factor hits 0.75 at 3 elements (3/4 = 0.75)
    insert(1, "one", map);
    insert(2, "two", map);
    insert(3, "three", map); // triggers resize to capacity 8
    insert(4, "four", map);

    assert(map->capacity == 8);
    assert(map->size == 4);

    char* res;
    assert(get(1, map, &res) == HM_SUCCESS); assert(strcmp(res, "one") == 0);
    assert(get(2, map, &res) == HM_SUCCESS); assert(strcmp(res, "two") == 0);
    assert(get(3, map, &res) == HM_SUCCESS); assert(strcmp(res, "three") == 0);
    assert(get(4, map, &res) == HM_SUCCESS); assert(strcmp(res, "four") == 0);

    destroy_map(map);
    printf("test_resize passed\n");
}

void test_load_factor() {
    assert(load_factor(3, 4) == 0.75);
    assert(load_factor(0, 4) == 0.0);
    assert(load_factor(4, 4) == 1.0);
    printf("test_load_factor passed\n");
}

void test_print() {
    HashMap* map = create_hashmap(4);
    insert(1, "one", map);
    insert(5, "five", map); // collides with 1
    insert(2, "two", map);
    printf("--- print_map output ---\n");
    print_map(map);
    printf("------------------------\n");
    destroy_map(map);
    printf("test_print passed\n");
}

int main() {
    test_create();
    test_insert_and_get();
    test_update();
    test_collision();
    test_remove();
    test_remove_collision_chain();
    test_contains();
    test_resize();
    test_load_factor();
    test_print();

    printf("\nAll tests passed.\n");
    return 0;
}
