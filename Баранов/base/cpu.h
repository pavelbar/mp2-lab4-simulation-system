#ifndef __CPU_H__
#define __CPU_H__

#include <string>

class TCpu
{
	int aa;
public:
	TCpu (int val);
	int GetInfix();
	int GetPostfix();
	int ToPostfix();
	double Calculate();
};

#endif