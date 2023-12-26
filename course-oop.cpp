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

	menu.CreateNewItem("Додати екзамен до залікової книги", [&gbook] {
		try {
			Exam exam;
			exam.fill();
			gbook.push_back(move(exam));
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		}, []() {return true;});
	menu.CreateNewItem("Видалити екзамен з залікової книги", [&gbook] {
		try {
			gbook.pop_back();
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		}, [] {return true; });

	menu.CreateNewItem("Вивести залікову книгу", [&gbook] { 
		gbook.print();
		}, []() {return true; });
	menu.CreateNewItem("Вивести відсортовану залікову книгу", [&gbook] {
		gbook.printSort();
		}, []() {return true; });
	menu.CreateNewItem("Видалити залікову книгу", [&gbook] {
		try {
			if (gbook.empty())
				throw exception{ runtime_error{ "Заліковa книгa вже порожня!" } };
			gbook.clean();
			cout << "Залікову книгу видалено." << endl;
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		}, [] {return true; });

	menu.CreateNewItem("Додати викладача", [&prof] {
		try {
			prof->fill();
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
		}, [] {return true; });
	menu.CreateNewItem("Додати студента", [&student] {
		try {
			student->fill();
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}}, [] {return true; });

	menu.CreateNewItem("Вивести викладача", [&prof] { prof->print(); }, [] {return true; });
	menu.CreateNewItem("Вивести студента", [&student] { student->print(); }, [] {return true; });

	menu.CreateNewItem("Записати залікову книгу у файл", [&gbook] {
		try {
			gbook.save(file);
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}}, [] {return true; });
	menu.CreateNewItem("Зчитати залікову книгу з файлу", [&gbook] {
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