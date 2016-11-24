#include "queue.h"
#include "task.h"
#include <iostream>//rand()

int main()

{
    const double A = 0.7;//�������� ������
    //report
    double r_done_task = 0;       //���������� ����������� �����
    double r_task_in_queue = 0;   //���������� ����� � �������
    double r_time = 0;            //������� ����� ���������� ������
    double r_stop_tact = 0;       //���������� ������ �������
    double r_all_tact = 0;        //����� ���������� ������
    double r_no_task = 0;         //���������� �����, ���������� �����
    //--
    Queue<Task> q(MaxSize);//������� ����� ������������� �������

    for (;;) {
        r_all_tact++;
        double AT = (double)(rand()) / RAND_MAX * 1; // ��������� �������������� ����� �� 0 �� 1
        if (AT > A) {
            Task t( rand() % TMaxSize + 1 );//�������� ����� ������, ��� ���������� ������� ���������� 0 - TMaxSize ������
            q.enqueue(t);// ���������� � ������� ����� ������
        }
    }
    return 0;
}