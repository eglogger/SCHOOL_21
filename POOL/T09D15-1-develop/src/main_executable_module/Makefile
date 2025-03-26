BUILD_DIR = ../../build

all: main data_stat.a build_with_static data_process.so build_with_dynamic

main: $(BUILD_DIR)/main_executable_module.o $(BUILD_DIR)/decision.o $(BUILD_DIR)/data_io.o $(BUILD_DIR)/data_stat.o $(BUILD_DIR)/data_process.o
	gcc $(BUILD_DIR)/main_executable_module.o $(BUILD_DIR)/decision.o $(BUILD_DIR)/data_io.o $(BUILD_DIR)/data_stat.o $(BUILD_DIR)/data_process.o -o $(BUILD_DIR)/Quest_3

data_stat.a: $(BUILD_DIR)/data_stat.o
	ar rcs $(BUILD_DIR)/data_stat.a $(BUILD_DIR)/data_stat.o

build_with_static: $(BUILD_DIR)/main_executable_module.o $(BUILD_DIR)/decision.o $(BUILD_DIR)/data_io.o $(BUILD_DIR)/data_process.o data_stat.a
	gcc $(BUILD_DIR)/main_executable_module.o $(BUILD_DIR)/decision.o $(BUILD_DIR)/data_io.o $(BUILD_DIR)/data_process.o $(BUILD_DIR)/data_stat.a -o $(BUILD_DIR)/Quest_5

data_process.so: $(BUILD_DIR)/data_process.o $(BUILD_DIR)/data_stat.o
	gcc -shared $(BUILD_DIR)/data_process.o $(BUILD_DIR)/data_stat.o -o $(BUILD_DIR)/data_process.so

build_with_dynamic: $(BUILD_DIR)/main_executable_module.o $(BUILD_DIR)/decision.o $(BUILD_DIR)/data_io.o $(BUILD_DIR)/data_stat.o data_process.so
	gcc $(BUILD_DIR)/main_executable_module.o $(BUILD_DIR)/decision.o $(BUILD_DIR)/data_io.o $(BUILD_DIR)/data_process.so -o $(BUILD_DIR)/Quest_6

$(BUILD_DIR)/main_executable_module.o: main_executable_module.c
	gcc -c main_executable_module.c -o $(BUILD_DIR)/main_executable_module.o

$(BUILD_DIR)/decision.o: ../yet_another_decision_module/decision.c
	gcc -c ../yet_another_decision_module/decision.c -o $(BUILD_DIR)/decision.o

$(BUILD_DIR)/data_io.o: ../data_libs/data_io.c
	gcc -c ../data_libs/data_io.c -o $(BUILD_DIR)/data_io.o

$(BUILD_DIR)/data_stat.o: ../data_libs/data_stat.c
	gcc -c ../data_libs/data_stat.c -o $(BUILD_DIR)/data_stat.o

$(BUILD_DIR)/data_process.o: ../data_module/data_process.c
	gcc -c ../data_module/data_process.c -o $(BUILD_DIR)/data_process.o

run: main
	./$(BUILD_DIR)/Quest_3

clean:
	rm -rf $(BUILD_DIR)/*

rebuild: clean all