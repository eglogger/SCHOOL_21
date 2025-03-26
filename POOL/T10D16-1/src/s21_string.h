#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
void s21_strcpy(char *dst, const char *src);
void s21_strcat(char *dst, char *src);
char *s21_strchr(char *str, int c);
char *s21_strstr(char *str1, char *str2);

#endif
