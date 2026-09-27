#include<iostream>;
#include"Array.h";
using namespace std;



int main() {
	Array<int> v(4);
	v.Init();
	v.Print();

	v.AddBack(8);
	v.Add(10);
	v.Print();

	v.SetAt(0, 5);
	v.Print();

	Array<int> v2 = v;
	v2.Print();
	v.Print();

	v2.RemoveAll();
	v2.SetSize(2, 1);
	v2.Init();
	v2.Print();

	Array<int> v3 = v2.Append(v);
	v3.Print();

	v.Print();
	v.SetSize(2, 2);
	v.Grow();
	v.Print();

	cout << v.GetUpperBound() << "\t" << v.IsEmpty() << "\t" << v.GetAt(0) << "\t" << v[0] << endl;

	v.FreeExtra();
	v.Add(10);
	v.Print();

	int temp[] = { 101, 102 };
	v.InsertAt(0, 1, temp);
	v.Print();
	v.RemoveAt(0, 0);
	v.Print();
	return 0;
}