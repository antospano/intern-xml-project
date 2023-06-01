#include "xmlshapehandler.hpp"

XMLShapeHandler::XMLShapeHandler(const char *path)
{
	this->path = path;
	std::cout<<(doc.LoadFile(path) == XML_SUCCESS ? "XML LOADED\n" : "XML FAILED TO LOAD\n");
	root = doc.FirstChildElement("shapes");
}

void XMLShapeHandler::AddShape(Shape polygon)
{
	elem* shape = doc.NewElement("shape");
	shape->SetAttribute("id", polygon.id.c_str());
	root->InsertEndChild(shape);
	
	for (auto item : polygon.elements)
	{
		elem* elem = doc.NewElement(item.name.c_str());
		elem->SetText(item.value.c_str());
		shape->InsertEndChild(elem);
	}
}

XMLShapeHandler::~XMLShapeHandler()
{
	std::cout<<(doc.SaveFile(path) == XML_SUCCESS ? "XML SAVED\n" : "XML FAILED TO SAVE\n");
}