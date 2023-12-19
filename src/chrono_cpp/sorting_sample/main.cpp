#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int32_t main()
{
	std::vector<int32_t> values = { 3,5,1,4,2 };
	//std::sort(values.begin(), values.end());
	//std::sort(values.begin(), values.end(), std::greater<int32_t>());
	//std::sort(values.begin(), values.end(), std::less<int32_t>());
	std::sort(values.begin(), values.end(), [](const int32_t a, const int32_t b)
		{
			//return a < b;
			//return a > b;
			if (a == 1)
			{
				return false;
			}
			if (b == 1)
			{
				return true;
			}
			return a < b;
		});

	for (const int32_t value : values)
	{
		std::cout << value << ' ';
	}
	
	std::cin.get();
}