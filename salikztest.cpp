#include<iostream>

using namespace std;


int main()
{
	char colors[4];

	srand(time(NULL));
	int randomint;
	do
	{
	for(int i=0;i<4;i++)
	{
	randomint = (rand()%5)+1;

	 switch(randomint)
	 {
	 case 1:
		 colors[i] = 'R';
		 break;
	 case 2:
		 colors[i] = 'B';
		 break;
	 case 3:
		 colors[i] = 'Y';
		 break;
	 case 4:
		 colors[i] = 'P';
		 break;
	 case 5:
		 colors[i] = 'G';
		 break;
	 } while(colors[i]==colors[i-1]||colors[i]==colors[i-2]||colors[i]==colors[i-3]);
	 	cout << colors[i] << endl;
	 	
	 	
	 	return 0;
	}
