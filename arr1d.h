#ifndef ARR1D_H_INCLUDED
#define ARR1D_H_INCLUDED

template <class T>
class arr1d
{
    T *element;
    int maxsize;
public:
    arr1d();
    arr1d(int);                         ///Constructor
    arr1d(arr1d<T>& v);                 ///Copy Constructor
    ~arr1d();                           ///Destructor
    arr1d<T>& operator+(arr1d<T>&);     ///OP Overload +
    arr1d<T>& operator=(arr1d<T>&);     ///OP Overload =
    arr1d<T>& operator+=(T);            ///OP Overload +=
    T operator[](int);                  ///OP Overload [] : indexing op
    void resizee(arr1d<T>&);
    void resizee(int);
    void getdata();
    void disp();

};



#endif // ARR1D_H_INCLUDED
