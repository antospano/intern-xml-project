#include <iostream>
#include "File/file.hpp"
#include "XML/tinyxml2.h"

#define ARG argv[i++]

using namespace tinyxml2;
using elem = XMLElement;

//sas
int main(int argc, char **argv)
{

	std::cout<<"il numero di argomenti è "<<argc<<"\n";
	
	int i = 2;
	//std::cout<<"prima if"<<(doc.LoadFile("data.xml") == XML_SUCCESS)<<"\n";
	
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile("data.xml") == tinyxml2::XML_SUCCESS) {
        const tinyxml2::XMLElement* shapesElement = doc.FirstChildElement("shapes");
        if (shapesElement) {
            const tinyxml2::XMLElement* shapeElement = shapesElement->FirstChildElement("shape");
            if (shapeElement) {
                const tinyxml2::XMLElement* xposElement = shapeElement->FirstChildElement("xpos");
                if (xposElement) {
                    const char* value = xposElement->GetText();
                    if (value) {
                        std::cout << "xpos: " << value << std::endl;
                    }
                }
            }
        }
    } else {
        std::cout << "Failed to load XML file." << std::endl;
    }
	
	if (!strcmp(argv[1], "1"))
	{
		std::cout<<"creo una SFERA alle coordinate "<<ARG<<" "<<ARG<<" "<<ARG<<" di raggio "<<ARG<<" di colore "<<ARG<<".\n";
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