#include "HoursExc.h"
HoursExc::HoursExc(uint val) : Exception(val) {}
void HoursExc::print() {
	if (val < 0)
		cout << "ʳ������ ����� �� ���� ���� ��'�����! �� �����: " << val << ".";
	else if (val == 0)
		cout << "ʳ������ ����� �� ���� ���������� 0!";
	else if (val > 244)
		cout << "ʳ������ ����� �� ���� ���� ����� 244! �� �����: " << val << ".";
	cout << "������, ���� �����, �� ���: ";
}