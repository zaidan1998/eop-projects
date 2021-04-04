#include <iostream>
using namespace std;

int *ptr;
int findDeterm(int matric[3][3])
{
	int determ;
	determ = *(ptr) *( (*((ptr+1)+1)) * (*((ptr+2)+2)) - *((ptr+2)+1) * (*(ptr+1)+2) )  -   *(ptr+1) * ((*((ptr+1)))**((ptr+2)+2) - *((ptr+2))*(*((ptr+1)+2))) + *(ptr+2)*(*((ptr+1))*(*((ptr+2)+1))-*(ptr+2)**((ptr+1)+1));
	//determ = *(*matric) *( (*(*(matric+1)+1)) * (*(*(matric+2)+2)) - *(*(matric+2)+1) * (*(*matric+1)+2) )  -   *(*matric+1) * ((*(*(matric+1)))**(*(matric+2)+2) - *(*(matric+2))*(*(*(matric+1)+2))) + *(*matric+2)*(*(*(matric+1))*(*(*(matric+2)+1))-*(*matric+2)**(*(matric+1)+1));
	//determ = (matric[0][0]*((matric[1][1]*matric[2][2])-(matric[2][1]*matric[1][2]))) - (matric[0][1]*((matric[1][0]*matric[2][2])-(matric[2][0]*matric[1][2]))) + (matric[0][2]*((matric[1][0]*matric[2][1])-(matric[2][0]*matric[1][1])));
	return determ;
}

void transposeMat(int matric[3][3])
{
	cout << "XT or the transposed value of matrix X is : " << endl << endl;
	for (int x=0; x<3; x++)
	{
		for (int y=0; y<3; y++)
		{
			cout << matric[y][x] << "   ";
		}
		cout << endl;
	}
	
}

void xtractDiag(int matric[3][3])
{
	cout << endl << "The values of DT is : " << endl << endl << "| ";
	for (int a=0; a<3; a++)
	{
		cout << matric[a][a] << " "; 
	}
	cout << "|";
}

int main()
{
	int matric[3][3], deter;
	
	ptr = &matric[0][0];
	cout << "Enter values for array X (separated by a space) : " << endl;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			cin >> *(*(matric+i)+j); //matric[i][j];
		}
	}
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			cout << matric[i][j] << "   ";
		}
		cout << endl;
	}
	deter=findDeterm(matric);
	cout << endl << "|X| or the determinant of X is : " << deter << endl;
	transposeMat(matric);
	xtractDiag(matric);
	
	return 0;
}
