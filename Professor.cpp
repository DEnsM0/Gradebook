#include "Professor.h"

Professor::Professor() : UniversityMember(),
	surname{ "Безіменний" },
	pos{ "--" }
{}

Professor::Professor(string depart, string surname, string pos) :
	UniversityMember(depart),
	surname{ surname },
	pos{ pos }
{}

string Professor::getSurname() const
{
	return surname;
}

void Professor::setSurname(string surname)
{
	if (surname.size() > 0)
		this->surname = surname;
}

string Professor::getPos() const
{
	return pos;
}

void Professor::setPos(string pos)
{
	if (pos.size() > 0)
		this->pos = pos;
}

string Professor::toString() const
{
	stringstream ss;
	ss  << "Прізвище: " << surname << endl
		<< "Посада: " << pos << endl << endl;
	return ss.str();
}

void Professor::print() const
{
	cout << "Прізвище: " << surname << endl
		<< "Посада: " << pos << endl;
}

void Professor::fill()
{
	cout << "Введіть дані викладача: " << endl;

	cout << "Прізвище: ";
	while (true) {
		cin >> surname;
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				throw exception{ runtime_error{"Помилка! Ви ввели прізвище неправильно. Спробуйте знову:"} };
			}
			else {
				break;
			}
		}
		catch (const exception& exeption) {
			cout << exeption.what();
		}
	}

	cout << "Посада: ";
	while (true) {
		cin >> pos;
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				throw exception{ runtime_error{"Помилка! Ви ввели посаду неправильно. Спробуйте знову:"} };
			}
			else {
				break;
			}
		}
		catch (const exception& exeption) {
			cout << exeption.what() << endl;
		}
	}
}

ostream& operator<<(ostream& os, const Professor& other)
{
	os << other.depart << endl
		<< other.surname << endl
		<< other.pos << endl;
	return os;
}

istream& operator>>(istream& is, Professor& other)
{
	is >> other.depart >> other.surname >> other.pos;
	return is;
}
