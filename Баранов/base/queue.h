#ifndef __QUEUE_H__
#define __QUEUE_H__


const int MaxSize = 100;
class TQueue
{
protected:
	TQueue *pMem;
	int size;
	int count;
public:
	TQueue(int = 10);
	~TQueue();
	bool IsEmpty();
	bool IsFull();
	void Push(const T &val);//add
	TQueue Pop();//показать и удалить
	TQueue Top();//view
};
#endif