#if !defined SERIALIZER
#define SERIALIZER

#include <stdint.h>
#include <iostream>

struct Data {
    int id;
    std::string name;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer&);
	Serializer& operator=(const Serializer&);
	~Serializer();
public:

	static	uintptr_t serialize(Data* ptr);
	static	Data* deserialize(uintptr_t raw);
};

#endif
