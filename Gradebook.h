#pragma once
#include "Header.h"

template <typename C> class Gradebook {
protected:
	// �������� �� ��� ����������
	C* items;
	// ����� ����������
	size_t size_;
public:
	// ������������: 
	Gradebook();
	Gradebook(initializer_list<C>);
	Gradebook(const Gradebook<C>&);
	Gradebook(Gradebook<C>&&) noexcept;

	// ���������� ����������:
	virtual ~Gradebook();

	// �������������� ���������:
	Gradebook<C>& operator=(const Gradebook<C>&);
	Gradebook<C>& operator=(Gradebook<C>&&) noexcept;
	class Iterator {
	protected:
		// �������� �������:
		C* p;
	public:
		// ������������:
		explicit Iterator(C* p) : p(p) {}
		Iterator(const Iterator& it) : p(it.p) {}

		// �������������� ���������:
		Iterator& operator++() { ++p; return *this; }
		Iterator operator++(int) { Iterator returnValue = *this; ++(*this); return returnValue; }
		Iterator& operator--() { --p; return *this; }
		Iterator operator--(int) { Iterator returnValue = *this; --(*this); return returnValue; }
		bool operator==(const Iterator& obj) const { return p == obj.p; }
		bool operator!=(const Iterator& obj) const { return p != obj.p; }

		// ������������ ���������:
		C& operator*() { return *p; }
	};
public:
	[[nodiscard]] size_t size() const noexcept;
	// ���� ������� �� ����������:
	void push_back(const C&);
	void push_back(C&&);

	// ������� ������� � ����������:
	void pop_back();

	//  ������� �������� ������� ����������:
	Iterator begin() const noexcept { return Iterator(items); }
	//  ������� �������� ���� ����������:
	Iterator end() const noexcept { return Iterator(items + size_); }

	// ������ � ������
	void save(string);
	bool isopen(string);
	void load(string);

	// ����� ���������
	void clean();
	// ��������, �� ������� ���������:
	bool empty() const noexcept;

	// �������� �� ������� ��� ����������:
	void print() const;
	// �������� �� ������� ���������� ��� ����������:
	void printSort() const;

};

