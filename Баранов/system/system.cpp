#include "queue.h"
#include "task.h"
#include <iostream>//rand()

int main()

{
    const double A = 0.7;//создание задачи
    //report
    double r_done_task = 0;       //количество выполненных задач
    double r_task_in_queue = 0;   //количество задач в очереди
    double r_time = 0;            //среднее время выполнения задачи
    double r_stop_tact = 0;       //количество тактов простоя
    double r_all_tact = 0;        //общее количество тактов
    double r_no_task = 0;         //количество задач, получивших отказ
    //--
    Queue<Task> q(MaxSize);//очередь задач максимального размера

    for (;;) {
        r_all_tact++;
        double AT = (double)(rand()) / RAND_MAX * 1; // случайное действительное число от 0 до 1
        if (AT > A) {
            Task t( rand() % TMaxSize + 1 );//создание новой задачи, для выполнение которой необходимо 0 - TMaxSize тактов
            q.enqueue(t);// добавление в очередь новой задачи
        }
    }
    return 0;
}