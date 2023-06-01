#pragma once
#include <string>
#include "vector.hpp"

enum Color
{
	red,
	green,
	purple,
	yellow,
	blue,
	cyan
};

class Polygon
{
	Vector3 pos;
	Color col;
	
public:
	Polygon(Vector3 pos, Color col) : pos(pos), col(col) { }
};

class Sphere : Polygon
{
	float radius;
	
public:
	Sphere(Vector3 pos, float radius, Color col) : Polygon(pos, col), radius(radius) { }
};

class Block : Polygon
{
	Vector3 dim;
	
public:
	Block(Vector3 pos, Vector3 dim, Color col) : Polygon(pos, col), dim(dim) { }
};

class Cylinder : Polygon
{
	float radius;
	float ydim;
	
public:
	Cylinder(Vector3 pos, float radius, float ydim, Color col) : Polygon(pos, col), radius(radius), ydim(ydim) { }
};