#include"Lab7.h"

template<typename T>
Stack<T>::Stack()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
void Stack<T>::pop()
{
	try
	{
		if (Size==0)
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void Stack<T>::clear() 
{
	while (Size)
	{
		pop();
	}
}

template<typename T>
T& Stack<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void Stack<T>::push(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void Sort(int n, T* ms) 
{
	int j;
	T m;
	for (int i = 1; i < n; ++i)         
	{
		j = i - 1;                
		m = ms[i];                
		while (j >= 0 && m < ms[j])
		{
			ms[j-- + 1] = ms[j];  
		}
		ms[j + 1] = m;            
	}
}

template<typename T>
ostream& operator<<(ostream& out, const Node<T>& node)
{
	out << node.data;
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const Iterator<T>& it)
{
	out << *it;
	return out;
}

int main()
{
	Stack<int> st1;
	Stack<double> st2;
	Stack<char> st3;
	int n;
	int* value1;
	double* value2;
	char* value3;
	cout << "Enter the number of elements: " << endl;
	try
	{
		cin >> n;
		if (cin.fail())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return 0;
	}
	value1 = new int[n];
	value2 = new double[n];
	value3 = new char[n];
	cout << "Enter stack 1 (int): " << endl;
	for (int i = 0; i < n; i++)
	{
		try
		{
			cin >> value1[i];
			if (cin.fail())
			{
				throw 1;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			return 0;
		}
		st1.push(value1[i]);
	}
	cout << "Enter stack 2 (double): " << endl;
	for (int i = 0; i < n; i++)
	{
		try
		{
			cin >> value2[i];
			if (cin.fail())
			{
				throw 2;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			return 0;
		}
		st2.push(value2[i]);
	}
	cout << "Enter stack 3 (char): " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> value3[i];
		st3.push(value3[i]);
	}
	Iterator<int> it1(st1.begin());
	Iterator<double> it2(st2.begin());
	Iterator<char> it3(st3.begin());
	cout << "__________________________________________" << endl;
	cout << "Stack 1: " << endl;
	for (int i = 0; i < st1.GetSize(); i++)
	{
		cout << st1[i] <<endl;
	}
	cout << "\nStack 2: " << endl;
	while (it2!=st2.end())
	{
		cout << *it2 <<endl;
		it2++;
	}
	cout << "\nStack 3: " << endl;
	while (it3 != st3.end())
	{
		cout << *it3 << endl;
		it3++;
	}
	cout << "__________________________________________" << endl;
	cout << "Deletion of 2 elements from stack 3:" << endl;
	st3.pop();
	st3.pop();
	while (it3 != st3.end())
	{
		cout << *it3 << endl;
		it3++;
	}
	cout << "__________________________________________" << endl;
	cout << "Sorting values from stack 1:" << endl;
	Sort(n, value1);
	for (int i = 0; i < n; i++)
	{
		cout << value1[i] << "  ";
	}
	cout << " " << endl;
	cout << "Sorting values from stack 2:" << endl;
	Sort(n, value2);
	for (int i = 0; i < n; i++)
	{
		cout << value2[i] << "  ";
	}
	cout << " " << endl;
	delete[] value1;
	delete[] value2;
	delete[] value3;
	return 0;
}