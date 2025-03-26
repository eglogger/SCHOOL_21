CC=gcc -Wall -Werror -Wextra -std=c11
BUILD_DIR=../build

all: cipher

cipher: cipher.c
	$(CC) cipher.c -o $(BUILD_DIR)/cipher

clean:
	rm -rf ../build/*

rebuild: clean build
