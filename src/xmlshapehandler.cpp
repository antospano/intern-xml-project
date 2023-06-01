#include "xmlshapehandler.hpp"

XMLShapeHandler::XMLShapeHandler(const char *path)
{
	doc.LoadFile(path);
}

void XMLShapeHandler::AddShape(Shape polygon)
{
	
	if (polygon.type == ShapeType::sphere) {
		std::cout<<"SI LO è \n";
    }
}

void XMLShapeHandler::AddShape(const char *elem, const char *parent)
{
	
}
	
template <typename T>
void XMLShapeHandler::AddShape(const char *attribName, T attribValue, const char *elem)
{
	
}

template <typename T>
void XMLShapeHandler::AddShape(const char *attribName, T attribValue, const char *elem, const char *parent)
{
	
}