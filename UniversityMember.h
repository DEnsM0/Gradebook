#pragma once
#include "Interface.h"


class UniversityMember abstract : public Interface
{
protected:
	// поля класу: 
	string depart;
public:
	using uint = unsigned int;

	// конструктори:
	UniversityMember();
	UniversityMember(string);
	UniversityMember(const UniversityMember&) = default;
	UniversityMember(UniversityMember&&) = default;

	// віртуальний деструктор:
	virtual ~UniversityMember();

	// перевантаження операторів:
	UniversityMember& operator=(const UniversityMember&) = default;
	UniversityMember& operator=(UniversityMember&&) = default;

	// гетери/сетери:
	[[nodiscard]] string getDepart() const;
	void setDepart(string);
};

