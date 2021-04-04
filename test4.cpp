#include <iostream>
#include <fstream> // file stream
#include <cstdlib> // needed for exit
#include <string>
using namespace std;
int main(){
 string filename = "user.dat"; // put the filename up front
 string descrip;
 double price;
 ifstream inFile;
 inFile.open(filename.c_str());
 if(inFile.fail()) { // check for successful open
cout << "The file is not successfully opened"
 << "\n Please check that the file currently exists."
 << endl;
 exit(1);
}
//read and display file’s contents
 inFile >> descrip >> price;
 while (inFile.good()) // check next character
 {
 cout << descrip << ' ' << price << endl;
 inFile >> descrip >> price;
 }
 inFile.close();
 return 0;
}
