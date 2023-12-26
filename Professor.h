#pragma once
#include "UniversityMember.h"

class Professor : public virtual UniversityMember
{
protected:
	// ���� �����: 
	string surname;
	string pos;
public:
	using uint = unsigned int;

	// ������������:  
	Professor();
	Professor(string, string, string);
	Professor(const Professor&) = default;
	Professor(Professor&&) = default;

	// ���������� �� �������������:
	~Professor() = default;

	// �������������� ���������:
	Professor& operator=(const Professor&) = default;
	Professor& operator=(Professor&&) = default;
	friend ostream& operator<<(ostream&, const Professor&);
	friend istream& operator>>(istream&, Professor&);

	// ������/������:
	[[nodiscard]] string getSurname() const;
	void setSurname(string);
	[[nodiscard]] string getPos() const;
	void setPos(string);

	// �������� �-���:
	virtual string toString() const override;
	virtual void print() const override;
	virtual void fill() override;
};

