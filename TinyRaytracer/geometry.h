#pragma once
#include <cstdint>

struct Vec3f
{

};

struct Vec3u
{
	uint8_t x, y, z;
	Vec3u() :
		x(0.f),
		y(0.f),
		z(0.f)
	{}
	
	Vec3u(float inX, float inY, float inZ) :
		x(inX),
		y(inY),
		z(inZ)
	{}
};

using Color = Vec3u;

struct Ray
{
	
};

struct Sphere
{
	
};
