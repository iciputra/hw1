# Let's declare some variables
CC       = g++
CPPFLAGS = -Wall -g
BIN_DIR  = bin


all: $(BIN_DIR)/LListInt
	./$(BIN_DIR)/LListInt

GTEST_LL = -I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread

$(BIN_DIR)/LListInt: unitTest.cpp llistint.h $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) llistint.cpp unitTest.cpp $(GTEST_LL) -o $@

.PHONY: copytest

tests: $(BIN_DIR)/LListInt
	-@$(BIN_DIR)/LListInt
	-@echo "--- All Tested!---"

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp