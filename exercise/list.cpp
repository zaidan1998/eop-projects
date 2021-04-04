#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void calcList(int i)
{
	double *list = new double[i];
	
	for(int j = 0; j<i; j++)
	{
		*(list + j) = pow(j, 3) + j / 2.0;
	}
	
	cout << fixed << showpoint << setprecision(2);
	
	for(int j = 0; j < i; j++)
	{
		cout << *(list + j) << " ";
	}
	
	cout << endl;
	
	*(list + 0) = *(list + 4) - *(list + 2);
	*(list + 2) = *(list + 3) + *(list + 1);
	
	for(int j = 0; j < i; j++)
	{
		cout << *(list + j) << " ";
	}
	
	cout << endl;
}

int main()
{
	double nums;
	
	cin >> nums;
	
	calcList(nums);
	
	return 0;
}
