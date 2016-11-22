#ifndef __TASK_H__
#define __TASK_H__

class TTask
{
	int bb;
public:
	TTask(int val)
	{
		bb = val;
	}

	int GetInfix();
	int GetPostfix();
	int ToPostfix();
	double Calculate();
};

#endif