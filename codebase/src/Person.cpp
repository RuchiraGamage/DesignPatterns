#include"Builder/Person.h"
#include"Builder/PersonBuilder.h"

PersonBuilder Person::create()
{
	return PersonBuilder{};
}