// - ------------------------------------------------------------------------------------------ - //
#ifndef __GEL_MATH_RECT_H__
#define __GEL_MATH_RECT_H__
// - ------------------------------------------------------------------------------------------ - //
// This is the NEW rectangle code. //
// - ------------------------------------------------------------------------------------------ - //
// rect2,rect3   - Standard Rectangles, AKA: Shape Rectangles. i.e. Position + Shape Vector (w,h,l).
// rect2r,rect3r - Radius Rectangles. i.e. Center Position + the Half-Shape (per axis Radius)
//   Pair Rectangles are obsolete, but a static function "pair" is available to construct them.
// rect2i,rect3i - Standard Integer Rectangle.
//   There are no rect2ir/rect3ir types. You can however construct a rectXi using ::radius.
// rectX::shape(...)  - Construct a rectangle using Shape syntax (Position and Shape)
// rectX::radius(...) - Construct a rectangle using Radius syntax (Position and Half-Shape)
// rectX::pair(...)   - Construct a rectangle using Pair syntax (Point1 and Point2)
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#include "vec.h"
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
// 32bit FLOAT: Standard Rectangle, i.e. a "Shape" rectangle //
struct _rect2 {
	union {
		struct {
			float x,y;			// Corner Position //
		};
		_vec2 p;				// Corner Position as a Vector //
	};
	union {
		struct {
			float w,h;			// Width and Height //
		};
		_vec2 s;				// Shape Vector //
	};
};
struct rect2: public _rect2 {
	inline rect2(const float _x = 0.0f, const float _y = 0.0f, const float _w = 0.0f, const float _h = 0.0f) {
		x = _x;
		y = _y;
		w = _w;
		h = _h;
	}
	inline rect2(const _vec2& v, const float _w = 0.0f, const float _h = 0.0f) {
		*this = rect2(v.x,v.y,_w,_h);
	}
	inline rect2(const _vec2& v, const _vec2& s) {
		*this = rect2(v.x,v.y,s.x,s.y);
	}
	inline rect2(const _rect2& _v) {
		*((_rect2*)this) = _v;
	}
	inline operator _rect2&() {
		return *this;
	}
	inline operator const _rect2&() {
		return *this;
	}
	
	// Construction Methods //
	inline static rect2 radius(const float _x = 0.0f, const float _y = 0.0f, const float _rx = 0.0f, const float _ry = 0.0f) {
		return rect2(_x-_rx,_y-_ry,_rx+_rx,_ry+_ry);
	}
	inline static rect2 radius(const _vec2& p, const _vec2& r) {
		return rect2(p.x-r.x,p.y-r.y, r.x+r.x,r.y+r.y);
	}
	
	inline static rect2 shape(const float px = 0.0f, const float py = 0.0f, const float sx = 0.0f, const float sy = 0.0f) {
		return rect2(px,py, sx,sy);
	}
	inline static rect2 shape(const _vec2& p, const _vec2& s) {
		return rect2(p.x,p.y, s.x,s.y);
	}
	
	inline static rect2 pair(const float p1x = 0.0f, const float p1y = 0.0f, const float p2x = 0.0f, const float p2y = 0.0f) {
		return rect2(min(p1x,p2x),min(p1y,p2y), max(p1x,p2x),max(p1y,p2y));
	}
	inline static rect2 pair(const _vec2& p1, const _vec2& p2) {
		return rect2(min(p1.x,p2.x),min(p1.y,p2.y), max(p1.x,p2.x),max(p1.y,p2.y));
	}
};
// - ------------------------------------------------------------------------------------------ - //
struct _rect3 {
	union {
		struct {
			float x,y,z;		// Corner Position //
		};
		_vec3 p;				// Corner Position as a Vector //
	};
	union {
		struct {
			float w,h,l;		// Width, Height, and Length //
		};
		_vec3 s;				// Shape Vector //
	};
};
struct rect3: public _rect3 {
	inline rect3(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f, const float _w = 0.0f, const float _h = 0.0f, const float _l = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
		h = _h;
		l = _l;
	}
	inline rect3(const _vec3& v, const float _w = 0.0f, const float _h = 0.0f, const float _l = 0.0f) {
		*this = rect3(v.x,v.y,v.z,_w,_h,_l);
	}
	inline rect3(const _vec3& v, const _vec3& s) {
		*this = rect3(v.x,v.y,v.z,s.x,s.y,s.z);
	}
	inline rect3(const _rect3& _v) {
		*((_rect3*)this) = _v;
	}
	inline operator _rect3&() {
		return *this;
	}
	inline operator const _rect3&() {
		return *this;
	}
	
