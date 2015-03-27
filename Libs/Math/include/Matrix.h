#ifndef ENGINE_MATH_MATRIX_H
#define ENGINE_MATH_MATRIX_H

// SIMD includes
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Enum.h"
#include "Vect.h"



class Matrix
{
public:
	Matrix();
    ~Matrix();
    Matrix (const float _m0, const float _m1, const float _m2, const float _m3, 
            const float _m4, const float _m5, const float _m6, const float _m7, 
            const float _m8, const float _m9, const float _m10, const float _m11, 
            const float _m12, const float _m13, const float _m14, const float _m15);
    Matrix (const Vect &_v0, const Vect &_v1, const Vect &_v2, const Vect &_v3);
    Matrix (const MatrixSpecialType type);
    Matrix (const MatrixTransType type, const float x, const float y, const float z);
    Matrix (const MatrixScaleType type, const float x, const float y, const float z);
    Matrix (const RotType type, const float angle);

    const void set (const Vect & V0, const Vect & V1, const Vect & V2, const Vect & V3);
    const void set (const MatrixSpecialType type);
    const void set (const MatrixTransType type, const float x, const float y, const float z);
    const void set (const MatrixScaleType type, const float x, const float y, const float z);
    const void set (const RotType type, const float angle);
    const void set (const MatrixRowType, const Vect & V);
    const Vect get (const MatrixRowType type) const;

    const float det(void) const;
    Matrix T(void);
    Matrix getT(void);
    const Matrix inv (void);
    Matrix getInv(void);
    const Matrix adj(void);

    const bool isEqual (Matrix & M, const float epsilon = MATH_TOLERANCE);
    const bool isIdentity (const float epsilon = MATH_TOLERANCE);
    
    const Matrix & operator = (const Matrix &M);

    const Matrix operator + (void) const;
    const Matrix operator - (void) const;

    const Matrix operator + (const Matrix & M) const;
    const Matrix &operator += (const Matrix & M);

    const Matrix operator - (const Matrix & M) const;
    const Matrix &operator -= (const Matrix & M);

    const Matrix operator * (const Matrix & M) const;
    const Matrix &operator *= (const Matrix & M);

    const Matrix operator * (const float scale) const;
    const Matrix &operator *= (const float scale);
    friend Matrix operator * (const float scale, const Matrix &M );

    float &operator[] (const enum m0_enum );
    float &operator[] (const enum m1_enum );
    float &operator[] (const enum m2_enum );
    float &operator[] (const enum m3_enum );	
    float &operator[] (const enum m4_enum );	
    float &operator[] (const enum m5_enum );	
    float &operator[] (const enum m6_enum );	
    float &operator[] (const enum m7_enum );	
    float &operator[] (const enum m8_enum );	
    float &operator[] (const enum m9_enum );	
    float &operator[] (const enum m10_enum );	
    float &operator[] (const enum m11_enum );	
    float &operator[] (const enum m12_enum );	
    float &operator[] (const enum m13_enum );	
    float &operator[] (const enum m14_enum );	
    float &operator[] (const enum m15_enum );

    const float operator[] (const enum m0_enum ) const;
    const float operator[] (const enum m1_enum ) const;	
    const float operator[] (const enum m2_enum ) const;	
    const float operator[] (const enum m3_enum ) const;	
    const float operator[] (const enum m4_enum ) const;	
    const float operator[] (const enum m5_enum ) const;	
    const float operator[] (const enum m6_enum ) const;	
    const float operator[] (const enum m7_enum ) const;	
    const float operator[] (const enum m8_enum ) const;
    const float operator[] (const enum m9_enum ) const;	
    const float operator[] (const enum m10_enum ) const;	
    const float operator[] (const enum m11_enum ) const;	
    const float operator[] (const enum m12_enum ) const;	
    const float operator[] (const enum m13_enum ) const;	
    const float operator[] (const enum m14_enum ) const;	
    const float operator[] (const enum m15_enum ) const;

private:

// Level 4 complains nameless struct/union ...
#pragma warning( disable : 4201)

union 
		{
		struct 
			{
			Vect v0;
			Vect v1;
			Vect v2;
			Vect v3;
			};

		struct 
			{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;	
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
			};
		};
};

#endif