#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>  
using namespace std; 
#include <locale>    

const unsigned int MaxSize = 100;
template <class T>
class Queue
{
private:
    T *TMEM;            
    T *TMEMTMP;         
    int size;          
    int begin;          
    int end;            
    int count;         
public:
    Queue(int = MaxSize);         
    Queue(const Queue<T> & val);  
    ~Queue();                    
    bool IsEmpty();               
    bool IsFull();                
    void enqueue(const T &val);   
    T dequeue();                 
    void printQueue();         
};


template <class T>
Queue<T>::Queue(int sizeQueue)
{
    if ((sizeQueue<1) || (sizeQueue>MaxSize)) throw (sizeQueue);
    size = sizeQueue; 
    begin = 0;
    end = 0;
    count = 0;
    TMEM = new T[size+1];
    TMEMTMP = new T[1];
}

template <class T>
Queue<T>::Queue(const Queue &otherQueue)
{
    size = otherQueue.size;
    begin = otherQueue.begin;
    end = otherQueue.end;
    count = otherQueue.count;
    TMEM = new T[size + 1];
    for (int i = 0; i < size; i++)
        TMEM[i] = otherQueue.TMEM[i]; 
}

template <class T>
Queue<T>::~Queue()
{
    delete[] TMEM;
    delete[] TMEMTMP;
    TMEM = NULL;
    TMEMTMP = NULL;
}

template <class T>
bool Queue<T>::IsEmpty()
{
    return(count == 0);
}

template <class T>
bool Queue<T>::IsFull()
{
    return (count == size);
}

template <class T>
void Queue<T>::enqueue(const T &newElem)
{
    if (IsFull())  throw (count);
    TMEM[end] = newElem; 
    end++;
    count++;

    if (end > size)
        end = end - size + 1; 
}

template <class T>
T Queue<T>::dequeue()
{
    if (IsEmpty()) throw (count);
    TMEMTMP[0] = TMEM[begin];
    begin++;
    count--;
    if (begin > size)
        begin -= size + 1; 
    return TMEMTMP[0];
}

template<typename T>
void Queue<T>::printQueue()
{
    cout << endl << "Очередь: " << endl;
    if (count == 0 )
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

#endif 