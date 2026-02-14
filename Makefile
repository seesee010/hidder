SRC = src/code/all_cmds.c \
			src/code/hash-map.c \
			src/code/main.c 

# target detection
ifeq ($(OS),Windows_NT)
	TARGET = hidder.exe
	RM = del /Q
	RUN = .\$(TARGET)
else
	TARGET = hidder
	RM = rm -f 
	RUN = ./$(TARGET)
endif

# so that arguments works in make as well.
ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

all: $(TARGET)

$(TARGET): $(SRC)
	gcc $(SRC) -o $(TARGET)

run: $(TARGET)
	$(RUN) $(RUN_ARGS)

clean:
	$(RM) $(TARGET)