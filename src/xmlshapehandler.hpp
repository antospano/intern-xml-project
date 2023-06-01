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
	doc doc;
	elem* root;
	
public:
	XMLShapeHandler(const char *path);
	
	void AddShape(Shape polygon);
	void AddShape(const char *elem, const char *parent);
	
	template <typename T>
	void AddShape(const char *attribName, T attribValue, const char *elem);
	template <typename T>
	void AddShape(const char *attribName, T attribValue, const char *elem, const char *parent);
};