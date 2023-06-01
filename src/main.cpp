#include "xmlshapehandler.hpp"
#include "file.hpp"

#define ID argv[1]
#define ARG argv[i++]



//sas
int main(int argc, char **argv)
{

	std::cout<<"il numero di argomenti è "<<argc<<"\n";
	int i = 2;
	
	XMLShapeHandler doc("data.xml");
	Shape shape;
	
	switch(atoi(ID))
	{
		case 1:
			shape = Sphere(Vector3(atoi(ARG), atoi(ARG), atoi(ARG)), atoi(ARG), ARG, ID);
			break;
		case 2:
			shape = Block(Vector3(atoi(ARG), atoi(ARG), atoi(ARG)), Vector3(atoi(ARG), atoi(ARG), atoi(ARG)), ARG, ID);
			break;
		case 3:
			shape = Cylinder(Vector3(atoi(ARG), atoi(ARG), atoi(ARG)), atoi(ARG), atoi(ARG), ARG, ID);
			break;
		default:
			return -1;
			break;
	}
	
	doc.AddShape(shape);
	
	return 0;
}