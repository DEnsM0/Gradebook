#include "Student.h"

Student::Student() : UniversityMember(),
	surname {"Безіменний"},
	group{}
{}

Student::Student(string depart, string surname, uint group) :
	UniversityMember(depart),
	surname {surname},
	group{ group }
{}

string Student::getSurname() const
{
	return surname;
}

void Student::setSurname(string surname)
{
	if (surname.size() > 0)
		this->surname = surname;
}

unsigned int Student::getGroup() const noexcept
{
	return group;
}

void Student::setGroup(uint group)
{
	this->group = group;
}

string Student::toString() const
{
	stringstream ss;
	ss 
		<< "Прізвище: " << surname << endl
		<< "Група: " << group << endl << endl;
	return ss.str();
}

void Student::print() const
{
	cout
		<< "Прізвище: " << surname << endl
		<< "Група: " << group << endl;
}

void Student::fill()
{
	cout << "Введіть дані студента: " << endl;

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
			cout << exeption.what() << endl;
		}
	}

	cout << "Група: ";
	while (true) {
		cin >> group;
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(3217, '\n');
				throw exception{ runtime_error{"Помилка! Ви ввели групу неправильно. Спробуйте знову:"} };
			}
			else {
				break;
			}
		}
		catch (const exception& exeption) {
			cout << exeption.what();
		}
	}
}

ostream& operator<<(ostream& os, const Student& other)
{
	os << other.depart << endl
		<< other.surname << endl
		<< other.group << endl;
	return os;
}

istream& operator>>(istream& is, Student& other)
{
	is >> other.depart >> other.surname >> other.group;
	return is;
}
