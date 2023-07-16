make:
	@clear

	rm -f tempos.dat

	gcc -pthread paralelo.c -o paralelo.out
	gcc sequencial.c -o sequencial.out

	echo --- Matriz 1000x1000 --- >> tempos.dat

	for i in $$(seq 1 10); do \
		echo >> tempos.dat; \
		echo Iteração $$i >> tempos.dat; \
		\
		echo >> tempos.dat; \
		echo Sequencial >> tempos.dat; \
		{ time ./sequencial.out 1000 ; } 2>> tempos.dat; \
		\
		for j in $$(seq 1 8); do \
			echo >> tempos.dat; \
			echo Fluxos: $$j >> tempos.dat; \
			{ time ./paralelo.out $$j 1000 ; } 2>> tempos.dat; \
			((j = j + 1)); \
		done; \
		\
		((i = i + 1)); \
	done

	echo >> tempos.dat; \
	echo --- Matriz 1500x1500 --- >> tempos.dat

	for i in $$(seq 1 10); do \
		echo >> tempos.dat; \
		echo Iteração $$i >> tempos.dat; \
		\
		echo >> tempos.dat; \
		echo Sequencial >> tempos.dat; \
		{ time ./sequencial.out 1500 ; } 2>> tempos.dat; \
		\
		for j in $$(seq 1 8); do \
			echo >> tempos.dat; \
			echo Fluxos: $$j >> tempos.dat; \
			{ time ./paralelo.out $$j 1500 ; } 2>> tempos.dat; \
			((j = j + 1)); \
		done; \
		\
		((i = i + 1)); \
	done

	echo >> tempos.dat; \
	echo --- Matriz 2250x2250 --- >> tempos.dat

	for i in $$(seq 1 10); do \
		echo >> tempos.dat; \
		echo Iteração $$i >> tempos.dat; \
		\
		echo >> tempos.dat; \
		echo Sequencial >> tempos.dat; \
		{ time ./sequencial.out 2250 ; } 2>> tempos.dat; \
		\
		for j in $$(seq 1 8); do \
			echo >> tempos.dat; \
			echo Fluxos: $$j >> tempos.dat; \
			{ time ./paralelo.out $$j 2250 ; } 2>> tempos.dat; \
			((j = j + 1)); \
		done; \
		\
		((i = i + 1)); \
	done
