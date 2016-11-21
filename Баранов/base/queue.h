﻿#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <cassert>

const unsigned int MaxSize = 100;
template <class T>
class Queue
{
private:
    T *TMEM;   // указатель на очередь
    unsigned int size;  // максимальное количество элементов в очереди
    int begin; // начало очереди
    int end;   // конец очереди
    unsigned int count; // счетчик элементов
public:
    Queue(int = 100);          // конструктор по умолчанию
    Queue(const Queue<T> &);  // конструктор копирования
    ~Queue();                 // деструктор
    bool IsEmpty();           // очередь пуста
    bool IsFull();            // очередь полна
    void push(const T &val);  // добавить элемент в очередь
    T pop();                  // удалить и показать элемент из очереди
    void top();               // удалить элемент из очереди
};


template <class T>// конструктор по умолчанию
Queue<T>::Queue(int sizeQueue)
{
    if ((sizeQueue<1) || (sizeQueue>MaxSize)) throw (sizeQueue);
    size = sizeQueue; // инициализация константы
    begin = 0;
    end = 0;
    count = 0;
}

template <class T>// конструктор копиирования
Queue<T>::Queue(const Queue &otherQueue)
{
    size = otherQueue.size;
    begin = otherQueue.begin;
    end = otherQueue.end;
    count = otherQueue.count;
    TMEM(new T[size + 1]);

    for (int i = 0; i < size; i++)
        TMEM[i] = otherQueue.TMEM[i]; // копируем очередь
}

template <class T>// деструктор 
Queue<T>::~Queue()
{
    delete[] TMEM;
    TMEM = NULL;
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

template <class T>//добавить элемент в очередь
void Queue<T>::push(const T &newElem)
{
    if (IsFull())  throw (count);
    TMEM[end] = newElem; // очередь начинает заполняться с 0 индекса
    end++;
    count++;
}

template <class T>// удалить и показать элемент из очереди
T Queue<T>::pop()
{
    if (IsEmpty()) throw (count);
    count--;
    end--;
    return TMEM[end];
}

template <class T>// удалить элемент из очереди
void Queue<T>::top()
{
    if (IsEmpty()) throw (count);
    count--;
    end--;
}

#endif // QUEUE_H