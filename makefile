
CC=gcc

default: main

main: main.o Empleado.o lista.o Local.o Mueble.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $^ -c 

run:
	./exe
clean:
	rm -rf main.o Empleado.o lista.o Local.o Mueble.o
