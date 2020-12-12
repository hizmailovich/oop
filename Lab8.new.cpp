#include "Lab8.h"

Stack::Stack()
{
	Size = 0;
	head = nullptr;
}

Stack::~Stack()
{
	clear();
}

void Stack::pop()
{
	try
	{
		if (Size == 0)
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
	Product* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

void Stack::clear()
{
	while (Size)
	{
		pop();
	}
}

Product& Stack::operator[](const int index)
{
	int counter = 0;
	Product* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return *current;
		}
		current = current->pNext;
		counter++;
	}
}

void Stack::push(char _category, string _name, string _workshop, int _amount)
{
	head = new Product(_category, _name, _workshop, _amount, head);
	Size++;
}

ostream& operator<<(ostream& out, const Product& pr)
{
	out << "Category: " << pr.category << endl;
	out << "Name: " << pr.name << endl;
	out << "Workshop: " << pr.workshop << endl;
	out << "Amount: " << pr.amount << endl;
	return out;
}

void InsertSort(int n, int* ms)
{
	int j;
	int m;
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
	return;
}

int File::Del(int index, int n, Stack& st)
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
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
	Product* ms;
	ms = new Product[n];
	for (int i = 0; i < n; i++)
	{
		fs.read((char*)&ms[i], sizeof(ms[i]));
	}
	fs.close();
	fstream fs1;
	fs1.open(path, fstream::binary | fstream::out | fstream::trunc);
	fs1.close();
	fstream fs2;
	fs2.open(path, fstream::binary | fstream::out);
	for (int i = 0; i < index; i++)
	{
		this->WriteBin(ms[i]);
	}
	for (int i = index + 1; i < n; i++)
	{
		this->WriteBin(ms[i]);
	}
	n = n -1;
	cout << "After deletion: " << endl;
	this->ReadBin(n);
	fs2.close();
	return n;
}

void File::ReadTextBin()
{
	char* msg;
	msg = new char[10];
	fstream fs;
	fs.open(path, fstream::in | fstream::binary);
	try
	{
		if (!fs.is_open())
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
	fs.read(msg, 10);
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (msg[i] >= 97 && msg[i] <= 122 || msg[i] >= 65 && msg[i] <= 90)
		{
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << msg[i];
	}
	cout << endl;
	fs.close();
}

void File::Sort(int n, Stack &st)
{
	if (n == 1)
	{
		this->ReadBin(n);
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
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
	int* m;
	m = new int[n];
	Product* ms;
	ms = new Product[n];
	int i = 0;
	for (int k = 0; k < n; k++)
	{
		fs.read((char*)&ms[i], sizeof(ms[i]));
		m[i] = ms[i].amount;
		i++;
	}
	InsertSort(n, m);
	fs.close();
	fstream fs1;
	fs1.open(path, fstream::binary | fstream::out | fstream::trunc);
	try
	{
		if (!fs1.is_open())
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
	fs1.close();
	fstream fs2;
	fs2.open(path, fstream::binary | fstream::out);
	try
	{
		if (!fs2.is_open())
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
	cout << "Sort by amount of products:  " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ms[j].amount == m[i])
			{
				this->WriteBin(ms[j]);
			}
		}
	}
	this->ReadBin(n);
	fs2.close();
	delete[] ms;
	delete[] m;
}

void File::Search()
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
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
	Product ms[10];
	int i = 0;
	char c;
	while (!fs.eof())
	{
		fs.read(reinterpret_cast<char*>(&ms[i]), sizeof(ms[i]));
		/*fs.read((char*)&ms[i], sizeof(ms[i]));*/
		i++;
	}
	cout << "Enter workshop (A, B, C): ";
	cin >> c;
	cout << "Searching results: " << endl;
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (ms[i].category == c)
		{
			cout << "____________________________________" << endl;
			cout << ms[i] << endl;
			count = count + ms[i].amount;
		}
	}
	cout << "Total number of products in this category: " << count << endl;
	fs.close();
}

void File::WriteBin(Product pr)
{
	fstream fs;
	fs.open(path, fstream::out | fstream::binary | fstream::app);
	try
	{
		if (!fs.is_open())
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
	fs.write((char*)&pr, sizeof(pr));
	/*fs.write(reinterpret_cast<char*>(&pr), sizeof(pr));*/
	fs.close();
}

void File::WriteText()
{
	string msg;
	fstream fs;
	fs.open(path, fstream::out | fstream::app);
	try
	{
		if (!fs.is_open())
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
	cout << "Enter message: ";
	cin >> msg;
	fs << msg << "\n";
	fs.close();
}

void File::ReadBin(int n)
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out );
	try
	{
		if (!fs.is_open())
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
	cout << "____________________________________" << endl;
	Product pr;
	while (fs.read((char*)&pr, sizeof(Product))) 
	{
		cout << pr; 
		cout << "____________________________________" << endl;
	}
	fs.close();
}

void File::ReadText()
{
	string msg;
	fstream fs;
	fs.open(path, fstream::in);
	try
	{
		if (!fs.is_open())
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
	cout << "File " << path << ":" << endl;
	while (!fs.eof())
	{
		while (getline(fs, msg))
		{
			cout << msg << endl;
		}
	}
	fs.close();
}

int main()
{
	Stack st;
	File file2("2.bin");
	char* _category;
	string* _name;
	string* _workshop;
	int* _amount;
	int n, index, choice, ch;
	cout << "Work with text or binary file? Choose 1 or 2: ";
	cin >> choice;
	if (choice == 1)
	{
		system("CLS");
		cout << "Text file mode:" << endl;
		File file1("1.txt");
		file1.WriteText();
		file1.ReadText();
		cout << "Read as a binary file: " << endl;
		file1.ReadTextBin();
	}
	if (choice == 2)
	{
		system("CLS");
		cout << "Writing the file: " << endl;
		cout << "Enter the number of products: ";
		try
		{
			cin >> n;
			if (cin.fail())
			{
				throw 0;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			return 0;
		}
		_category = new char[n];
		_name = new string[n];
		_workshop = new string[n];
		_amount = new int[n];
		for (int i = 0; i < n; i++)
		{
			cout << "Enter product [" << i << "]: " << endl;
			cout << "Category (A, B or C): ";
			try
			{
				cin >> _category[i];
				if (_category[i] < 65 || _category[i] > 67)
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
			cout << "Name: ";
			cin >> _name[i];
			cout << "Workshop: ";
			cin >> _workshop[i];
			cout << "Amount: ";
			try
			{
				cin >> _amount[i];
				if (cin.fail())
				{
					throw 0;
				}
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			Product pr(_category[i], _name[i], _workshop[i], _amount[i]);
			file2.WriteBin(pr);
		}
		cout << "\nRead the file - 1" << endl;
		cout << "Search - 2" << endl;
		cout << "Sort - 3" << endl;
		cout << "Deletion - 4" << endl;
		cin >> ch;
		if (ch == 1)
		{
			cout << "File: " << endl;
			file2.ReadBin(n);
		}
		if (ch == 2)
		{
			file2.Search();
		}
		if (ch == 3)
		{
			file2.Sort(n, st);
		}
		if (ch == 4)
		{
			cout << "Enter index of element for deletion: ";
			try
			{
				cin >> index;
				if (cin.fail())
				{
					throw 0;
				}
			}
			catch (int i)
			{
				Exception ex(i);
				ex.Print();
				return 0;
			}
			int k;
			k = file2.Del(index, n, st);
			n = k;
		}
		delete[] _category;
		delete[] _name;
		delete[] _workshop;
		delete[] _amount;
	}
	return 0;
}