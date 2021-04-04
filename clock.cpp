#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include <time.h>
using namespace std;

void Closing()
{
	system("cls");
	cout<<"\n\n\n                XXXXXXX  XXXX  XX      XX XXXXXXX    XXXXXX XX  XX XXXXXX XXXXX    \n";
	cout<<"                xXXXXXX XX  XX XXXX  XXXX XXXXXXX    XX  XX XX  XX XXXXXX XX  XX   \n";
	cout<<"                XX      XX  XX XX XXXX XX XX         XX  XX XX  XX XX     XX  XX   \n";
	cout<<"                XX  XXX XXXXXX XX  XX  XX XXXXXX     XX  XX XX  XX XXXXXX XXXXX    \n";
	cout<<"                XX  XXX XXXXXX XX      XX XXXXXX     XX  XX XX  XX XXXXXX XXXXXX   \n";
	cout<<"                XX    X XX  XX XX      XX XX         XX  XX XX  XX XX     XX  XX   \n";
	cout<<"                XXXXXXX XX  XX XX      XX XXXXXX     XX  XX  XXXX  XXXXXX XX   XX  \n";
	cout<<"                XXXXXXX XX  XX XX      XX XXXXXX     XXXXXX   XX   XXXXXX XX   XX    \n\n";
	
	cout<<",  Your score is "<<endl;
	system("pause");	
}
int displayrow(float d)
{
	clock_t start = clock();
	
	while ( ! _kbhit() )
    {
        if (((clock () - start)/ CLOCKS_PER_SEC ) > d) 
       {
       	 
       	 Closing();
		} 
    }
	return 0 ;
}

int main()
{
	float timer = 2.0;
	displayrow(timer);
}
