/*
 * MyFirstOne.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: michael
 */


#include <iostream>
#include <iomanip>
//#include <cmath>

using namespace std;

int main()
{
	int rows;
	int cols;
	bool check1 = true;
	bool check2 = true;
	bool aug = false;
	bool check3 = true;
	int anst;
	cout << "Hello this is a row reduction application!" << endl;
	while(check3 == true)
	{
		cout << "Is the matrix you are trying to reduce augmented?" << endl;
		cout << "[1] Yes" << endl;
		cout << "[2] No" << endl;
		cin >> anst;
		if(anst >2 || anst < 1)
		{
			cout << "That is not an answer..." << endl;
			check3 = true;
		}
		else
		{
			check3 = false;
		}
	}
	if(anst == 1)
	{
		aug = true;
	}
	else if(anst == 2)
	{
		aug = false;
	}
		cout << "Please enter the number of rows that you would like to have:" << endl;
		cin >> rows;
		check1 = false;
		cout << "Please enter the number of columns that the matrix has(including the final column):" << endl;
		cin >> cols;
		check2 = false;
	cout << "Your matrix has " << rows << " rows, and " << cols << " columns!" << endl;
	double number[rows][cols];
	for(int i = 0; i <rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout << "For row " << i+1 << " please enter the number in place " << j+1 << endl;
			cin >> number[i][j];
		}
	}
	cout << "Here is your matrix:" << endl;
	for(int i = 0; i <rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(j==cols-1 && aug == true)
				{
					cout << " | " << number[i][j] << endl;
				}
				else
				{
					cout << "   " << number[i][j];
					if(j==cols-1)
					{
						cout << endl;
					}
				}
			}
		}
	int totnums[rows];
	for(int i = 0; i< rows; i++)
	{
		int counter1 = 0;
		for(int j = 0; j<cols; j++)
		{
			if(number[i][j] == 0)
			{
				counter1 = counter1 + 1;
			}
			else
			{
				break;
			}

			//here make a array, totnums that counts how many zeros are in each row and then interchange from there!
		}
		totnums[i] = counter1;
//		cout << "HERE" << totnums[i] << endl;
	}
	int countere = 0;
	int counter2;
	bool truth = true;
	while(truth == true)
	{
		counter2 = 0;
		for(int i = 0; i<rows-1; i++)
		{
			if(totnums[i] > totnums[i+1])
			{
//				truth = true;
				counter2 = counter2 + 1;
				double temp1[cols];
				double temp2[cols];
				int temp3, temp4;
				for(int j = 0; j<cols;j++)
				{
					temp1[j] = number[i][j];
					temp2[j] = number[i+1][j];
					temp3 = totnums[i];
					temp4 = totnums[i+1];
				}
				for(int t = 0; t<cols;t++)
				{
					number[i][t] = temp2[t];
					number[i+1][t] = temp1[t];
					totnums[i] = temp4;
					totnums[i+1] = temp3;
				}

			}
		}
		if(counter2 > 0)
		{
			truth = true;
		}
		else
		{
			truth = false;
		}
		countere = countere+1;
	}
	cout << "Here is your matrix after row swapping:" << endl;
		for(int i = 0; i <rows; i++)
			{
				for(int j = 0; j < cols; j++)
				{
					if(j==cols-1 && aug == true)
					{
						cout << " | " << number[i][j] << endl;
					}
					else
					{
						cout << "   " << number[i][j];
						if(j==cols-1)
						{
							cout << endl;
						}
					}
				}
			}
		cout << "Now to reduce..." << endl;
		int place;
			for(int i = 0; i<rows;i++)
			{
				for(int j = 0; j< cols; j++)
				{
					if(number[i][j] != 0)
					{
						place = j;
						break;
					}
				}
				int size = rows - 1;
				size = size - i;
				double tempop1[size][cols];
				double tempop2[cols];
				double tempop3[cols];
				for(int t = 0;t<size;t++)
				{
					for(int r = 0;r<cols;r++)
					{
						tempop1[t][r] = number[t+i+1][r];
					}
				}
				for(int t=0;t<cols;t++)
				{
					tempop2[t] = number[i][t];
				}
				double mult1,mult2,mult3;
				mult1 = tempop2[place];
				for(int y=0;y<size;y++)
				{
					mult2 = tempop1[y][place]; //This should be mult1(x) + mult2 = 0
					mult3 = -1 * mult2;
					mult3 = mult3 / mult1;
					for(int g = 0; g<cols;g++) // this might need to be from g=place, if this is the case you need to change parts above
					{
						tempop3[g] = tempop2[g] * mult3;
					}
					for(int v = 0; v<cols;v++)
					{
						tempop1[y][v] = tempop1[y][v] + tempop3[v];
					}
				}
				for(int g=0;g<size;g++)
				{
					for(int b=0;b<cols;b++)
					{
						number[g+i+1][b] = tempop1[g][b];
					}
				}
			}
		cout << "Here is your matrix after reducing:" << endl;
		for(int i = 0; i <rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(j==cols-1 && aug == true)
				{
					cout << " | " << number[i][j] << endl;
				}
				else
				{
					cout << "   " << number[i][j];
					if(j==cols-1)
					{
						cout << endl;
					}
				}
			}
		}
		cout << "Now to put it into echlon form!" << endl;
		int place2;
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(number[i][j] != 0)
				{
					place2 = j;
					break;
				}
			}
			double temporar[cols];
			for(int h = 0; h < cols; h++)
			{
				temporar[h] = number[i][h];
			}
			double divisor = temporar[place2];
			if(divisor == 0)
			{
				break;
			}
			for(int u = 0; u < cols; u++)
			{
				double tnum = temporar[u];
				tnum = tnum / divisor;
				temporar[u] = tnum;
			}
			for(int t = 0; t<cols;t++)
			{
				number[i][t] = temporar[t];
			}
		}
		for(int i = 0; i <rows; i++)
				{
					for(int j = 0; j < cols; j++)
					{
						if(number[i][j] <0.00000000000000000000005 && number[i][j] > -0.00000000000000000000005)
						{
							number[i][j] = 0;
						}
					}
				}
		for(int i = 0; i <rows; i++)
				{
					for(int j = 0; j < cols; j++)
					{
						if(j==cols-1 && aug == true)
						{
							cout << " | " << number[i][j] << endl;
						}
						else
						{
							cout << "   " << number[i][j];
							if(j==cols-1)
							{
								cout << endl;
							}
						}
					}
				}
		cout << "Finally we will complete the reducing now..." << endl;
		//NOW all i have to do is do the backwards portion and reduce all numbers above each pivot point
		int place3;
			for(int i = rows-1;i>0;i--)
			{
				int counterer=0;
					for(int j = 0; j<cols;j++)
					{
						if(number[i][j] != 0)
						{
							place3 = j;
							break;
						}
						else
						{
							counterer = counterer + 1;
						}
					}
					if(counterer != cols)
					{
				double temparr1[i][cols];
				double temparr2[cols];
				for(int t=0; t<i;t++)
				{
					for(int h = 0; h < cols; h++)
					{
						temparr1[t][h] = number[t][h];
					}
				}
				for(int r = 0; r<cols;r++)
				{
					temparr2[r] = number[i][r];
				}
				for(int e=0;e<i;e++)
				{
					double temparr3[cols];
					double num1,num2,num3;
					num1 = temparr2[place3];
					num2 = temparr1[e][place3];
					num3 = -num2/num1;
					for(int r = 0; r<cols;r++)
					{
						temparr3[r] = num3 * temparr2[r];
					}
					for(int w = 0; w<cols; w++)
					{
						temparr1[e][w] = temparr1[e][w] + temparr3[w];
					}

				}
				for(int t=0;t<i;t++)
				{
					for(int a =0; a<cols;a++)
					{
						number[t][a]= temparr1[t][a];
					}
				}
					}
			}
			for(int i = 0; i <rows; i++)
			{
				for(int j = 0; j < cols; j++)
				{
					if(j==cols-1 && aug == true)
					{
						cout << " | " << number[i][j] << endl;
					}
					else
					{
						cout << "   " << number[i][j];
						if(j==cols-1)
						{
							cout << endl;
						}
					}
				}
			}
}
