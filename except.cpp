#include "except.h"
#include<iostream>
#include<cstdlib>
using namespace std;

int OOB()
{
    cout<<"Out Of Bounds"<<endl;
    exit (EXIT_FAILURE);
}

int nomem()
{
    cout<<"No memory"<<endl;
    exit (EXIT_FAILURE);
}

int badinit()
{
    cout<<"Bad initialization"<<endl;
    exit (EXIT_FAILURE);
}
