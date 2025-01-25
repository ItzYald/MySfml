#pragma once

template<typename T>
class Vector2
{
public:
	Vector2() = default;
	Vector2(T x, T y);
	template <typename U>
	explicit Vector2(const Vector2<U>& vector);

	T x;
	T y;
};

template<typename T>
inline Vector2<T>::Vector2(T X, T Y)
	: x(X), y(Y)
{

}

template<typename T>
template<typename U>
inline Vector2<T>::Vector2(const Vector2<U>& vector) :
	x(static_cast<T>(vector.x)),
	y(static_cast<T>(vector.y))
{
}

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

