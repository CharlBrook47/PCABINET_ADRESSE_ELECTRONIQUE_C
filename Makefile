# REPERTOIRE MAKEFILE						
# ================================================================== #
TARGET 			= main
# compiler
CC 			= gcc
# debug
DEBUG 			= -g
# optimisation
OPT 			= -O0
# warnings
WARN 			= -Wall
PTHREAD 		= -pthread
CCFLAGS 		= $(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
# libraries
GTKLIB 			= `pkg-config --cflags --libs gtk+-3.0`
MYSQLFLAGS 		= `mysql_config --cflags`
MYSQLLIBS 		= `mysql_config --libs`
# linker
LDFLAGS 		= $(PTHREAD) $(GTKLIB) -export-dynamic
OBJS 			= main.o fonction.o
# ================================================================== #
all: $(OBJS)
	$(CC) $(MYSQLFLAGS) $(OBJS) $(MYSQLLIBS) $(LDFLAGS) -o $(TARGET)
	rm -f *.o

main.o: main.c
	$(CC) -c $(CCFLAGS) $(MYSQLFLAGS) main.c $(MYSQLLIBS) $(GTKLIB) -o main.o

fonction.o: fonction.c
	$(CC) -c $(CCFLAGS) $(MYSQLFLAGS) fonction.c $(MYSQLLIBS) $(GTKLIB) -o fonction.o

clean:
	rm -f *.o $(TARGET)
# ================================================================== #
