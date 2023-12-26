#pragma once
#include "UniversityMember.h"

class Student : public virtual UniversityMember
{
protected:
	// поля класу: 
	string surname;
	uint group;
public:
	using uint = unsigned int;

	// конструктори: 
	Student();
	Student(string, string, uint);
	Student(const Student&) = default;
	Student(Student&&) = default;

	// деструктор за замовчуванням:
	~Student() = default;

	// перевантаження операторів:
	Student& operator=(const Student&) = default;
	Student& operator=(Student&&) = default;
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);

	// гетери/сетери:
	[[nodiscard]] string getSurname() const;
	void setSurname(string);
	[[nodiscard]] uint getGroup() const noexcept;
	void setGroup(uint);

	// віртуальні ф-ції:
	virtual string toString() const override;
	virtual void print() const override;
	virtual void fill() override;
};

