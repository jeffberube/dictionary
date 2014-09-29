CC = g++
OBJ = dictionary.o 
LIB = 

dictionary: $(OBJ)
	$(CC) $(OBJ) $(LIB) -g -o $@

.c.o:
	$(CC) -c $<

clean:
	rm *.o dictionary 
