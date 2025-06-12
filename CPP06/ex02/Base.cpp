#include "Base.hpp"

Base::Base(){}

Base::~Base(){}

Base *generate(void)
{
	int nbr = std::rand() % 3;
	if (nbr == 0)
		return new A;
	else if (nbr == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	std::cout << "\033[32m";
	if (dynamic_cast<A *>(p)){
		std::cout << "---- A Pointer ----" << std::endl;}
	else if (dynamic_cast<B *>(p)){
		std::cout << "---- B Pointer ----" << std::endl;}
	else if (dynamic_cast<C *>(p)){
		std::cout << "---- C Pointer ----" << std::endl;}
	else {
		std::cout << "\033[31m";
		std::cout << "---- Invalid Pointer ---- "<< std::endl;
	}
	std::cout << "\033[0m";
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "---- A Reference ----" << std::endl;
		(void)a;
		return;
	} catch (...) {}
	
	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "---- B Reference ----" << std::endl;
		(void)b;
		return;
	} catch (...) {}
	
	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "---- C Reference ----" << std::endl;
		(void)c;
		return;
	} catch (...) {}
	
	std::cout << "---- Invalid Reference ----" << std::endl;
}
