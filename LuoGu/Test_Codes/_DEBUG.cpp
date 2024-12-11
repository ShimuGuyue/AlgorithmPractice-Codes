#include <iostream>

struct Node
{
	int data;
	Node* last;
	Node* next;

	void print()
	{
		std::cout << data << std::endl;
	}
};


int main(void)
{
	std::string s("123");
	std::string t("123456789");
	int len(std::min(s.size(), t.size()));
	for (int i(1); i <= len; ++i)
	{
		std::cout << i << std::endl;
		std::cout << std::string(s.end() - i, s.end()) << " ";
		std::cout << std::string(t.begin(), t.begin() + i) << std::endl;
	}
	return 0;
}