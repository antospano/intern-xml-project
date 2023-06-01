#include "xmlshapehandler.hpp"
#include "file.hpp"

#define ARG argv[i++]



//sas
int main(int argc, char **argv)
{

	std::cout<<"il numero di argomenti è "<<argc<<"\n";
	
	XMLShapeHandler coc("data.xml");
	Sphere sphere(Vector3(2, 2, 2), 5, "cyan");
	Block block(Vector3(2, 2, 2), Vector3(3, 3, 3), "red");
	coc.AddShape(sphere);
	
	int i = 2;
	/*
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
		
	} while (secondShape); */
	
	
	if (!strcmp(argv[1], "1"))
	{
		//Sphere sphere = Sphere(atoi(ARG), atoi(ARG), atoi(ARG), atoi(ARG), ARG);
		//std::cout<<"creo una SFERA alle coordinate "<<sphere.xpos<<" "<<sphere.ypos<<" "<<sphere.zpos<<" di raggio "<<sphere.radius<<" di colore "<<sphere.color<<".\n";
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