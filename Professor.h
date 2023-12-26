#pragma once
#include "UniversityMember.h"

class Professor : public virtual UniversityMember
{
protected:
	// поля класу: 
	string surname;
	string pos;
public:
	using uint = unsigned int;

	// конструктори:  
	Professor();
	Professor(string, string, string);
	Professor(const Professor&) = default;
	Professor(Professor&&) = default;

	// деструктор за замовчуванням:
	~Professor() = default;

	// перевантаження операторів:
	Professor& operator=(const Professor&) = default;
	Professor& operator=(Professor&&) = default;
	friend ostream& operator<<(ostream&, const Professor&);
	friend istream& operator>>(istream&, Professor&);

	// гетери/сетери:
	[[nodiscard]] string getSurname() const;
	void setSurname(string);
	[[nodiscard]] string getPos() const;
	void setPos(string);

	// віртуальні ф-ції:
	virtual string toString() const override;
	virtual void print() const override;
	virtual void fill() override;
};

