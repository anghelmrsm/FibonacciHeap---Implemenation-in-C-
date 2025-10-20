# FibonacciHeap-Implementation-in-C++

## System Overview  
This project implements a **Fibonacci Heap** data structure in C++ (though the repository name says “in C”, the source files use C++). This advanced heap supports efficient operations such as insertion, find-minimum, union/merge, decrease-key, and delete-minimum — making it suitable for priority-queue tasks in algorithms like Dijkstra’s or Prim’s.

---

## Project Structure  
- `FibonacciHeap.h` – Header with class definitions and template declarations  
- `FibonacciHeap.cpp` – Implementation of Fibonacci Heap methods  
- `main.cpp` – Example usage of the Fibonacci Heap: creation of heap, performing operations, displaying results  

---

## Key Features  
- Supports **Insert**, **Find-Minimum**, **Delete-Minimum**, **Decrease-Key**, and **Merge/Union** operations  
- Uses the **amortized log n (or better)** performance characteristics of Fibonacci Heaps  
- Modular design: separate header and implementation files for clear structure  
- Example and test code included in `main.cpp` for quick verification  

---

## Technologies Used  
- C++ (classes, templates, pointers)  
- Standard Template Library (STL) where appropriate  
- Clean separation of interface (`.h`) and implementation (`.cpp`)  

---

## Getting Started  
To build and run the project locally:  
1. Clone the repository  
   ```bash
   git clone https://github.com/anghelmrsm/FibonacciHeap---Implemenation-in-C-.git
