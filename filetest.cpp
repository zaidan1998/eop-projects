#include <fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;

int show()
{
	ofstream outfile;
	outfile.open("user.dat");
	
	if(outfile.fail())
		cout<<"Not success"<<endl;
	else
		outfile<<"Salikz "<< endl;
		
	outfile.close();
	
}
int main()
{
	
	ostringstream ss;
    long num = show();
    ss << num;
    cout << ss.str() << endl;

	

	return 0;
}

