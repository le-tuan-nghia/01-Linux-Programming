.PHONY: all clean

LIB_NAME := utils

CUR_DIR := .
OBJ_DIR := $(CUR_DIR)/objs

LIB_DIR := /home/pnc/Training/01-Linux-Programming/utils
LIB_SRC := $(LIB_DIR)/src
LIB_INC := $(LIB_DIR)/inc

# Include path
INC_FLAGS := -I $(LIB_INC)

CC := gcc
CFLAGS := -pthread

# run:
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./main

# Cần thêm cờ -pthread để build các hàm trong  pthread.h
mk_objs:
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o $(INC_FLAGS)
	$(CC) -c $(LIB_SRC)/stringUtils.c -o $(OBJ_DIR)/stringUtils.o $(INC_FLAGS)
	$(CC) -c $(LIB_SRC)/timeUtils.c -o $(OBJ_DIR)/timeUtils.o $(INC_FLAGS)

mk_static:
	ar rcs $(OBJ_DIR)/lib$(LIB_NAME).a $(OBJ_DIR)/stringUtils.o $(OBJ_DIR)/timeUtils.o

# Chú ý 2 khai báo
# -L: thư mục thư viện
# -l: tên file lib cụ thể muốn trỏ đến
all: mk_objs mk_static
	$(CC) $(OBJ_DIR)/main.o -L$(OBJ_DIR) -l$(LIB_NAME) $(CFLAGS) -o $(CUR_DIR)/main

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf main

