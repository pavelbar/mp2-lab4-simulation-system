#include "task.h"
#include <iostream>  
using namespace std;

int main()
{
    //debug zone
    Task t(5);
    cout << "have: " << t.get_need() << endl;
    cout << "need: " << t.get_need() << endl << endl;
    //--
    return 0;
}