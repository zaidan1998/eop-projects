#include <iostream>
using namespace std;

void findDeterm(int matric[2][2])
{
	int determ;
	determ = (matric[0][0]*((matric[1][1]*matric[2][2])-(matric[2][1]*matric[1][2]))) - (matric[1][0]*((matric[1][0]*matric[2][2])-(matric[2][0]*matric[1][2]))) + (matric[0][2]*((matric[1][0]*matric[2][1])-(matric[2][0]*matric[1][1])));
	cout << "|X| or the determinant of X is : " << determ;
}

int main()
{
	int matric[2][2];
	cout << "Enter values for matricay X (separated by a space) : " << endl;
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			cin >> matric[i][j];
		}
	}
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			cout << matric[i][j] << "   ";
		}
		cout << endl;
	}
	findDeterm(matric);
	
	return 0;
}
