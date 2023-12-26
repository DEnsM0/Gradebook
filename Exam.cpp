#include "Exam.h"
#include "MarkExc.h"
#include "DateExc.h"
#include "HoursExc.h"

Exam::Exam() :
	Professor(),
	Student(),
	UniversityMember()
{
	subject= "���������" ;
	hours= 1 ;
	mark={};
	date = {};
	time_t now = time(0);;
	gmtime_s(&date, &now);;
}

Exam::Exam(string depart, string professorSurname, string pos, string studentSurname, uint group, string subject, uint hours, tm date, uint mark) :
	Professor(depart, professorSurname, pos),
	Student(depart, studentSurname, group),
	UniversityMember(depart),
	subject{ subject },
	hours{ hours },
	date{ date },
	mark{ mark }
{
}

string Exam::getSubject() const
{
	return subject;
}

void Exam::setSubject(string subject)
{
	if (subject.size() > 0)
		this->subject = subject;
	else
		throw exception{ runtime_error{ "����� �������!"} };
}

unsigned int Exam::getHours() const noexcept
{
	return hours;
}

void Exam::setHours(uint hours)
{
	if (hours > 0u)
		this->hours = hours;
	else
		throw exception{ runtime_error{ "�� ����� ������ 0 �����!"} };
}

tm Exam::getDate() const noexcept
{
	return date;
}

void Exam::setDate(tm date)
{
	this->date = date;
}

unsigned int Exam::getMark() const noexcept
{
	return mark;
}

void Exam::setMark(uint mark)
{
	this->mark = mark;
}

string Exam::toString() const
{
	stringstream ss;
	ss	<< "����� �������: " << depart << endl
		<< "������� ���������: " << Professor::surname << endl
		<< "������: " << pos << endl
		<< "������� ��������: " << Student::surname << endl
		<< "�����: " << Student::group << endl
		<< "�������: " << subject << endl
		<< "ʳ������ �����: " << hours << endl
		<< "����: " << date.tm_hour << ':' << date.tm_min << ' ' << date.tm_mday << '.' << date.tm_mon + 1 << '.' << 1900 + date.tm_year << endl
		<< "������: " << mark << endl << endl;
	return ss.str();
}

void Exam::print() const
{

	cout.setf(ios::fixed);
	cout << setw(8) << left << depart << "|"
		<< setw(10) << left << Professor::surname << "|"
		<< setw(18) << left << pos << "|"
		<< setw(9) << left << Student::surname << "|"
		<< setw(15) << left << group << "|"
		<< setw(9) << left << subject << "|"
		<< setw(16) << left << hours << "|"
		<< setw(2) << date.tm_hour << ':' << date.tm_min << ' ';
		if (date.tm_mday < 10) cout << "0";
		cout << date.tm_mday << '.';
		if ((date.tm_mon + 1)< 10) cout << "0";
		cout << date.tm_mon + 1 << '.' << 1900 + date.tm_year << "|"
		<< setw(10) << left << mark;
}

void Exam::fill()
{
	cout << "���� �����, ������ ��� ������:" << endl << endl;

	cout << "����� �������: ";
	string buff;
	while (true) {
		cin>> depart;
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				throw exception{ runtime_error{"�������! �� ����� ����� ������� �����������. ��������� �����:"} };
			}
			else {
				break;
			}
		}
		catch (const exception& exeption) {
			cout << exeption.what() << endl;
		}
	}

	Professor::fill();
	cout << endl;

	Student::fill();
	cout << endl;

	cout << "��� ��������:" << endl;
	cout << "����� ��������: ";
	while (true) {
		cin>>subject;
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				throw exception{ runtime_error{"�������! �� ����� ����� �������� �����������. ��������� �����:"} };
			}
			else {
				break;
			}
		}
		catch (const exception& ex) {
			cout << ex.what() << endl;
		}
	}

	cout << "ʳ������ �����: ";
	while (true) {
		cin >> hours;
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				throw exception{ runtime_error{"�������! �� ����� ������� ����� �����������. ��������� �����:"} };
			}
			else if (hours > 244 || hours <= 0) throw new HoursExc(hours);
			else {
				break;
			}
		}
		catch (const exception& ex) {
			cout << ex.what();
		}
		catch (Exception* ex) {
			ex->print();
		}
	}

	cout << endl << "�����: " << endl;
	cout << "���� (������ ����: ��:��-��.��.����): ";
	string str;
	struct tm datecv;
	string dateTimeFormat = "%H:%M-%d.%m.%y";
	cin.ignore(32767, '\n');
	while (true) {
		cin >> str;
		stringstream ss1(str),ss2(str);
		ss1 >> get_time(&datecv, dateTimeFormat.c_str());
		ss2 >> get_time(&date, dateTimeFormat.c_str());
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				throw exception{ runtime_error{"�������! �� ����� ���� �����������. ��������� �����:"} };
			}
			else if (mktime(&datecv)==-1) throw new DateExc(date);
			else {
				break;
			}
		}
		catch (const exception& ex) {
			cout << ex.what();
		}
		catch (Exception* ex) {
			ex->print();
		}
	}

	cout << "������: ";
	while (true) {
		cin >> mark;
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				throw exception{ runtime_error{"�������! �� ����� ������ �����������. ��������� �����:"} };
			}
			else if (mark > 100 || mark <= 0) 	throw new MarkExc(mark);
			else {
				break;
			}
		}
		catch (const exception& ex) {
			cout << ex.what();
		}
		catch (Exception* ex) {
			ex->print();
		}
	}
}

ostream& operator<<(ostream& os, const Exam& other)
{
	os << other.depart << endl
		<< other.Professor::surname << endl
		<< other.Professor::pos << endl
		<< other.Student::surname << endl
		<< other.Student::group << endl
		<< other.subject << endl
		<< other.hours << endl
		<< other.date.tm_hour << endl
		<< other.date.tm_min << endl
		<< other.date.tm_mday << endl
		<< other.date.tm_mon << endl
		<< other.date.tm_year << endl
		<< other.mark << endl << endl;
	return os;
}

istream& operator>>(istream& is, Exam& other)
{
	is >> other.UniversityMember::depart 
		>> other.Professor::surname
		>> other.Professor::pos
		>> other.Student::surname
		>> other.Student::group
		>> other.subject
		>> other.hours
		>> other.date.tm_hour
		>> other.date.tm_min
		>> other.date.tm_mday
		>> other.date.tm_mon
		>> other.date.tm_year
		>> other.mark;
	return is;
}
