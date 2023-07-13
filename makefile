#!/bin/bash

make:
	@clear

	@rm -f tempos.dat

	@gcc -pthread main.c

	@echo --- Matriz 1000x1000 --- >> tempos.dat

	@i=1; while [[ $$i -le 10 ]]; do \
		echo >> tempos.dat; \
		echo Iteração $$i >> tempos.dat; \
		\
		j=1; while [[ $$j -le 8 ]]; do \
			echo >> tempos.dat; \
			echo Fluxos: $$j >> tempos.dat; \
			{ time ./a.out $$j 1000 ; } 2>> tempos.dat; \
			((j = j + 1)); \
		done; \
		\
		((i = i + 1)); \
	done

	@echo --- Matriz 1500x1500 --- >> tempos.dat

	@i=1; while [[ $$i -le 10 ]]; do \
		echo >> tempos.dat; \
		echo Iteração $$i >> tempos.dat; \
		\
		j=1; while [[ $$j -le 8 ]]; do \
			echo >> tempos.dat; \
			echo Fluxos: $$j >> tempos.dat; \
			{ time ./a.out $$j 1500 ; } 2>> tempos.dat; \
			((j = j + 1)); \
		done; \
		\
		((i = i + 1)); \
	done

	@echo --- Matriz 2250x2250 --- >> tempos.dat

	@i=1; while [[ $$i -le 10 ]]; do \
		echo >> tempos.dat; \
		echo Iteração $$i >> tempos.dat; \
		\
		j=1; while [[ $$j -le 8 ]]; do \
			echo >> tempos.dat; \
			echo Fluxos: $$j >> tempos.dat; \
			{ time ./a.out $$j 2250 ; } 2>> tempos.dat; \
			((j = j + 1)); \
		done; \
		\
		((i = i + 1)); \
	done


