#include"PersonBuilder.h"
#include"PersonAddreeBuilder.h"
#include"PersonJobBuilder.h"

PersonAddreeBuilder PersonBuilder::live() 
{
	return PersonAddreeBuilder{ person };
}
PersonJobBuilder PersonBuilder::work()
{
	return PersonJobBuilder{ person };
}