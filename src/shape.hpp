#pragma once
#include <string>
#include "vector.hpp"

enum ShapeType
{
	sphere,
	block,
	cylinder
};

class Shape
{
public:
	Vector3 pos;
	std::string col;
	ShapeType type;
	
	Shape(Vector3 pos, std::string col, ShapeType type) : pos(pos), col(col), type(type) { }
};

class Sphere : public Shape
{
public:
	float radius;
	
	Sphere(Vector3 pos, float radius, std::string col) : Shape(pos, col, ShapeType::sphere), radius(radius) { }
};

class Block : public Shape
{
public:
	Vector3 dim;
	
	Block(Vector3 pos, Vector3 dim, std::string col) : Shape(pos, col, ShapeType::block), dim(dim) { }
};

class Cylinder : public Shape
{
public:
	float radius;
	float ydim;
	
	Cylinder(Vector3 pos, float radius, float ydim, std::string col) : Shape(pos, col, ShapeType::cylinder), radius(radius), ydim(ydim) { }
};