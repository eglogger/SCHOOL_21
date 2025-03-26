#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

int main() {
#ifdef QUEST_1
    s21_strlen_test();
#endif

#ifdef QUEST_2
    s21_strcmp_test();
#endif

#ifdef QUEST_3
    s21_strcpy_test();
#endif

#ifdef QUEST_4
    s21_strcat_test();
#endif

#ifdef QUEST_5
    s21_strchr_test();
#endif

#ifdef QUEST_6
    s21_strstr_test();
#endif

    return 0;
}

void s21_strlen_test() {
    char *string = "hello";
    s21_strlen(string) == 5 ? printf("SUCCESS\n") : printf("FAIL\n");

    string = "\0";
    s21_strlen(string) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    string = "a";
    s21_strlen(string) == 1 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcmp_test() {
    char *string1 = "hello";
    char *string2 = "hello";
    s21_strcmp(string1, string2) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    string1 = "hell01";
    string2 = "hell0";
    s21_strcmp(string1, string2) != 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    string1 = "\n";
    string2 = "\0";
    s21_strcmp(string1, string2) != 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcpy_test() {
    char string1[] = "heyho";
    char string2[] = "hello";
    s21_strcpy(string2, string1);
    s21_strcmp(string1, string2) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    char string3[] = "hey";
    char string4[] = "hello";
    s21_strcpy(string4, string3);
    s21_strcmp(string3, string4) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    char string5[] = "heyho";
    char string6[] = "hi";
    s21_strcpy(string6, string5);
    s21_strcmp(string5, string6) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcat_test() {
    char string1[] = "heyho";
    char string2[] = "hello";
    char string_r[] = "helloheyho";
    s21_strcat(string2, string1);
    s21_strcmp(string_r, string2) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    char string3[] = "hello";
    char string4[] = "!";
    char string_r1[] = "hello!";
    s21_strcat(string3, string4);
    s21_strcmp(string_r1, string3) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    char string5[] = "hello";
    char string6[] = "";
    char string_r2[] = "hello";
    s21_strcat(string5, string6);
    s21_strcmp(string_r2, string5) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strchr_test() {
    char string1[] = "heyho";
    char ch = 'y';
    s21_strchr(string1, ch) - string1 == 2 ? printf("SUCCESS\n") : printf("FAIL\n");

    ch = 'h';
    s21_strchr(string1, ch) - string1 == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    ch = 'o';
    s21_strchr(string1, ch) - string1 == 4 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strstr_test() {
    char string1[] = "heyhello";
    char string2[] = "hello";
    s21_strcmp(s21_strstr(string1, string2), string2) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    char string3[] = "heyhello";
    char string4[] = "hey";
    s21_strcmp(s21_strstr(string3, string4), string3) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    char string5[] = "hello";
    char string6[] = "hey";
    s21_strstr(string5, string6) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}