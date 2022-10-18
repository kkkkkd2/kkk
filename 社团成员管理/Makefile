CC=g++
OBJS=main.o emis.o manager.o department.o employee.o tools.o manager_ctrl_impl.o manager_mode_impl.o manager_view_impl.o service_ctrl_impl.o service_mode_impl.o service_view_impl.o
FLAG=-Wall -Werror
BIN=eims.bin

all:$(OBJS)
	$(CC) $(OBJS) -o $(BIN) && ./$(BIN)

%.o:%.cpp
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf *~ $(OBJS) $(BIN) *.h.gch
