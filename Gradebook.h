#pragma once
#include "Header.h"

template <typename C> class Gradebook {
protected:
	// вказівник на дані контейнера
	C* items;
	// розмір контейнера
	size_t size_;
public:
	// конструктори: 
	Gradebook();
	Gradebook(initializer_list<C>);
	Gradebook(const Gradebook<C>&);
	Gradebook(Gradebook<C>&&) noexcept;

	// віртуальний деструктор:
	virtual ~Gradebook();

	// перевантаження операторів:
	Gradebook<C>& operator=(const Gradebook<C>&);
	Gradebook<C>& operator=(Gradebook<C>&&) noexcept;
	class Iterator {
	protected:
		// поточний елемент:
		C* p;
	public:
		// конструктори:
		explicit Iterator(C* p) : p(p) {}
		Iterator(const Iterator& it) : p(it.p) {}

		// перевантаження операторів:
		Iterator& operator++() { ++p; return *this; }
		Iterator operator++(int) { Iterator returnValue = *this; ++(*this); return returnValue; }
		Iterator& operator--() { --p; return *this; }
		Iterator operator--(int) { Iterator returnValue = *this; --(*this); return returnValue; }
		bool operator==(const Iterator& obj) const { return p == obj.p; }
		bool operator!=(const Iterator& obj) const { return p != obj.p; }

		// розіменування вказівника:
		C& operator*() { return *p; }
	};
public:
	[[nodiscard]] size_t size() const noexcept;
	// додає елемент до контейнера:
	void push_back(const C&);
	void push_back(C&&);

	// видаляє елемент з контейнера:
	void pop_back();

	//  повертає ітератор початку контейнера:
	Iterator begin() const noexcept { return Iterator(items); }
	//  повертає ітератор кінця контейнера:
	Iterator end() const noexcept { return Iterator(items + size_); }

	// работа з файлом
	void save(string);
	bool isopen(string);
	void load(string);

	// очищає контейнер
	void clean();
	// перевірка, чи порожній контейнер:
	bool empty() const noexcept;

	// виводить на консоль дані контейнера:
	void print() const;
	// виводить на консоль відсортовані дані контейнера:
	void printSort() const;

};

