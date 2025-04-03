# Makefile para a calculadora
# Use o comando: mingw32-make (no Windows com MSYS2)
# Ou simplesmente: make (no Linux ou WSL)

# Compilador
CC = gcc

# Flags para GTK
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

# Arquivos de origem
SRC = src/main.c src/calculator.c src/ui.c
OBJ = $(SRC:.c=.o)

# Regra principal
calculadora: $(OBJ)
	$(CC) -o calculadora $(OBJ) $(LIBS)

# Regra para objetos
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Regra para limpar
clean:
	rm -f calculadora calculadora.exe src/*.o