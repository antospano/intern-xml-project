#include <iostream>
#include "File/file.hpp"
#include "XML/tinyxml2.h"

#define ARG argv[i++]

using namespace tinyxml2;
using doc = XMLDocument;
using elem = XMLElement;

struct Circle
{
	float xpos;
	float ypos;
	float zpos;
	
	float radius;
	std::string color;
	
public:
	Circle(float xpos, float ypos, float zpos, float radius, std::string color) : xpos(xpos), ypos(ypos), zpos(zpos), radius(radius), color(color) { }
};

//sas
int main(int argc, char **argv)
{

	std::cout<<"il numero di argomenti è "<<argc<<"\n";
	
	int i = 2;
	
    doc doc;
	doc.LoadFile("data.xml");
	elem* root = doc.FirstChildElement("shapes");
	elem* shape = root->FirstChildElement("shape");
	elem* secondShape;
	elem* tempShape = shape;
	
	do
	{
		secondShape = tempShape->NextSiblingElement("shape");
		tempShape = secondShape;
		
		if (secondShape)
		{
			elem* xpos = secondShape->FirstChildElement("xpos");
			const char* _xpos = xpos->GetText();
			std::cout<<_xpos<<"\n";
		}
		
	} while (secondShape);
	
	
	if (!strcmp(argv[1], "1"))
	{
		Circle circle = Circle(atoi(ARG), atoi(ARG), atoi(ARG), atoi(ARG), ARG);
		std::cout<<"creo una SFERA alle coordinate "<<circle.xpos<<" "<<circle.ypos<<" "<<circle.zpos<<" di raggio "<<circle.radius<<" di colore "<<circle.color<<".\n";
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
	
	File file("data.xml", FileMode::Write);
	//file.Write("ciao come stai\nciao come stai");
	std::string line = "";
	
	return 0;
}