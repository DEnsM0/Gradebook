#include "UniversityMember.h"
UniversityMember::UniversityMember() :
	depart{ "Untitled" }
{}

UniversityMember::UniversityMember(string depart) :
	depart{ depart }
{}

UniversityMember::~UniversityMember()
{}

string UniversityMember::getDepart() const
{
	return depart;
}

void UniversityMember::setDepart(string depart)
{
	if (depart.size() > 0)
		this->depart = depart;
}