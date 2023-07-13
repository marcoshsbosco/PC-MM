#!/bin/bash

make:
	@clear
	@gcc -pthread main.c

	for i in {1..10}; do \
		echo "Execução $i"; \
		time ./a.out 6 1000; \
		echo; \
	done

	for i in {1..10}; do \
		echo "Execução $i"; \
		time ./a.out 6 2000; \
		echo; \
	done

	for i in {1..10}; do \
		echo "Execução $i"; \
		time ./a.out 6 3000; \
		echo; \
	done


