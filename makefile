make:
	@clear
	@gcc -pthread main.c

	@i=1; while [[ $$i -le 10 ]]; do \
		time ./a.out 6 1000; \
		echo; \
		((i = i + 1)); \
	done

	@i=1; while [[ $$i -le 10 ]]; do \
		time ./a.out 6 2000; \
		echo; \
		((i = i + 1)); \
	done

	@i=1; while [[ $$i -le 10 ]]; do \
		time ./a.out 6 3000; \
		echo; \
		((i = i + 1)); \
	done
