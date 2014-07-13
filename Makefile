#Makefile for main

CC=gcc
CCFLAGS=`pkg-config --cflags gtk+-3.0`
CCLIBS=`pkg-config --libs gtk+-3.0`
CLEAN=rm -f
PROGRAM_NAME=main

$(PROGRAM_NAME): main.o app.o chart.o
	$(CC) -o $(PROGRAM_NAME) main.o app.o chart.o $(CCLIBS)

main.o:
	$(CC) $(CCFLAGS) -c main.c

app.o:
	$(CC) $(CCFLAGS) -c app.c

chart.o:
	$(CC) $(CCFLAGS) -c chart.c

clean:
	$(CLEAN) *.o
	$(CLEAN) $(PROGRAM_NAME)

