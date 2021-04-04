#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include <fstream>//for file header
#include "extern.h"


using namespace std;


struct player//create structure for user information
{
	string name;
	int score;
};

void loading()//to show loading screen
{
	cout<<"\n\n\n\n\n                                                   LOADING";
	for(int f=1;f<5;f++)
	{
		Sleep(750);//to delay the output
		cout<<" . ";
	}
	system("cls");
}
void instruct()//provide instruction for player
{
	int back;
	system("cls"); //clear the screen before
	
	cout << "\nHOW TO PLAY" << endl;
	cout << "\n1 - The computer has selected a secret combination of 4 colors." << endl;
	cout << "2 - You have to guess that combination in 10 or fewer tries to win." << endl;
	cout << "3 - To create your guess, write the indicator for each color until the fourth colour." << endl;
	cout << "4 - Each time you submit a guess the program will tell how many are" << endl;
	cout << "    right color and right position & right color but wrong position." << endl;
	cout << "5 - If your guess scores 4 right colors on the right position within 10 tries, you win." << endl << endl;
	do
	{
		cout << "Enter 1 to go to main menu : ";
		cin >> back;
	}while(back!=1); //prevent invalid input
	
	
}
void error()
{
			cout << "===============================================" << endl;
			cout << "        Your enter invalid keywords    "          <<endl;
			cout << " Please enter the keyword for the colors only!! "  <<endl;
			cout << "===============================================" << endl;
}

void start() //function to play the game
{
	system("cls");
	player p;
	int score=100;//initialize the variables
		int a=0;
		int b=0;
		int c=0;
		int d=0;
		int e=0;
	char colors[4];
	do
	{
		srand(time(NULL));
		int randomint;
		a-=a;
		b-=b;
		c-=c;
		d-=d;
		e-=e;
	
		for(int i=0;i<4;i++)
		{
			randomint = (rand()%5)+1;//create random number

			 switch(randomint)//the colors bank
			 {
				case 1:colors[i] = 'R'; a++; break;
	 			case 2:colors[i] = 'B';	b++; break;
	 			case 3:colors[i] = 'Y'; c++; break;
	 			case 4:colors[i] = 'P'; d++; break;
	 			case 5:colors[i] = 'G';	e++; break;
	 		}
		}
	}while(a>1||b>1||c>1||d>1||e>1);
	//prevent the system from entering more than one same colors in order to make the game easier :)
	
	char usercolors[4];//array for user input

	cout << "The colors have been chosen!!!" << endl;
	cout << endl << endl;
	
	int count = 0;
	while(count!= 10)//limit the number of tries
	{
		int R=0,W=0;
		count++;
		
		// You may uncomment below if want to show correct answers for testing the game
		//  for(int i=0;i<4;i++)   
		//     cout << colors[i] << endl;
		
		cout << "(R-Red, B-Blue, Y-Yellow, P-Purple, G-Green)" << endl;
		cout << "Current try : " << count << endl;

		for(int i=0;i<4;i++)//loop to show the position
		{
			cout << "Position " << i+1 << ": "; 
			cin >> usercolors[i];
		
			while(usercolors [i]!= 'R'&&usercolors [i]!= 'G'&&usercolors [i]!= 'B'&&usercolors [i]!= 'Y'&&usercolors [i]!= 'P')//loop if detect invalid input
			{
				error();//display error messages
				cout << "Position " << i+1 << ": "; 
				cin >> usercolors[i];
			}
			
			cout << endl;
		}

		for(int i=0;i<4;i++)//loop to check if the user input equal to the random generated color
		{	
			//compare the user input with random generated color with correct position 
			//we use pointer to compare the address
			//R++ - to total the true color with true position
			if(*(usercolors + i) == colors[i])
				R++;		
		}
		
		//compare the user input with random generated color but with wrong position 
		//W++ - to total number the true color but with wrong position
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
		
//		for(int i=0;i<4;i++)
//		{
//			if(usercolors [i]!= 'R'||usercolors [i]!= 'G'||usercolors [i]!= 'B'||usercolors [i]!= 'Y'||usercolors [i]!= 'P')
//			error();
//		}
			
		cout << "Right colour with correct position : " << R << endl;
		cout << "Right colour with wrong position : " << W << endl;
		
		cout << endl << endl;
	
		//to end the game when get all the guesses correct
		if(*usercolors == colors[0] && *(usercolors+1) == colors[1] &&   *(usercolors+2) == colors[2] &&   *(usercolors+3) == colors[3])
		{
			cout << "Congrats you win!"<<endl;
			p.score=score;
			cout << "Your score is : "<<score<<endl;
			cout << "\nEnter username : " ;
			cin >> p.name;
		
			//we create file to store the username and score
			ofstream myfile;
			myfile.open ("user.dat",ios::app);
			myfile << p.name << " " << p.score << endl;
			myfile.close();
		
			count = 10;//to prevent it to get into while loop again
		}
		else
		{
			cout << "Try Again!" << endl << endl;
		}
	
		R-=R;
		W-=W;
		score-=10;
		if(count==10)//to show the final answer in the end
		{
			cout <<" The right colors:" << endl;
			for(int i=0;i<4;i++)
				cout << colors[i] << endl;
			cout<<"\n\n\n\n\n                                                   RELINK TO MAIN MENU";
	
			for(int f=1;f<5;f++)//to delay the output
			{
				Sleep(750);
				cout<<"";
			}
			system("cls");//clear the screen 
		}
	}
}

