#pragma once

namespace Tvdr{
	class Vector{
	public:
		float x, y;
		Vector(float x = 0, float y = 0);
		~Vector(){}
		Vector Norm();
		static Vector Normalize(Vector vec);

		Vector operator+(Vector vec);
		Vector operator-(Vector vec);
		Vector operator*(float f);
		Vector operator*(Vector vec);
		Vector operator/(float f);
	};
}