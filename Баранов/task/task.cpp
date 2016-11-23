#include "task.h"
#include <iostream>  
using namespace std;

int main()
{
    //debug zone
    Task t(5);
    cout << "have: " << t.show_have() << endl;
    cout << "need: " << t.show_need() << endl << endl;

    t.plus();//1
    cout << "have: " << t.show_have() << endl;
    cout << "need: " << t.show_need() << endl << endl;

    t.plus();//2
    cout << "have: " << t.show_have() << endl;
    cout << "need: " << t.show_need() << endl << endl;

    t.plus();//3
    cout << "have: " << t.show_have() << endl;
    cout << "need: " << t.show_need() << endl << endl;

    t.plus();//4
    cout << "have: " << t.show_have() << endl;
    cout << "need: " << t.show_need() << endl << endl;

    t.plus();//5
    cout << "have: " << t.show_have() << endl;
    cout << "need: " << t.show_need() << endl << endl;
    //--
    return 0;
}