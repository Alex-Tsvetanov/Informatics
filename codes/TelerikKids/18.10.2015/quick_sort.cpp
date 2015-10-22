#include <iostream>
#include <random>

using namespace std;

template <typename T>
T* get_pivot (T* a, T* b)
{
	T* masterPivot = a;
	T averrage = 0;
	for (T* it = a ; it != b ; it ++)
		averrage += (*it);
	averrage /= (b - a);
	for (T* it = a ; it != b ; it ++)
		if (abs ((*masterPivot) - averrage) > abs ((*it) - averrage))
			masterPivot = it;

	return masterPivot;
}

template <typename T>
T* fillArr (T* newArr, T* pivot, T* s, T* e)
{
	T* indOfPivot;
	size_t ind = 0;
	for (T* it = s ; it != e ; it ++)
		if ((*it) < (*pivot))
		{
			newArr [ind] = *it;
			ind ++;
		}
	indOfPivot = newArr + ind;
	for (T* it = s ; it != e ; it ++)
		if ((*it) >= (*pivot))
		{
			newArr [ind] = *it;
			ind ++;
		}
	return indOfPivot;
}

template <typename T>
void copyArr (T* newArr, T* s, T* e)
{
	T* newArrIt = newArr;
	for (T* it = s ; it != e ; it ++, newArrIt ++)
		*it = *newArrIt;
}

template <typename T>
void quick_sort (T* s, T* e)
{
	if (s + 1 == e)
		return ;
	if (s == e)
		return ;
	T* newArr = new T [e - s];
	T* pivot = fillArr (newArr, get_pivot (s, e), s, e);
	//for (T* it = s ; it != e ; it ++)
	//	cout << *it << " ";
	//cout << "\n" << *pivot << "\n----------------------------" << endl;
	quick_sort (newArr, pivot + 1);
	quick_sort (pivot + 1, newArr + (e - s));
	copyArr (newArr, s, e);
	delete[] newArr;
}

int main ()
{
	size_t SIZE;
	cin >> SIZE;
	int* arr = new int [SIZE];
	for (size_t i = 0 ; i < SIZE ; i ++)
		cin >> arr [i];
	quick_sort (arr + 0, arr + SIZE);
	for (size_t i = 0 ; i < SIZE ; i ++)
		cout << arr [i] << " ";
	cout << "\n";
}
