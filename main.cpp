#include <iostream>

#include "grid.h"

int main(int, char* argv[]) {
    int argc = 0;
    while(argv[argc] != NULL) {
        argc++;
    }

    Grid obj;
    if (argc == 4) {
        obj = Grid(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    }

    int aliveCells = 0;
    int oscilatorCounter = 0;

    while (true) {
        for (int i = 1; i < obj.returnColumns() - 1; i++) {
            for (int j = 1; j < obj.returnRows() - 1; j++) {
                if (obj.returnCellState(i, j)) {
                    std::cout << "X";
                } else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << obj.returnNoOfGeneration() << " " << obj.returnNoOfCells() << " " <<
                obj.returnNoOfAlliveCells() << " " << obj.returnNoOfDeathCells() << std::endl;
        obj.nextGeneration();
        /*if (!obj.returnIfChanged()) {
            std::cout << std::endl << "Žádná změna!!!" << std::endl;
            break;
        }
        if(aliveCells == obj.returnNoOfAlliveCells()) {
            oscilatorCounter++;
            if (oscilatorCounter > 3) {
                std::cout << std::endl << "Osciluji!!!" << std::endl;
                break;
            }
        }  */  
        aliveCells = obj.returnNoOfAlliveCells();
        std::cin.ignore();
    }

    /* Grid obj;
    if (argc == 4) {
        int columns             = atoi(argv[1]);
        int rows                = atoi(argv[2]);
        int initialPopulation   = atoi(argv[3]);
        obj = Grid(columns, rows, initialPopulation);
    }

    while (true) {
        for (int i = 1; i < obj.returnColumns() - 1; i++) {
            for (int j = 1; j < obj.returnRows() - 1; j++) {
                if (obj.returnCellState(i, j)) {
                    cout << "X";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << obj.returnNoOfGeneration() << " " << obj.returnNoOfCells() << " " <<
                obj.returnNoOfAlliveCells() << " " << obj.returnNoOfDeathCells() << endl;
        obj.nextGeneration();
        cin.ignore();
    } */

    return 0;
}
