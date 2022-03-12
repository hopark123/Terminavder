#include "Vector.hpp"
#include <cmath>

using namespace std;

namespace Tvdr{
	Vector::Vector(float x, float y) : x(x), y(y){}

	Vector Vector::Norm(){
		float temp = sqrtf(x * x + y * y);
		if (temp > 0){
			x /= temp;
			y /= temp;
		}
		return *this;
	}

	Vector Vector::operator+(Vector vec){
		return Vector(x + vec.x, y + vec.y);
	}

	Vector Vector::operator-(Vector vec){
		return Vector(x - vec.x, y - vec.y);
	}

	Vector Vector::operator*(float f){
		return Vector(x * f, y * f);
	}

	Vector Vector::operator*(Vector vec){
		return Vector(x * vec.x, y * vec.y);
	}


	Vector Vector::operator/(float f){
		return Vector(x / f, y / f);
	}
	
}