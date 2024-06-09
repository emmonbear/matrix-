PROJECT_NAME = s21_matrix_oop

# COMPILER ===================================================================#
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g
LDFLAGS = -lgtest
#=============================================================================#

# DIRECTORIES ================================================================#
OBJ_DIR = ./obj
MODULES_DIR = ./modules
TESTS_DIR = ./tests
REPORT_DIR = ./report
DVI_DIR = ../docs
INCLUDE_DIR = ./include
DEBUG_DIR = ./debug
#=============================================================================#

# TARGET NAMES ===============================================================#
TARGET = test
LIB = $(PROJECT_NAME).a 
#=============================================================================#

# LIST OF FILES AND DIRECTORIES IN MODULES ===================================#
MODULES_DIRS = $(shell find $(MODULES_DIR) -type d)
MODULES_CC = $(shell find $(MODULES_DIR) -type f -name "*.cc")
MODULES_H = $(shell find $(INCLUDE_DIR) -type f -name "*.h")
MODULES_O = $(notdir $(MODULES_CC:%.cc=%.o))
MODULES_OBJ_PATH = $(addprefix $(OBJ_DIR)/modules/, $(MODULES_O))
#=============================================================================#

# LIST OF FILES AND DIRECTORIES IN TESTS =====================================#
TESTS_DIRS = $(shell find $(TESTS_DIR) -type d)
TESTS_CC = $(shell find $(TESTS_DIR) -type f -name "*.cc")
TESTS_H = $(shell find $(TESTS_DIR) -type f -name "*.h")
TESTS_O = $(notdir $(TESTS_CC:%.cc=%.o))
TESTS_OBJ_PATH = $(addprefix $(OBJ_DIR)/tests/, $(TESTS_O))
#=============================================================================#

# LIST OF FILES AND DIRECTORIES IN DEBUG =====================================#
DEBUG_CC = $(shell find $(DEBUG_DIR) -type f -name "*.cc")
DEBUG_H = $(shell find $(DEBUG_DIR) -type f -name "*.h")
DEBUG_O = $(notdir $(DEBUG_CC:%.cc=%.o))
DEBUG_OBJ_PATH = $(addprefix $(OBJ_DIR)/debug/, $(DEBUG_O))

# LIST OF FILES TO CLANG-FORMAT AND CPPCHECK =================================#
CC_FILES = $(MODULES_CC)
H_FILES = $(MODULES_H)
#=============================================================================#

vpath %.cc $(MODULES_DIRS) $(TESTS_DIRS) $(DEBUG_DIR)
vpath %.o $(OBJ_DIR)

# TARGETS ====================================================================#
.PHONY: all
all: $(LIB)

.PHONY: $(LIB)
$(LIB): $(OBJ_DIR) $(MODULES_O) $(MODULES_H)
	ar rcs $@ $(MODULES_OBJ_PATH)
	ranlib $@

.PHONY: $(TARGET)
$(TARGET): $(LIB) $(OBJ_DIR) $(TESTS_O) $(DEBUG_O)
	$(CXX) $(TESTS_OBJ_PATH) $(LIB) $(LDFLAGS) $(DEBUG_OBJ_PATH) -o $@
	./$@

%_debug.o: %_debug.cc $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $(addprefix $(OBJ_DIR)/debug/, $@) $<

%_test.o: %_test.cc $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $(addprefix $(OBJ_DIR)/tests/, $@) $<

%.o: %.cc $(MODULES_H) $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $(addprefix $(OBJ_DIR)/modules/, $@) $<
#=============================================================================#

clang_fix:
	clang-format -style=Google -i $(CC_FILES) $(H_FILES)

clang_check:
	clang-format -style=Google -n $(CC_FILES) $(H_FILES)

cpplint:
	cpplint $(CC_FILES) $(H_FILES)

clean:
	rm -f $(TARGET)
	rm -f $(LIB)
	rm -rf $(OBJ_DIR)
.PHONY: preferences
preferences:
	sudo apt install libgtest-dev

#=============================================================================#
# .PHONY $(OBJ_DIR)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/tests/
	mkdir -p $(OBJ_DIR)/modules/
	mkdir -p $(OBJ_DIR)/debug/

# .PHONY $(DVI_DIR)
$(DVI_DIR):
	mkdir -p $(DVI_DIR)

#=============================================================================#