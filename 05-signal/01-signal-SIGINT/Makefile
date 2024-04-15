
CC := gcc
CFLAGS := -pthread

# run:
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./main

# Cần thêm cờ -pthread để build các hàm trong  pthread.h
all:
	$(CC) -o main main.c $(CFLAGS)

clean:
	rm -rf main

