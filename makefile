make:
	@clear
	@gcc -pthread main.c

	@i=1; while [[ $$i -le 10 ]]; do \
		./a.out 1 3; \
		echo; \
		((i = i + 1)); \
	done
