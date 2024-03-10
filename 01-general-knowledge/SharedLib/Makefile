.PHONY: all clean

LIB_NAME := test

CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
SRC_DIR := $(CUR_DIR)/src
OBJ_DIR := $(CUR_DIR)/objs

LIB_DIR := $(CUR_DIR)/libs
LIB_STATIC := $(LIB_DIR)/static
LIB_SHARED := $(LIB_DIR)/shared

# Include path
INC_FLAGS := -I $(INC_DIR)

CC := gcc


# Add flag -fPIC to create the shared lib
mk_objs:
	$(CC) -c $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o $(INC_FLAGS)
	$(CC) -c $(SRC_DIR)/strUtils.c -o $(OBJ_DIR)/strUtils.o $(INC_FLAGS)
	$(CC) -c $(SRC_DIR)/timeUtils.c -o $(OBJ_DIR)/timeUtils.o $(INC_FLAGS)

# Tên lib bắt buộc có tiền số 'lib'
mk_static:
	ar rcs $(LIB_STATIC)/lib$(LIB_NAME).a $(OBJ_DIR)/strUtils.o $(OBJ_DIR)/timeUtils.o

# Chú ý 2 khai báo
# -L: thư mục thư viện
# -l: tên file lib cụ thể muốn trỏ đến
all: mk_objs mk_static
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_STATIC) -l$(LIB_NAME) -o $(BIN_DIR)/test_static

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(LIB_STATIC)/*
	rm -rf $(BIN_DIR)/*

