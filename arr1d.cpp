#include "arr1d.h"
#include "except.h"
#include<iostream>
using namespace std;

/*
template <class T>
arr1d<T>   ::  arr1d (int n)
{
    maxsize=n;
    element= new T[maxsize];
}
*/
template <class T>
arr1d<T>::arr1d()
{
    maxsize=1;
    element = new T[maxsize];
}



template <class T>
arr1d<T>::arr1d(int n)
{
    maxsize=n;
    element = new T[maxsize];
}


template <class T>
arr1d<T>::arr1d(arr1d<T>& v)          ///Copy Constructor
{
    maxsize=v.maxsize;
    element= new T[maxsize];
    for (int i=0; i<maxsize; i++)
        element[i]=v.element[i];
}


template <class T>
arr1d<T>::~arr1d()
{
    delete []element;
}


template <class T>                                  ///v 1.0
arr1d<T>& arr1d<T>:: operator+(arr1d<T>& v)
{
    if(maxsize!=v.maxsize)  throw OOB();
    static arr1d<T> sum(maxsize);
///    cout<<"P1"<<endl;
    for( int i=0; i<maxsize; i++)
        sum.element[i]=element[i] + v.element[i];
///    cout<<"P2"<<endl;
    return sum;
}

/*
template <class T>                                  ///v 2.0
arr1d<T>& arr1d<T>:: operator+(arr1d<T>& v)
{
    if(maxsize!=v.maxsize)                          ///throw OOB();
    {
        if(maxsize>v.maxsize){resizee(v);}
    }
    static arr1d<T> sum(maxsize);
///    cout<<"P1"<<endl;
    for( int i=0; i<maxsize; i++)
        sum.element[i]=element[i] + v.element[i];
///    cout<<"P2"<<endl;
    return sum;
}
*/


template <class T>
arr1d<T>& arr1d<T>:: operator=(arr1d<T>& v)
{
    if(maxsize!=v.maxsize) throw OOB();
///    cout<<"e1"<<endl;

    for( int i=0; i<maxsize; i++)
        element[i] = v.element[i];
///    cout<<"e2"<<endl;
    return *this;
}

template <class T>
arr1d<T>& arr1d<T>:: operator+=(T x)
{
    for( int i=0; i<maxsize; i++)
        element[i] += x;
    return *this;
}

template <class T>
T arr1d<T>::operator[](int i)
{
    if(i<1 || i>maxsize) throw OOB();
    return element[i-1];
}


template <class T>
void arr1d<T>::resizee(arr1d<T>& v)
{
    maxsize=v.maxsize;
    delete []element;
    element = new T[maxsize];
}

template <class T>
void arr1d<T>::resizee(int x)
{
    maxsize=x;
    delete []element;
    element = new T[maxsize];
}

template <class T>
void arr1d<T>::getdata()
{
    for (int i=0; i<maxsize; i++)
        cin>>element[i];

}


template <class T>
void arr1d<T>::disp()
{
    for (int i=0; i<maxsize; i++)
        cout<<element[i]<<" ";
    cout<<endl;

}
