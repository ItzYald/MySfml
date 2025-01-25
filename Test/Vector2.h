#pragma once
#include <iostream>

template<typename T>
class Vector2
{
public:
	Vector2() = default;
	Vector2(T x, T y);
	template <typename U>
	explicit Vector2(const Vector2<U>& vector);

	Vector2<T> normalize();
	float length();

	Vector2<T> operator +(const Vector2<T>& rightVector) const;

	Vector2<T> operator -(const Vector2<T>& rightVector);

	T x;
	T y;
};

template<typename T>
inline Vector2<T>::Vector2(T X, T Y)
	: x(X), y(Y)
{

}

template<typename T>
inline Vector2<T> Vector2<T>::operator+(const Vector2<T>& rightVector) const
{
	return Vector2<T>(x + rightVector.x, y + rightVector.y);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator -(const Vector2<T>& rightVector)
{
	return Vector2<T>(x-rightVector.x, y-rightVector.y);
}

template<typename T>
template<typename U>
inline Vector2<T>::Vector2(const Vector2<U>& vector) :
	x(static_cast<T>(vector.x)),
	y(static_cast<T>(vector.y))
{
}

template<typename T>
inline Vector2<T> Vector2<T>::normalize()
{
	return Vector2<T>(x / length(), y / length());
}

template<typename T>
float Vector2<T>::length()
{
	return sqrtf(x * x + y * y);
}

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

