BUILD_DIR = ../build
FLAGS = -Wall -Werror -Wextra

all: door_struct list_test stack_test

door_struct: dmanager_module.c
	gcc dmanager_module.c $(FLAGS) -o $(BUILD_DIR)/Quest_1

list_test: list.c list_test.c
	gcc list.c list_test.c $(FLAGS) -o $(BUILD_DIR)/Quest_2

stack_test: stack.c stack_test.c
	gcc stack.c stack_test.c $(FLAGS) -o $(BUILD_DIR)/Quest_3

clean:
	rm -rf $(BUILD_DIR)/*

rebuild: clean all

.PHONY: all clean rebuild