	// Construction Methods //
	inline static rect3 radius(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f, const float _rx = 0.0f, const float _ry = 0.0f, const float _rz = 0.0f) {
		return rect3(_x-_rx,_y-_ry,_z-_rz, _rx+_rx,_ry+_ry,_rz+_rz);
	}
	inline static rect3 radius(const _vec3& p, const _vec3& r) {
		return rect3(p.x-r.x,p.y-r.y,p.z-r.z, r.x+r.x,r.y+r.y,r.z+r.z);
	}
	
	inline static rect3 shape(const float px = 0.0f, const float py = 0.0f, const float pz = 0.0f, const float sx = 0.0f, const float sy = 0.0f, const float sz = 0.0f) {
		return rect3(px,py,pz, sx,sy,sz);
	}
	inline static rect3 shape(const _vec3& p, const _vec3& s) {
		return rect3(p.x,p.y,p.z, s.x,s.y,s.z);
	}
	
	inline static rect3 pair(const float p1x = 0.0f, const float p1y = 0.0f, const float p1z = 0.0f, const float p2x = 0.0f, const float p2y = 0.0f, const float p2z = 0.0f) {
		return rect3(min(p1x,p2x),min(p1y,p2y),min(p1z,p2z), max(p1x,p2x),max(p1y,p2y),max(p1z,p2z));
	}
	inline static rect3 pair(const _vec3& p1, const _vec3& p2) {
		return rect3(min(p1.x,p2.x),min(p1.y,p2.y),min(p1.z,p2.z), max(p1.x,p2.x),max(p1.y,p2.y),max(p1.z,p2.z));
	}
};
// - ------------------------------------------------------------------------------------------ - //
// Radius Rectangle //
struct _rect2r {
	union {
		struct {
			float x,y;			// Center //
		};
		_vec2 p;				// (Center) Position //
	};
	union {
		struct {
			float rx,ry;		// Radius, NOT w/h!! //
		};
		_vec2 r;				// Radius (Half Shape) //
	};
};
struct rect2r: public _rect2r {
	inline rect2r(const float _x = 0.0f, const float _y = 0.0f, const float _rx = 0.0f, const float _ry = 0.0f) {
		x = _x;
		y = _y;
		rx = _rx;
		ry = _ry;
	}
	inline rect2r(const _rect2r& _v) {
		*((_rect2r*)this) = _v;
	}
	inline operator _rect2r&() {
		return *this;
	}
	inline operator const _rect2r&() {
		return *this;
	}
		
	// Construction Methods //
	inline static rect2r radius(const float _x = 0.0f, const float _y = 0.0f, const float _rx = 0.0f, const float _ry = 0.0f) {
		return rect2r(_x,_y,_rx,_ry);
	}
	inline static rect2r radius(const _vec2& p, const _vec2& r) {
		return rect2r(p.x,p.y, r.x,r.y);
	}
	
	inline static rect2r shape(const float px = 0.0f, const float py = 0.0f, const float sx = 0.0f, const float sy = 0.0f) {
		return rect2r(px-(sx*0.5f),py-(sy*0.5f), sx*0.5f,sy*0.5f);
	}
	inline static rect2r shape(const _vec2& p, const _vec2& s) {
		return rect2r(p.x-(s.x*0.5f),p.y-(s.y*0.5f), s.x*0.5f,s.y*0.5f);
	}
	
