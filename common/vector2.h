#ifndef VECTOR2_H
#define VECTOR2_H

#include <common/config.h>
#include <math.h>

class Vector2 {
public:
	Vector2(float _x = 0.0f, float _y = 0.0f);
	virtual ~Vector2();

	float x;
	float y;

	void devide(float f);

	void distance(Vector2 begin, Vector2 end);

	void setposition(Vector2* p);

	float getLength();

	float getLengthSquared();

	float getAngleDeg();

	void normalize();

	void rotate(float angle);

	void rotation(float angle);

	float magnitude() {return sqrt((x * x) + (y * y));}

    float getAngle() {return atan2(y, x) * RADTODEG;}

	void limit(float value);

	Vector2& operator+= (const Vector2& vec);
	Vector2& operator+= (const float vec);

	Vector2& operator-= (const Vector2& vec);
	Vector2& operator-= (const float vec);

	Vector2& operator/= (const Vector2& vec);
	Vector2& operator/= (const float vec);

	Vector2& operator*= (const Vector2& vec);
	Vector2& operator*= (const float vec);

	Vector2 operator+ (const Vector2& vec);
	Vector2 operator+ (const float vec);

	Vector2 operator- (const Vector2& vec);
	Vector2 operator- (const float vec);

	Vector2 operator* (const Vector2& vec);
	Vector2 operator* (const float vec);

	Vector2 operator/ (const Vector2& vec);
	Vector2 operator/ (const float vec);

	bool operator== (const Vector2& vec);
	bool operator!= (const Vector2& vec);

private:

};

#endif