template <typename C> Gradebook<C>::Gradebook() : items{ nullptr }, size_{} {}
template <typename C> Gradebook<C>::Gradebook(initializer_list<C> list) :
	size_{ list.size() }
{
	// �������� ���'�� ������:
	items = new C[size_];

	// ��������� ��������:
	size_t i = 0u;
	for (auto it = list.begin(); it != list.end() && i < list.size(); ++it, ++i)
		items[i] = *it;
}
template <typename C> Gradebook<C>::Gradebook(const Gradebook<C>& obj) :
	size_{ obj.size_ }
{
	// �������� ���'�� ������:
	items = new C[size_];

	// ��������� ��������:
	size_t i = 0;
	for (auto it = obj.begin(); it != obj.end(); ++it, ++i)
		items[i] = *it;
}
template <typename C> Gradebook<C>::Gradebook(Gradebook<C>&& obj) noexcept
{
	// �������� ���'�� ������:
	items = new C[size_];

	// ��������� ��������:
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
	// ���� ���������� �������� ��'��� ������ ���:
	if (this == &obj) return *this;
	// ��������� ������������ ����������:
	if (items != nullptr) { delete[] items; items = nullptr; }

	// ��������� ��������:
	size_ = obj.size_;
	items = new C[size_];
	size_t i = 0;
	for (auto it = obj.begin(); it != obj.end(); ++it, ++i)
		items[i] = *it;

	return *this;
}
template <typename C> Gradebook<C>& Gradebook<C>::operator=(Gradebook<C>&& obj) noexcept
{
	// ���� ���������� �������� ��'��� ������ ���:
	if (this == &obj) return *this;
	// ��������� ������������ ����������:
	if (items != nullptr) { delete[] items; items = nullptr; }

	// ��������� ��������:
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
	 // ���� ������ ����������:
	 C* newCs = new C[size_ + 1];

	 // ��������� ��������:
	 if (!empty()) {
		 int i = 0;
		 for (auto it = begin(); it != end(); ++it, ++i)
			 newCs[i] = *it;
	 }
	 newCs[size_] = item;

	  //��������� ������������ ����������:
	 if (items != nullptr) { delete[] items; items = nullptr; }
	 items = newCs;
	 ++size_;
 }
 template <typename C> void Gradebook<C>::push_back(C&& item)
 {
	 // ���� ������ ����������:
	 C* newCs = new C[size_ + 1];

	 // ��������� ��������:
	 if (!empty()) {
		 int i = 0;
		 for (auto it = begin(); it != end(); ++it, ++i)
			 newCs[i] = *it;
	 }
	 newCs[size_] = item;

	 //  ��������� ������������ ����������:
	 if (items != nullptr) { delete[] items; items = nullptr; }
	 items = newCs;
	 ++size_;
 }
 template <typename C> void Gradebook<C>::pop_back()
 {
	 // ����������, ���� ��������� �������
	 if (empty())
		 throw exception{ runtime_error{ "���������  ��� �������!" } };

	 // ���� ������ ����������:
	 --size_;
	 C* newCs = new C[size_];

	 // ��������� ��������:
	 size_t i = 0;
	 for (auto it = begin(); i < size_; ++it, ++i)
		 newCs[i] = *it;

	 // ��������� ������������ ����������:
	 if (items != nullptr) { delete[] items; items = nullptr; }

	 items = newCs;

	 cout << "��� ���� " << typeid(C).name() << " ��������." << endl;
 }
 template <typename C> bool Gradebook<C>::empty() const noexcept
 {
	 return !size_;
 }
 template <typename C> void Gradebook<C>::print() const
 {
	 if (empty()) { cout << "������� ������ �������." << endl; return; }
	 cout << endl << setw(7) << left << "�������:"
		 << setw(11) << left << "|��������:"
		 << setw(19) << left << "|������ ���������:"
		 << setw(10) << left << "|C������:"
		 << setw(16) << left << "|����� ��������:"
		 << setw(10) << left << "|�������:"
		 << setw(16) << left << "|ʳ������ �����:"
		 << setw(17) << left << "|����:"
		 << setw(12) << left << "|������:";
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
	 if (empty()) { cout << "������� ������ �������." << endl; return; }
	 C* newCs = new C[size_];
	 // ��������� ��������:
	 size_t i = 0;
	 for (auto it = begin(); i < size_; ++it, ++i) {
		 newCs[i] = *it;
	 }
	 C buff;
	 // ���������� ��������:
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
	 //��������� �������:
	 cout << endl << setw(7) << left << "�������:"
		 << setw(11) << left << "|��������:"
		 << setw(19) << left << "|������ ���������:"
		 << setw(10) << left << "|C������:"
		 << setw(16) << left << "|����� ��������:"
		 << setw(10) << left << "|�������:"
		 << setw(16) << left << "|ʳ������ �����:"
		 << setw(17) << left << "|����:"
		 << setw(12) << left << "|������:";
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
	 // �������� �����:
	 ofstream file(input.data(), ios_base::out);

	 // ����� ����� �� �����:
	 file << size_ << endl;
	 for (auto i = begin(); i != end(); ++i)
		 file << *i;
	 file.close();

	 if (file.good())
		 cout << "������� ������ ���������." << endl;
	 else
		 throw exception{ runtime_error{"������� ������ �� ���������!"} };
 }
 template <typename C> void Gradebook<C>::load(string input)
 {
	 // �������� �����:
	 ifstream file(input.data(), ios_base::in);

	 // ���������� ����� � �����:
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
		 cout << "������� ������ �����������." << endl;
	 else
		 throw exception{ runtime_error{"��������� ����������� ������� ������!"} };
 }
 template <typename C> bool Gradebook<C>::isopen(string input)
 {
	 // �������� �������� ������ ��� ���������� � �����:
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
