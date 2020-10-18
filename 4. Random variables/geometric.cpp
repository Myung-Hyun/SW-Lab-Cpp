#include <iostream>

#include <ctime>

using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	int count = 0;
	int a, b, c;
	int Ntry = 10000000;
	for (int i = 0; i < Ntry; i++)
	{
		a = rand() % 6 + 1;
		b = rand() % 6 + 1;
		c = rand() % 6 + 1;
		if (a!=6&&b!=6&&c==6)
			count++;
	}
	cout << (float)count / Ntry;
	return 0;
}