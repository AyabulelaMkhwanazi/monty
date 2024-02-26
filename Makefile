CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c89
TARGET=monty

all:
	@i=0; \
	total=100; \
	while [ $$i -le $$total ]; do \
		perc=$$((200*$$i/$$total % 2 + 100*$$i/$$total)); \
		printf "\rCompiling: $$perc%%"; \
		sleep 0.01; \
		i=$$((i+1)); \
	done; \
	$(CC) $(CFLAGS) *.c -o $(TARGET) > /dev/null 2>&1; \
	printf "\rCOMPILED\n"; \
	sleep 2; \
	printf "\033[1A\033[2K\033[1A";

clean:
	rm -f $(TARGET)
