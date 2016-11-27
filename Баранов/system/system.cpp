#include "queue.h"
#include "task.h"

#include <conio.h>

int main()
{
    const double A = 0.7;//����������� �������� ������
    //pause
    int key = 10;
    int key_on = 0;
    //report
    double r_done_task = 0;       //+���������� ����������� �����
    double r_task_in_queue = 0;   //+���������� ����� � �������
    double r_time = 0;            //+������� ����� ���������� ������
    double r_stop_tact = 0;       //+���������� ������ �������
    double r_all_tact = 0;        //+����� ���������� ������
    double r_no_task = 0;         //+���������� �����, ���������� �����
    //������
    Queue queue_tact_need(MaxSize);
    int tact_have = 0;
    //--

    setlocale(LC_ALL, "Russian");
    cout << endl << "������� ����� �������, ����� ���������� ���������� � ������� �����" << endl;

    while (!_kbhit())
    {
        if (!key) key_on = 1;
        r_all_tact++;//����
        Task task(rand() % MaxSize + 1);//�������� ������ ��� ���������� ������� ���������� 0 - MaxSize ������ 
        double AT = (double)(rand()) / RAND_MAX * 1; // ��������� �������������� ����� �� 0 �� 1

        //�������� ����� ������
        if (AT > A)
        {
            if ((queue_tact_need.IsFull()))
                r_no_task++;//������ �������� �����
            else
            {
                queue_tact_need.enqueue(task.get_need());
            }
        }

        //����������
        if (queue_tact_need.IsEmpty())
            r_stop_tact++;//���� �������
        else if (queue_tact_need.top() == tact_have)
        {
            r_done_task++;//����� ���������
            //������� ������
            queue_tact_need.dequeue();
            tact_have = 0;
            //--
            r_stop_tact++;//���� �������
            if (key_on == 1) break;//���� ���� ���� ������� �� ���������, �� ���� ������ ����� ���������� ������� ������
        }
        else
        {
            tact_have++;
        }
        r_task_in_queue = queue_tact_need.get_size();
        r_time = r_all_tact / r_done_task;
    }

    //report
    cout << endl << "�����: " << endl;
    cout << "���������� ����������� �����: " << r_done_task << endl;
    cout << "���������� ����� � �������: " << r_task_in_queue << endl;
    cout << "������� ����� ���������� ������: " << r_task_in_queue << " ������� �������" << endl;
    cout << "���������� ������ �������: " << r_stop_tact << endl;
    cout << "����� ���������� ������: " << r_all_tact << endl;
    cout << "���������� �����, ���������� �����: " << r_no_task << endl;
    //--
    return 0;
}