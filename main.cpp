#include <iostream>
#include <string>
#include "sorting\BubbleSorter.h"
#include "sorting\InsertionSorter.h"
#include "sorting\SelectionSorter.h"
#include "benchmarks\SortingBenchmark.h"
#include "ADTs\Vector.h"

using namespace std;

int main(void)
{
    Vector<int> v1{};
    SortingBenchmark bm{};
    Vector<string> labels = { "Bubble", "Insertion", "Selection" };
    Vector<IndexedSorter<int> *> sorters = { new BubbleSorter<int>{},
                                             new InsertionSorter<int>{},
                                             new SelectionSorter<int>{} };
    for (int i = 0; i < 3; i++)
    {
        cout << labels[i] << endl;
        for (int j = 1000; j < 10000; j += 1000)
        {
            v1 = Vector<int>{};
            cout << j;
            cout << "\t" << bm.sortReverseSortedBenchmark(sorters[i], &v1, j) << endl;
        }
    }
    
    return 0;
}