CC = g++
OBJ = dictionary.o 

dictionary: $(OBJ)
	$(CC) $(OBJ) -g -o $@

.c.o:
	$(CC) -c $<

clean:
	rm *.o dictionary 
