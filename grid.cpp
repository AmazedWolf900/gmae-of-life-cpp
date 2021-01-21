/**
    Game of Life in C++.
    @file grid.cpp
    @file grid.h
    @author Tomáš Weber
    @version 6th Dec 2020
*/

#include "grid.h"

// Constructors
Grid::Grid() {
    // Default values
    COLUMNS = 22;   // 20 columns
    ROWS = 22;      // 20 rows
    INITIAL_POPULATION = 40;    // 40% of cells will be live at the start
    createGrid();
    initialForm();
}
Grid::Grid(int col, int row, int cha) {
    COLUMNS = col + 2;
    ROWS = row + 2;
    INITIAL_POPULATION = cha;
    createGrid();
    initialForm();
}

// Private functions
void Grid::createGrid() {
    grid.resize(COLUMNS);
    for (int i = 0; i < COLUMNS; i++) {
        grid[i].resize(ROWS);
    }
}
void Grid::initialForm() {
    srand((unsigned) time(0));
    for (int i = 1; i < COLUMNS - 1; i++) {
        for (int j = 0; j < ROWS - 1; j++) {
            if (1 + (rand() % 100) < INITIAL_POPULATION) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// Public functions
int Grid::returnColumns() { return COLUMNS; }
int Grid::returnRows() { return ROWS; }
int Grid::returnInitialPopulation() { return INITIAL_POPULATION; }
int Grid::returnNoOfGeneration() { return noOfGeneration; }
int Grid::returnNoOfCells() { return (COLUMNS - 2) * (ROWS - 2); }

bool Grid::returnIfChanged() { return changed; }
int Grid::returnNoOfAlliveCells() {
    int alive = 0;
    for (int i = 1; i < COLUMNS - 1; i++) {
        for (int j = 1; j < ROWS - 1; j++) {
            if (grid[i][j]) {
                alive++;
            }
        }
    }
    return alive;
}
int Grid::returnNoOfDeathCells() {
    int death = 0;
    for (int i = 1; i < COLUMNS - 1; i++) {
        for (int j = 1; j < ROWS - 1; j++) {
            if (!grid[i][j]) {
                death++;
            }
        }
    }
    return death;
}
bool Grid::returnCellState(int col, int row) { 
    if (grid[col][row] == 1) 
        return true; 
    else 
        return false;
}
void Grid::nextGeneration() {
    changed = false;
    //int nextGen[COLUMNS][ROWS];
    std::vector<std::vector<int> > nextGen;
    nextGen.resize(COLUMNS);
    for (int i = 0; i < COLUMNS; i++) {
         nextGen[i].resize(ROWS);
    }

    for (int a = 1; a < COLUMNS - 1; a++) {
        for (int b = 1; b < ROWS - 1; b++) {
            int aliveNeighbours = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = - 1; j <=1; j++) {
                    aliveNeighbours += grid[a + i][b + j];
                }
            }
            aliveNeighbours -= grid[a][b];

            if (grid[a][b]) {
                if (aliveNeighbours == 2 || aliveNeighbours == 3) {
                    nextGen[a][b] = 1;
                } else {
                    nextGen[a][b] = 0;
                    changed = true;
                }
            } else {
                if (aliveNeighbours == 3) {
                    nextGen[a][b] = 1;
                    changed = true;
                } else {
                    nextGen[a][b] = 0;
                }
            }
        }
    }
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            grid[i][j] = nextGen[i][j];
        }
    }
    if (changed) {
        noOfGeneration++;
    }
}