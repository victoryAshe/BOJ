#include <iostream>
#include <string>
using namespace std;

int main()
{
	string result = "";

	//input 
	int a; int b;
	cin >> a >> b;

	//calculate
	if (a > b) result = ">";
	else if (a < b) result = "<";
	else result = "==";

	cout << result;


	return 0;
}