#ifndef ENGINE_MATH_VECT_H
#define ENGINE_MATH_VECT_H

// Includes to handle SIMD register types
#include <xmmintrin.h>
#include <smmintrin.h> 
#include "Constants.h"
// forward declare
class Matrix;

class Vect
{
public:

    Vect();
    ~Vect();
    Vect(float _x, float _y, float _z);
    Vect(float _x, float _y, float _z, float _w);
    Vect(const Vect &V);

    const void set (const float _x, const float _y, const float _z, const float _w = 1.0f);
    const void set (const Vect &V);

    const float dot (const Vect &V) const;
    const Vect cross (const Vect &V) const;
    const void norm (void);
    const Vect getNorm(void);
    const float mag (void) const;
    const float magSqr (void) const;
    const float getAngle (const Vect &V) const;

    bool isEqual(const Vect &V, const float epsilon = MATH_TOLERANCE) const;
    bool isZero(const float epsilon = MATH_TOLERANCE) const;

    const Vect & operator = (const Vect &V);

    const Vect operator + (void) const;
    const Vect operator - (void) const;

    const Vect operator + (const Vect &V) const;
    const Vect &operator += (const Vect &V);

    const Vect operator - (const Vect &V) const;
    const Vect &operator -= (const Vect &V);

    const Vect operator * (const float scale) const;
    const Vect &operator *= (const float scale);
    friend Vect operator * (const float scale, const Vect &V );

    const Vect operator * (const Matrix &M ) const;
    const Vect operator *= (const Matrix &M );

    float &operator[] (const enum x_enum);
    float &operator[] (const enum y_enum);
    float &operator[] (const enum z_enum);
    float &operator[] (const enum w_enum);

    const float operator[] (const enum x_enum ) const;
    const float operator[] (const enum y_enum ) const;
    const float operator[] (const enum z_enum ) const;
    const float operator[] (const enum w_enum ) const;

private:

// Level 4 complains nameless struct/union ...
#pragma warning( disable : 4201)
	// anonymous union
	union 
	{
		__m128	m;

		// anonymous struct
		struct 
			{
			float x;
			float y;
			float z;
			float w;
			};
	};


};


#endif