#include "ScalarConvert.hpp"

// Default constructor
ScalarConvert::ScalarConvert(){}

// Copy constructor
ScalarConvert::ScalarConvert(const ScalarConvert &other){*this = other;}

// Destructor
ScalarConvert::~ScalarConvert(){}

// Copy assignment operator
ScalarConvert &ScalarConvert::operator=(const ScalarConvert &other)
{
	if (this != &other) {
		*this = other;
	}
	return *this;
}

void ScalarConvert::convert(const std::string &str)
{
}