void score() //function to show the highscore by retrieve the data file
{
	player p;
	string filename = "user.dat"; // put the filename up front   
	string userName;
	string arr[10][2];   
	double userscore;   
	ifstream myfile;   
	myfile.open(filename.c_str()); 
	
	system("cls");
    myfile >> userName >> userscore; 
    cout<<"HIGHSCORES"<<endl<< endl;
 
   while (myfile.good()) // check next character   
   {    
   		int i = 0;
   		cout << userName << ' ' << userscore << endl;     
		myfile >> userName >> userscore; //insert the username and score into file

	} 
	myfile.close();//close the file
 	
   int ex;
   do //to return to main menu
   {
   		cout << endl << "Enter 1 to exit : ";
   		cin >> ex;
   		
   }while(ex!=1);
}

int choose(int a)//to make option in main menu
{
	int opt;
	do
	{
		cout << "\nChoose Your Option : ";
		cin >> opt;
		
		if(opt < 1 || opt > 4)//prevent from invalid input
		{
			cout << "\nINVALID INPUT.Choose 1-4 only!!" << endl;
		}
		
	}while (opt < 1 || opt > 4);
	
	switch(opt) //user enter option to go to other function
	{
		case 1: start(); break;
		case 2: instruct(); break;
		case 3: score(); break;
		case 4: a +=4; break;
	}
	
	return a;
}

void welcome() //to show our game name
{
	cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout << "        ####      ####     ####              ##########          ######    ####      ####  ##  ####   ##  ######" << endl;
	cout << "        ## ##    ## ##    ##  ##    ########     ##     #######  ##   ##   ## ##    ## ##  ##  ## ##  ##  ##   ##" << endl;
	cout << "        ## ##    ## ##    ##  ##    ###          ##     ##       #######   ##  ##  ##  ##  ##  ## ##  ##  ##    ##" << endl;                                                                                                                                                    
	cout << "        ##  ##  ##  ##   ########   ########     ##     #######  ## ##     ##   ####   ##  ##  ##  ## ##  ##    ##" << endl;
	cout << "        ##    ##    ##   ##    ##        ###     ##     ##       ##  ##    ##    ##    ##  ##  ##   ####  ##   ##" << endl;
	cout << "        ##          ##  ##      ##  ########     ##     #######  ##   ##   ##          ##  ##  ##    ###  ######" << endl;
	
	for(int f=1;f<5;f++)//to delay the output
	{
		Sleep(500);
	}

}

int main()
{
	int exit;
	int a=0;
	loading(); //loading screen
	welcome(); //welcome screen
	do
	{
		system("cls"); //clear the screen
		menu(); //menu function
		exit=choose(a);
	}while(exit != 4); //make loop if the user dont want to exit
	
	cout << endl <<" Thank You ";
	return 0;
}
	

