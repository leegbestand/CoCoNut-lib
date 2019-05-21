MKDIR = mkdir -p

CC           := gcc
CFLAGS       := -Wall -std=gnu11 -g -Og -pedantic -MMD \
				-Werror=implicit-function-declaration
LDFLAGS      := 
INCLUDE_DIRS = -Iinclude/
SOURCE_DIR = source
BIN_DIR = bin
BUILD_DIR  = build
SILENCED:=
AR := ar
AR_FLAGS := rcs
SRC := $(wildcard $(SOURCE_DIR)/*.c)
OBJ := $(SRC:.c=.o)
OBJ := $(patsubst $(SOURCE_DIR)/%, $(BUILD_DIR)/%, $(OBJ))

coconut-lib: $(BIN_DIR)/libcoconut.a

$(BIN_DIR)/libcoconut.a: $(OBJ)
	$(SILENCED)$(AR) $(AR_FLAGS) $@ $^ 


$(OBJ): | $(BUILD_DIR) $(BIN_DIR)

$(BUILD_DIR): 
	$(SILENCED)$(MKDIR) $@

$(BIN_DIR):
	$(SILENCED)$(MKDIR) $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(SILENCED)$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ -c $<

.PHONY = clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
