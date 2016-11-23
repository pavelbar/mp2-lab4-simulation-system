#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>  //debug
using namespace std; //debug
#include <locale>    //debug

const unsigned int MaxSize = 100;
template <class T>
class Queue
{
private:
    T *TMEM;            // указатель на очередь
    T *TMEMTMP;         // указатель на tmp
    int size;           // размер очереди
    int begin;          // начало очереди
    int end;            // конец очереди
    int count;          // счетчик элементов
public:
    Queue(int = MaxSize);         // конструктор по умолчанию
    Queue(const Queue<T> & val);  // конструктор копирования
    ~Queue();                     // деструктор
    bool IsEmpty();               // очередь пуста
    bool IsFull();                // очередь полна
    void enqueue(const T &val);   // добавить элемент в в конец очереди
    T dequeue();                  // взять первый элемент из очереди
    void printQueue();            //debug       
};


template <class T>// конструктор по умолчанию
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

template <class T>// конструктор копиирования
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

template <class T>// деструктор 
Queue<T>::~Queue()
{
    delete[] TMEM;
    delete[] TMEMTMP;
    TMEM = NULL;
    TMEMTMP = NULL;
}

template <class T>// очередь пуста
bool Queue<T>::IsEmpty()
{
    return(count == 0);
}

template <class T>// очередь полна
bool Queue<T>::IsFull()
{
    return (count == size);
}

template <class T>//добавить элемент в в конец очереди
void Queue<T>::enqueue(const T &newElem)
{
    if (IsFull())  throw (count);
    TMEM[end] = newElem; 
    end++;
    count++;

    if (end > size)
        end = end - size + 1; 
}

template <class T>// взять первый элемент из очереди
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

template<typename T>//debug
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