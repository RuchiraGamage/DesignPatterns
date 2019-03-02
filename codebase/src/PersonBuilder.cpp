#include"Builder/PersonBuilder.h"
#include"Builder/PersonAddreeBuilder.h"
#include"Builder/PersonJobBuilder.h"

PersonAddreeBuilder PersonBuilder::live() {
	return PersonAddreeBuilder{person};
}
PersonJobBuilder PersonBuilder::work() {
	return PersonJobBuilder{ person };
}