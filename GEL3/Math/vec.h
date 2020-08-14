// - ------------------------------------------------------------------------------------------ - //
#ifndef __GEL_MATH_VEC_H__
#define __GEL_MATH_VEC_H__
// - ------------------------------------------------------------------------------------------ - //
#include "float.h"
// - ------------------------------------------------------------------------------------------ - //
#if !defined(_MSC_VER)
#ifndef VECTOR_EXTENSIONS
#define VECTOR_EXTENSIONS
#endif // VECTOR_EXTENSIONS //
#endif
// - ------------------------------------------------------------------------------------------ - //
// Vector Types //
// - ------------------------------------------------------------------------------------------ - //
#ifdef VECTOR_EXTENSIONS
	// Single Precision Float (32bit) //
	typedef float v2sf __attribute__ ((vector_size(8)));
	typedef float v4sf __attribute__ ((vector_size(16)));
	typedef float v8sf __attribute__ ((vector_size(32)));
	// Single Precision Integer (32bit) //
	typedef int v2si __attribute__ ((vector_size(8)));
	typedef int v4si __attribute__ ((vector_size(16)));
	typedef int v8si __attribute__ ((vector_size(32)));
	// Double Precision Float (64bit) //
	typedef double v2df __attribute__ ((vector_size(16)));
	typedef double v4df __attribute__ ((vector_size(32)));
	typedef double v8df __attribute__ ((vector_size(64)));
	// Double Precision Integer (64bit) //
	typedef long long v2di __attribute__ ((vector_size(16)));
	typedef long long v4di __attribute__ ((vector_size(32)));
	typedef long long v8di __attribute__ ((vector_size(64)));
	// Half Precision Integer (16bit) //
	typedef short v2hi __attribute__ ((vector_size(4)));
	typedef short v4hi __attribute__ ((vector_size(8)));
	typedef short v8hi __attribute__ ((vector_size(16)));
	// Quarter Precision Integer (8bit) //
	typedef char v2qi __attribute__ ((vector_size(2)));
	typedef char v4qi __attribute__ ((vector_size(4)));
	typedef char v8qi __attribute__ ((vector_size(8)));
