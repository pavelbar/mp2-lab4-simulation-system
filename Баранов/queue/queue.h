#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>  
using namespace std;
#include <locale>    

const unsigned int MaxSize = 100;

//класс очереди
class Queue
{
protected:
    int *TMEM;
    int *TMEMTMP;
    int size;
    int begin;
    int end;
    int count;
public:
    Queue(int sizeQueue);            //конструктор по умолчанию
    Queue(const Queue &otherQueue);  //конструктор копирования
    ~Queue();                        //деструктор
    bool IsEmpty();                  //пуста ли очередь
    bool IsFull();                   //полна ли очередь
    void enqueue(const int &newElem);//добавить
    int dequeue();                   //удалить
    int top();                       //просмотр первого
    void printQueue();               //вывод
    int get_size();                  //размер очереди
};

#endif 