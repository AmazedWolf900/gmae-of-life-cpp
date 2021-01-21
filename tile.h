/**
    Game of Life in C++.
    @file tile.cpp
    @file tile.h
    @author Tomáš Weber
    @version 6th Dec 2020
*/

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

/**
 * Implementation of a cellular automaton "Game of Life" in C++.
 * 
 */
class Tile {
    private:
        int COLUMNS;
        int ROWS;
        int INITIAL_POPULATION;
        int noOfGeneration = 0;
        //int **grid;
        std::vector<std::vector<int> > grid;
        bool changed;

        void createGrid();
        void initialForm();
    public:
        /**
         * Create instance with default values.
         * 
         */
        Tile();
        /**
         * Create instance with specific values.
         * 
         * @param int number of columns
         * @param int number of rows
         * @param int initial population in percents
         */
        Tile(int col, int row, int cha);

        /**
         * Return number of columns in a grid.
         * 
         * @return columns
         */
        int returnColumns();
        /**
         * Return number of rows in a grid.
         * 
         * @return rows
         */
        int returnRows();
        /**
         * Return initial population in percents.
         * 
         * @return initial population
         */
        int returnInitialPopulation();
        /**
         * Return number of actual generation.
         * 
         * @return actual generation
         */
        int returnNoOfGeneration();
        /**
         * Return number of all cells.
         * 
         * @return cells
         */
        int returnNoOfCells();
        /**
         * Return number of alive cells.
         * 
         * @return alive cels
         */
        int returnNoOfAlliveCells();
        /**
         * Rentrun number of death cells.
         * 
         * @return death cells
         */
        int returnNoOfDeathCells();
        /**
         * Recognize if the grid has changed.
         * 
         * @return `true` if the grid has changed, `false` if the grid has not changed
         */
        bool returnIfChanged();
        /**
         * Return state of a specific cell.
         * 
         * @param int number of column
         * @param int number of row
         * @return `true` if a cell is alive, `false` if a cell is death
         */
        bool returnCellState(int col, int row);
        /**
         * Create a new generation of cells.
         * 
         */
        void nextGeneration();
};