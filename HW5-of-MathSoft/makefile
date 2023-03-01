FileName=main

all:
	gcc -I/usr/local/include/gsl -o ./bin/roots ./src/roots.c -lgsl -lgslcblas

report:
	cd doc && make report

clean:
	cd doc && make clean