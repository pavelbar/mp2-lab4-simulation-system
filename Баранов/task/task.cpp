#include "task.h"
#include "queue.h"

Task::Task(unsigned int val) //�������� ������ � ���������� ���-��� ������, ����������� ��� ����������
    {

        if ((val<1) || (val>MaxSize)) throw (val);
        tact_need = val;
    }


unsigned int Task::Task::get_need() 
{ 
    return tact_need; 
}


