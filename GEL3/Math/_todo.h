// TODO: Upgrade vector code, start using GLSL compatible names.
// ************************************************************************* //
// vec2, vec3, vec4 - Float vectors (x,y,z,w)
// vec - Macro that generates the correct type based on number of inputs

// vec2i, vec3i, vec4i - Integer vectors
// veci - Macro that generates the correct type based on number of inputs

// rect2, rect3 - Float Rectangles (x,y,z,w,h,l)
// rect2i, rect3i - Integer Rectangles

// mat2, mat3, mat4 - Float Matrix

// quat - Quaternion


// vec2r, vec3r, vec4r - Float vectors with Radius (x,y,z,w,r) (i.e. center and radius)
// vec2ir, vec3ir, vec4ir - Integer vectors with Radius

// rect2r, rect3r - Radius Rectangles (x,y,z,rx,ry,rz) (i.e. center and radius)
// rect2ir, rect3ir - Integer Radius Rectangles

// Pair Rectangles are not needed. Rect types can take a pair of points as inputs instead.


// NEW: Rectangles should effectively be Vectors with dimensions, especially Radius versions.


// vec2d, vec3d, vec4d - Double precision Vectors **
// vec2l, vec3l, vec4l - 64bit Integer Vectors **
// etc...

// fp - 32bit Floating Point Type (16.16)
// vec2fp, vec3fp, vec4fp - Floating Point Vectors **
// fp16 - 16bit Floating Point Type (8.8)
// etc...

// NOTE: C++ will never get a builtin 16bit floating point type (FP16), hence this is safe
