#include "Lab9.h"


	ostream& operator<<(ostream& out, const DeathStranding& d)
	{
		out << "ID: " << d.id << endl;
		out << "Level: " << d.level << endl;
		out << "Time: " << d.time << endl;
		return out;
	}

	void Algorithm1()
	{
		cout << "_______________________________________" << endl;
		cout << "Algorithm 1" << endl;
		fstream fs1;
		char ch;
		int count = 1;
		fs1.open("first.txt");
		try
		{
			if (!fs1.is_open())
			{
				throw 1;
			}
			cout << "File 1 is opened! " << endl;
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			return;
		}
		cout << "File 1: " << endl;
		while (fs1.get(ch))
		{
			cout << ch;
			if (ch == ' ' || ch == '\n')
			{
				count++;
			}

		}
		cout << endl;
		vector<int> v;
		v.push_back(count);
		cout << "Word count: " << v[0] << endl;
		fs1.close();
		fstream fs2;
		fs2.open("second.txt");
		try
		{
			if (!fs2.is_open())
			{
				throw 1;
			}
			cout << "File 2 is opened! " << endl;
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			return;
		}
		fs2 << v[0];
		cout << "Writing to file was successful!" << endl;
		fs2.close();
	}

	vector<DeathStranding>::iterator Algorithm2(vector<DeathStranding> v1)
	{
		cout << "_______________________________________" << endl;
		cout << "Algorithm 2" << endl;
		vector<DeathStranding> v2;
		int n = v1.size();
		int _id, _level, _time;
		cout << "Enter second vector: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Enter ID: ";
			cin >> _id;
			cout << "Enter level: ";
			cin >> _level;
			cout << "Enter time: ";
			cin >> _time;
			DeathStranding d(_id, _level, _time);
			v2.push_back(d);
		}
		cout << "Vector 2: " << endl;
		auto it2 = v2.begin();
		while (it2 != v2.end())
		{
			cout << *it2 << endl;
			it2++;
		}
		it2 = v2.begin();
		auto it1 = v1.begin();
		while (it1 != v1.end() && it2 != v2.end())
		{
			if ((*it1).id == (*it2).id)
			{
				it1++;
				it2++;
			}
			if ((*it1).id != (*it2).id)
			{
				cout << "The first differing element from vector 2: " << endl;
				cout << *it2;
				return it2;
			}
		}
	}

	void Algorithm3(vector<DeathStranding> v)
	{
		cout << "_______________________________________" << endl;
		cout << "Algorithm 3" << endl;
		auto it = v.begin();
		while (it != v.end())
		{
			if ((*it).level > 50)
			{
				(*it).level = 0;
			}
			it++;
		}
		cout << "Vector after changes: " << endl;
		it = v.begin();
		while (it != v.end())
		{
			cout << *it << endl;
			it++;
		}
	}

	int main()
	{
		vector<DeathStranding> v;
		stack<DeathStranding> st;
		int n, index, _id, _level, _time;
		cout << "Enter amount of elements: ";
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
		for (int i = 0; i < n; i++)
		{
			cout << "Enter ID: ";
			try
			{
				cin >> _id;
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
			cout << "Enter level: ";
			try
			{
				cin >> _level;
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
			cout << "Enter time: ";
			try
			{
				cin >> _time;
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
			DeathStranding d(_id, _level, _time);
			v.push_back(d);
			st.push(d);
		}
		try
		{
			if (st.empty())
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
		cout << "Stack: " << endl;
		while (!st.empty())
		{
			cout << st.top() << endl;
			st.pop();
		}
		vector<DeathStranding>::iterator it;
		vector<DeathStranding>::iterator it1;
		cout << "Vector: " << endl;
		it = v.begin();
		while (it != v.end())
		{
			cout << *it << endl;
			it++;
		}
		cout << "Enter the index of element for searching and deletion: ";
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
		it = v.begin();
		cout << "Searching: " << endl << *(it + index) << endl;
		it = v.begin();
		v.erase(it + index);
		cout << "Vector after deletion: " << endl;
		it = v.begin();
		while (it != v.end())
		{
			cout << *it << endl;
			it++;
		}
		Algorithm1();
		Algorithm2(v);
		Algorithm3(v);
		return 0;
	}