#endif // VECTOR_EXTENSIONS //
// - ------------------------------------------------------------------------------------------ - //
// Array Versions, always arrays. Useful for hardcoded array type conversion. //
// - ------------------------------------------------------------------------------------------ - //
// Single Precision Float (32bit) //
typedef float a2sf[2];
typedef float a3sf[3];		// ** NON STANDARD (NPOT) ** //
typedef float a4sf[4];
typedef float a5sf[5];		// ** NON STANDARD (NPOT) ** //
typedef float a8sf[8];
// Single Precision Integer (32bit) //
typedef int a2si[2];
typedef int a3si[3];		// ** NON STANDARD (NPOT) ** //
typedef int a4si[4];
typedef int a5si[5];		// ** NON STANDARD (NPOT) ** //
typedef int a8si[8];
// Double Precision Float (64bit) //
typedef double a2df[2];
typedef double a3df[3];		// ** NON STANDARD (NPOT) ** //
typedef double a4df[4];
typedef double a5df[5];		// ** NON STANDARD (NPOT) ** //
typedef double a8df[8];
// Double Precision Integer (64bit) //
typedef long long a2di[2];
typedef long long a3di[3];	// ** NON STANDARD (NPOT) ** //
typedef long long a4di[4];
typedef long long a5di[5];	// ** NON STANDARD (NPOT) ** //
typedef long long a8di[8];
// Half Precision Integer (16bit) //
typedef short a2hi[2];
typedef short a3hi[3];		// ** NON STANDARD (NPOT) ** //
typedef short a4hi[4];
typedef short a5hi[5];		// ** NON STANDARD (NPOT) ** //
typedef short a8hi[8];
// Quarter Precision Integer (8bit) //
typedef char a2qi[2];
typedef char a3qi[3];		// ** NON STANDARD (NPOT) ** //
typedef char a4qi[4];
typedef char a5qi[5];		// ** NON STANDARD (NPOT) ** //
typedef char a8qi[8];
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// Style Guide: 
// - Underscored version (i.e. _vec2) is raw type, no constructor.
// - Derive from the Underscored version.
// - Always use Non-Underscored in code (unless you specifically need to union it)
// - Always return Non-Underscored
// - Always take Underscored as arguments.
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// 32bit FLOAT //
// - ------------------------------------------------------------------------------------------ - //
struct _vec2 {
	union {
		struct {
			float x,y;
		};
#ifdef VECTOR_EXTENSIONS
		v2sf v;
#endif // VECTOR_EXTENSIONS //
		a2sf a;
	};
};
struct vec2: public _vec2 {
	inline vec2(const float _x = 0.0f, const float _y = 0.0f) {
		x = _x;
		y = _y;
	}
	inline vec2(const _vec2& _v) {
		*((_vec2*)this) = _v;
	}
	inline vec2(const class _vec2i& _v);
#ifdef VECTOR_EXTENSIONS
	inline vec2(const v2sf& _v) {
		v = _v;
	}
#endif // VECTOR_EXTENSIONS //
	inline vec2(const a2sf& _a) {
		a[0] = _a[0];
		a[1] = _a[1];
	}
	inline operator _vec2&() {
		return *this;
	}
	inline operator const _vec2&() {
		return *this;
	}
};
// - ------------------------------------------------------------------------------------------ - //
struct _vec3 {
	union {
		struct {
			float x,y,z;
		};
		// There is no v3sf type. Vector types are powers-of-two only! //
		a3sf a;
	};
};
struct vec3: public _vec3 {
	inline vec3(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
	}
	inline vec3(const _vec2& v, const float _z = 0.0f) {
		x = v.x;
		y = v.y;
		z = _z;
	}
	inline vec3(const _vec3& _v) {
		*((_vec3*)this) = _v;
	}
	inline vec3(const class _vec3i& _v);
	inline vec3(const a3sf& _a) {
		a[0] = _a[0];
		a[1] = _a[1];
		a[2] = _a[2];
	}
	inline operator _vec3&() {
		return *this;
	}
	inline operator const _vec3&() {
		return *this;
	}
};
// - ------------------------------------------------------------------------------------------ - //
struct _vec4 {
	union {
		struct {
			float x,y,z,w;
		};
#ifdef VECTOR_EXTENSIONS
		v4sf v;
#endif // VECTOR_EXTENSIONS //
		a4sf a;
	};
};
struct vec4: public _vec4 {
	inline vec4(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f, const float _w = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
	inline vec4(const _vec2& v, const float _z = 0.0f, const float _w = 0.0f) {
		x = v.x;
		y = v.y;
		z = _z;
		w = _w;
	}
	inline vec4(const _vec2& v1, const _vec2& v2) {
		x = v1.x;
		y = v1.y;
		z = v2.x;
		w = v2.y;
	}
	inline vec4(const _vec3& v, const float _w = 0.0f) {
		x = v.x;
		y = v.y;
		z = v.z;
		w = _w;
	}
	inline vec4(const _vec4& _v) {
		*((_vec4*)this) = _v;
	}
	inline vec4(const class _vec4i& _v);
#ifdef VECTOR_EXTENSIONS
	inline vec4(const v4sf& _v) {
		v = _v;
	}
#endif // VECTOR_EXTENSIONS //
	inline vec4(const a4sf& _a) {
		a[0] = _a[0];
		a[1] = _a[1];
		a[2] = _a[2];
		a[3] = _a[3];
	}
	inline operator _vec4&() {
		return *this;
	}
	inline operator const _vec4&() {
		return *this;
	}
};
// - ------------------------------------------------------------------------------------------ - //
// 'vec' will be vec4's, because vec4 is ideal (SIMD capable) //
typedef _vec4 _vec;
typedef vec4 vec;
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// 32bit RADIUS FLOAT //
// - ------------------------------------------------------------------------------------------ - //
struct _vec2r {
	union {
		struct {
			float x,y;
			float r;
		};
		a3sf a;
	};
};
struct vec2r: public _vec2r {
	inline vec2r(const float _x = 0.0f, const float _y = 0.0f, const float _r = 0.0f) {
		x = _x;
		y = _y;
		r = _r;
	}
	inline vec2r(const _vec2& v, const float _r = 0.0f) {
		x = v.x;
		y = v.y;
		r = _r;
	}
	inline vec2r(const _vec2r& _v) {
		*((_vec2r*)this) = _v;
	}
	inline vec2r(const a3sf& _a) {
		a[0] = _a[0];
		a[1] = _a[1];
		a[2] = _a[2];
	}
	inline operator _vec2r&() {
		return *this;
	}
	inline operator const _vec2r&() {
		return *this;
	}
};
// - ------------------------------------------------------------------------------------------ - //
struct _vec3r {
	union {
		struct {
			float x,y,z;
			float r;
		};
#ifdef VECTOR_EXTENSIONS
		v4sf v;
#endif // VECTOR_EXTENSIONS //
		a4sf a;
	};
};
struct vec3r: public _vec3r {
	inline vec3r(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f, const float _r = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
	}
	inline vec3r(const _vec2r& v, const float _z = 0.0f) {
		x = v.x;
		y = v.y;
		z = _z;
		r = v.r;
	}
	inline vec3r(const _vec3& v, const float _r = 0.0f) {
		x = v.x;
		y = v.y;
		z = v.z;
		r = _r;
	}
	inline vec3r(const _vec3r& _v) {
		*((_vec3r*)this) = _v;
	}
#ifdef VECTOR_EXTENSIONS
	inline vec3r(const v4sf& _v) {
		v = _v;
	}
#endif // VECTOR_EXTENSIONS //
	inline vec3r(const a4sf& _a) {
		a[0] = _a[0];
		a[1] = _a[1];
		a[2] = _a[2];
		a[3] = _a[3];
	}
	inline operator _vec3r&() {
		return *this;
	}
	inline operator const _vec3r&() {
		return *this;
	}
};
// - ------------------------------------------------------------------------------------------ - //
// TODO: this //
//struct _vec4r {
//	union {
//		struct {
//			float x,y,z,w;
//			float r;
//		};
//		a5sf a;
//	};
//};
// - ------------------------------------------------------------------------------------------ - //
// 'vecr' will be vec3r's, because vec3 is ideal (SIMD capable) //
typedef _vec3r _vecr;
typedef vec3r vecr;
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// 32bit INTEGER //
// - ------------------------------------------------------------------------------------------ - //
struct _vec2i {
	union {
		struct {
			int x,y;
		};
#ifdef VECTOR_EXTENSIONS
		v2si v;
#endif // VECTOR_EXTENSIONS //
		a2si a;
	};
};
struct vec2i: public _vec2i {
	inline vec2i(const int _x = 0, const int _y = 0) {
		x = _x;
		y = _y;
	}
	inline vec2i(const _vec2i& _v) {
		*((_vec2i*)this) = _v;
	}
	inline vec2i(const class _vec2& _v);
#ifdef VECTOR_EXTENSIONS
	inline vec2i(const v2si& _v) {
		v = _v;
	}
#endif // VECTOR_EXTENSIONS //
	inline vec2i(const a2si& _a) {
		a[0] = _a[0];
		a[1] = _a[1];
	}
	inline operator _vec2i&() {
		return *this;
	}
	inline operator const _vec2i&() {
		return *this;
	}
};
// - ------------------------------------------------------------------------------------------ - //
struct _vec3i {
	union {
		struct {
			int x,y,z;
		};
		// There is no v3si type. Vector types are powers-of-two only! //
		a3si a;
	};
};
struct vec3i: public _vec3i {
	inline vec3i(const int _x = 0, const int _y = 0, const int _z = 0) {
		x = _x;
		y = _y;
		z = _z;
	}
	inline vec3i(const _vec2i& v, const int _z = 0) {
		x = v.x;
		y = v.y;
		z = _z;
	}
	inline vec3i(const _vec3i& _v) {
		*((_vec3i*)this) = _v;
	}
	inline vec3i(const class _vec3& _v);
	inline vec3i(const a3si& _a) {
		a[0] = _a[0];
		a[1] = _a[1];
		a[2] = _a[2];
	}
	inline operator _vec3i&() {
		return *this;
	}
	inline operator const _vec3i&() {
		return *this;
	}
};
// - ------------------------------------------------------------------------------------------ - //
struct _vec4i {
	union {
		struct {
			int x,y,z,w;
		};
#ifdef VECTOR_EXTENSIONS
		v4si v;
#endif // VECTOR_EXTENSIONS //
		a4si a;
	};
};
struct vec4i: public _vec4i {
	inline vec4i(const int _x = 0, const int _y = 0, const int _z = 0, const int _w = 0) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
	inline vec4i(const _vec2& v, const int _z = 0, const int _w = 0) {
		x = v.x;
		y = v.y;
		z = _z;
		w = _w;
	}
	inline vec4i(const _vec2& v1, const _vec2& v2) {
		x = v1.x;
		y = v1.y;
		z = v2.x;
		w = v2.y;
	}
	inline vec4i(const _vec3& v, const int _w = 0) {
		x = v.x;
		y = v.y;
		z = v.z;
		w = _w;
	}
	inline vec4i(const _vec4i& _v) {
		*((_vec4i*)this) = _v;
	}
	inline vec4i(const class _vec4& _v);
#ifdef VECTOR_EXTENSIONS
	inline vec4i(const v4si& _v) {
		v = _v;
	}
#endif // VECTOR_EXTENSIONS //
	inline vec4i(const a4si& _a) {
		a[0] = _a[0];
		a[1] = _a[1];
		a[2] = _a[2];
		a[3] = _a[3];
	}
	inline operator _vec4i&() {
		return *this;
	}
	inline operator const _vec4i&() {
		return *this;
	}
};
// - ------------------------------------------------------------------------------------------ - //
// 'veci' will be vec4i's, because vec4i is ideal (SIMD capable) //
typedef _vec4i _veci;
typedef vec4i veci;
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// Arithmetic Operators //
// - ------------------------------------------------------------------------------------------ - //
#define OPERATOR_2_COMPOUND( _TYPE, _SCALAR, _OP ) \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _TYPE& b ) { \
	a.a[0] _OP ## = b.a[0]; \
	a.a[1] _OP ## = b.a[1]; \
	return a; \
} \
inline _TYPE operator _OP ( _TYPE a, const _TYPE& b ) { \
	a _OP ## = b; \
	return a; \
} \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _SCALAR& b ) { \
	a.a[0] _OP ## = b; \
	a.a[1] _OP ## = b; \
	return a; \
} \
inline _TYPE operator _OP ( const _TYPE& a, const _SCALAR& b ) { \
	_TYPE ret; \
	ret.a[0] = a.a[0] _OP b; \
	ret.a[1] = a.a[1] _OP b; \
	return ret; \
} \
inline _TYPE operator _OP ( const _SCALAR& a, const _TYPE& b ) { \
	_TYPE ret; \
	ret.a[0] = a _OP b.a[0]; \
	ret.a[1] = a _OP b.a[1]; \
	return ret; \
}
// - ------------------------------------------------------------------------------------------ - //
#define OPERATOR_3_COMPOUND( _TYPE, _SCALAR, _OP ) \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _TYPE& b ) { \
	a.a[0] _OP ## = b.a[0]; \
	a.a[1] _OP ## = b.a[1]; \
	a.a[2] _OP ## = b.a[2]; \
	return a; \
} \
inline _TYPE operator _OP ( _TYPE a, const _TYPE& b ) { \
	a _OP ## = b; \
	return a; \
} \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _SCALAR& b ) { \
	a.a[0] _OP ## = b; \
	a.a[1] _OP ## = b; \
	a.a[2] _OP ## = b; \
	return a; \
} \
inline _TYPE operator _OP ( const _TYPE& a, const _SCALAR& b ) { \
	_TYPE ret; \
	ret.a[0] = a.a[0] _OP b; \
	ret.a[1] = a.a[1] _OP b; \
	ret.a[2] = a.a[2] _OP b; \
	return ret; \
} \
inline _TYPE operator _OP ( const _SCALAR& a, const _TYPE& b ) { \
	_TYPE ret; \
	ret.a[0] = a _OP b.a[0]; \
	ret.a[1] = a _OP b.a[1]; \
	ret.a[2] = a _OP b.a[2]; \
	return ret; \
}
// - ------------------------------------------------------------------------------------------ - //
#define OPERATOR_4_COMPOUND( _TYPE, _SCALAR, _OP ) \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _TYPE& b ) { \
	a.a[0] _OP ## = b.a[0]; \
	a.a[1] _OP ## = b.a[1]; \
	a.a[2] _OP ## = b.a[2]; \
	a.a[3] _OP ## = b.a[3]; \
	return a; \
} \
inline _TYPE operator _OP ( _TYPE a, const _TYPE& b ) { \
	a _OP ## = b; \
	return a; \
} \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _SCALAR& b ) { \
	a.a[0] _OP ## = b; \
	a.a[1] _OP ## = b; \
	a.a[2] _OP ## = b; \
	a.a[3] _OP ## = b; \
	return a; \
} \
inline _TYPE operator _OP ( const _TYPE& a, const _SCALAR& b ) { \
	_TYPE ret; \
	ret.a[0] = a.a[0] _OP b; \
	ret.a[1] = a.a[1] _OP b; \
	ret.a[2] = a.a[2] _OP b; \
	ret.a[3] = a.a[3] _OP b; \
	return ret; \
} \
inline _TYPE operator _OP ( const _SCALAR& a, const _TYPE& b ) { \
	_TYPE ret; \
	ret.a[0] = a _OP b.a[0]; \
	ret.a[1] = a _OP b.a[1]; \
	ret.a[2] = a _OP b.a[2]; \
	ret.a[3] = a _OP b.a[3]; \
	return ret; \
}
// - ------------------------------------------------------------------------------------------ - //
#define OPERATOR_5_COMPOUND( _TYPE, _SCALAR, _OP ) \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _TYPE& b ) { \
	a.a[0] _OP ## = b.a[0]; \
	a.a[1] _OP ## = b.a[1]; \
	a.a[2] _OP ## = b.a[2]; \
	a.a[3] _OP ## = b.a[3]; \
	a.a[4] _OP ## = b.a[4]; \
	return a; \
} \
inline _TYPE operator _OP ( _TYPE a, const _TYPE& b ) { \
	a _OP ## = b; \
	return a; \
} \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _SCALAR& b ) { \
	a.a[0] _OP ## = b; \
	a.a[1] _OP ## = b; \
	a.a[2] _OP ## = b; \
	a.a[3] _OP ## = b; \
	a.a[4] _OP ## = b; \
	return a; \
} \
inline _TYPE operator _OP ( const _TYPE& a, const _SCALAR& b ) { \
	_TYPE ret; \
	ret.a[0] = a.a[0] _OP b; \
	ret.a[1] = a.a[1] _OP b; \
	ret.a[2] = a.a[2] _OP b; \
	ret.a[3] = a.a[3] _OP b; \
	ret.a[4] = a.a[4] _OP b; \
	return ret; \
} \
inline _TYPE operator _OP ( const _SCALAR& a, const _TYPE& b ) { \
	_TYPE ret; \
	ret.a[0] = a _OP b.a[0]; \
	ret.a[1] = a _OP b.a[1]; \
	ret.a[2] = a _OP b.a[2]; \
	ret.a[3] = a _OP b.a[3]; \
	ret.a[4] = a _OP b.a[4]; \
	return ret; \
}
// - ------------------------------------------------------------------------------------------ - //
#define OPERATOR_V_COMPOUND( _TYPE, _SCALAR, _OP ) \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _TYPE& b ) { \
	a.v _OP ## = b.v; \
	return a; \
} \
inline _TYPE operator _OP ( _TYPE a, const _TYPE& b ) { \
	a _OP ## = b; \
	return a; \
} \
inline const _TYPE& operator _OP ## = ( _TYPE& a, const _SCALAR& b ) { \
	a.v _OP ## = b; \
	return a; \
} \
inline _TYPE operator _OP ( const _TYPE& a, const _SCALAR& b ) { \
	_TYPE ret; \
	ret.v = a.v _OP b; \
	return ret; \
} \
inline _TYPE operator _OP ( const _SCALAR& a, const _TYPE& b ) { \
	_TYPE ret; \
	ret.v = a _OP b.v; \
	return ret; \
}
// - ------------------------------------------------------------------------------------------ - //
// Component-wise Compare. Returns -1's on success, 0's on failure //
//#define OPERATOR_VEC_COMPARE( _TYPE, OP ) \
//inline _TYPE operator _OP ( _TYPE& a, const _TYPE& b ) { \
//	return a _OP b; \
//}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#ifdef VECTOR_EXTENSIONS
	// 32bit Float //
	OPERATOR_V_COMPOUND( _vec2, float, + )
	OPERATOR_V_COMPOUND( _vec2, float, - )
	OPERATOR_V_COMPOUND( _vec2, float, * )
	OPERATOR_V_COMPOUND( _vec2, float, / )
	OPERATOR_3_COMPOUND( _vec2r, float, + )
	OPERATOR_3_COMPOUND( _vec2r, float, - )
	OPERATOR_3_COMPOUND( _vec2r, float, * )
	OPERATOR_3_COMPOUND( _vec2r, float, / )
	
	OPERATOR_3_COMPOUND( _vec3, float, + )
	OPERATOR_3_COMPOUND( _vec3, float, - )
	OPERATOR_3_COMPOUND( _vec3, float, * )
	OPERATOR_3_COMPOUND( _vec3, float, / )
	OPERATOR_V_COMPOUND( _vec3r, float, + )
	OPERATOR_V_COMPOUND( _vec3r, float, - )
	OPERATOR_V_COMPOUND( _vec3r, float, * )
	OPERATOR_V_COMPOUND( _vec3r, float, / )
	
	OPERATOR_V_COMPOUND( _vec4, float, + )
	OPERATOR_V_COMPOUND( _vec4, float, - )
	OPERATOR_V_COMPOUND( _vec4, float, * )
	OPERATOR_V_COMPOUND( _vec4, float, / )
