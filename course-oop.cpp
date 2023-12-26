#include "Exam.h"
#include "Gradebook.h"
#include "Menu.h"

 const string file = "data.txt";

int main() {
	using namespace menu;


	setlocale(LC_ALL, "Ukrainian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Gradebook<Exam> gbook;
	unique_ptr<UniversityMember> prof(new Professor);
	unique_ptr<UniversityMember> student(new Student);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Menu menu(hConsole);

	menu.CreateNewItem("������ ������� �� ������� �����", [&gbook] {
		try {
			Exam exam;
			exam.fill();
			gbook.push_back(move(exam));
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		}, []() {return true;});
	menu.CreateNewItem("�������� ������� � ������� �����", [&gbook] {
		try {
			gbook.pop_back();
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		}, [] {return true; });

	menu.CreateNewItem("������� ������� �����", [&gbook] { 
		gbook.print();
		}, []() {return true; });
	menu.CreateNewItem("������� ����������� ������� �����", [&gbook] {
		gbook.printSort();
		}, []() {return true; });
	menu.CreateNewItem("�������� ������� �����", [&gbook] {
		try {
			if (gbook.empty())
				throw exception{ runtime_error{ "������a ����a ��� �������!" } };
			gbook.clean();
			cout << "������� ����� ��������." << endl;
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		}, [] {return true; });

	menu.CreateNewItem("������ ���������", [&prof] {
		try {
			prof->fill();
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		}, [] {return true; });
	menu.CreateNewItem("������ ��������", [&student] {
		try {
			student->fill();
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}}, [] {return true; });

	menu.CreateNewItem("������� ���������", [&prof] { prof->print(); }, [] {return true; });
	menu.CreateNewItem("������� ��������", [&student] { student->print(); }, [] {return true; });

	menu.CreateNewItem("�������� ������� ����� � ����", [&gbook] {
		try {
			gbook.save(file);
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}}, [] {return true; });
	menu.CreateNewItem("������� ������� ����� � �����", [&gbook] {
		try
		{
			gbook.clean();
			gbook.load(file);
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}}, [&gbook]() {
			if (gbook.isopen(file)) return true;
			else return false;
		});

	menu.Start();

	return 0;
}