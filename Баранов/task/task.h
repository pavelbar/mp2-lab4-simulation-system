#ifndef __TASK_H__
#define __TASK_H__
  
//класс задачи
class Task 
{
private:
    unsigned int tact_need;  //кол-во тактов, необходимое для выполнения задачи
public:
    Task(unsigned int val);  //создание задачи с переданным кол-вом тактов, необходимым для выполнение задачи
    unsigned int get_need();// вернуть кол-во тактов, необходимое для выполнение задачи
};
#endif 