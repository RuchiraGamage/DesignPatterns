#include"Singleton.h"

int main(int ac,char* av[])
{
	auto& singleDB=SingletonDatabase::get();//shold take as auto & (reference) as we delete assignment and copy constructor
	auto& singleDB2 = SingletonDatabase::get();

	std::cout << SingletonDatabase::instance_count << std::endl;
	getchar();
	return 0;
}