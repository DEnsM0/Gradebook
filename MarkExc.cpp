#include "MarkExc.h"
MarkExc::MarkExc(uint val) : Exception(val){}
void MarkExc::print() {
	if (val<0)
	cout << "ќц≥нка не може бути в≥д'Їмною! ¬и ввели: " << val << ".";
	else if (val==0)
	cout << "ќц≥нка не може дор≥внювати 0!";
	else if (val>100)
	cout << "ќц≥нка не може бути б≥льше 100! ¬и ввели: " << val << ".";
	cout << "¬вед≥ть, будь ласка, ще раз: ";
}