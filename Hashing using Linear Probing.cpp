#include<iostream>
using namespace std;
int Max = 20;
class Hash {

public:
	int* Arr;
	int HashFuntion(int);
	Hash();
	void Display();
	void Insert(int);
	bool Search(int);
	void Delete(int);


};
Hash::Hash()
{
	Arr = new int[Max];
	for (int i = 0; i < Max; i++)
	{
		Arr[i] = INT_MIN;
	}
}
int Hash::HashFuntion(int key)
{

	return (key % Max);
}
void Hash::Delete(int value)
{
	int index;
	int count = 1;
	if (this->Search(value))
	{
		index = HashFuntion(value);
		Arr[index] = INT_MIN;
		while (true)
		{
			index = HashFuntion(value + count);
			count++;
			if (Arr[index] == INT_MIN)
			{
				break;
			}
			else
			{
				int val = Arr[index];
				Arr[index] = INT_MIN;
				Insert(val);


			}
		}
	}
	else
	{
		cout << "Value is not present" << endl;
	}
}
void Hash::Display()
{
	cout << "Index" << "	" << "Value" << endl;
	for (int i = 0; i < Max; i++)
	{
		if (Arr[i] != INT_MIN)
		{
			cout << i << "	" << Arr[i] << endl;;
		}
	}
	cout << endl;
}
void Hash::Insert(int value)
{
	int i = HashFuntion(value);
	int count = 0;
	if (Arr[i] == INT_MIN)
	{
		Arr[i] = value;
	}
	else
	{
		do
		{
			i = HashFuntion(value + count );//Hashing using linear Probing
			count++;


		} while (Arr[i] != INT_MIN);


		Arr[i] = value;

	}
}
bool Hash::Search(int value)
{
	int i = HashFuntion(value);
	if (Arr[i] == value)
	{
		return true;
	}
	else
	{
		int c = 0;
		do
		{
			i = HashFuntion(value + c);
			c++;
			if (i >= Max)
			{
				return false;
			}
			if (this->Arr[i] == value)
			{
				return true;
			}
		} while (Arr[i] != INT_MIN);
		if (Arr[i] == INT_MIN)
		{
			return false;
		}
	}
}

int main(void)
{
	Hash obj;
	int opt;
	int value = 0;
	do
	{
		cout << "Press 1 --> Insert()" << endl
			<< "Press 2 --> Search()" << endl
			<< "Press 3 --> Delete()" << endl
			<< "Press 4 --> Display()" << endl;
		cout << endl;
		cin >> opt;
		cout << endl;
		switch (opt)
		{
		case 1:
		{


			while (value != -111)
			{
				cout << "Enter the value or press -111 to exit: ";
				cin >> value;
				if (value != -111)
				{
					obj.Insert(value);
				}


			}
			cout << endl;
			break;

		}

		case 2:
		{
			int n;
			cout << "Enter the Value to found : ";
			cin >> n;
			if (obj.Search(n))
			{
				cout << n << " Value Found!!!" << endl;
			}
			else
			{
				cout << n << " Value does not Found!!!" << endl;
			}
			break;
		}

		case 3:
		{
			int n;
			cout << "Enter the Value: ";
			cin >> n;
			obj.Delete(n);
			break;

		}

		case 4:
		{
			obj.Display();
			break;
		}
		default:
			cout << "Select the Correct Option" << endl;
			break;
		}
	} while (opt);

	system("pause");
	return 0;
}