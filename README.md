# Data Structures

Welcome to the **Data Structures** repository! This repository contains various implementations of fundamental data structures and algorithms in C++ and showcases my understanding and application of these concepts. Whether you're a student, a developer, or just someone interested in learning more about data structures, this repository is here to help.

---

## Table of Contents
- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [Features](#features)
- [Usage](#usage)

---

## Introduction

Data structures are a critical component of computer science and programming. This repository focuses on the implementation and practical application of common data structures:

- **Graphs**
- **Binary Trees**
- **Binary Search Trees**
- **AVL Trees**
- **Linked List**
- **Sorting Algorithms**

---

## Project Structure

### **Graph/**
### Hash Table Implementation with `std::unordered_map`

The graph's adjacency list is implemented using `std::unordered_map<size_t, std::list<size_t>>`, which provides efficient storage and access for vertex connections. This data structure leverages a hash table, allowing for average-case time complexities of **O(1)** for key operations such as search, insertion, and deletion.

#### Benefits of Using `std::unordered_map`:
- **Fast Access**: The average time complexity for searching for a vertex or edge is **O(1)**, making it efficient to retrieve connected vertices.
- **Dynamic Resizing**: `std::unordered_map` dynamically resizes as needed, accommodating changes in the number of vertices without a significant performance hit.
- **Flexibility**: This implementation allows for easy management of sparse graphs, as it only stores edges that exist, reducing memory usage compared to dense representations.

By utilizing `std::unordered_map`, graph operations can be performed quickly and efficiently, making it suitable for a variety of applications requiring dynamic graph modifications and frequent lookups.

#### Features
- **Graph Construction**: Create graphs from a specified number of vertices with a given edge probability or from an input file.
- **Edge Management**: Methods to add edges, check if an edge exists, and manage vertex connections efficiently.
- **Vertex Management**: Functions to check for vertex existence, get the degree of a vertex, and delete vertices along with their connections.
- **Traversal Algorithms**: Implementations of breadth-first search (BFS) and depth-first search (DFS) for exploring the graph structure.
- **Adjacency List Representation**: Utilizes an unordered map for efficient access to connected vertices.
- **Error Handling**: Mechanisms for handling file I/O errors and vertex management issues, ensuring robustness.
- **Performance**: Optimized operations, typically operating within *O(1)* for insertion and *O(V + E)* for traversal methods.


### **Trees/**

#### Features
- **Insertion and Deletion**: Efficient methods for adding and removing elements in trees.
- **Traversal Algorithms**: Pre-order, in-order, and post-order traversal implementations.
- **Serialization and Deserialization**: Functionality to convert trees to and from string representations.
- **Error Handling**: Comprehensive error handling for various operations, ensuring robustness.
- **Performance**: Optimized algorithms for balanced tree structures, typically *O(log n)*.

---

### **Searchs/**

- **Binary Search/**: Efficiently finds the position of a target value within a sorted array.
- **Ternary Search/**: Similar to binary search but divides the array into three parts.
- **Exponential Search/**: Combines binary search with exponential growth for large datasets.

#### Features
- **Error Handling**: Checks for edge cases, such as empty arrays and invalid inputs, ensuring robust search operations.
- **Performance**: Optimized for fast searches in sorted data, with all algorithms operating in *O(log n)* time complexity.

---

### **Linked List/**

- **Singly Linked List**: Supports operations such as insertion, deletion, and traversal of nodes.

#### Features
- **Node Operations**: Supports basic operations like insertion (at head, tail, or specific position) and deletion.
- **Traversal Methods**: Access or modify node values through forward and backward traversals.
- **Memory Management**: Dynamic memory allocation and deallocation practices to prevent memory leaks.
- **Error Handling**: Mechanisms to manage edge cases, such as operations on empty lists.
- **Performance**: Offers time complexity benefits compared to arrays, with average complexities of *O(1)* for insertions and *O(n)* for traversal.

---

### **Sorts/**

- **BubbleSort/**: Sorts arrays through iterative comparisons.
- **InsertionSort/**: Efficiently sorts small datasets or partially sorted arrays.
- **SelectionSort/**: Selects the smallest element and places it in its correct position.
- **QuickSort/**: Uses a divide-and-conquer approach to sort arrays efficiently.
- **MergeSort/**: Divides the array into halves, sorts them, and merges the sorted halves.

#### Features
- **Error Handling**: Validation checks for edge cases, such as empty arrays.
- **Performance**: Each sorting algorithm is optimized for different scenarios, providing flexibility based on dataset characteristics.

---

## Usage

1. Clone the repository:
   
```bash
git clone https://github.com/isrreal/DataStructures.git
cd DataStructures
```
1.2 If you want to see operations in trees:

1.3 Choose the specific tree directory you want to work with (e.g., AVL Binary Search Tree, Binary Search Tree, or Binary Tree):

1.4 Compile the code:
```bash
make
```
1.5 Run the application:
   
```bash
./app
```
