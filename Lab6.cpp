#include "Lab6.h"

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)
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
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

int main()
{
	List<char> lst;
	int size, index;
	char t;
	cout << "Enter size: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter element [" << i << "]: ";
		cin >> t;
		lst.push_back(t);
	}
	cout << "List: " << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "[" << i << "] " << lst[i] << endl;
	}
	cout << "Let's add one more element: ";
	cin >> t;
	lst.push_back(t);
	cout << "Updated list: " << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "[" << i << "] " << lst[i] << endl;
	}
	cout << "Let's delete 2 last elements" << endl;
	lst.pop_back();
	lst.pop_back();
	cout << "Updated list: " << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "[" << i << "] " << lst[i] << endl;
	}
	cout << "What element do you want to delete? ";
	cin >> index;
	lst.removeAt(index);
	cout << "Updated list: " << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "[" << i << "] " << lst[i] << endl;
	}
	lst.clear();
	return 0;
}
