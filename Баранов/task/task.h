#ifndef __TASK_H__
#define __TASK_H__

const unsigned int TMaxSize = 10000;//максимальное кол-во тактов, необходимое для выполнение задачи

class Task
{
private:
    unsigned int tact_have;//кол-во тактов, необходимое для выполнение задачи
    unsigned int tact_need;//кол-во тактов, потраченных на задачу
public:
    Task(unsigned int val){//создание задачи с переданным кол-вом тактов, необходимым для выполнение задачи
        if ((val<1) || (val>TMaxSize)) throw (val);
        tact_need = val;
        tact_have = 0;//задача еще не обрабатывалась
    }

    unsigned int show_need() { return tact_need;}// вернуть кол-во тактов, необходимое для выполнение задачи
    
    unsigned int show_have() { return tact_have;}// вернуть кол-во тактов, потраченных на задачу

    bool IsFull() { return (tact_need == tact_have); }//является ли задача выполненной

    void plus() { // задача обрабатывалась один такт
        if (IsFull()) throw (tact_have);
        tact_have++;
    }
};

#endif