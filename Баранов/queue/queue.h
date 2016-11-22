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
};


template <class T>// конструктор по умолчанию
Queue<T>::Queue(int sizeQueue)
{
    if ((sizeQueue<1) || (sizeQueue>MaxSize)) throw (sizeQueue);
    size = sizeQueue; // инициализация константы
    begin = 0;
    end = 0;
    count = 0;
    TMEM = new T[size];
}
