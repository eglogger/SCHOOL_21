#ifndef LIST_H
#define LIST_H

#include "door_struct.h"

typedef struct node {
    Door door;
    struct node* next;
} Node;

Node* init(const Door* door);
Node* add_door(Node* elem, const Door* door);
Node* find_door(int door_id, const Node* root);
Node* remove_door(Node* elem, Node* root);
void destroy(Node* root);

#endif