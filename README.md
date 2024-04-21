# Borůvka's algorithm
This is a project I made for a course I took back in university called CSCI 411: Advanced Algorithms and Complexity. This project consisted of us investigating an algorithm that interests us. The algorithm I chose was called Borůvka's algorithm, which is a greedy algorithm that can find a minimum spanning tree in a graph. Also, for this project in this course, we needed to come up with a report, the implementation of our algorithm with test cases included, and a presentation.

(Note: This implementation of Borůvka's algorithm uses the **C++11** standard.)

## How to run the Code
There is a Makefile included where you could enter `make` in your terminal to compile the code or `make clean` to remove the executable.

## How to run the Unit Tests
Enter these commands in your command-line interface to compile and run the tests in this following order:
```
boruvka_algorithm$ cmake -S . -B build
boruvka_algorithm$ cmake --build build
boruvka_algorithm$ cd build && ctest --output-on-failure
```
Note: The tests were created using [GoogleTest](https://en.wikipedia.org/wiki/Google_Test).

Unit Testing File Structure:
```
- boruvka_algorithm.h (The header file for boruvka_algorithm.cpp.)

- boruvka_algorithm.cpp (The same code that is pretty much copied from main.cpp but does NOT contain a MAIN function. This file is the place where we run the code along with the tests we give it which are in test.cpp.)

- test.cpp (Where all the tests are located.)
```
