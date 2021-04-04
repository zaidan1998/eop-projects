#include<iostream>
using namespace std;
const int nums = 65;


int findIndices (int *pointer, int i)
{
	int value;
	
	switch (i)
	{
		case 0 : value = *pointer; break;
		case ((nums/2)-1) : value = *pointer; break;
		case (nums - 1) : value = *pointer; break;
		default: break;
	}
	
	return (value);
}

int main()
{
	int *gptr = new int[nums];
	int first, middle, last;
	
	for(int i = 0; i < nums; i++)
	{
		cin >> *(gptr + i);
		
		switch(i)
		{
			case 0 : first = findIndices((gptr + i), i); break;
			case ((nums/2)-1) : middle = findIndices((gptr + i), i); break;
			case (nums - 1) : last = findIndices((gptr + i), i); break;
			default: continue;
		}
	}
	
	cout << "First element: " << first << endl;
	cout << "Middle element: " << middle << endl;
	cout << "Last element: " << last << endl;
	
	
	
	return 0;
}
