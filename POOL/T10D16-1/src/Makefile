BUILD_DIR = ../build
FLAGS = -Wall -Werror -Wextra

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests

strlen_tests: $(BUILD_DIR)/s21_string.o s21_string_test.c
	gcc -D QUEST_1 -c s21_string_test.c -o $(BUILD_DIR)/s21_string_test.o
	gcc $(BUILD_DIR)/s21_string.o $(BUILD_DIR)/s21_string_test.o $(FLAGS) -o $(BUILD_DIR)/Quest_1

strcmp_tests: $(BUILD_DIR)/s21_string.o s21_string_test.c
	gcc -D QUEST_2 -c s21_string_test.c -o $(BUILD_DIR)/s21_string_test.o
	gcc $(BUILD_DIR)/s21_string.o $(BUILD_DIR)/s21_string_test.o $(FLAGS) -o $(BUILD_DIR)/Quest_2

strcpy_tests: $(BUILD_DIR)/s21_string.o s21_string_test.c
	gcc -D QUEST_3 -c s21_string_test.c -o $(BUILD_DIR)/s21_string_test.o
	gcc $(BUILD_DIR)/s21_string.o $(BUILD_DIR)/s21_string_test.o $(FLAGS) -o $(BUILD_DIR)/Quest_3

strcat_tests: $(BUILD_DIR)/s21_string.o s21_string_test.c
	gcc -D QUEST_4 -c s21_string_test.c -o $(BUILD_DIR)/s21_string_test.o
	gcc $(BUILD_DIR)/s21_string.o $(BUILD_DIR)/s21_string_test.o $(FLAGS) -o $(BUILD_DIR)/Quest_4

strchr_tests: $(BUILD_DIR)/s21_string.o s21_string_test.c
	gcc -D QUEST_5 -c s21_string_test.c -o $(BUILD_DIR)/s21_string_test.o
	gcc $(BUILD_DIR)/s21_string.o $(BUILD_DIR)/s21_string_test.o $(FLAGS) -o $(BUILD_DIR)/Quest_5

strstr_tests: $(BUILD_DIR)/s21_string.o s21_string_test.c
	gcc -D QUEST_6 -c s21_string_test.c -o $(BUILD_DIR)/s21_string_test.o
	gcc $(BUILD_DIR)/s21_string.o $(BUILD_DIR)/s21_string_test.o $(FLAGS) -o $(BUILD_DIR)/Quest_6

$(BUILD_DIR)/s21_string.o: s21_string.c
	gcc -c s21_string.c -o $(BUILD_DIR)/s21_string.o

$(BUILD_DIR)/s21_string_test.o: s21_string_test.c
	gcc -c s21_string_test.c -o $(BUILD_DIR)/s21_string_test.o

q1: strlen_tests
	./$(BUILD_DIR)/Quest_1

q2: strcmp_tests
	./$(BUILD_DIR)/Quest_2

q3: strcpy_tests
	./$(BUILD_DIR)/Quest_3

q4: strcat_tests
	./$(BUILD_DIR)/Quest_4

q5: strchr_tests
	./$(BUILD_DIR)/Quest_5

q6: strstr_tests
	./$(BUILD_DIR)/Quest_6

clean:
	rm -rf $(BUILD_DIR)/*

rebuild: clean all