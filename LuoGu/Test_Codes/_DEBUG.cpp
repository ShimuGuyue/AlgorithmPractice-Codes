#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> a(10);
	a.clear();
	std::cout << a.size();

	return 0;
}