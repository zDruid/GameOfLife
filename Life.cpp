#include "Life.h"
#include "GameBoard.h"

#include <fstream>
#include <iostream>

Life::Life(ifstream &ifs) {
  ifs >> _rowCount >> _colCount >> ws;

  _cells = new bool[_rowCount * _colCount]{};
  string line;
  int row = 0;
  while (getline(ifs, line)) {
    for (int col = 0; col < _colCount; col++) {
      bool isCellOn = (line[col] == 'O');
      setCellValueAt(row, col, isCellOn);
    }
    row++;
  }

  // There is another approach
}

// Copy constructor. Construct using the state of the passed game of life
// its rowCount, colCount and a deep copy if its cells.
Life::Life(const Life &rhs) {
  _rowCount = rhs._rowCount;
  _colCount = rhs._colCount;
  // =====> DJH -0% Should use cellCount()
  int size = _rowCount * _colCount;

  delete[] _cells;
  _cells = new bool[size]{};

  for (int i = 0; i < size; i++) {
    _cells[i] = rhs._cells[i];
  }
}

Life::Life(int rowCount, int colCount) {
  _rowCount = rowCount;
  _colCount = colCount;
  // =====> DJH -0% Should use cellCount()
  _cells = new bool[rowCount * colCount]{};

  // for (int index = 0; index < rowCount * colCount; index++) {
  //   _cells[index] = false;
  // }
}

Life &Life::operator=(const Life &rhs) {
  if (this == &rhs)
    return *this;

  _rowCount = rhs._rowCount;
  _colCount = rhs._colCount;
  // =====> DJH -0% Should use cellCount()
  int size = _rowCount * _colCount;

  delete[] _cells;
  _cells = new bool[size];

  for (int i = 0; i < size; i++) {
    _cells[i] = rhs._cells[i];
  }

  return *this;
}

// Destructor, which deallocates cells
Life::~Life() { delete[] _cells; }

// Return the value of the cell at the specified position
bool Life::cellValueAt(int row, int col) const {
  return _cells[row * _colCount + col];
}

// HINT: You might find it beneficial to create two versions of
// cellValueAt, where one checks the row, col for being in bounds
// and the other assumes they are.

// Set the value of the cell at the specified position
bool Life::safeCellValueAt(int row, int col) const {
  return (row >= 0 && row < _rowCount && col >= 0 && col < _colCount) &&
         cellValueAt(row, col);
}

// Set the value of the cell at the specified position
void Life::setCellValueAt(int row, int col, bool value) {
  _cells[row * _colCount + col] = value;
}

// Draw the current state on the given GameBoard, and return
// the total number of living cells
int Life::draw(GameBoard *board) const {
  int count = 0;
  for (int row = 0; row < _rowCount; row++) {
    for (int col = 0; col < _colCount; col++) {
      if (cellValueAt(row, col)) {
        count++;
        board->setTileAt(row, col, '#', blue);
      } else {
        board->clearTileAt(row, col);
      }
    }
  }
  return count;
}

// Return a new Life object representing the receiver's state updated according
// to the rules of Conway's Game of Life. In a nutshell:
//
// Non-living cells with exactly 3 live neighbors come to life in the next
// generation Living cells with 2 or 3 live neighbors remain living in the next
// generation Living cells with fewer than 2 live neighbors die of loneliness in
// the next generation Living cells with 4 or more live neighbors die of
// overcrowding in the next generation
Life Life::nextLife() const {
  Life result(_rowCount, _colCount);

  for (int row = 0; row < _rowCount; row++) {
    for (int col = 0; col < _colCount; col++) {
      int neighborsAlive = livingNeighbors(row, col);
      bool living = neighborsAlive == 3 || (cellValueAt(row, col) && neighborsAlive == 2);
      result.setCellValueAt(row, col, living);

      
      // bool living = false;
      // int neighborsAlive = livingNeighbors(row, col);
      // bool currValue = cellValueAt(row, col);
      
      // if (currValue && (neighborsAlive == 2 || neighborsAlive == 3))
      //   living = true;
      // else if (!currValue && (neighborsAlive == 3))
      //   living = true;

      // result.setCellValueAt(row, col, living);
    }
  }
  return result;
}

// Honors section - Decide how specifically to encode the complete state of
// the receiver and return that encoding as a string
//
// Non-honors - try it for fun, or just return "";
string Life::toString() const { return ""; }

// Return the number of living neighbors for the cell at the specified position
int Life::livingNeighbors(int row, int col) const {
  int count = 0;
  for (int r = row - 1; r <= row + 1; r++) {
    for (int c = col - 1; c <= col + 1; c++) {
      if (safeCellValueAt(r, c)) {
        count++;
      }
    }
  }
  if (safeCellValueAt(row, col)) {
    count--;
  }
  return count;
}
