#Makefile for main

CC=gcc
CCFLAGS=`pkg-config --cflags gtk+-3.0`
CCLIBS=`pkg-config --libs gtk+-3.0`
CLEAN=rm -f
PROGRAM_NAME=main

$(PROGRAM_NAME): main.o app.o chart.o
	$(CC) -o build/$(PROGRAM_NAME) main.o app.o chart.o $(CCLIBS) -Wl,--export-all-symbols

main.o:
	$(CC) $(CCFLAGS) -c examples/main.c

app.o:
	$(CC) $(CCFLAGS) -c examples/app.c

chart.o:
	$(CC) $(CCFLAGS) -c src/chart.c

clean:
	$(CLEAN) *.o
	$(CLEAN) $(PROGRAM_NAME)

