#include <iostream>
#include "ADTs\SkipList.h"
#include "ADTs\RandomNumberGenerator.h"
using namespace std;
int main(void)
{
	RandomNumberGenerator rng{};
	SkipList<int> numbers{};
	for (int i = 0; i < 100; i++)
	{
		numbers.addElement(rng.getRandomNumber());
	}

    return 0;
}