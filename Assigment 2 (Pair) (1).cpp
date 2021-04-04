//Mohamad Zaki bin Jaafar 1719207
//Ahmad Zaidan bin Adnan 1718733

#include <iostream>
using namespace std;
int x=0, y=0;
void generate_primes(int [], int [], int, int);
void commonPrimes(int [], int [], int, int);

int main()
{
	int NUM1, NUM2;
	cout << "Enter two integer values separated by a space : ";
	cin >> NUM1 >> NUM2; 
	typedef int integer;
	integer primeFactor1[NUM1], primeFactor2[NUM2]; 
	generate_primes(primeFactor1, primeFactor2, NUM1, NUM2);
	commonPrimes(primeFactor1, primeFactor2, NUM1, NUM2);
	
	return 0;
}

void generate_primes(int primeFactor1[], int primeFactor2[], int NUM1, int NUM2)
{
	cout << endl << "Prime factors of " << NUM1 << ":" << endl;
    for(int i=2; i<=NUM1; i++) 
    {
        while (NUM1%i==0) 
        {
            primeFactor1[x]=i;
            cout << primeFactor1[x] << " ";
            x++;
            NUM1/=i;
        }
    }
    
    cout << endl << endl << "Prime factors of " << NUM2 << ":" << endl;
    for(int i=2; i<=NUM2; i++) 
    {
        while (NUM2%i==0) 
        {
            primeFactor2[y]=i;
            cout << primeFactor2[y] << " ";
            y++;
            NUM2/=i;
        }
    }
	
}

void commonPrimes(int primeFactor1[], int primeFactor2[], int NUM1, int NUM2)
{
	int highest;
	for (int a=0; a<x; a++)
	{
		for (int b=0; b<y; b++)
		{
			if (primeFactor1[a]==primeFactor2[b])
			{
				highest = primeFactor1[a];
			}
		}
	}
	cout << endl << endl << "Highest Common Prime Factor of "<< NUM1 << " and " << NUM2 << " is " << highest << endl;
}
