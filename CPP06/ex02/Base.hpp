#if !defined BASE
#define BASE

#include "iostream"
#include <cstdlib>

class Base
{
public:
	Base();
	virtual	~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

//Others classes
class A : public Base{
public:
	A();
	~A();
};

class B : public Base{
public:
	B();
	~B();
};

class C : public Base{
public:
	C();
	~C();
};

#endif // BASE
