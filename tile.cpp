/**
    Game of Life in C++.
    @file tile.cpp
    @file tile.h
    @author Tomáš Weber
    @version 6th Dec 2020
*/

#include "../header_files/tile.h"

// Constructors
Tile::Tile() {
    // Default values
    COLUMNS = 22;   // 20 columns
    ROWS = 22;      // 20 rows
    INITIAL_POPULATION = 40;    // 40% of cells will be live at the start
    createGrid();
    initialForm();
}
Tile::Tile(int col, int row, int cha) {
    COLUMNS = col + 2;
    ROWS = row + 2;
    INITIAL_POPULATION = cha;
    createGrid();
    initialForm();
}

// Private functions
void Tile::createGrid() {
    grid.resize(COLUMNS);
    for (int i = 0; i < COLUMNS; i++) {
        grid[i].resize(ROWS);
    }
}
void Tile::initialForm() {
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
int Tile::returnColumns() { return COLUMNS; }
int Tile::returnRows() { return ROWS; }
int Tile::returnInitialPopulation() { return INITIAL_POPULATION; }
int Tile::returnNoOfGeneration() { return noOfGeneration; }
int Tile::returnNoOfCells() { return (COLUMNS - 2) * (ROWS - 2); }

bool Tile::returnIfChanged() { return changed; }
int Tile::returnNoOfAlliveCells() {
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
int Tile::returnNoOfDeathCells() {
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
bool Tile::returnCellState(int col, int row) { 
    if (grid[col][row] == 1) 
        return true; 
    else 
        return false;
}
void Tile::nextGeneration() {
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