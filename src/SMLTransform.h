#pragma once
#include "SMLVector.h"

namespace SML
{
	class Transform2D
	{
	private:
		Vector2 position;
		float rotation; //Clockwise rotation
		Vector2 scale;

	public:
		void translate(const Vector2& move);
		void translate(const float& a, const float& b);
		void rotate(const float& angle);

		void uniformscale(const float& s);
		void variedscale(const float& a, const float& b);
		void variedscale(const Vector2& s);
	};

	class Transform3D
	{
	private:
		Vector3 position;
		Vector3 rotation; //TODO: change this to a Quaternion or a Matrix
		Vector3 scale;

	public:
		void translate(const Vector3& move);
		void translate(const float& a, const float& b, const float& c);
		void rotate(const float& pitch, const float& yaw, const float& roll);

		void uniformscale(const float& s);
		void variedscale(const float& a, const float& b, const float& c);
		void variedscale(const Vector3& s);
	};
}

