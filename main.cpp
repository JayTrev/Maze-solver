#include <iostream>
#include <fstream>
#include "maze.h"
using namespace std;

int main() {
    ifstream fin("maze.dat");

    if (!fin) {
        cout << "Could not open maze.dat\n";
        return 1;
    }

    while (fin.peek() != EOF) {
        Maze m(fin);
        cout << m.toString() << endl;
    }

    return 0;
}