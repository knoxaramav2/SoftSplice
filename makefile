#compiles application
SRC= file.c util.c splice.c main.c
O_SRC = $(SRC:.c=.o)
OUT=ssplice
BITVRS=64

#get OS
ifeq ($(shell uname), Linux)
	FixPath = $1
	LIB_EXT = .a
	EXEC_EXT = 
	OS_NAME = GNU
else
#Windows
	FixPath = $(subst /,\,$1)
	LIB_EXT = .a#.lib
	EXEC_EXT = .exe
	OS_NAME = WINDOWS
endif

COMMON= -m$(BITVRS) -D$(OS_NAME) -Wall -g

.c.o:
	$(CC) -c -o $@ $< $(COMMON)

$(OUT).exe : $(O_SRC)
	$(CC) -o $@ $(O_SRC)

.PHONY: clean
clean:
	rm -f *.o *.exe

.PHONY: run
run:
	./$(OUT)$(EXEC_EXT)

.PHONY: dev
dev:
	./$(OUT) -hv