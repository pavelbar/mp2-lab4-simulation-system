#ifndef __TASK_H__
#define __TASK_H__
  
//����� ������
class Task 
{
private:
    unsigned int tact_need;  //���-�� ������, ����������� ��� ���������� ������
public:
    Task(unsigned int val);  //�������� ������ � ���������� ���-��� ������, ����������� ��� ���������� ������
    unsigned int get_need();// ������� ���-�� ������, ����������� ��� ���������� ������
};
#endif 