#include <iostream>
#include "File/file.hpp"

#define ARG argv[i++]

//sas
int main(int argc, char **argv)
{
	std::cout<<"il numero di argomenti è "<<argc<<"\n";
	
	int i = 2;
	
	if (!strcmp(argv[1], "1"))
	{
		std::cout<<"creo una sfera alle coordinate "<<ARG<<" "<<ARG<<" "<<ARG<<" di raggio "<<ARG<<" di colore "<<ARG<<".\n";
	}
	else
	{
		std::string figura;
		switch(atoi(argv[1]))
		{
			case 2:
				std::cout<<"creo un BLOCK alle coordinate "<<ARG<<" "<<ARG<<" "<<ARG<<" di dimensioni "<<ARG<<" "<<ARG<<" "<<ARG<<" di colore "<<ARG<<".\n";
				break;
			case 3:
				std::cout<<"creo un CYLINDER alle coordinate "<<ARG<<" "<<ARG<<" "<<ARG<<" di raggio "<<ARG<<" di altezza "<<ARG<<" di colore "<<ARG<<".\n";
				break;
		}
	}
	
	for (int i = 1 ; i < argc; i++)
	{
		std::cout<<"arg "<<i<<": "<<argv[i]<<"\n";
	}
	
	File file("../data.xml", FileMode::Read);
	std::cout<<file.GetContent()<<"\n";
	
	return 0;
}