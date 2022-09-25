CC = g++
CFLAGS = -g
TARGET = P0
OBJS = tree.o
.SUFFIXES: .cpp .o

.DEFAULT_GOAL : $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	/bin/rm -f *.o *.preorder *.postorder *.inorder $(TARGET)
