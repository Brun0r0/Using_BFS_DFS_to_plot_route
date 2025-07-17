#nome do executável
EXEC = programa

#Compilador
CC = gcc

#flags de compilação
CFLAGS = -Wall -Wextra -std=c99

#Arquivos fonte
SRC = main.c grafo.c busca.c FilaEstatica.c PilhaEstatica.c

#Arquivos objeto
OBJ = $(SRC:.c=.o)

#Compilar tudo
all: $(EXEC)

#Construção do executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


#Compilar cada arquivo .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Limpar arquivos gerados
clean:
	rm -f $(OBJ) $(EXEC)