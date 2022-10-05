#include "SMLTransform.h"

#pragma region Transform2D

void SML::Transform2D::translate(const Vector2& move)
{
	position = position + move;
}

void SML::Transform2D::translate(const float& a, const float& b)
{
	position.x += a;
	position.y += b;
}

void SML::Transform2D::rotate(const float& angle)
{
	rotation += angle;
}

void SML::Transform2D::uniformscale(const float& s)
{
	scale = scale * s;
}

void SML::Transform2D::variedscale(const float& a, const float& b)
{
	scale.Scale(a, b);
}

void SML::Transform2D::variedscale(const Vector2& s)
{
	scale.x = scale.x * s.x;
	scale.y = scale.y * s.y;
}

#pragma endregion 

#pragma region Transform3D

void SML::Transform3D::translate(const Vector3& move)
{
	position = position + move;
}

void SML::Transform3D::translate(const float& a, const float& b, const float& c)
{
	position.x = position.x + a;
	position.y = position.y + b;
	position.z = position.z + c;
}

void SML::Transform3D::rotate(const float& pitch, const float& yaw, const float& roll)
{
	//TODO: 3D rotation 
}

void SML::Transform3D::uniformscale(const float& s)
{
	scale = scale * s;
}

void SML::Transform3D::variedscale(const float& a, const float& b, const float& c)
{
	scale.Scale(a, b, c);
}

void SML::Transform3D::variedscale(const Vector3& s)
{
	scale.Scale(s.x, s.y, s.z);
}
#pragma endregion