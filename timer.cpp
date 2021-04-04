#include <windows.h>
#include <iostream>
#include <unistd.h>
using namespace std;
int main(void)
 {
    cout<<"TIMER" << endl;

	for(int j=10;j>0;j--)
       	{
       		cout << j ;
       		sleep(1.5);
			system("cls");
	  	}
		
      
        cout<<endl<<" GAME OVER ";
        cin.ignore();
}
