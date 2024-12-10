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
	std::string s("45123");
	std::string t("123456789");
	int len(std::min(s.size(), t.size()));
	for (int i(1); i <= len; ++i)
	{
		std::string a(s.end() - i, s.end());
		std::string b(t.begin(), t.begin() + i);
		if (a == b)
		{
			s += std::string(t.begin() + i, t.end());
			break;
		}
	}
	std::cout << s << std::endl;
	
	return 0;
}