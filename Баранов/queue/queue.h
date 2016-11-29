#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>  
using namespace std;
#include <locale>    

const unsigned int MaxSize = 100;

//����� �������
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
    Queue(int sizeQueue);            //����������� �� ���������
    Queue(const Queue &otherQueue);  //����������� �����������
    ~Queue();                        //����������
    bool IsEmpty();                  //����� �� �������
    bool IsFull();                   //����� �� �������
    void enqueue(const int &newElem);//��������
    int dequeue();                   //�������
    int top();                       //�������� �������
    void printQueue();               //�����
    int get_size();                  //������ �������
};

#endif 