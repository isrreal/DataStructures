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

#### Features
- **Graph Construction**: Create graphs from a specified number of vertices with a given edge probability or from an input file.
- **Edge Management**: Methods to add edges, check if an edge exists, and manage vertex connections efficiently.
- **Vertex Management**: Functions to check for vertex existence, get the degree of a vertex, and delete vertices along with their connections.
- **Traversal Algorithms**: Implementations of breadth-first search (BFS) and depth-first search (DFS) for exploring the graph structure.
- **Adjacency List Representation**: Utilizes an unordered map for efficient access to connected vertices.
- **Error Handling**: Mechanisms for handling file I/O errors and vertex management issues, ensuring robustness.
- **Performance**: Optimized operations, typically operating within *O(1)* for insertion and *O(V + E)* for traversal methods.

---

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
