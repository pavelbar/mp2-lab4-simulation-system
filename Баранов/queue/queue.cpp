#include "queue.h"
Queue::Queue(int sizeQueue)
{
    if ((sizeQueue < 1) || (sizeQueue > MaxSize)) throw (sizeQueue);
    size = sizeQueue;
    begin = 0;
    end = 0;
    count = 0;
    TMEM = new int[size + 1];
    TMEMTMP = new int[1];
}

Queue::Queue(const Queue &otherQueue)
{
    size = otherQueue.size;
    begin = otherQueue.begin;
    end = otherQueue.end;
    count = otherQueue.count;
    TMEM = new int[size + 1];
    for (int i = 0; i < size; i++)
        TMEM[i] = otherQueue.TMEM[i];
}

Queue::~Queue()
{
    delete[] TMEM;
    delete[] TMEMTMP;
    TMEM = NULL;
    TMEMTMP = NULL;
}

bool Queue::IsEmpty()
{
    return(count == 0);
}

bool Queue::IsFull()
{
    return (count == size);
}

void Queue::enqueue(const int &newElem)
{
    if (IsFull())  throw (count);
    TMEM[end] = newElem;
    end++;
    count++;

    if (end > size)
        end = end - size + 1;
}

int Queue::dequeue()
{
    if (IsEmpty()) throw (count);
    TMEMTMP[0] = TMEM[begin];
    begin++;
    count--;
    if (begin > size)
        begin = begin - size + 1;
    return TMEMTMP[0];
}

int Queue::top()
{
    if (IsEmpty()) throw (count);
    return TMEM[begin];;
}

void Queue::printQueue()
{
    cout << endl << "Очередь: " << endl;
    if (count == 0)
        cout << " пустая\n";
    else
    {
        int tmp = count;
        int tmp2 = end;
        while (tmp != 0)
        {
            cout << TMEM[tmp2 - 1] << " ";
            tmp--;
            tmp2--;
        }
        cout << endl;
    }
}

int Queue::get_size()
{
    return count;
}



