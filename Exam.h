#pragma once
#include "Professor.h"
#include "Student.h"

class Exam :
	public Professor,
	public Student
{
protected:
	using uint = unsigned int;
	string subject;
	uint hours;
	struct tm date;
	uint mark;
public:

	// ������������:
	Exam();
	Exam(string, string, string, string, uint, string, uint, tm, uint);
	Exam(const Exam&) = default;
	Exam(Exam&&) = default;

	// ���������� �� �������������:
	~Exam() = default;

	// �������������� ���������:
	Exam& operator=(const Exam&) = default;
	Exam& operator=(Exam&&)=default;
	friend ostream& operator<<(ostream& os, const Exam& other);
	friend istream& operator>>(istream& is, Exam& other);

	// ������/������:
	[[nodiscard]] string getSubject() const;
	void setSubject(string);
	[[nodiscard]] uint getHours() const noexcept;
	void setHours(uint);
	[[nodiscard]] tm getDate() const noexcept;
	void setDate(tm);
	[[nodiscard]] uint getMark() const noexcept;
	void setMark(uint);

	// �������� �-���:
	virtual string toString() const override;
	virtual void print() const override;
	virtual void fill() override;
};

