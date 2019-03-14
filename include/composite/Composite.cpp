#include"composite/Composite.h"
#include"composite/ShapeComposite.h"
#include"composite/Neurons.h"
/*

int main(int ac, char* av[])
{
//lets build above expression

AdditionExpression sum
{
make_shared<Literal>(2),
make_shared<AdditionExpression>
(
make_shared<Literal>(3),
make_shared<Literal>(4)
)
};

cout << "2+(3+4) = "<< sum.eval()<< endl;

//suppose wewant to get separately literal values,through this design it is possible
vector<double> literals;
sum.collect(literals);

for (const auto& l: literals)
{
cout << l << endl;
}

std::cout << endl;

Group root("root");
Circle c1, c2;
root.objects.push_back(&c1);

Group sub("sub");
sub.objects.push_back(&c2);

root.objects.push_back(&sub);

root.draw();

//Neuron example
std::cout << "Neuron example" << std::endl;
Neuron n1, n2;
n1.connect_to(n2);

std::cout << n1 <<std::endl << n2 << std::endl;

NeuronLayer l1{ 5 };
NeuronLayer l2{ 5 };
Neuron n3;

l1.connect_to(l2);

std::cout << l1 << std::endl;

getchar();
return 0;
}
*/