# Variable de entorno (Para en el caso de que se quiera correr en MacOS)
# Se instala GCC con Homebrew y se usa make CC=gcc-15
CC ?= gcc 
CFLAGS = -fopenmp 

TARGET = Lab01Daza Lab02Daza Lab03Daza Lab04Daza Lab05Daza Lab06Daza 

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -f $(TARGET)

