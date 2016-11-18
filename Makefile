OBJS := nscanf.o main.o
CFLAGS := -Wall -g

nscanf_test: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)

$(OBJS): nscanf.h Makefile

clean:
	-rm $(OBJS) nscanf_test
