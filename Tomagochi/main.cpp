#include <iostream>
#include <string>

using namespace std;

class Tamogochi
{
public:
	Tamogochi(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
	void GetPrint();
private:
	int m_Hunger;
	int m_Boredom;

	int GetMood() const;
	void PassTime(int time=1);
};

int main()
{
	setlocale(LC_ALL, "Rus");
	Tamogochi Tom;
	Tom.Talk();
	int choise;
	do
	{
		cout << "Доступные действия:" << endl
			<< "0 - Выйти" << endl
			<< "1 - Выслушать Томагочи" << endl
			<< "2 - Покормить Томагочи" << endl
			<< "3 - Поиграть с Томагочи" << endl
		    << "4 - Изучить состояние Томагочи" << endl;
		cin >> choise;
		switch (choise)
		{
		case 0:
			cout << "Всего доброго Вам!!!" << endl;
			break;
		case 1:
			Tom.Talk();
			system("pause");
			system("cls");
			break;
		case 2:
			Tom.Eat();
			system("pause");
			system("cls");
			break;
		case 3:
			Tom.Play();
			system("pause");
			system("cls");
			break;
		case 4:
			Tom.GetPrint();
			system("pause");
			system("cls");
			break;
		default:
			cout << "Извините, такой выбор невозможен, попробуйте снова "<< endl;
			system("pause");
			system("cls");
		}
	} while (choise!=0);
}

Tamogochi::Tamogochi(int hunger, int boredom)
{
	m_Hunger = hunger;
	m_Boredom = boredom;
}

int Tamogochi::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Tamogochi::PassTime(int time)
{
	m_Hunger +=time;
	m_Boredom += time;
}

void Tamogochi::Talk()
{
	cout << "Я Томагочи, я себя чувствую: ";
	int mood = GetMood();
	if (mood > 20) cout << " возмущенно" << endl ;
	else if (mood > 10) cout << " не уютно" << endl ;
	else if (mood > 5) cout << " хорошо "<< endl;
	else cout << " отлично " << endl;

	PassTime();
}

void Tamogochi::Eat(int food)
{
	cout << "Ням , Ням вкусно" << endl;
	m_Hunger -= food;
	if (m_Hunger < 0) m_Hunger = 0;
	
	PassTime();
}

void Tamogochi::Play(int fun)
{
	cout << "Увиииииии" << endl;
	m_Boredom -= fun;
	if (m_Boredom < 0) m_Boredom = 0;

	PassTime();
}

void Tamogochi::GetPrint()
{
	cout << "Уровень голода: " << m_Hunger << endl;
	cout << "Уровень скуки: " << m_Boredom << endl;
}




