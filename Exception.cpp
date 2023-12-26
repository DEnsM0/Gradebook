#include "Exception.h"
Exception::Exception(uint val) {
	this->val = val;
 }
Exception::Exception(struct tm date) {
	this->date = date;
}