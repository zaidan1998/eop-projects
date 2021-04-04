#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

struct player
{
	char name[50];
	int score;
};

void loading()
{
	cout<<"\n\n\n\n\n                                                   LOADING";
	for(int f=1;f<5;f++)
	{
		Sleep(750);
		cout<<" . ";
	}
	system("cls");
}
void instruct()
{
	int back;
	cout << "\nHOW TO PLAY" << endl;
	cout << "\n1 - The computer has selected a secret combination of 4 colors." << endl;
	cout << "2 - You have to guess that combination in 10 or fewer tries to win." << endl;
	cout << "3 - To create your guess, write the indicator for each color until the fourth time." << endl;
	cout << "4 - Each time you submit a guess the program will tell how many is right or wrong." << endl;
	cout << "5 - R: Right color on the right position. \nW : Right color on the wrong position." << endl;
	cout << "6 - If your guess scores 4 right colors on the right position within 10 tries, you win." << endl << endl;
	do
	{
		cout << "Enter 1 to go to main menu : ";
		cin >> back;
	}while(back!=1);
	
	
}
void menu()
{
	cout << endl;
	cout << "\t\t"<< "*****WELCOME TO MASTERMIND GUESSING GAME*****" << "\t\t" << endl;
	cout << "\nMAIN MENU : " << endl;
	cout << "\n1 - START" << endl;
	cout << "\n2 - INSTRUCTION" << endl;
	cout << "\n3 - HIGH SCORE" << endl;
	cout << "\n4 - EXIT" << endl;
}
void play1()
{
	char colors[4];

	srand(time(NULL));
	
	for(int i=0; i<4; i++)
	{
		cout << "Choose the colour for position " << i+1 << "(R-Red, B-Blue, Y-Yellow, P-Purple, G-Green) : ";
		cin >> colors[i];
	}
	
	system("cls");
	
	char usercolors[4];

	cout << "We have our colors!" << endl;
	cout << endl << endl;
	int turncounter = 0;
	while(turncounter != 10)
	{
		int R=0,W=0;
		turncounter++;

		cout << "Current try: " << turncounter << endl;

		for(int i=0;i<4;i++)
		{
			cout << "Color " << i << ": "; 
			cin >> usercolors[i];
			cout << endl;
		}

		for(int i=0;i<4;i++)
		{	
			if(*(usercolors + i) == colors[i])
				R++;
		}
		

		if(*usercolors == colors[1] ||  *usercolors == colors[2] || *usercolors == colors[3] )
		{
			   W++;
		}
		   if(*(usercolors+1) == colors[0] || *(usercolors+1) == colors[2] ||*(usercolors+1) == colors[3])
		   {
				   W++;
		   }
		   if(*(usercolors+2) == colors[0] ||*(usercolors+2) == colors[1] ||*(usercolors+2) == colors[3])
		   {
			   W++;
		   }
		   if(*(usercolors+3) == colors[0] ||*(usercolors+3) == colors[1] ||*(usercolors+3) == colors[2])
			{
				W++;
			}
			
			int A=R+W;
			if (A>4)
				W=4-R;
				
			
			
			cout << "Colour with correct position : " << R << endl;
			cout << "Colour with wrong position : " << W << endl;
			
			
		cout << endl << endl;
		
	//	p.score = 10 - (turncounter-1);

		if(*usercolors == colors[0] &&
		   *(usercolors+1) == colors[1] &&
		   *(usercolors+2) == colors[2] &&
		   *(usercolors+3) == colors[3])
		{
			cout << "You win! Number of tries: " << turncounter << endl;
	//		cout << "\nYour score is " << p.score << " points." << endl;
			turncounter = 12;
		}else{
			cout << "You not win yet." << endl << endl;
		}
		R-=R;
		W-=W;
		
	//	p.score = 10 - (turncounter-1);

	}
}

void play2()
{
	char colors[4];

	srand(time(NULL));
	int randomint = (rand()%5)+1;

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
	 
	 }
	 
	 	cout << colors[i] << endl;

	}
	
	
	
		char usercolors[4];

	cout << "We have our colors!" << endl;
	cout << endl << endl;
	int turncounter = 0;
	while(turncounter != 10)
	{
		int R=0,W=0;
		turncounter++;

		cout << "Current try: " << turncounter << endl;

		for(int i=0;i<4;i++)
		{
			cout << "Color " << i+1 << ": "; 
			cin >> usercolors[i];
			cout << endl;
		}

		for(int i=0;i<4;i++)
		{	
			if(*(usercolors + i) == colors[i])
				R++;
		}
		

		if(*usercolors == colors[1] ||  *usercolors == colors[2] || *usercolors == colors[3] )
		{
			   W++;
		}
		   if(*(usercolors+1) == colors[0] || *(usercolors+1) == colors[2] ||*(usercolors+1) == colors[3])
		   {
				   W++;
		   }
		   if(*(usercolors+2) == colors[0] ||*(usercolors+2) == colors[1] ||*(usercolors+2) == colors[3])
		   {
			   W++;
		   }
		   if(*(usercolors+3) == colors[0] ||*(usercolors+3) == colors[1] ||*(usercolors+3) == colors[2])
			{
				W++;
			}
			
			int A=R+W;
			if (A>4)
				W=4-R;
				
			
			
			cout << "Correct : " << R << endl;
			cout << "Wrong : " << W << endl;
			
			
		cout << endl << endl;

		if(*usercolors == colors[0] &&
		   *(usercolors+1) == colors[1] &&
		   *(usercolors+2) == colors[2] &&
		   *(usercolors+3) == colors[3])
		{
			cout << "You win! Number of tries: " << turncounter << endl;
			turncounter = 12;
		}else{
			cout << "You not win yet." << endl << endl;
		}
		R-=R;
		W-=W;

	}
}
void start()
{
	player p;
	int n;
	
	cout << "\nEnter username : ";
	cin >> p.name;
	
	cout << "\nChoose type of game : " << endl;
	cout << "\n1 - Player vs Player" << endl;
	cout << "2 - Player vs Computer" << endl;
	
	do
	{
		cout << "\nChoose : ";
		cin >> n;
		
		if (n != 1 && n != 2)
		{
			cout << "\nError. Please enter again." << endl;
		}
	}while(n != 1 && n != 2);
	
	if(n==1)
	{
		play1();
	}
	
	else if(n == 2)
	{
		play2();
	}
}



int choose(int a)
{
	int opt;

	
	do
	{
		cout << "\nChoose Your Option : ";
		cin >> opt;
		
		if(opt < 1 || opt > 4)
		{
			cout << "\nINVALID INPUT.Choose 1-4 only!!" << endl;
		}
		
	}while (opt < 1 || opt > 4);
	
	switch(opt)
	{
		case 1: start(); break;
		case 2: instruct(); break;
	//	case 3: score(); break;
		case 4: a +=4; break;
	}
	
	return a;
}



void score()
{
	
}

int main()
{
	int exit;
	int a=0;
	loading();
	do
	{
	//welcome();
	//loading();
	system("cls");
	menu();
	exit=choose(a);
	}while(exit!=4);
	cout << "Thank You";
	return 0;
}
	

