#include <iostream>
int main()
{
	std::cout << "output : " << std::endl;
	for (int i = 11; i < 15; ++i)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		std::cout << i << std::endl;
	}
	return 0;
}