	inline static rect2r pair(const float p1x = 0.0f, const float p1y = 0.0f, const float p2x = 0.0f, const float p2y = 0.0f) {
		return shape(min(p1x,p2x),min(p1y,p2y), max(p1x,p2x),max(p1y,p2y));
	}
	inline static rect2r pair(const _vec2& p1, const _vec2& p2) {
		return shape(min(p1.x,p2.x),min(p1.y,p2.y), max(p1.x,p2.x),max(p1.y,p2.y));
	}
};
// - ------------------------------------------------------------------------------------------ - //
struct _rect3r {
	union {
		struct {
			float x,y,z;		// Center //
		};
		_vec3 p;				// (Center) Position //
	};
	union {
		struct {
			float rx,ry,rz;		// Radius, NOT w/h/l!! //
		};
		_vec3 r;				// Radius (Half Shape) //
	};
};
struct rect3r: public _rect3r {
	inline rect3r(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f, const float _rx = 0.0f, const float _ry = 0.0f, const float _rz = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
		rx = _rx;
		ry = _ry;
		rz = _rz;
	}
	inline rect3r(const _vec3& v, const float _rx = 0.0f, const float _ry = 0.0f, const float _rz = 0.0f) {
		*this = rect3r(v.x,v.y,v.z,_rx,_ry,_rz);
	}
	inline rect3r(const _vec3& v, const _vec3& s) {
		*this = rect3r(v.x,v.y,v.z,s.x,s.y,s.z);
	}
	inline rect3r(const _rect3r& _v) {
		*((_rect3r*)this) = _v;
	}
	inline operator _rect3r&() {
		return *this;
	}
	inline operator const _rect3r&() {
		return *this;
	}
	
	// Construction Methods //
	inline static rect3r radius(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f, const float _rx = 0.0f, const float _ry = 0.0f, const float _rz = 0.0f) {
		return rect3r(_x,_y,_z, _rx,_ry,_rz);
	}
	inline static rect3r radius(const _vec3& p, const _vec3& r) {
		return rect3r(p.x,p.y,p.z, r.x,r.y,r.z);
	}
	
	inline static rect3r shape(const float px = 0.0f, const float py = 0.0f, const float pz = 0.0f, const float sx = 0.0f, const float sy = 0.0f, const float sz = 0.0f) {
		return rect3r(px-(sx*0.5f),py-(sy*0.5f),pz-(sz*0.5f), sx*0.5f,sy*0.5f,sz*0.5f);
	}
	inline static rect3r shape(const _vec3& p, const _vec3& s) {
		return rect3r(p.x-(s.x*0.5f),p.y-(s.y*0.5f),p.z-(s.z*0.5f), s.x*0.5f,s.y*0.5f,s.z*0.5f);
	}
	
	inline static rect3r pair(const float p1x = 0.0f, const float p1y = 0.0f, const float p1z = 0.0f, const float p2x = 0.0f, const float p2y = 0.0f, const float p2z = 0.0f) {
		return shape(min(p1x,p2x),min(p1y,p2y),min(p1z,p2z), max(p1x,p2x),max(p1y,p2y),max(p1z,p2z));
	}
	inline static rect3r pair(const _vec3& p1, const _vec3& p2) {
		return shape(min(p1.x,p2.x),min(p1.y,p2.y),min(p1.z,p2.z), max(p1.x,p2.x),max(p1.y,p2.y),max(p1.z,p2.z));
	}
};
// - ------------------------------------------------------------------------------------------ - //


// - ------------------------------------------------------------------------------------------ - //
// 32bit INTEGER: Standard Rectangle, i.e. a "Shape" rectangle //
struct _rect2i {
	union {
		struct {
			int x,y;			// Corner Position //
		};
		_vec2i p;				// Corner Position as a Vector //
	};
	union {
		struct {
			int w,h;			// Width and Height //
		};
		_vec2i s;				// Shape Vector //
	};
};
struct rect2i: public _rect2i {
	inline rect2i(const int _x = 0, const int _y = 0, const int _w = 0, const int _h = 0) {
		x = _x;
		y = _y;
		w = _w;
		h = _h;
	}
	inline rect2i(const _vec2i& v, const int _w = 0, const int _h = 0) {
		*this = rect2i(v.x,v.y,_w,_h);
	}
	inline rect2i(const _vec2i& v, const _vec2i& s) {
		*this = rect2i(v.x,v.y,s.x,s.y);
	}
	inline rect2i(const _rect2i& _v) {
		*((_rect2i*)this) = _v;
	}
	inline operator _rect2i&() {
		return *this;
	}
	inline operator const _rect2i&() {
		return *this;
	}
	
