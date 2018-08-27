
CC=gcc

default:exe

exe: main.o Empleado.o lista.o Local.o Mueble.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $^ -c 

run:
	./exe
clean:
	rm -rf main.o Empleado.o lista.o Local.o Mueble.o