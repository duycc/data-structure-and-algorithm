
SRCS = ./main.cpp
TARGET = ./dsaa

INCLUDE_PATH = -I algorithm/ -I test/ -I data-structure/

CC = g++ 
CFLAGS = -std=c++11

$(TARGET):$(SRCS)
	$(CC) $^ $(CFLAGS) $(INCLUDE_PATH) -o $@

clean:
	-rm -rf $(TARGET)

.PHONY: clean 
