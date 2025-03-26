CC=gcc -Wall -Werror -Wextra -std=c11
BUILD_DIR=../build

all: build

build: rpn_test

rpn_test: draw.c graph.c stack.c rpn.c lexemas_list.c input_check.c
	$(CC) draw.c graph.c stack.c rpn.c lexemas_list.c input_check.c -o $(BUILD_DIR)/build_graph

clean:
	rm -rf ../build/*

rebuild: clean build