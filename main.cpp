#include <iostream>
#include <fstream>
#include <cctype>
#include "maze.h"
using namespace std;

int main() {
    ifstream fin("maze.dat");

    if (!fin) {
        cout << "Could not open maze.dat\n";
        return 1;
    }

    while (true) {
        // Skip any leading whitespace / blank lines between mazes
        while (fin.peek() != EOF && isspace(fin.peek()))
            fin.get();

        if (fin.peek() == EOF)
            break;

        Maze m(fin);
        cout << m.toString() << endl;
    }

    return 0;
}