//	OPERATOR_5_COMPOUND( _vec4r, float, + )
//	OPERATOR_5_COMPOUND( _vec4r, float, - )
//	OPERATOR_5_COMPOUND( _vec4r, float, * )
//	OPERATOR_5_COMPOUND( _vec4r, float, / )
	
	// 32bit Integer //
	OPERATOR_V_COMPOUND( _vec2i, int, + )
	OPERATOR_V_COMPOUND( _vec2i, int, - )
	OPERATOR_V_COMPOUND( _vec2i, int, * )
	OPERATOR_V_COMPOUND( _vec2i, int, / )
	OPERATOR_V_COMPOUND( _vec2i, int, % )
	OPERATOR_V_COMPOUND( _vec2i, int, | )
	OPERATOR_V_COMPOUND( _vec2i, int, & )
	OPERATOR_V_COMPOUND( _vec2i, int, ^ )

	OPERATOR_3_COMPOUND( _vec3i, int, + )
	OPERATOR_3_COMPOUND( _vec3i, int, - )
	OPERATOR_3_COMPOUND( _vec3i, int, * )
	OPERATOR_3_COMPOUND( _vec3i, int, / )
	OPERATOR_3_COMPOUND( _vec3i, int, % )
	OPERATOR_3_COMPOUND( _vec3i, int, | )
	OPERATOR_3_COMPOUND( _vec3i, int, & )
	OPERATOR_3_COMPOUND( _vec3i, int, ^ )

	OPERATOR_V_COMPOUND( _vec4i, int, + )
	OPERATOR_V_COMPOUND( _vec4i, int, - )
	OPERATOR_V_COMPOUND( _vec4i, int, * )
	OPERATOR_V_COMPOUND( _vec4i, int, / )
	OPERATOR_V_COMPOUND( _vec4i, int, % )
	OPERATOR_V_COMPOUND( _vec4i, int, | )
	OPERATOR_V_COMPOUND( _vec4i, int, & )
	OPERATOR_V_COMPOUND( _vec4i, int, ^ )
