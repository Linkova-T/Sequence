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


	void generatingSequence(std::vector<int>&vectorForRand, int n) {
		srand(static_cast<unsigned int>(time(0)));
		for (int count = 0; count < n; ++count)
		{
			vectorForRand.push_back(getRandomNumber(1,10));
		};
	}

int main() {
//generating of random vector
	std::vector<int> sequence;
	std::vector <int>::iterator Iter;
	generatingSequence(sequence,10);
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
//delete duplicates
	std::sort(sequence.begin(), sequence.end());
	for (Iter = sequence.begin(); Iter != sequence.end(); Iter++)
		std::cout << *Iter << " ";
	std::cout << "\n";
	sequence.erase(std::unique(sequence.begin(), sequence.end()), sequence.end());
	for (Iter = sequence.begin(); Iter != sequence.end(); Iter++)
		std::cout << *Iter << " ";
	std::cout << "\n";
//
	int amount = 0;
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] % 2 != 0)
			amount = amount+1;
	}
	std::cout << amount;
	std::cout << "\n";
// min and max elements
	std::vector<int>::const_iterator it; // объявляем итератор
	it = min_element(sequence.begin(), sequence.end());
	std::cout << "min = " << *it << ' ';
	it = max_element(sequence.begin(), sequence.end());
	std::cout << "max = " << *it << ' ';
	std::cout << '\n';
//Prime
	
	for (int j = 0; j < sequence.size(); j++) {
		bool isPrime = true;
		for (int i = 2; i <= (sqrt(abs(sequence[j]))); i++) {
			if (sequence[j] % i == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			std::cout << "Prime = "<< sequence[j] << " ";
		}
	}
	std::cout << '\n';
//sqr
	class functorType2 {
	public:
		int operator()(int i) {
			return i*i;
		}
	};
	functorType2 functorObj;
	std::transform(sequence.begin(), sequence.end(), sequence.begin(), functorObj);
	std::copy(sequence.begin(), sequence.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
//generating new vector
	std::vector<int> vect;
	std::vector <int>::iterator It;
	generatingSequence(vect, sequence.size());
	std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
//sum 
	int sum = 0;
	for (It = vect.begin(); It != vect.end(); It++)
		sum = sum + *It;
	std::cout << "sum = " << sum << "\n";
	//int sum = std::accumulate(vect.begin(), vect.end());
//replacement
	for (It = vect.begin(); It != vect.begin() + 2; It++)
		*It = 1;
	std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
//difference
	std::vector<int> arr;
	std::vector<int>::iterator iter;
	arr.reserve(vect.size());
	/*for (iter = arr.begin(); iter != arr.end(); iter++)
	{
		*iter = 
	}*/
	for (int m = 0; m < vect.size(); m++)
	{
		arr.push_back((sequence[m] - vect[m]));
	}
	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
// -n -> 0
	/*for (iter = arr.begin(); iter != arr.begin() + 3; iter++) {
			*iter = -3;
	}*/
	arr[4] = -1;
	for (iter = arr.begin(); iter != arr.end(); iter++) {
		if (*iter < 0)
			*iter = 0;
	}
	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

}
