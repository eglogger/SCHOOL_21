#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void read_file(char *filename);
int write_file(char *filename);

int main(){
    menu();
}

void menu() {
    int n;
    char check;
    while (1) {
        if (scanf("%d%c", &n, &check) != 2) {
            while(getchar() != '\n');
            n = 0;
        }

        switch (n) {
            case -1: exit(0);
            case 1:
                char file[100];
                if (scanf("%s", file) != 1){
                    printf("n/a\n");
                    break;
                } else if (strcmp(file, "-1") == 0) {
                    exit(0);
                } else {
                    read_file(file);        
                    printf("\n");
                    break;
                }
            case 2:
                if (write_file(file)) {
                    read_file(file);
                    printf("\n");
                }
                break;
            default:
                printf("n/a\n");
                break;
        }
    }
        
}

void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("n/a");   
    } else {
        char result;
        while (fscanf(file, "%c", &result) == 1){
            printf("%c", result);
        } 
    }
    fclose(file);
    
}

int write_file(char *filename) {
    int flag = 1;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("n/a\n");
        fclose(file);
        flag = 0;
    } else {
        file = fopen(filename, "a+");
        char input[100];
        if (scanf("%s", input) != 1){
            printf("n/a");
        } else if (strcmp(input, "-1") == 0) {
            exit(0);
        } else fprintf(file, "%s", input);
    }
    fclose(file);
    return flag;
}