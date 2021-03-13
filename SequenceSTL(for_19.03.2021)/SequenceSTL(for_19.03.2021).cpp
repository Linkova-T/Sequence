#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <random>


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
};


	void generatingSequence(std::vector<int>&vectorForRand) {
		srand(static_cast<unsigned int>(time(0)));
		for (int count = 0; count < 10; ++count)
		{
			vectorForRand.push_back(getRandomNumber(1,10));
		};
	}

int main() {
	std::vector<int> sequence;
	generatingSequence(sequence);
	for (int i = 0; i < 10; i++)
	{
		std::cout << sequence[i] << "\n";
	};
}
