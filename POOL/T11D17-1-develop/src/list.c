#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node* init(const Door* door) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return NULL;

    new_node->door = *door;
    new_node->next = NULL;

    return new_node;
}

Node* add_door(Node* elem, const Door* door) {
    if (!elem) return NULL;
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return NULL;

    new_node->door = *door;
    new_node->next = elem->next;
    elem->next = new_node;

    return new_node;
}

Node* find_door(int door_id, const Node* root) {
    const Node* current = root;

    while (current) {
        if (current->door.id == door_id) {
            return (Node*)current;
        }
        current = current->next;
    }

    return NULL;
}

Node* remove_door(Node* elem, Node* root) {
    if (!root || !elem) return root;

    if (root == elem) {
        Node* new_root = root->next;
        free(root);
        return new_root;
    }

    Node* current = root;
    while (current->next && current->next != elem) {
        current = current->next;
    }

    if (current->next) {
        current->next = elem->next;
        free(elem);
    }

    return root;
}

void destroy(Node* root) {
    while (root) {
        Node* temp = root;
        root = root->next;
        free(temp);
    }
}