#else // !VECTOR_EXTENSIONS
	// 32bit Float //
	OPERATOR_2_COMPOUND( _vec2, float, + )
	OPERATOR_2_COMPOUND( _vec2, float, - )
	OPERATOR_2_COMPOUND( _vec2, float, * )
	OPERATOR_2_COMPOUND( _vec2, float, / )
	OPERATOR_3_COMPOUND( _vec2r, float, + )
	OPERATOR_3_COMPOUND( _vec2r, float, - )
	OPERATOR_3_COMPOUND( _vec2r, float, * )
	OPERATOR_3_COMPOUND( _vec2r, float, / )
	
	OPERATOR_3_COMPOUND( _vec3, float, + )
	OPERATOR_3_COMPOUND( _vec3, float, - )
	OPERATOR_3_COMPOUND( _vec3, float, * )
	OPERATOR_3_COMPOUND( _vec3, float, / )
	OPERATOR_4_COMPOUND( _vec3r, float, + )
	OPERATOR_4_COMPOUND( _vec3r, float, - )
	OPERATOR_4_COMPOUND( _vec3r, float, * )
	OPERATOR_4_COMPOUND( _vec3r, float, / )
	
	OPERATOR_4_COMPOUND( _vec4, float, + )
	OPERATOR_4_COMPOUND( _vec4, float, - )
	OPERATOR_4_COMPOUND( _vec4, float, * )
	OPERATOR_4_COMPOUND( _vec4, float, / )
