#pragma once
#include "shape.hpp"
#include "XML/tinyxml2.h"

#include <iostream>

using namespace tinyxml2;
using doc = XMLDocument;
using elem = XMLElement;

class XMLShapeHandler
{
private:
	const char* path;
	doc doc;
	elem* root;
	
public:
	XMLShapeHandler(const char *path);
	
	void AddShape(Shape polygon);
	
	~XMLShapeHandler();
};