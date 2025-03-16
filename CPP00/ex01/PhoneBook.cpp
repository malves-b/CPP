#include "Contact.hpp"

void update_oldest(){
	oldest = (oldest < 8) ? (oldest++) : 0;
}
