#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
namespace zcq
{
	int a = 6;
	int add(int x, int y)
	{
		return x + y;
	}
}
int main()
{
	cout << zcq:: a;
	int b = 0;
	cin >> b;
	cout << b;
	


	return 0;

}

