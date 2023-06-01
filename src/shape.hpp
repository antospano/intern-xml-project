#pragma once
#include <string>
#include "vector.hpp"
#include <vector>

struct Element
{
	std::string name;
	std::string value;
	
	Element(std::string name, std::string value) : name(name), value(value) { }
};

class Shape
{
public:
	std::string id;
	Vector3 pos;
	std::string col;
	std::vector<Element> elements;
	
	Shape() { }
	Shape(Vector3 pos, std::string col, std::string id) : pos(pos), col(col), id(id) { }
};

class Sphere : public Shape
{
public:
	float radius;
	
	Sphere(Vector3 pos, float radius, std::string col, std::string id) : Shape(pos, col, id), radius(radius)
	{ 
		this->elements.push_back(Element("xpos", std::to_string(pos.x)));
		this->elements.push_back(Element("ypos", std::to_string(pos.y)));
		this->elements.push_back(Element("zpos", std::to_string(pos.z)));
		this->elements.push_back(Element("radius", std::to_string(radius)));
		this->elements.push_back(Element("color", col));
	}
};

class Block : public Shape
{
public:
	Vector3 dim;
	
	Block(Vector3 pos, Vector3 dim, std::string col, std::string id) : Shape(pos, col, id), dim(dim)
	{
		this->elements.push_back(Element("xpos", std::to_string(pos.x)));
		this->elements.push_back(Element("ypos", std::to_string(pos.y)));
		this->elements.push_back(Element("zpos", std::to_string(pos.z)));
		this->elements.push_back(Element("xdim", std::to_string(dim.x)));
		this->elements.push_back(Element("ydim", std::to_string(dim.y)));
		this->elements.push_back(Element("zdim", std::to_string(dim.z)));
		this->elements.push_back(Element("color", col));
	}
};

class Cylinder : public Shape
{
public:
	float radius;
	float ydim;
	
	Cylinder(Vector3 pos, float radius, float ydim, std::string col, std::string id) : Shape(pos, col, id), radius(radius), ydim(ydim)
	{
		this->elements.push_back(Element("xpos", std::to_string(pos.x)));
		this->elements.push_back(Element("ypos", std::to_string(pos.y)));
		this->elements.push_back(Element("zpos", std::to_string(pos.z)));
		this->elements.push_back(Element("radius", std::to_string(radius)));
		this->elements.push_back(Element("ydim", std::to_string(ydim)));
		this->elements.push_back(Element("color", col));
	}
};