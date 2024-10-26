CPPFLAGS=-std=c++17 
IPATH=-Iinc/
SRC=src/
OBJ=obj/
CHAIN=g++

all: app

app: main.gch BinaryTree.gch
	$(CHAIN) $(OBJ)main.gch $(OBJ)BinaryTree.gch -o app

main.gch: $(SRC)main.cpp
	$(CHAIN) $(CPPFLAGS) $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.gch

BinaryTree.gch: $(SRC)BinaryTree.cpp
	$(CHAIN) $(CPPFLAGS) $(IPATH) -c $(SRC)BinaryTree.cpp -o $(OBJ)BinaryTree.gch

clean:	
	rm -rf $(OBJ)*.gch

