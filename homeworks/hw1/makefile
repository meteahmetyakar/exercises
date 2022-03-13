all: clean compile run

compile: main.c util.c util.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc main.c -c
	@gcc -o test.out main.o util.c

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test.out
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f *.out
