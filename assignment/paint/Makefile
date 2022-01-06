CC := gcc
SRC := ./src
LIB := ./lib
OBJS = $(LIB)/paintapp.o $(LIB)/interpret.o $(LIB)/history.o $(LIB)/draw_screen.o $(LIB)/canvas.o
INCLUDE := -I./include
TARGETDIR := ./bin

paint: $(OBJS)
	$(CC) $(INCLUDE) -o $(TARGETDIR)/$@ $^

$(LIB)/%.o : $(SRC)/%.c
	$(CC) -o $@ -c $^ $(INCLUDE)

.PHONY: clean
clean:
	rm $(LIB)/*.o $(TARGETDIR)/*