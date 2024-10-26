CPPFLAGS=-std=c++17 
IPATH=-Iinc/
SRC=src/
OBJ=obj/
CHAIN=g++

all: app

app: main.gch BinarySearchTreeAVL.gch
	$(CHAIN) $(OBJ)main.gch $(OBJ)BinarySearchTreeAVL.gch -o app

main.gch: $(SRC)main.cpp
	$(CHAIN) $(CPPFLAGS) $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.gch

BinarySearchTreeAVL.gch: $(SRC)BinarySearchTreeAVL.cpp
	$(CHAIN) $(CPPFLAGS) $(IPATH) -c $(SRC)BinarySearchTreeAVL.cpp -o $(OBJ)BinarySearchTreeAVL.gch

clean:	
	rm -rf $(OBJ)*.gch

