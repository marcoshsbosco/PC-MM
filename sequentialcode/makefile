#!/bin/bash

make:
	@clear
	@gcc sequential.c -o sequential.c

	for i in {1..10}; do \
		echo "Execução $i"; \
		time ./sequential.out 1000; \
		echo; \
	done

	for i in {1..10}; do \
		echo "Execução $i"; \
		time ./sequential.out 2000; \
		echo; \
	done

	for i in {1..10}; do \
		echo "Execução $i"; \
		time ./sequential.out 3000; \
		echo; \
	done