//	OPERATOR_5_COMPOUND( _vec4r, float, + )
//	OPERATOR_5_COMPOUND( _vec4r, float, - )
//	OPERATOR_5_COMPOUND( _vec4r, float, * )
//	OPERATOR_5_COMPOUND( _vec4r, float, / )
	
	// 32bit Integer //
	OPERATOR_2_COMPOUND( _vec2i, int, + )
	OPERATOR_2_COMPOUND( _vec2i, int, - )
	OPERATOR_2_COMPOUND( _vec2i, int, * )
	OPERATOR_2_COMPOUND( _vec2i, int, / )
	OPERATOR_2_COMPOUND( _vec2i, int, % )
	OPERATOR_2_COMPOUND( _vec2i, int, | )
	OPERATOR_2_COMPOUND( _vec2i, int, & )
	OPERATOR_2_COMPOUND( _vec2i, int, ^ )

	OPERATOR_3_COMPOUND( _vec3i, int, + )
	OPERATOR_3_COMPOUND( _vec3i, int, - )
	OPERATOR_3_COMPOUND( _vec3i, int, * )
	OPERATOR_3_COMPOUND( _vec3i, int, / )
	OPERATOR_3_COMPOUND( _vec3i, int, % )
	OPERATOR_3_COMPOUND( _vec3i, int, | )
	OPERATOR_3_COMPOUND( _vec3i, int, & )
	OPERATOR_3_COMPOUND( _vec3i, int, ^ )

	OPERATOR_4_COMPOUND( _vec4i, int, + )
	OPERATOR_4_COMPOUND( _vec4i, int, - )
	OPERATOR_4_COMPOUND( _vec4i, int, * )
	OPERATOR_4_COMPOUND( _vec4i, int, / )
	OPERATOR_4_COMPOUND( _vec4i, int, % )
	OPERATOR_4_COMPOUND( _vec4i, int, | )
	OPERATOR_4_COMPOUND( _vec4i, int, & )
	OPERATOR_4_COMPOUND( _vec4i, int, ^ )
