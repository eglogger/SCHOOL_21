#include "list.h"

#include <stdio.h>
#include <stdlib.h>

int test_add_door() {
    Door door1 = {1, 0};
    Door door2 = {2, 1};

    Node* root = init(&door1);
    if (!root) return 0;

    Node* added = add_door(root, &door2);
    if (!added || added->door.id != door2.id) {
        destroy(root);
        return 0;
    }

    destroy(root);
    return 1;
}

int test_remove_door() {
    Door door1 = {1, 0};
    Door door2 = {2, 1};

    Node* root = init(&door1);
    if (!root) return 0;

    Node* added = add_door(root, &door2);
    if (!added) {
        destroy(root);
        return 0;
    }

    root = remove_door(added, root);
    if (find_door(door2.id, root)) {
        destroy(root);
        return 0;
    }

    destroy(root);
    return 1;
}

int main() {
    test_add_door() == 1 ? printf("SUCCESS\n") : printf("FAIL\n");
    test_remove_door() == 1 ? printf("SUCCESS") : printf("FAIL");

    return 0;
}