template <typename C> Gradebook<C>::Gradebook() : items{ nullptr }, size_{} {}
template <typename C> Gradebook<C>::Gradebook(initializer_list<C> list) :
	size_{ list.size() }
{
	// виділення пам'яті буфера:
	items = new C[size_];

	// копіювання елементів:
	size_t i = 0u;
	for (auto it = list.begin(); it != list.end() && i < list.size(); ++it, ++i)
		items[i] = *it;
}
template <typename C> Gradebook<C>::Gradebook(const Gradebook<C>& obj) :
	size_{ obj.size_ }
{
	// виділення пам'яті буфера:
	items = new C[size_];

	// копіювання елементів:
	size_t i = 0;
	for (auto it = obj.begin(); it != obj.end(); ++it, ++i)
		items[i] = *it;
}
template <typename C> Gradebook<C>::Gradebook(Gradebook<C>&& obj) noexcept
{
	// виділення пам'яті буфера:
	items = new C[size_];

	// копіювання елементів:
	size_t i = 0;
	for (auto it = obj.begin(); it != obj.end(); ++it, ++i)
		items[i] = *it;
}
template <typename C> Gradebook<C>::~Gradebook()
{
	if (items != nullptr)
		delete[] items;
}
template <typename C> Gradebook<C>& Gradebook<C>::operator=(const Gradebook<C>& obj)
{
	// якщо спробувати присвоїти об'єкт самому собі:
	if (this == &obj) return *this;
	// видалення попереднього контейнера:
	if (items != nullptr) { delete[] items; items = nullptr; }

	// копіювання елементів:
	size_ = obj.size_;
	items = new C[size_];
	size_t i = 0;
	for (auto it = obj.begin(); it != obj.end(); ++it, ++i)
		items[i] = *it;

	return *this;
}
template <typename C> Gradebook<C>& Gradebook<C>::operator=(Gradebook<C>&& obj) noexcept
{
	// якщо спробувати присвоїти об'єкт самому собі:
	if (this == &obj) return *this;
	// видалення попереднього контейнера:
	if (items != nullptr) { delete[] items; items = nullptr; }

	// копіювання елементів:
	size_ = obj.size_;
	items = new C[size_];
	size_t i = 0;
	for (auto it = obj.begin(); it != obj.end(); ++it, ++i)
		items[i] = *it;

	return *this;
}

 template <typename C> size_t Gradebook<C>::size() const noexcept
{
	return size_;
}
 template <typename C> void Gradebook<C>::push_back(const C& item)
 {
	 // зміна розміру контейнера:
	 C* newCs = new C[size_ + 1];

	 // копіювання елементів:
	 if (!empty()) {
		 int i = 0;
		 for (auto it = begin(); it != end(); ++it, ++i)
			 newCs[i] = *it;
	 }
	 newCs[size_] = item;

	  //видалення попереднього контейнера:
	 if (items != nullptr) { delete[] items; items = nullptr; }
	 items = newCs;
	 ++size_;
 }
 template <typename C> void Gradebook<C>::push_back(C&& item)
 {
	 // зміна розміру контейнера:
	 C* newCs = new C[size_ + 1];

	 // копіювання елементів:
	 if (!empty()) {
		 int i = 0;
		 for (auto it = begin(); it != end(); ++it, ++i)
			 newCs[i] = *it;
	 }
	 newCs[size_] = item;

	 //  видалення попереднього контейнера:
	 if (items != nullptr) { delete[] items; items = nullptr; }
	 items = newCs;
	 ++size_;
 }
 template <typename C> void Gradebook<C>::pop_back()
 {
	 // виключення, якщо контейнер порожній
	 if (empty())
		 throw exception{ runtime_error{ "Контейнер  вже порожній!" } };

	 // зміна розміру контейнера:
	 --size_;
	 C* newCs = new C[size_];

	 // копіювання елементів:
	 size_t i = 0;
	 for (auto it = begin(); i < size_; ++it, ++i)
		 newCs[i] = *it;

	 // видалення попереднього контейнера:
	 if (items != nullptr) { delete[] items; items = nullptr; }

	 items = newCs;

	 cout << "Дані типу " << typeid(C).name() << " видалено." << endl;
 }
 template <typename C> bool Gradebook<C>::empty() const noexcept
 {
	 return !size_;
 }
 template <typename C> void Gradebook<C>::print() const
 {
	 if (empty()) { cout << "Залікова книжка порожня." << endl; return; }
	 cout << endl << setw(7) << left << "Кафедра:"
		 << setw(11) << left << "|Викладач:"
		 << setw(19) << left << "|Посада викладача:"
		 << setw(10) << left << "|Cтудент:"
		 << setw(16) << left << "|Група студента:"
		 << setw(10) << left << "|Предмет:"
		 << setw(16) << left << "|Кількість годин:"
		 << setw(17) << left << "|Дата:"
		 << setw(12) << left << "|Оцінка:";
	 for (auto i = begin(); i != end(); ++i)
	 {
		 cout << endl << "-------------------------------------------------"
			 << "-------------------------------------------------"
		 << "-----------------" << endl;
		 (*i).print();
	 }

	 cout << endl << endl;

 }
 template <typename C> void Gradebook<C>::printSort() const
 {
	 if (empty()) { cout << "Залікова книжка порожня." << endl; return; }
	 C* newCs = new C[size_];
	 // копіювання елементів:
	 size_t i = 0;
	 for (auto it = begin(); i < size_; ++it, ++i) {
		 newCs[i] = *it;
	 }
	 C buff;
	 // сортування елементів:
	 for (size_t i = 0; i < size_; i++)
		 for (size_t j = 0; j < size_ - i - 1; j++) {
			 struct tm time1 = newCs[j].getDate();
			 struct tm time2 = newCs[j + 1].getDate();
			 if (difftime(mktime(&time1), mktime(&time2)) > 0) {
				 buff = newCs[j];
				 newCs[j] = newCs[j + 1];
				 newCs[j + 1] = buff;
			 }
		 }
	 //виведення таблиці:
	 cout << endl << setw(7) << left << "Кафедра:"
		 << setw(11) << left << "|Викладач:"
		 << setw(19) << left << "|Посада викладача:"
		 << setw(10) << left << "|Cтудент:"
		 << setw(16) << left << "|Група студента:"
		 << setw(10) << left << "|Предмет:"
		 << setw(16) << left << "|Кількість годин:"
		 << setw(17) << left << "|Дата:"
		 << setw(12) << left << "|Оцінка:";
	 for (size_t i = 0; i < size_; ++i) {
		 cout << endl << "-------------------------------------------------"
			 << "-------------------------------------------------"
			 << "-----------------" << endl;
		 newCs[i].print();

	 }

	 cout << endl << endl;

 }
 template <typename C> void Gradebook<C>::save(string input)
 {
	 // відкриття файлу:
	 ofstream file(input.data(), ios_base::out);

	 // запис даних до файлу:
	 file << size_ << endl;
	 for (auto i = begin(); i != end(); ++i)
		 file << *i;
	 file.close();

	 if (file.good())
		 cout << "Залікову книжку збережено." << endl;
	 else
		 throw exception{ runtime_error{"Залікову книжку не збережено!"} };
 }
 template <typename C> void Gradebook<C>::load(string input)
 {
	 // відкриття файлу:
	 ifstream file(input.data(), ios_base::in);

	 // зчитування даних з файлу:
	 C item;
	 size_t size;
	 file >> size;
	 for (size_t i = 0; !file.eof() && i < size; ++i)
	 {
		 file >> item;
		 push_back(move(item));
	 }
	 file.close();

	 if (file.good())
		 cout << "Залікову книжку завантажено." << endl;
	 else
		 throw exception{ runtime_error{"Неможливо завантажити залікову книжку!"} };
 }
 template <typename C> bool Gradebook<C>::isopen(string input)
 {
	 // перевірка відкриття потоку для зчитування з файлу:
	 ifstream file;
	 file.open(input.data(), ios_base::in);
	 if (!file) return 0;
	 else {
		 file.close();
		 return 1;
	 }
 }
 template <typename C> void Gradebook<C>::clean()
 {
	 if (items != nullptr) { delete[] items; items = nullptr; }
	 size_ = 0;
 }
