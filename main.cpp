#include <iostream>
#include "arr1d.h"
#include "except.h"

#include "arr1d.cpp"        ///Linker not finding definition of arr1d

using namespace std;

template<class T>
class arr1d;

template <class T>
class arr2d
{
    arr1d<T> *row;
    int r,c;
public:
    arr2d(int n1=1,int n2=1)
    {
        if(n1<1 || n2<1) throw badinit();
        r=n1;
        c=n2;
        row= new arr1d<T> [r];
        for(int i=0; i<r; i++)
            row[i].resizee(c);
    }

    arr2d<T>& operator+(arr2d<T> v)
    {
        if(r!=v.r || c!=v.c) throw OOB(); ///{cout<<"Mismatched dimensions";}
        static arr2d<T> sum(r,c);
        for(int i=0; i<r; i++)
            sum.row[i]=row[i]+v.row[i];
        return sum;
    }
    arr1d<T> operator[](int i)
    {
        return row[i-1];
    }
    void get();
    void disp2();

};

template <class T>
void arr2d<T>::get()
{
    cout<<"Enter data: ";
    for (int i=0; i<r; i++)
        row[i].getdata();
}

template <class T>
void arr2d<T>::disp2()
{
    cout<<"Stored data: "<<endl;
    for (int i=0; i<r; i++)
        row[i].disp();

}

int main()
{
    int rr,cc;
    cout<<"Enter rows and cols: ";
    cin>>rr>>cc;

    arr2d<int> a(rr,cc),b(rr,cc),c(rr,cc);
    a.get();
    b.get();

    c=a+b;

    cout<<endl<<"in A"<<endl;
    a.disp2();
    cout<<endl<<"in B"<<endl;
    b.disp2();
    cout<<endl<<"C = A + B"<<endl;
    cout<<"in C"<<endl;
    c.disp2();

    return 0;
}
