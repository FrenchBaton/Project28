#include<iostream>
using namespace std;

template<class T>
class Array
{
    T* ptr;
    int size;
    int lastElIdx;
    int grow;
public:
    Array();
    Array(int s);
    Array(const Array<T>& arr);
    void Init();
    void Print();
    ~Array();
    void AddBack(T a);

    int GetSize();
    void SetSize(int s, int gr = 1);
    
    int GetUpperBound();

    bool IsEmpty();

    void FreeExtra();
    void RemoveAll();

    T GetAt(int idx);
    void SetAt(int idx, T obj);

    T& operator[](int idx);

    void Add(T a);
    Array<T> Append(Array<T> arr);
    void Grow();

    Array<T>& operator =(const Array<T>& arr);

    T* GetData();
    void InsertAt(int from, int at, T* arr);
    void RemoveAt(int from,int at);
};

template<class T>
Array<T>::Array()
{
    ptr = nullptr;
    size = 0;
    lastElIdx = -1;
    grow = 1;
}

template<class T>
Array<T>::Array(int s)
{
    size = s;
    ptr = new T[size];
    lastElIdx = -1;
    grow = 1;
}

template<class T>
Array<T>::Array(const Array<T>& arr)
{
    size = arr.size;
    lastElIdx = arr.lastElIdx;
    grow = arr.grow;
    ptr = new T[size];
    for (int i = 0; i <= lastElIdx; i++) {
        ptr[i] = arr.ptr[i];
    }
}

template<class T>
void Array<T>::Init()
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 100;
    }
    lastElIdx = size - 1;
}

template<class T>
void Array<T>::Print()
{
    for (int i = 0; i <= lastElIdx; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl;

}

template<class T>
Array<T>::~Array()
{
    delete[]ptr;
}

template<class T>
void Array<T>::AddBack(T a)
{
    T* temp = new T[size + 1];
    temp[0] = a;
    for (int i = 0; i < size; i++)
    {
        temp[i+1] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    size++;
    lastElIdx++;
}

template<class T>
int Array<T>::GetSize()
{
    return size;
}

template<class T>
void Array<T>::SetSize(int s, int gr)
{
    T* arr = new T[s];
    size = s;
    if (lastElIdx >= s) { lastElIdx = size - 1; }
    for (int i = 0; i <= lastElIdx; i++) {
        arr[i] = ptr[i];
    }
    delete[]ptr;
    ptr = arr;
    grow = gr;
}

template<class T>
int Array<T>::GetUpperBound()
{
    return lastElIdx;
}

template<class T>
bool Array<T>::IsEmpty()
{
    return lastElIdx<0;
}

template<class T>
void Array<T>::FreeExtra()
{
    if (IsEmpty())return;
    size = lastElIdx + 1;
    T* arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = ptr[i];
    }
    delete[]ptr;
    ptr = arr;
}

template<class T>
void Array<T>::RemoveAll()
{
    delete[] ptr;
    ptr = nullptr;
    size = 0;
    lastElIdx = -1;
    grow = 1;
}

template<class T>
T Array<T>::GetAt(int idx)
{
    return ptr[idx];
}

template<class T>
void Array<T>::SetAt(int idx, T obj)
{
    if (idx < 0 || idx > lastElIdx) return;
    ptr[idx] = obj;
}

template<class T>
T& Array<T>::operator[](int idx)
{
    return ptr[idx];
}

template<class T>
void Array<T>::Add(T a)
{
    if (ptr == nullptr) { size = 1; ptr = new T[size];  }
    if (lastElIdx == size - 1) { Grow(); }
    lastElIdx++;
    ptr[lastElIdx] = a;
}

template<class T>
Array<T> Array<T>::Append(Array<T> arr)
{
    Array<T> temp(size + arr.size + grow);
    temp.lastElIdx = lastElIdx+1 + arr.lastElIdx;

    for (int i = 0; i <= lastElIdx; i++) {
        temp[i] = ptr[i];
    }
    for (int i = 0; i <= arr.lastElIdx; i++) {
        temp[lastElIdx+1 +i] = arr[i];
    }

    return temp;
}

template<class T>
void Array<T>::Grow()
{
    size+=grow;
    T* arr = new T[size];
    for (int i = 0; i < lastElIdx+1; i++) {
        arr[i] = ptr[i];
    }
    delete[]ptr;
    ptr = arr;
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& arr)
{
    if (this == &arr) {
        return *this;
    }
    RemoveAll();
    // глубокое копирование
    lastElIdx = arr.lastElIdx;
    SetSize(arr.size, arr.grow);
    for (int i = 0; i < size; i++) {
        ptr[i] = arr.ptr[i];
    }
    return *this;
}

template<class T>
T* Array<T>::GetData()
{
    T* arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = ptr[i];
    }
    return arr;
}

template<class T>
void Array<T>::InsertAt(int from, int to, T* arr)
{
    if (IsEmpty() || arr == nullptr || from> to || to >= size) { return; }
    if (from == to) { SetAt(to, arr[0]); }
    for (int i = from, j = 0; i <= to; i++, j++) {
        ptr[i] = arr[j];
    }
}

template<class T>
void Array<T>::RemoveAt(int from, int to)
{
    if (IsEmpty()|| from > to || to >= size) { return; }
    if (from == to) { SetAt(to, ptr[lastElIdx]); lastElIdx--; }
    for (int i = from, j = 0; i <= to; i++, j++) {
        ptr[i] = ptr[lastElIdx-j];
    }
    lastElIdx -= to - from;
}


