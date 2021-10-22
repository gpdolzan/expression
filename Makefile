#Makefile padrao

#Variaveis
CFLAGS = -Wall

#arquivos-objeto
objects = main.o binary_tree.o expression.o

#regra default
all: calculadora

calculadora: $(objects)
	gcc $(CFLAGS) $(objects) -o calculadora

main.o: main.c
	cc -c main.c $(CFLAGS)

binary_tree.o: binary_tree.c binary_tree.h
	cc -c binary_tree.c $(CFLAGS)

expression.o: expression.c expression.h
	cc -c expression.c $(CFLAGS)

#remove arquivos temporarios
clean:
	rm -f *~ *.o

#remove arquivos temporarios e executavel 
purge: clean
	rm -f calculadora