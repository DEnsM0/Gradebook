#pragma once
#include "UniversityMember.h"

class Student : public virtual UniversityMember
{
protected:
	// ���� �����: 
	string surname;
	uint group;
public:
	using uint = unsigned int;

	// ������������: 
	Student();
	Student(string, string, uint);
	Student(const Student&) = default;
	Student(Student&&) = default;

	// ���������� �� �������������:
	~Student() = default;

	// �������������� ���������:
	Student& operator=(const Student&) = default;
	Student& operator=(Student&&) = default;
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);

	// ������/������:
	[[nodiscard]] string getSurname() const;
	void setSurname(string);
	[[nodiscard]] uint getGroup() const noexcept;
	void setGroup(uint);

	// �������� �-���:
	virtual string toString() const override;
	virtual void print() const override;
	virtual void fill() override;
};

