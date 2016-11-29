#include "queue.h"
#include "task.h"
#include <conio.h>
#include <iostream>  
using namespace std;

int main()
{
    const double A = 0.7;//вероятность создание задачи
    //pause
	int VAL;
	int key = 10;
    int key_on = 0;
    //report
    double r_done_task = 0;       //+количество выполненных задач
    double r_task_in_queue = 0;   //+количество задач в очереди
    double r_time = 0;            //+среднее время выполнения задачи
    double r_stop_tact = 0;       //+количество тактов простоя
    double r_all_tact = 0;        //+общее количество тактов
    double r_no_task = 0;         //+количество задач, получивших отказ
    //задача
    Queue queue_tact_need(MaxSize);
    int tact_have = 0;
    //--
    setlocale(LC_ALL, "Russian");
	cout << endl << "Максимальное количество тактов: ";
	cin >> VAL;
	cout << endl << "Нажмите ЛЮБУЮ клавишу, чтобы остановить выполнение и увидеть отчет" << endl;
    while (!_kbhit())
    {
        if (!key) key_on = 1;
        r_all_tact++;//такт
        Task task(rand() % VAL + 1);//создание задачи для выполнение которой необходимо 0 - MaxSize тактов 
        double AT = (double)(rand()) / RAND_MAX * 1; // случайное действительное число от 0 до 1

        //создание новой задачи
        if (AT > A)
        {
            if ((queue_tact_need.IsFull()))
                r_no_task++;//задача получила отказ
            else
            {
                queue_tact_need.enqueue(task.get_need());
            }
        }

        //вычисление
        if (queue_tact_need.IsEmpty())
            r_stop_tact++;//такт простоя
        else if (queue_tact_need.top() == tact_have)
        {
            r_done_task++;//задач выполнено
            //удаляем задачу
            queue_tact_need.dequeue();
            tact_have = 0;
            //--
            r_stop_tact++;//такт простоя
            if (key_on == 1) break;//если была дана команда на остановку, то стоп только после выполнения текущей задачи
        }
        else
        {
            tact_have++;
        }
        r_task_in_queue = queue_tact_need.get_size();
        r_time = r_all_tact / r_done_task;
    }

    //report
    cout << endl << "Отчет: " << endl;
    cout << "количество выполненных задач: " << r_done_task << endl;
    cout << "количество задач в очереди: " << r_task_in_queue << endl;
    cout << "среднее время выполнения задачи: " << r_all_tact/r_done_task << " квантов времени" << endl;
    cout << "количество тактов простоя: " << r_stop_tact << endl;
    cout << "общее количество тактов: " << r_all_tact << endl;
    cout << "количество задач, получивших отказ: " << r_no_task << endl;
    //--
    return 0;
}
