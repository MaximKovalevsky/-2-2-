#include <iostream>
#include <string>
//конструктор ничего не возвращает
//книга дейтел "как программировать на с++"
//(*this).len = this->len
using namespace std;

class MyString
{
	private:

		char* str;
		int length;

	public:

		MyString()//базовый конструктор
		{
			str = nullptr;
			length = 0;

		}

		MyString(const char *str)//конструктор для создания строки
		{
			length = strlen(str);
			this->str = new char[length + 1];

			for (int i = 0; i < length; i++)
			{
				this->str[i] = str[i];
			}

			this->str[length] = '\0';
		}

		MyString(const MyString& other)//конструктор копирования
		{

			length = strlen(other.str);
			this->str = new char[length + 1];

			for (int i = 0; i < length; i++)
			{
				this->str[i] = other.str[i];
			}

			this->str[length] = '\0';

		}

		MyString& operator=(const MyString& other)//оператор присваивания копированием
		{
			if (this->str != nullptr)//проверка на мусор в памяти
			{
				delete[] str;
			}
			int length = strlen(other.str);
			this->str = new char[length + 1];

			for (int i = 0; i < length; i++)
			{
				this->str[i] = other.str[i];
			}

			this->str[length] = '\0';

			return *this;//возвращаем разыменованый указатель на this
		}

		MyString operator+(const MyString& other)//оператор +
		{
			MyString newStr;
			int thislength = strlen(this->str);
			int otherlength = strlen(other.str);
			newStr.length = thislength + otherlength;
			newStr.str = new char[thislength + otherlength + 1];

			int i = 0;

			for (;i < thislength; i++)
			{
				newStr.str[i] = this->str[i];
			}
			for (int j = 0; j < otherlength; j++,i++)
			{
				newStr.str[i] = other.str[j];

			}
			newStr.str[thislength + otherlength] = '\0';

			return newStr;
			

		}

		bool operator==(const MyString& other)//оператор ==
		{
			if (this->length!=other.length)
			{
				return false;
			}

			for (int i = 0; i < this->length; i++)
			{
				if (this->str[i]!=other.str[i])
				{
					return false;
				}
			}

			return true;

		}

		friend bool operator>(const MyString& other1, const MyString& other2)//оператор больше
		{
			return other1.str > other2.str;
		}

		friend bool operator<(const MyString& other1, const MyString& other2)//оператор меньше
		{
			return other1.str < other2.str;
		}

		char& operator[](int index)//метод []
		{
			return this->str[index];
		}

		friend ostream& operator<<(ostream& out, const MyString& other)//оператор вывода
		{
			return (out << other.str);
		}

		friend istream& operator>>(istream& in,MyString& other)//оператор ввода
		{
			in >> other.str;
			//in.getline(other.str, sizeof(other.str));
			return in;
		}

		int Length(const MyString& other)//метод length
		{
			length;
			for (length = 0; str[length] != '\0'; length++);
			return length;
		}

		~MyString()//деструктор
		{
			delete[] this->str;
		}
	

};

int main()
{
	setlocale(LC_ALL, "Rus");
	MyString str("Hello");
	MyString str2("Hello");


	cout << "Длина строки номер 2:  " << str2.Length(str) << '\n';//метод Length на примере

	str = str2;
	cout << "Копируем вторую строку в первую: " << str << '\n'; //конструктор копирования на примере

	MyString result;

	result = str + str2;//оператор + на примере

	cout << "Сложили первую и вторую строку: " << result << '\n';

	cout << "Выводим 2-й символ второй строки: " << str2[1] << '\n';//оператор [] на прмиере
	str2[1] = 'Q';//оператор [] на примере
	cout << "Изменяем 2-й символ второй строки на 'Q': " << str2 << '\n';
	cout << "Вводим строку: ";
	cin >> str2;//оператор ввода на примере
	cout << "Полученная строка: " << str2 << '\n';//оператор вывода на примере
  	cout << "Проверяем строки на равенство: " << (str == str2) << '\n';//оператор == на примере
	cout << "Первая строка больше второй? " << (str > str2) << '\n';//оператор больше на примере
	cout << "Первая строка меньше второй? " << (str < str2) << '\n';//оператор меньше на примере
	return 0;
}