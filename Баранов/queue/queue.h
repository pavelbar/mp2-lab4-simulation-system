#include <cassert>
const unsigned int MaxSize = 100;
template <class T>
class Queue
{
private:
    T *TMEM;   // ��������� �� �������
    unsigned int size;  // ������������ ���������� ��������� � �������
    int begin; // ������ �������
    int end;   // ����� �������
    unsigned int count; // ������� ���������
public:
    Queue(int = 100);          // ����������� �� ���������
};


template <class T>// ����������� �� ���������
Queue<T>::Queue(int sizeQueue)
{
    if ((sizeQueue<1) || (sizeQueue>MaxSize)) throw (sizeQueue);
    size = sizeQueue; // ������������� ���������
    begin = 0;
    end = 0;
    count = 0;
    TMEM = new T[size];
}
