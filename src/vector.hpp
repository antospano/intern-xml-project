#pragma once

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3() { }
	Vector3(float x, float y, float z) : x(x), y(y), z(z) { }

	Vector3 operator *(Vector3 other)
	{
		return Vector3(other.x * x, other.y * y, other.z * z);
	}

	Vector3 operator *(float other)
	{
		return Vector3(other * x, other * y, other * z);
	}

	Vector3 operator +=(Vector3 other)
	{
		return Vector3(other.x + x, other.y + y, other.z + z);
	}

	Vector3 operator +=(float other)
	{
		return Vector3(other + x, other + y, other + z);
	}
};