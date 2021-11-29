#include <iostream>
using namespace std;

class sudoku {
	public:
		sudoku();
		sudoku(int g[][9]);
		void initializeSudokuGrid();
		void initializeSudokuGrid(int g[][9]);
		void printSudokuGrid();
		bool solveSudoku();
		bool findEmptyGridSlot(int &row, int &col);
		bool canPlaceNum(int row, int col, int num);
		bool numAlreadyInRow(int row, int num);
		bool numAlreadyInCol(int col, int num);
		bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num);

	private:
		int grid[9][9];
};

sudoku::sudoku() {
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			grid[i][j] = 0;
		}
	}
}

sudoku::sudoku(int g[][9]) {
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			grid[i][j] = g[i][j];
		}
	}
}

void sudoku::initializeSudokuGrid() {
	cout << "Enter Sudoku Grid (0 for blanks)" << endl;
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			cin >> grid[i][j];
		}	
		cout << endl;
	}
}

void sudoku::initializeSudokuGrid(int g[][9]) {
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			grid[i][j] = g[i][j];
		}
	}
}

void sudoku::printSudokuGrid() {
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}

bool sudoku::solveSudoku() {
	int row, col;
	
	if (findEmptyGridSlot(row, col)) {
		for (int num=1; num<=9; num++) {
			if (canPlaceNum(row, col, num)) {
				grid[row][col] = num;
				if (solveSudoku())
					return true;
				grid[row][col] = 0;
			}
		}
		return false;
	}
	else
		return true;
}

bool sudoku::findEmptyGridSlot(int &row, int &col) {
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			if (grid[i][j]==0) {
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool sudoku::canPlaceNum(int row, int col, int num) {
	return (!numAlreadyInRow(row, num) && !numAlreadyInCol(col, num) && !numAlreadyInBox(row/3, col/3, num));
}

bool sudoku::numAlreadyInRow(int row, int num) {
	bool output = false;
	for (int i=0; i<9; i++) {
		if (grid[row][i] == num)
			output = true;
	}
	return output;
}

bool sudoku::numAlreadyInCol(int col, int num) {
	bool output = false;
	for (int i=0; i<9; i++) {
	       if (grid[i][col] == num)
	       output=true;
	}	
	return output;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num) {
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (grid[3*smallGridRow+i][3*smallGridCol+j] == num)
				return true;
		}
	}
	return false;
}

int main() {
	int g[9][9] = {{6,0,3,0,2,0,0,9,0},{0,0,0,0,5,0,0,8,0},{0,2,0,4,0,7,0,0,1},{0,0,6,0,1,4,3,0,0},{0,0,0,0,8,0,0,5,6},{0,4,0,6,0,3,2,0,0},{8,0,0,2,0,0,0,0,7},{0,1,0,0,7,5,8,0,0},{0,3,0,0,0,6,1,0,5}};
	sudoku mySudoku;
	mySudoku.initializeSudokuGrid(g);
	mySudoku.printSudokuGrid();
	mySudoku.solveSudoku();
	mySudoku.printSudokuGrid();
	return 0;
}








