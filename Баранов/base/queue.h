#ifndef __QUEUE_H__
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
#endif // QUEUE_H