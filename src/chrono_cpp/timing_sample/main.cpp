#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		auto ms = duration.count() * 1000.0f;
		std::cout << "Timer took: " << ms << "ms" << std::endl;
	}
};

void printHello() 
{
	Timer timer;
	for (size_t i = 0; i < 100; i++)
	{
		//std::cout << "Hello!" << std::endl;
		std::cout << "Hello\n"; //use "\n" to replace std::endl to speed up
	}
}

int32_t main()
{
	using namespace std::literals::chrono_literals;

	auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(1s);
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;
	std::cout << duration.count() << "s" << std::endl;

	printHello();

	std::cin.get();
	return 0;
}