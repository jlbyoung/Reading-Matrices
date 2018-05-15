/*
* Name : James Young
* ID : 100273383
* Course : CPSC 1160
* Instructor : Bijan Farrahi
* Assignment #5
* Purpose : To read a file containing matrices and display them in matrix format using dynamic memory

* I pledge that I have completed the programming assignment independently.
* I have not copied the code from a student or any other source.
* I have not given my code to any student

* Date : May 31, 2017
*/

#include <iostream>
#include <fstream>
using namespace std;

/* locateLargest method
* This method finds the largest element in a given matrix
* @param n The number of elements in a row
* @param m The number of elements in a column
* @param matrix The 2D matrix containing n*m elements
* @param rowCol[] The array that will hold the location of the largest element by Cartesian coordinates. eg(3, 5)
*/
void locateLargest(double ** matrix, int n, int m, int rowCol[]);

int main()
{
	ifstream file;
	int nRows, mCols;
	int rowCol[2];
	typedef double* DoubleArrayPtr;
	//Open file
	file.open("matrices.txt");

	//Repeat until end of line
	while (!file.eof())
	{
		cout << "Reading Matrix..." << endl;
		//Read the number of rows, n
		file >> nRows;
		cout << "The number of rows : " << nRows << endl;
		//Read the number of columns, m
		file >> mCols;
		cout << "The number of columns : " << mCols << endl;
		//Create n*m dynamic array(matrix)
		DoubleArrayPtr *matrix = new DoubleArrayPtr[nRows];
		for (int i = 0; i < nRows; i++)
		{
			matrix[i] = new double[mCols];
		}
		//Read n*m values
		for (int i = 0; i < nRows; i++)
		{
			for (int j = 0; j < mCols; j++)
			{
				file >> matrix[i][j];
			}
		}
		//Display the matrix in matrix format
		for (int i = 0; i < nRows; i++)
		{
			for (int j = 0; j < mCols; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		//Find largest element and display it
		cout << "The largest element is ";
		locateLargest(matrix, nRows, mCols, rowCol);
		cout << " at location (" << rowCol[0] + 1 << "," << rowCol[1] + 1 << ")" << endl;
		cout << "Finished reading matrix!" << endl << endl;
		//Release matrix memory
		delete[] matrix;
		//Reset the array that contains the location of the largest element
		rowCol[0] = 0;
		rowCol[1] = 0;
	}

	//End Repeat
	//Close file
	file.close();
	cin.get();

	return 0;
}

/* locateLargest method
* This method finds the largest element in a given matrix
* @param n The number of elements in a row
* @param m The number of elements in a column
* @param matrix The 2D matrix containing n*m elements
* @param rowCol[] The array that will hold the location of the largest element by Cartesian coordinates. eg(3, 5)
*/
void locateLargest(double ** matrix, int n, int m, int rowCol[])
{
	//Compare each element in the matrix to the first value in the matrix
	double temp = matrix[0][0];
	int i = 0, j = 0;
	while (i < n) 
	{
		while (j < m)
		{
			//If a value is greater than value compared, then the largest is set to temp and the location is recorded
			if (matrix[i][j] > temp)
			{
				temp = matrix[i][j];
				rowCol[0] = i;
				rowCol[1] = j;
			}
			j++;
		}
		//Reset the column position
		j = 0;
		i++;
	}
	//Display the largest value in the matrix
	cout << temp;
	
}