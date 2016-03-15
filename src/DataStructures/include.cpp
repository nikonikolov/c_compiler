#include "include.h"


std::ostream& pad(std::ostream& os) {
	return os <<"\t"<<std::left<< std::setfill(' ') << std::setw(8);
}