#include <iostream>
#include <fstream> // file stream
#include <cstdlib> // needed for exit
#include <string>
using namespace std;
/*void savedata(string username,int score)
{
	string filename="user.dat";
	ofstream outfile;//declare output stream
	outfile.open(filename.c_str());
	
	outfile<<username<<" "<<score;
	outfile.close();
	
}*/
void showdata(string x)
{
	
	string filename="user.dat";
	string descr;
	ifstream infile;
	infile.open(filename.c_str());
	
	
	while (infile.good()) // check next character
 {
	 infile >> descr ;
 }
	infile.close();	
}

int main()
{
	string username;
//	cin>>username>>score;
//	savedata(username,score);
	
	showdata(username,score);
	
	return 0;
}
