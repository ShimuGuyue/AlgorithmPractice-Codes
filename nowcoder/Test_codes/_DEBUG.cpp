#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	for (int i(1); i < 10; ++i)
	{
		std::cout << rand() % 10 + 1 << " " << rand() % 10 + 1 << std::endl;
	}
	

	return 0;
}