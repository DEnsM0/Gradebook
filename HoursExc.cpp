#include "HoursExc.h"
HoursExc::HoursExc(uint val) : Exception(val) {}
void HoursExc::print() {
	if (val < 0)
		cout << "Кількість годин не може бути від'ємною! Ви ввели: " << val << ".";
	else if (val == 0)
		cout << "Кількість годин не може дорівнювати 0!";
	else if (val > 244)
		cout << "Кількість годин не може бути більше 244! Ви ввели: " << val << ".";
	cout << "Введіть, будь ласка, ще раз: ";
}