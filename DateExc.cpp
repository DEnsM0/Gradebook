#include "DateExc.h"
DateExc::DateExc(struct tm date) : Exception(date) {}
void DateExc::print() {
		cout << "������ ���� �������� ������! ������, ���� �����, �� ��� (������ ����: ��:��-��.��.����): ";
}