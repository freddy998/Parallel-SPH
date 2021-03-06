#pragma once
#include <vector>

using namespace std;

struct vec3
{
	double x, y, z;
	vec3()
	{
		x = y = z = 0;
	}

	vec3(double a, double b, double c)
	{
		x = a;
		y = b;
		z = c;
	}

	double getMagnitude()
	{
		return sqrt(x*x + y * y + z * z);
	}

	vec3 Normalized()
	{
		double m = getMagnitude();
		return vec3(x / m, y / m, z / m);
	}

	vec3 operator+(const vec3& other)
	{
		double tx = x + other.x;
		double ty = y + other.y;
		double tz = z + other.z;
		vec3 f = vec3(tx, ty, tz);
		return f;
	}

	vec3 operator-(const vec3& other)
	{
		double tx = x - other.x;
		double ty = y - other.y;
		double tz = z - other.z;
		vec3 f = vec3(tx, ty, tz);
		return f;
	}

	
	vec3 operator*(const double& other)
	{
		double tx = x * other;
		double ty = y * other;
		double tz = z * other;
		vec3 f = vec3(tx, ty, tz);
		return f;
	}

	vec3& operator+=(const vec3& other)
	{
		x+= other.x;
		y+=  other.y;
		z+= other.z;
		
		return *this;
	}
	vec3& operator/=(const double& other)
	{
		x /= other;
		y /= other;
		z /= other;

		return *this;
		
	}

	vec3& operator-=(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}
};

struct Particle
{
	vector<Particle*> neighbors;
	double density;
	double pressure;
	vec3 Fpressure;
	vec3 Fviscocity;
	vec3 FGravity;
	vec3 acceleration;
	vec3 velocity;
	vec3 position;
	vec3 halfVelocity;
	double mass;

	Particle()
	{
		velocity.x = 0;
		velocity.y = 0;
		velocity.z = 0;
		
		acceleration.x = 0;
		acceleration.y = 0;
		acceleration.z = 0;

		halfVelocity.x = 0;
		halfVelocity.y = 0;
		halfVelocity.z = 0;
	}

	Particle(double x , double y , double z , double m , double d)
	{
		position.x = x; 
		position.y = y;
		position.z = z;
		
		velocity.x = 0;
		velocity.y = 0;
		velocity.z = 0;
		
		acceleration.x = 0;
		acceleration.y = 0;
		acceleration.z = 0;

		halfVelocity.x = 0;
		halfVelocity.y = 0;
		halfVelocity.z = 0;
		Fpressure = vec3(0, 0, 0);
		FGravity = vec3(0, 0, 0);
		Fviscocity = vec3(0, 0, 0);

		mass = m;
		density = d;
	}
};

struct FluidParams
{
	double viscocity;
	
};


