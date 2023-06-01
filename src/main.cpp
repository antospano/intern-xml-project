#include <iostream>
#include "file.hpp"
#include "XML/tinyxml2.h"

#define ARG argv[i++]

using namespace tinyxml2;
using doc = XMLDocument;
using elem = XMLElement;

struct Sphere
{
	float xpos;
	float ypos;
	float zpos;
	
	float radius;
	std::string color;
	
public:
	Sphere(float xpos, float ypos, float zpos, float radius, std::string color) : xpos(xpos), ypos(ypos), zpos(zpos), radius(radius), color(color) { }
};

struct Block
{
	float xpos;
	float ypos;
	float zpos;
	
	float xdim;
	float ydim;
	float zdim;
	
	std::string color;
	
public:
	Block(float xpos, float ypos, float zpos, float xdim, float ydim, float zdim, std::string color) : xpos(xpos), ypos(ypos), zpos(zpos), xdim(xdim), ydim(ydim), zdim(zdim), color(color) { }
};

struct Cylinder
{
	float xpos;
	float ypos;
	float zpos;
	
	float radius;
	float ydim;
	std::string color;
	
public:
	Cylinder(float xpos, float ypos, float zpos, float radius, float ydim, std::string color) : xpos(xpos), ypos(ypos), zpos(zpos), radius(radius), ydim(ydim), color(color) { }
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
		Sphere sphere = Sphere(atoi(ARG), atoi(ARG), atoi(ARG), atoi(ARG), ARG);
		std::cout<<"creo una SFERA alle coordinate "<<sphere.xpos<<" "<<sphere.ypos<<" "<<sphere.zpos<<" di raggio "<<sphere.radius<<" di colore "<<sphere.color<<".\n";
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