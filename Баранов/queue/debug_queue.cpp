#include "queue.h"

int main()
{
    //debug zone
    setlocale(LC_ALL, "Russian");
    Queue v(2);
    v.printQueue();

    v.enqueue(1);
    v.enqueue(2);
    v.printQueue();

    v.dequeue();
    v.printQueue();

    v.enqueue(2);
    v.printQueue();

    v.dequeue();
    v.printQueue();

    v.enqueue(2);
    v.printQueue();

    v.dequeue();
    v.printQueue();

    v.enqueue(2);
    v.printQueue();

    v.dequeue();
    v.printQueue();

    v.enqueue(2);
    v.printQueue();

    v.dequeue();
    v.printQueue();

    v.dequeue();
    v.printQueue();
    //--
    return 0;
}