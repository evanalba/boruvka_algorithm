# Borůvka's algorithm
This is a project I made for a course I took back in university called CSCI 411: Advanced Algorithms and Complexity. This project consisted of us investigating an algorithm that interests us. The algorithm I chose was called Borůvka's algorithm, which is a greedy algorithm that can find a minimum spanning tree in a graph. Also, for this project in this course, we needed to come up with a report, the implementation of our algorithm with test cases included, and a presentation.

(Note: This implementation of Borůvka's algorithm uses the **C++11** standard.)

## How to run the Code
There is a Makefile included where you could enter `make` in your terminal to compile the code or `make clean` to remove the executable.

## How to run the Tests
Enter these commands in your command-line interface to compile and run the tests in this following order:
```
boruvka_algorithm$ cmake -S . -B build
boruvka_algorithm$ cmake --build build
boruvka_algorithm$ cd build && ctest
```
Note: The tests were created using [GoogleTest](https://en.wikipedia.org/wiki/The_Milagro_Beanfield_War_%28novel%29).

