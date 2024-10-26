CPPFLAGS=-std=c++17 
IPATH=-Iinc/
SRC=src/
OBJ=obj/
CHAIN=g++

all: app

app: main.gch BinarySearchTree.gch
	$(CHAIN) $(OBJ)main.gch $(OBJ)BinarySearchTree.gch -o app

main.gch: $(SRC)main.cpp
	$(CHAIN) $(CPPFLAGS) $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.gch

BinarySearchTree.gch: $(SRC)BinarySearchTree.cpp
	$(CHAIN) $(CPPFLAGS) $(IPATH) -c $(SRC)BinarySearchTree.cpp -o $(OBJ)BinarySearchTree.gch

clean:	
	rm -rf $(OBJ)*.gch