#endif // VECTOR_EXTENSIONS //
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// Converting between Float and Integer Vector Types //
// - ------------------------------------------------------------------------------------------ - //
vec2::vec2(const class _vec2i& _v) {
	x = _v.x;
	y = _v.y;
}
// - ------------------------------------------------------------------------------------------ - //
vec3::vec3(const class _vec3i& _v) {
	x = _v.x;
	y = _v.y;
	z = _v.z;
}
// - ------------------------------------------------------------------------------------------ - //
vec4::vec4(const class _vec4i& _v) {
	x = _v.x;
	y = _v.y;
	z = _v.z;
	w = _v.w;
}
// - ------------------------------------------------------------------------------------------ - //
vec2i::vec2i(const class _vec2& _v) {
	x = _v.x;
	y = _v.y;
}
// - ------------------------------------------------------------------------------------------ - //
vec3i::vec3i(const class _vec3& _v) {
	x = _v.x;
	y = _v.y;
	z = _v.z;
}
// - ------------------------------------------------------------------------------------------ - //
vec4i::vec4i(const class _vec4& _v) {
	x = _v.x;
	y = _v.y;
	z = _v.z;
	w = _v.w;
}
// - ------------------------------------------------------------------------------------------ - //


// - -------------------------------------------------------------------------------------- - //
// Signal Conversion to/from [0,1] and [-1,+1] //
// - -------------------------------------------------------------------------------------- - //
// Expands a value from [0,1] to [-1,+1] //
inline vec2 expand(const _vec2& v) {
	return vec2(expand(v.x),expand(v.y));
}
inline vec3 expand(const _vec3& v) {
	return vec3(expand(v.x),expand(v.y),expand(v.z));
}
inline vec4 expand(const _vec4& v) {
	return vec4(expand(v.x),expand(v.y),expand(v.z),expand(v.w));
}
// - -------------------------------------------------------------------------------------- - //
// Compacts a value from [-1,+1] to [0,1] //
inline vec2 compact(const _vec2& v) {
	return vec2(compact(v.x),compact(v.y));
}
inline vec3 compact(const _vec3& v) {
	return vec3(compact(v.x),compact(v.y),compact(v.z));
}
inline vec4 compact(const _vec4& v) {
	return vec4(compact(v.x),compact(v.y),compact(v.z),compact(v.w));
}
// - -------------------------------------------------------------------------------------- - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __GEL_MATH_VEC_H__ //
// - ------------------------------------------------------------------------------------------ - //
