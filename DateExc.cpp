#include "DateExc.h"
DateExc::DateExc(struct tm date) : Exception(date) {}
void DateExc::print() {
		cout << "‘ормат дати введений нев≥рно! ¬вед≥ть, будь ласка, ще раз (формат дати: гг:хх-дд.мм.рррр): ";
}