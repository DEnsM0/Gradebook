#include "MarkExc.h"
MarkExc::MarkExc(uint val) : Exception(val){}
void MarkExc::print() {
	if (val<0)
	cout << "������ �� ���� ���� ��'�����! �� �����: " << val << ".";
	else if (val==0)
	cout << "������ �� ���� ���������� 0!";
	else if (val>100)
	cout << "������ �� ���� ���� ����� 100! �� �����: " << val << ".";
	cout << "������, ���� �����, �� ���: ";
}