	// Construction Methods //
	inline static rect2i radius(const int _x = 0, const int _y = 0, const int _rx = 0, const int _ry = 0) {
		return rect2i(_x-_rx,_y-_ry,_rx+_rx,_ry+_ry);
	}
	inline static rect2i radius(const _vec2i& p, const _vec2i& r) {
		return rect2i(p.x-r.x,p.y-r.y, r.x+r.x,r.y+r.y);
	}
	
	inline static rect2i shape(const int px = 0, const int py = 0, const int sx = 0, const int sy = 0) {
		return rect2i(px,py, sx,sy);
	}
	inline static rect2i shape(const _vec2i& p, const _vec2i& s) {
		return rect2i(p.x,p.y, s.x,s.y);
	}
	
	inline static rect2i pair(const int p1x = 0, const int p1y = 0, const int p2x = 0, const int p2y = 0) {
		return rect2i(min(p1x,p2x),min(p1y,p2y), max(p1x,p2x),max(p1y,p2y));
	}
	inline static rect2i pair(const _vec2i& p1, const _vec2i& p2) {
		return rect2i(min(p1.x,p2.x),min(p1.y,p2.y), max(p1.x,p2.x),max(p1.y,p2.y));
	}
};
// - ------------------------------------------------------------------------------------------ - //
struct _rect3i {
	union {
		struct {
			int x,y,z;			// Corner Position //
		};
		_vec3i p;				// Corner Position as a Vector //
	};
	union {
		struct {
			int w,h,l;			// Width, Height, and Length //
		};
		_vec3i s;				// Shape Vector //
	};
};
struct rect3i: public _rect3i {
	inline rect3i(const int _x = 0, const int _y = 0, const int _z = 0, const int _w = 0, const int _h = 0, const int _l = 0) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
		h = _h;
		l = _l;
	}
	inline rect3i(const _vec3i& v, const int _w = 0, const int _h = 0, const int _l = 0) {
		*this = rect3i(v.x,v.y,v.z,_w,_h,_l);
	}
	inline rect3i(const _vec3i& v, const _vec3i& s) {
		*this = rect3i(v.x,v.y,v.z,s.x,s.y,s.z);
	}
	inline rect3i(const _rect3i& _v) {
		*((_rect3i*)this) = _v;
	}
	inline operator _rect3i&() {
		return *this;
	}
	inline operator const _rect3i&() {
		return *this;
	}
	
	// Construction Methods //
	inline static rect3i radius(const int _x = 0, const int _y = 0, const int _z = 0, const int _rx = 0, const int _ry = 0, const int _rz = 0) {
		return rect3i(_x-_rx,_y-_ry,_z-_rz, _rx+_rx,_ry+_ry,_rz+_rz);
	}
	inline static rect3i radius(const _vec3i& p, const _vec3i& r) {
		return rect3i(p.x-r.x,p.y-r.y,p.z-r.z, r.x+r.x,r.y+r.y,r.z+r.z);
	}
	
	inline static rect3i shape(const int px = 0, const int py = 0, const int pz = 0, const int sx = 0, const int sy = 0, const int sz = 0) {
		return rect3i(px,py,pz, sx,sy,sz);
	}
	inline static rect3i shape(const _vec3i& p, const _vec3i& s) {
		return rect3i(p.x,p.y,p.z, s.x,s.y,s.z);
	}
	
	inline static rect3i pair(const int p1x = 0, const int p1y = 0, const int p1z = 0, const int p2x = 0, const int p2y = 0, const int p2z = 0) {
		return rect3i(min(p1x,p2x),min(p1y,p2y),min(p1z,p2z), max(p1x,p2x),max(p1y,p2y),max(p1z,p2z));
	}
	inline static rect3i pair(const _vec3i& p1, const _vec3i& p2) {
		return rect3i(min(p1.x,p2.x),min(p1.y,p2.y),min(p1.z,p2.z), max(p1.x,p2.x),max(p1.y,p2.y),max(p1.z,p2.z));
	}
};
// - ------------------------------------------------------------------------------------------ - //
#endif // __GEL_MATH_RECT_H__ //
// - ------------------------------------------------------------------------------------------ - //
