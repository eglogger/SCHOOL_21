#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(Door *doors);
void sort(Door *doors, int size);
void close_all(Door *doors, int size);
void output(Door *doors, int size);

int main() {
    Door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors, DOORS_COUNT);
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
    output(doors, DOORS_COUNT);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(Door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(Door *doors, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                Door temp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = temp;
            }
        }
    }
}

void output(Door *doors, int size) {
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d, %d", doors[i].id, doors[i].status);
        } else {
            printf("%d, %d\n", doors[i].id, doors[i].status);
        }
    }
}