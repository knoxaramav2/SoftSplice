#compiles application
SRC= util.c splice.c main.c
O_SRC = $(SRC:.c=.o)
OUT=ssplice

.c.o:
	$(CC) -c -o $@ $< -g

$(OUT).exe : $(O_SRC)
	$(CC) -o $@ $(O_SRC)

.PHONY: clean
clean:
	rm -f *.o *.exe

.PHONY: run
run:
	./$(OUT)

.PHONY: dev
dev:
	./$(OUT) -hv