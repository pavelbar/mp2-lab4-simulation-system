#include "task.h"
#include "queue.h"

Task::Task(unsigned int val) //создание задачи с переданным кол-вом тактов, необходимым для выполнения
    {

        if ((val<1) || (val>MaxSize)) throw (val);
        tact_need = val;
    }


unsigned int Task::Task::get_need() 
{ 
    return tact_need; 
}


