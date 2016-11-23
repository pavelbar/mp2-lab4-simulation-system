#ifndef __TASK_H__
#define __TASK_H__

const unsigned int MaxSize = 1000000000;

class Task
{
private:
    unsigned int tact_have;
    unsigned int tact_need;
public:
    Task(unsigned int val){
        if ((val<1) || (val>MaxSize)) throw (val);
        tact_need = val;
        tact_have = 0;
    }

    unsigned int show_need() { return tact_need;}
    
    unsigned int show_have() { return tact_have;}

    bool IsFull() { return (tact_need == tact_have); }

    void plus() { 
        if (IsFull()) throw (tact_have);
        tact_have++;
    }
};

#endif