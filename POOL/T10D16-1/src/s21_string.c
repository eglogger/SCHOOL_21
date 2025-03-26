#include "s21_string.h"

int s21_strlen(const char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int s21_strcmp(const char *str1, const char *str2) {
    int i = 0;
    int count = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            count++;
        }
        i++;
    }
    return count;
}

void s21_strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
}

void s21_strcat(char *dst, char *src) {
    int i = 0;
    int len = s21_strlen(src);
    while (src[i] != '\0') {
        dst[i + len] = src[i];
        i++;
        dst[i + len] = '\0';
    }
}

char *s21_strchr(char *str, int c) {
    while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
}

char *s21_strstr(char *str1, char *str2) {
    if (*str2 == '\0') {
        return (char *)str1;
    }

    while (*str1) {
        char *s1 = str1;
        char *s2 = str2;

        while (*s1 && *s2 && (*s1 == *s2)) {
            s1++;
            s2++;
        }

        if (*s2 == '\0') {
            return (char *)str1;
        }

        str1++;
    }

    return 0;
}