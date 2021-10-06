# Makefile
BUILD_ROOT = $(shell pwd)
INCLUDE_PATH =	-I $(BUILD_ROOT)/dtl/ \
				-I $(BUILD_ROOT)/solution/ \
				-I $(BUILD_ROOT)/test/

DEBUG = true

ifeq ($(DEBUG),true)
CC = g++ -std=c++11 -g
VERSION = debug
else
CC = g++ -std=c++11
VERSION = release
endif

TARGET = $(BUILD_ROOT)/tinyDTL

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

LINK_OBJ_DIR = $(BUILD_ROOT)/link_obj
DEP_DIR = $(BUILD_ROOT)/dep

$(shell mkdir -p $(LINK_OBJ_DIR))
$(shell mkdir -p $(DEP_DIR))

OBJS := $(addprefix $(LINK_OBJ_DIR)/, $(OBJS))
DEPS := $(addprefix $(DEP_DIR)/, $(DEPS))

LINK_OBJ = $(wildcard $(LINK_OBJ_DIR)/*.o)
LINK_OBJ += $(OBJS)

all:$(DEPS) $(OBJS) $(TARGET)

ifneq ("$(wildcard $(DEPS))","")
include $(DEPS)
endif

$(TARGET):$(LINK_OBJ)
	@echo "//===----------------------- [build $(VERSION) mode] ------------------------===//"
	$(CC) -o $@ $^

$(LINK_OBJ_DIR)/%.o:%.cpp
	$(CC) $(INCLUDE_PATH) -o $@ -c $(filter %.cpp, $^)

$(DEP_DIR)/%.d:%.cpp
	echo -n $(LINK_OBJ_DIR)/ > $@
	g++ $(INCLUDE_PATH) -MM $^ >> $@

.PHONY: clean 
clean:
	-rm -rf $(TARGET) $(LINK_OBJ_DIR) $(DEP_DIR)

