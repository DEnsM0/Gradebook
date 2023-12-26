#pragma once
#include "Interface.h"


class UniversityMember abstract : public Interface
{
protected:
	// ���� �����: 
	string depart;
public:
	using uint = unsigned int;

	// ������������:
	UniversityMember();
	UniversityMember(string);
	UniversityMember(const UniversityMember&) = default;
	UniversityMember(UniversityMember&&) = default;

	// ���������� ����������:
	virtual ~UniversityMember();

	// �������������� ���������:
	UniversityMember& operator=(const UniversityMember&) = default;
	UniversityMember& operator=(UniversityMember&&) = default;

	// ������/������:
	[[nodiscard]] string getDepart() const;
	void setDepart(string);
};

