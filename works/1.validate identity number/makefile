all: clean compile run

compile: test_driver.c util.c util.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc test_driver.c -c
	@gcc -o test.out test_driver.o util.c

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
