make:
	@clear
	@gcc -pthread main.c

	@echo --- Matriz 1000x1000 ---

	@i=1; while [[ $$i -le 10 ]]; do \
		time ./a.out 1 1000; \
		time ./a.out 2 1000; \
		time ./a.out 3 1000; \
		time ./a.out 4 1000; \
		time ./a.out 5 1000; \
		time ./a.out 6 1000; \
		time ./a.out 7 1000; \
		time ./a.out 8 1000; \
		((i = i + 1)); \
	done

	@echo --- Matriz 1500x1500 ---

	@i=1; while [[ $$i -le 10 ]]; do \
		time ./a.out 1 1500; \
		time ./a.out 2 1500; \
		time ./a.out 3 1500; \
		time ./a.out 4 1500; \
		time ./a.out 5 1500; \
		time ./a.out 6 1500; \
		time ./a.out 7 1500; \
		time ./a.out 8 1500; \
		((i = i + 1)); \
	done

	@echo --- Matriz 2250x2250 ---

	@i=1; while [[ $$i -le 10 ]]; do \
		time ./a.out 1 2250; \
		time ./a.out 2 2250; \
		time ./a.out 3 2250; \
		time ./a.out 4 2250; \
		time ./a.out 5 2250; \
		time ./a.out 6 2250; \
		time ./a.out 7 2250; \
		time ./a.out 8 2250; \
		((i = i + 1)); \
	done
