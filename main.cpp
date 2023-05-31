#include <iostream>
#include "File/file.hpp"

//sas
int main(int argc, char **argv)
{
	std::cout<<"il numero di argomenti è "<<argc<<"\n";
	
	if (!strcmp(argv[1], "1"))
	{
		std::cout<<"sfera\n";
	}
	else
	{
		std::cout<<"figura 3D\n";
	}
	
	for (int i = 1 ; i < argc; i++)
	{
		std::cout<<"arg "<<i<<": "<<argv[i]<<"\n";
	}
	
	File file("../data.xml", FileMode::Read);
	std::cout<<file.GetContent()<<"\n";
	
	return 0;
}