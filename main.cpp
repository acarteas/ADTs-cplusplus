#include <iostream>
#include "ADTs\Vector.h"
#include "ADTs\LinkedList.h"
#include "ADTs\QueueAdapter.h"
#include "ADTs\CircularQueue.h"
using namespace std;

int main(void)
{
    //vectorQueueExample();
    //linkedListQueueExample();
    CircularQueue<int> q1{ 1 };

    for (int i = 0; i < 10; i++)
    {
        q1.enqueue(i);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << q1.dequeue() << endl;
    }
    return 0;
}