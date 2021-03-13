#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>


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
//generating of random vector
	std::vector<int> sequence;
	std::vector <int>::iterator Iter;
	generatingSequence(sequence);
	for (Iter = sequence.begin(); Iter != sequence.end(); Iter++)
		std::cout << *Iter << " ";
	std::cout << "\n";
//adding elements from cin
	std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(sequence));
	std::cin.clear();
	for (Iter = sequence.begin(); Iter != sequence.end(); Iter++)
		std::cout << *Iter << " ";
	std::cout << "\n";
//random shuffle of vector
	std::random_shuffle(sequence.begin(), sequence.end());
	for (Iter = sequence.begin(); Iter != sequence.end(); Iter++)
		std::cout << *Iter << " ";
	std::cout << "\n";

}
