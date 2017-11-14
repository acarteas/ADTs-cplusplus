#include <iostream>
#include <string>
#include "sorting\Sorting.h"
#include "benchmarks\SortingBenchmark.h"
#include "ADTs\Vector.h"

using namespace std;

int main(void)
{
    Vector<int> v1{};
    
    SortingBenchmark bm{};
    Vector<string> labels = { "Bubble", "Insertion", "Selection", "Merge", "Quick", "Shell" };
    Vector<IndexedSort<int> *> sorters = { new BubbleSort<int>{},
                                             new InsertionSort<int>{},
                                             new SelectionSort<int>{},
                                             new MergeSort<int>{},
                                             new QuickSort<int>{},
                                             new ShellSort<int>{}
    };
    for (int i = 3; i < labels.getSize(); i++)
    {
        cout << labels[i] << endl;
        for (int j = 1000; j < 100000; j += 10000)
        {
            v1 = Vector<int>{};
            cout << j;
            cout << "\t" << bm.sortReverseSortedBenchmark(sorters[i], &v1, j) << endl;
        }
    }
    
    return 0;
}