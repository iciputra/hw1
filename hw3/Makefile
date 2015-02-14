# Let's declare some variables
CC       = g++
CPPFLAGS = -Wall -g
BIN_DIR  = bin

GTEST_LL = -I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread

$(BIN_DIR)/LListInt: unitTest.cpp llistint.h $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) llistint.cpp unitTest.cpp $(GTEST_LL) -o $@

$(BIN_DIR)/SetTest: settest.cpp setint.h llistint.h $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) llistint.cpp setint.cpp settest.cpp $(GTEST_LL) -o $@

$(BIN_DIR)/MAPS: maps.cpp llistint.h $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) llistint.cpp maps.cpp -o $@

.PHONY: copytest settest pgindex 

copytest: $(BIN_DIR)/LListInt
	-@$(BIN_DIR)/LListInt
	-@echo "--- All Tested!---"

settest: $(BIN_DIR)/SetTest
	-@$(BIN_DIR)/SetTest
	-@echo "--- All Tested!---"

pgindex: $(BIN_DIR)/MAPS 
	-@$(BIN_DIR)/MAPS


$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp