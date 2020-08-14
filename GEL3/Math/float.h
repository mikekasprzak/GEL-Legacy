// - ------------------------------------------------------------------------------------------ - //
#ifndef __GEL_MATH_FLOAT_H__
#define __GEL_MATH_FLOAT_H__
// - ------------------------------------------------------------------------------------------ - //
namespace Float {
	extern float Identity;
//	extern float Zero;
//	extern float One;
//	extern float Two;
//	extern float Three;
//	extern float Four;
//	extern float Eight;
//	extern float Half;
//	extern float Quarter;
//	extern float ThreeQuarter;
//	extern float Eighth;
//	extern float Sixteenth;
	extern float SmallestUnit;

//	extern float Pi;
//	extern float TwoPi;
//	extern float HalfPi;
//	extern float QuarterPi;
//	extern float InvPi;
//	extern float InvTwoPi;
//	extern float InvHalfPi;
//	extern float InvQuarterPi;

//	extern float e;					// Euler's Number/Napier's Constant. Used in Natural Logarithms (log)

//	extern float Sine0;				// Precomputed value of a 0 degree angle //
//	extern float Sine45;			// Precomputed value of a 45 degree angle //
//	extern float Sine90;			// Precomputed value of a 90 degree angle //

//	extern float Cosine0;			// Precomputed value of a 0 degree angle //
//	extern float Cosine45;			// Precomputed value of a 45 degree angle //
//	extern float Cosine90;			// Precomputed value of a 90 degree angle //
};
// - ------------------------------------------------------------------------------------------ - //


// - -------------------------------------------------------------------------------------- - //
inline float normalize(float& x) {
	if ( x > 0.0f )
		x = 1.0f;
	else if ( x < 0.0f )
		x = -1.0f;
	else
		x = 0.0f;
		
	return x;
}
// - -------------------------------------------------------------------------------------- - //
// Variation of Normalize that returns the Magnitude after calculating the normalized vector //
inline float normalizeret(float& x) {
	float Temp = x;
	if ( x > 0.0f ) {
		x = 1.0f;
	}
	else if ( x < 0.0f ) {
		x = -1.0f;
		return -Temp;
	}
	else {
		x = 0.0f;
	}
	return Temp;
}	
// - -------------------------------------------------------------------------------------- - //
// Variation of Normalize that only returns the normal //
inline float normal(const float x) {
	if ( x > 0.0f )
		return 1.0f;
	else if ( x < 0.0f )
		return -1.0f;
	return 0.0f;
}
// - -------------------------------------------------------------------------------------- - //
// The length of a vector //
inline float magnitude(const float x) {
	return abs(x);
}
// - -------------------------------------------------------------------------------------- - //
// The squared length of a vector //
inline float magnitudesquared(const float x) {
	return x * x;
}
// - -------------------------------------------------------------------------------------- - //
// The sum of all absolute value parts //
inline float manhattan(const float x) {
	return abs(x);
}
// - -------------------------------------------------------------------------------------- - //
// No Dot or Cross, as their's not enough axis for tangents //
// - -------------------------------------------------------------------------------------- - //

//// - -------------------------------------------------------------------------------------- - //
//// Square Root //
//inline float Sqrt(const float x) {
//	if ( iszero(x) )
//		return 0.0f;
//	else
//		return sqrt( x ));
//}
//// - -------------------------------------------------------------------------------------- - //
//// Square Root //
//inline float Sqrt_(const float x) {
//	return (sqrt( x ));
//}
//// - -------------------------------------------------------------------------------------- - //

// - -------------------------------------------------------------------------------------- - //
// Signal Conversion to/from [0,1] and [-1,+1] //
// - -------------------------------------------------------------------------------------- - //
// Expands a value from [0,1] to [-1,+1] //
inline float expand(const float x) {
	return (x * 2.0f) - 1.0f;
}
// - -------------------------------------------------------------------------------------- - //
// Compacts a value from [-1,+1] to [0,1] //
inline float compact(const float x) {
	return (x * 0.5f) + 0.5f;
}
// - -------------------------------------------------------------------------------------- - //

// - -------------------------------------------------------------------------------------- - //
// Simple Math //
// - -------------------------------------------------------------------------------------- - //
// Half the value //
inline float half(const float x) {
	return x * 0.5f;
}
// - -------------------------------------------------------------------------------------- - //
// Third the value //
inline float third(const float x) {
	return x * (1.0f/3.0f);
}
// - -------------------------------------------------------------------------------------- - //
// Two-Third the value //
inline float twothird(const float x) {
	return x * (2.0f/3.0f);
}
// - -------------------------------------------------------------------------------------- - //
// Quarter the value //
inline float quarter(const float x) {
	return x * 0.25f;
}
// - -------------------------------------------------------------------------------------- - //
// Three-Quarter the value //
inline float threequarter(const float x) {
	return x * 0.75f;
}
// - -------------------------------------------------------------------------------------- - //
// Power of Two - Square (sqr) //
inline float pow2(const float x) {
	return x * x;
}
// - -------------------------------------------------------------------------------------- - //
// Power of Three - Cube (cube) //
inline float pow3(const float x) {
	return x * x * x;
}
// - -------------------------------------------------------------------------------------- - //

// - -------------------------------------------------------------------------------------- - //
// LOGARITHM NOTES //
//   10^x (TenPowX) is a significant quantity when dealing with logarithms. //
//   10^2 = 100, Log(100) = 2. 10^3 = 1000, Log(1000) = 3. //
//   The "10" represents the base of the number system.
//   C standard library has a log10() function for doing this (Common Base-10).
//   C standard also has log() function (Neutral Base-E). "Inverse of the Natural Exponent Func"
//   It is related to the exp() function (Base-E Exponent)... which is not the same thing as pow()
//   The "ln" is the natural logarithm function on the calculator!!
//   To calculate Log2(n) (Binary Logarithm), do either ln(n)/ln(2) or log10(n)/log10(2) //
//   e is a mathematical constant. It's where, after smartness, the logarithm base intersects 1.
//   e is Napier's Constant or Euler's Number, not to be confused with Euler's Constant.
//   http://en.wikipedia.org/wiki/E_%28mathematical_constant%29
//
//   [Base 2] Binary Logarithm  -- No Function, but can be calculated with func(n)/func(2)
//   [Base e] Natural Logarithm -- log(n) in C, ln(n) on Calculator. e is Euler's Number.
//   [Base 10] Common Logarithm -- log10(n) in C, log(n) on Calculator. Paired with 10^x.
// - -------------------------------------------------------------------------------------- - //

// - -------------------------------------------------------------------------------------- - //
// Power functions to contrast the various logarithm bases //
// - -------------------------------------------------------------------------------------- - //
//inline float pow2(const float x) {
//	return (pow( 2, x ));
//}
// - -------------------------------------------------------------------------------------- - //
inline float pown(const float x) { 	// n = Natural //
	return (exp( x ));
}
// - -------------------------------------------------------------------------------------- - //
inline float pow8(const float x) {
	return (pow( 8, x ));
}
// - -------------------------------------------------------------------------------------- - //
inline float pow10(const float x) {
	return (pow( 10, x ));
}
// - -------------------------------------------------------------------------------------- - //
inline float pow16(const float x) {
	return (pow( 16, x ));
}
// - -------------------------------------------------------------------------------------- - //

// - -------------------------------------------------------------------------------------- - //
// I'm assuming "log10" is the faster logarithm function. If wrong, make it log. 
// - -------------------------------------------------------------------------------------- - //
inline float log2(const float x) {	// Built in to C++11 //
	return ((float)log10( x ) * (float)log10( 2.0f ));
}
// - -------------------------------------------------------------------------------------- - //
inline float logn(const float x) {	// n = Natural, Built in to C++11 (log1p = 1+x) //
	return (log( x ));
}
// - -------------------------------------------------------------------------------------- - //
inline float log8(const float x) {
	return ((float)log10( x ) * (float)log10( 8.0f ));
}
// - -------------------------------------------------------------------------------------- - //
//inline float log10(const float x) {
//	return (log10( x ));
//}
// - -------------------------------------------------------------------------------------- - //
inline float log16(const float x) {
	return ((float)log10( x ) * (float)log10( 16.0f ));
}
// - -------------------------------------------------------------------------------------- - //

//	// - -------------------------------------------------------------------------------------- - //
//	// Sine - Input *[0,1] -- Output *[-1,+1] //
//	inline const Real Sin() const {
//		return Real(sin( (*this * Real::TwoPi).x ));
//	}	
//	// - -------------------------------------------------------------------------------------- - //
//	// Cosine - Input *[0,1] -- Output *[-1,+1] //
//	inline const Real Cos() const {
//		return Real(cos( (*this * Real::TwoPi).x ));
//	}	
//	// - -------------------------------------------------------------------------------------- - //
//	// ArcSine and ArcCosine are only partial inverses of Sine and Cosine. They are non-repeating.
//	// They are used to partially get the curve of Sine and Cosine but about the opposite axis.
//	// They are NOT full waves, despite the input of two iterations [-1,+1], you get two halfs. //
//	// - -------------------------------------------------------------------------------------- - //
//	// ArcSine - Input [-1,+1] -- Output [-.5,+.5]
//	inline const Real ArcSin() const {
//		return Real(asin( x )) * Real::InvPi;// / Real::Pi; // Optimization //
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// ArcCosine - Input [-1,+1] -- Output [0,1]
//	inline const Real ArcCos() const {
//		return Real(acos( x )) * Real::InvPi;// / Real::Pi; // Optimization //
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	
//	// TODO: Update these //
//	// TODO: Add Cotangent, Secant, Cosecant... all are weird-ass waveforms like Tangent //
//	// TODO: Add Hyperbolic functions (sinh, cosh)... though they're also weird-ass like Tangent //
//	// - -------------------------------------------------------------------------------------- - //
//	// Tangent - Input *[0,1] -- Output *[-?,+?] //
//	inline const Real Tan() const {
//		return Real(tan( (*this * Real::TwoPi).x ));
//	}	
//	// - -------------------------------------------------------------------------------------- - //
//	// Arc Tangent - Input *[0,1] -- Output *[-?,+?] //
//	inline const Real ArcTan() const {
//		return Real(atan( (*this * Real::TwoPi).x ));
//	}	
//	// - -------------------------------------------------------------------------------------- - //
//	// ArcTan2 (atan2) can be found outside, since it takes 2 arguments (y,x) //
//	// - -------------------------------------------------------------------------------------- - //
//
//	// - -------------------------------------------------------------------------------------- - //
//	// SawTooth Wave  /| /|
//	//               / |/ | -- 2 periods shown - Input *[0,1] -- Output *[0,1]
//	inline const Real SawTooth() const {
//		return *this - Floor(*this);
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Inverse SawTooth Wave |\ |\																  //
//	//                       | \| \ -- 2 periods shown -- Input *[0,1] -- Output *[0,1]
//	inline const Real InvSawTooth() const {
//		return Real::One - SawTooth();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Triangle Wave  /\  /\																	  //
//	//               /  \/  \ -- 2 periods shown -- Input *[0,1] -- Output *[0,1]
//	inline const Real Triangle() const {
//		Real Period = SawTooth() * Real::Two; // Get a 0-2 range //
//		
//		if ( Period >= Real::One )
//			return Period.InvSawTooth(); // Period 1-2 goes down //
//		else
//			return Period.SawTooth();    // Period 0-1 goes up //
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Inverse Triangle Wave \  /\  /
//	//                        \/  \/  -- 2 periods shown -- Input *[0,1] -- Output *[0,1]
//	inline const Real InvTriangle() const {
//		return Real::One - Triangle();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Square Wave  |-| |-    This is different than clamping. You may want that instead.
//	//             _| |_|  -- 2 periods shown -- Input *[0,1] -- Output *[0,1]
//	inline const Real Square() const {
//		return SawTooth().Round();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Inverse Square Wave -| |-| 
//	//                      |_| |_ -- 2 periods shown -- Input *[0,1] -- Output *[0,1]
//	inline const Real InvSquare() const {
//		return Real::One - Square();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//
//	// - -------------------------------------------------------------------------------------- - //
//	// Circle Wave -- Input *[0,1] -- Output *[0,1]
//	inline const Real Circle() const {
//		return CalcHalf().Sin().Abs();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Inverse Circle Wave -- Input *[0,1] -- Output *[0,1]
//	inline const Real InvCircle() const {
//		return Real::One - Circle();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Cosine Circle Wave -- Input *[0,1] -- Output *[0,1]
//	inline const Real CoCircle() const {
//		return CalcHalf().Cos().Abs();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Inverse Cosine Circle Wave -- Input *[0,1] -- Output *[0,1]
//	inline const Real InvCoCircle() const {
//		return Real::One - CoCircle();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//
//	// TODO: Figure out which of these are Ease In's and Ease Out's //
//	// - -------------------------------------------------------------------------------------- - //
//	// Circle Tooth Wave -- Input *[0,1] -- Output *[0,1]
//	inline const Real CircleTooth() const {
//		return SawTooth().CalcQuarter().Sin().Abs();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Inverse Circle Tooth Wave -- Input *[0,1] -- Output *[0,1]
//	inline const Real InvCircleTooth() const {
//		return Real::One - CircleTooth();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Cosine Circle Tooth Wave -- Input *[0,1] -- Output *[0,1]
//	inline const Real CoCircleTooth() const {
//		return SawTooth().CalcQuarter().Cos().Abs();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Inverse Cosine Circle Tooth Wave -- Input *[0,1] -- Output *[0,1]
//	inline const Real InvCoCircleTooth() const {
//		return Real::One - CoCircleTooth();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//
//
//	// - -------------------------------------------------------------------------------------- - //
//	// Sine and Cosine family waveform functions //
//	// NOTE: Sine and Cosine family functions lack Inverse functions, but can flip the waveform 
//	//       by simply negating the returned value!
//	// - -------------------------------------------------------------------------------------- - //
//	// Sine Triangle Wave /\  /\      Starts at 0 following a rigid wave similar to Sine.
//	//                      \/  \/ -- 2 periods shown -- Input *[0,1] -- Output *[-1,+1]
//	inline const Real SinTriangle() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(3) )
//			return Period - Real(3+1); // Period 3-4 starts at -1 and goes up //
//		else if ( Period >= Real(1) )
//			return Real::One - (Period - Real(1)); // Periods 1-2 and 2-3 go the same way //
//		else
//			return Period; // Period 0-1 is the same as a SawTooth //
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Cosine Triangle Wave \  /\  /    Similar to InvTriangle(), except with negative ranges.
//	//                       \/  \/  -- 2 periods shown -- Input *[0,1] -- Output *[-1,+1]
//	inline const Real CosTriangle() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(2) )
//			return Period - Real(2+1); // Periods 2-3 and 3-4 start at -1 and go the same way //
//		else
//			return Real::One - Period; // Periods 0-1 and 1-2 start at +1 and go the same way //
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Sine Square Wave _|-|_   _|-|_ 
//	//                       |_|     |_| -- 2 periods shown -- Input *[0,1] -- Output *[-1,+1]
//	inline const Real SinSquare() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(3) )
//			return -Period.InvSquare();
//		else if ( Period >= Real(2) )
//			return -Period.Square();
//		else if ( Period >= Real(1) )
//			return Period.InvSquare();
//		else
//			return Period.Square();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Cosine Square Wave -|_   _|-|_   _|
//	//                       |_|     |_|   -- 2 periods shown -- Input *[0,1] -- Output *[-1,+1]
//	inline const Real CosSquare() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(3) )
//			return Period.Square();
//		else if ( Period >= Real(2) )
//			return -Period.InvSquare();
//		else if ( Period >= Real(1) )
//			return -Period.Square();
//		else
//			return Period.InvSquare();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Sine Saw Tooth Wave /| /|     Different from SinTriangle(). Ups take 2x as long, then drop.
//	//                      |/ |/ -- 2 periods shown -- Input *[0,1] -- Output *[-1,+1]
//	inline const Real SinSawTooth() const {
//		Real Period = SawTooth() * Real(2); // Get a 0-2 range //
//		
//		if ( Period >= Real(1) )
//			return Period.SawTooth() - Real::One;
//		else
//			return Period.SawTooth();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Cosine Saw Tooth Wave '| /| ,    *NOTE* WEIRD! A slightly forward offset SinSawTooth()
//	//                        |/ |/  -- 2 periods shown -- Input *[0,1] -- Output *[-1,+1]
//	inline const Real CosSawTooth() const {
//		return Real( *this + Real::Quarter ).SinSawTooth();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Sine Tooth Wave  /| /|    Since true CosSawTooth is strange, this is what you expect.
//	//                 / |/ | -- 2 periods shown -- Input *[0,1] -- Output *[-1,+1]
//	inline const Real SinTooth() const {
//		return SawTooth().Expand();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Cosine Tooth Wave  /| /|     *NOTE* WEIRD! A slightly forward offset SinTooth()
//	//                   ' |/ |, -- 2 periods shown -- Input *[0,1] -- Output *[-1,+1]
//	inline const Real CosTooth() const {
//		return Real( *this + Real::Quarter ).SinTooth();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	
//	// - -------------------------------------------------------------------------------------- - //
//	// Pulse Waves -- Waveforms with a controllable HalfPeriod, which is the midpoint of the waveform //
//	// - -------------------------------------------------------------------------------------- - //
//	// Triangle Pulse Wave  /\  /\  															  //
//	//                     /  \/  \ -- 2 periods shown -- Input *[0,1] -- Output *[0,1]
//	// A period of 0 and 1 return a Sawtooth like curve //
//	inline const Real TrianglePulse( const Real& HalfPeriod = Real::Half ) const {
//		const Real Wave = SawTooth();
//		
//		if (Wave >= HalfPeriod)
//			// A HalfPeriod of 1 should be caught by the floor, wrapping it back to zero) //
//			return Real::One - ((Wave - HalfPeriod) / (Real::One - HalfPeriod));
//		else
//			// If HalfPeriod is zero, the above should catch it, avoiding our division by zero //
//			return Wave / HalfPeriod;
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Square Pulse Wave  |-| |-| 
//	//                   _| |_| | -- 2 periods shown -- Input *[0,1] -- Output *[0,1]
//	// A period of 0 and 1 return constantly high //
//	inline const Real SquarePulse( const Real& HalfPeriod = Real::Half ) const {
//		const Real Wave = SawTooth();
//		
//		if (Wave >= HalfPeriod)
//			// A HalfPeriod of 1 should be caught by the floor, wrapping it back to zero) //
//			return Real::One;
//		else
//			// If HalfPeriod is zero, the above should catch it, avoiding our division by zero //
//			return Real::Zero;
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Linear Interpolation Pulse  /| /|    A SawTooth() where you control the midpoint (0.5) interpolation rate.
//	//                            / |/ | -- 2 periods shown -- Input *[0,1] -- Output *[0,1]
//	inline const Real LerpPulse( const Real& HalfPeriod = Real::Half ) const {
//		const Real Wave = SawTooth();
//		
//		if (Wave >= HalfPeriod)
//			// A HalfPeriod of 1 should be caught by the floor, wrapping it back to zero) //
//			return Real::Half + (((Wave - HalfPeriod) / (Real::One - HalfPeriod)) * Real::Half);
//		else
//			// If HalfPeriod is zero, the above should catch it, avoiding our division by zero //
//			return (Wave / HalfPeriod) * Real::Half;
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Double Saw Tooth Pulse  /| /| /| /|    A single SawTooth Pulse is useless, so here's two.
//	//                        / |/ |/ |/ | -- 2 periods shown -- Input *[0,1] -- Output *[0,1]
//	inline const Real DoubleSawToothPulse( const Real& HalfPeriod = Real::Half ) const {
//		const Real Wave = SawTooth();
//		
//		if (Wave >= HalfPeriod)
//			// A HalfPeriod of 1 should be caught by the floor, wrapping it back to zero) //
//			return ((Wave - HalfPeriod) / (Real::One - HalfPeriod));
//		else
//			// If HalfPeriod is zero, the above should catch it, avoiding our division by zero //
//			return Wave / HalfPeriod;
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	
//
//	// - -------------------------------------------------------------------------------------- - //
//	// Parabolic Curve Sine and Cosine family waveform functions //
//	// NOTE: Sine and Cosine family functions lack Inverse functions, but can flip the waveform 
//	//       by simply negating the returned value!
//	// - -------------------------------------------------------------------------------------- - //
//	// Sin Parabolic Curve "Smooth Step" -- Slowly leaves and reaches extreme, with brief stops.
//	inline const Real SinSmoothStep() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(3) )
//			return -Period.SawTooth()._InvSmoothStep();
//		else if ( Period >= Real(2) )
//			return -Period.SawTooth()._SmoothStep();
//		else if ( Period >= Real(1) )
//			return Period.SawTooth()._InvSmoothStep();
//		else
//			return Period.SawTooth()._SmoothStep();
//	}		
//	// - -------------------------------------------------------------------------------------- - //
//	// Sin Parabolic Curve "Ease In" -- Slowly reaches extreme, with a brief stop.
//	inline const Real SinEaseIn() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(3) )
//			return -Period.SawTooth()._InvEaseOut();
//		else if ( Period >= Real(2) )
//			return -Period.SawTooth()._EaseIn();
//		else if ( Period >= Real(1) )
//			return Period.SawTooth()._InvEaseOut();
//		else
//			return Period.SawTooth()._EaseIn();
//	}	
//	// - -------------------------------------------------------------------------------------- - //
//	// Sin Parabolic Curve "Ease In" Tooth -- Hits the tooth and turns around.
//	inline const Real SinEaseInTooth() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(3) )
//			return -Period.SawTooth()._InvEaseIn();
//		else if ( Period >= Real(2) )
//			return -Period.SawTooth()._EaseIn();
//		else if ( Period >= Real(1) )
//			return Period.SawTooth()._InvEaseIn();
//		else
//			return Period.SawTooth()._EaseIn();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Sin Parabolic Curve "Ease Out" -- Quickly reaches extreme, with a brief stop.
//	inline const Real SinEaseOut() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(3) )
//			return -Period.SawTooth()._InvEaseIn();
//		else if ( Period >= Real(2) )
//			return -Period.SawTooth()._EaseOut();
//		else if ( Period >= Real(1) )
//			return Period.SawTooth()._InvEaseIn();
//		else
//			return Period.SawTooth()._EaseOut();
//	}	
//	// - -------------------------------------------------------------------------------------- - //
//	// Sin Parabolic Curve "Ease Out" Tooth -- NOTE: A decent approximation for SIN!
//	inline const Real SinEaseOutTooth() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(3) )
//			return -Period.SawTooth()._InvEaseOut();
//		else if ( Period >= Real(2) )
//			return -Period.SawTooth()._EaseOut();
//		else if ( Period >= Real(1) )
//			return Period.SawTooth()._InvEaseOut();
//		else
//			return Period.SawTooth()._EaseOut();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// TODO: Cosine Versions //
//	// - -------------------------------------------------------------------------------------- - //
//
//	// - -------------------------------------------------------------------------------------- - //
//	// Experiments //
//	// - -------------------------------------------------------------------------------------- - //
//	// NOTES: The Ease In makes it accelerate fast, but the trasition to Triangle abruptly slows it.
//	//        This is probably not useful. An ideal alternative would be to Mix or feed values in
//	//        to Triangle itself.
//	inline const Real SinEaseInToTriangle() const {
//		Real Period = SawTooth() * Real(4); // Get a 0-4 range //
//		
//		if ( Period >= Real(1) )
//			return SinTriangle();
//		else
//			return Period.SawTooth().CalcQuarter().Sin();//_EaseIn();
//	}	
//	// - -------------------------------------------------------------------------------------- - //

//	// - -------------------------------------------------------------------------------------- - //
//	// *** TIP *** - Interpolation functions can be called more than once for greater impact! //
//	// - -------------------------------------------------------------------------------------- - //
//	// Linear Interpolation  /
//	//                      /  (DOES NOT CLAMP! Use Lerp() instead) 
//	inline const Real _Lerp() const {
//		return *this;
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Inverse Linear Interpolation \   .
//	//                               \  (DOES NOT CLAMP! Use InvLerp() instead) 
//	inline const Real _InvLerp() const {			
//		return (Real::One - *this)._Lerp();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// SmoothStep Interpolation   /'
//	//                          ,/   (DOES NOT CLAMP! Use SmoothStep() instead) 
//	inline const Real _SmoothStep() const {
//		return (*this) * (*this) * (Real(3) - (Real(2) * (*this)));
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Inverse SmoothStep Interpolation '\   .
//	//                                    \. (DOES NOT CLAMP! Use InvSmoothStep() instead) 
//	inline const Real _InvSmoothStep() const {
//		return (Real::One - *this)._SmoothStep();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Ease-In Interpolation  .-'`
//	//                       /   (DOES NOT CLAMP! Use EaseIn() instead) 
//	inline const Real _EaseIn() const {
//		return (*this) * (*this);
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Ease-More-In Interpolation  .-'`
//	//                            /   (DOES NOT CLAMP! Use EaseMoreOut() instead) 
//	inline const Real _EaseMoreIn() const {
//		return (*this) * (*this) * (*this);
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Ease-Out Interpolation    /
//	//                        .,/   (DOES NOT CLAMP! Use EaseIn() instead) 
//	inline const Real _EaseOut() const {
//		return Real::One - (Real::One - *this) * (Real::One - *this);
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Ease-More-Out Interpolation    /
//	//                             .,/   (DOES NOT CLAMP! Use EaseMoreOut() instead) 
//	inline const Real _EaseMoreOut() const {
//		return Real::One - (Real::One - *this) * (Real::One - *this) * (Real::One - *this);
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	inline const Real _InvEaseIn() const {
//		return (Real::One - *this)._EaseIn();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	inline const Real _InvEaseOut() const {
//		return (Real::One - *this)._EaseOut();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	inline const Real _InvEaseMoreIn() const {
//		return (Real::One - *this)._EaseMoreIn();
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	inline const Real _InvEaseMoreOut() const {
//		return (Real::One - *this)._EaseMoreOut();
//	}
//	// - -------------------------------------------------------------------------------------- - //


//	// - -------------------------------------------------------------------------------------- - //
//	inline bool IsZero() const {
//		//return *this == Real::Zero;
//		return (*this).Abs() <= Real::SmallestUnit;
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	// Variation, that requires the guarentee that the number is positive. Used with magnitude. //
//	inline bool IsZeroOrLess() const {
//		//return *this == Real::Zero;
//		return *this <= Real::SmallestUnit;
//	}
//	// - -------------------------------------------------------------------------------------- - //
//	
//	// - -------------------------------------------------------------------------------------- - //
//	inline bool Is( const Real& _Vs ) const {
//		//return (*this - _Vs) == Real::Zero;
//		return (*this - _Vs).Abs() <= Real::SmallestUnit;
//	}
//	// - -------------------------------------------------------------------------------------- - //

//	// - -------------------------------------------------------------------------------------- - //
//	// WARNING: A limit of 64 ToString calls can be made at a time, otherwise returned values may be bad //
//	inline const char* ToString() const {
//		static char Text[64][128];		// 64 slots, 128 chars long (8,192 bytes). An Int is 10 chars long max. //
//		static int CurrentText = 0;
//		CurrentText++;
//		CurrentText &= 63;
//		
//		safe_sprintf( Text[CurrentText], sizeof(Text[CurrentText]), "%f", x );
//		return Text[CurrentText];
//	}
//	// - -------------------------------------------------------------------------------------- - //



// Swizzle ?? //



// - ------------------------------------------------------------------------------------------ - //
// External Operations, for GLSL familiar syntax. From the Procedural book. //
// NOTE: These functions, for the most part, operate on ranges. Functions above are typically [0,1]
// - ------------------------------------------------------------------------------------------ - //
inline float mix( const float a, const float b, const float Alpha ) {
	return (a * (1.0f - Alpha)) + (b * Alpha);
}
// - ------------------------------------------------------------------------------------------ - //
inline float step( const float a, const float x ) {
	return float(x >= a); // NOTE: This is a boolean op [0,1] //
}
// - ------------------------------------------------------------------------------------------ - //
inline float pulse( const float a, const float b, const float x ) {
	return step(a,x) - step(b,x); // Clever! x>a Becomes 1, then as x>b it becomes 1-1=0 //
}
// - ------------------------------------------------------------------------------------------ - //
inline float min( const float a, const float b ) {
	return a < b ? a : b;
}
// - ------------------------------------------------------------------------------------------ - //
inline float max( const float a, const float b ) {
	return a < b ? b : a;
}
// - ------------------------------------------------------------------------------------------ - //
inline float clamp( const float x, const float a, const float b ) {
	return min( max(x,a), b );
}
// - ------------------------------------------------------------------------------------------ - //
// Clamp 0 to +1 //
inline float clamp0( const float x ) {
	return min( max(x,0.0f), 1.0f );
}
// - ------------------------------------------------------------------------------------------ - //
// Clamp -1 to +1 //
inline float clamp1( const float x ) {
	return min( max(x,-1.0f), 1.0f );
}
// - ------------------------------------------------------------------------------------------ - //
inline float abs( const float x ) {
	return x < 0.0f ? -x : x;
}
// - ------------------------------------------------------------------------------------------ - //
inline float smoothstep( const float a, const float b, float x ) {
	if ( x < a )  return 0.0f;
	if ( x >= b ) return 1.0f;
	x = (x-a) / (b-a);
	return (x * x * (3.0f - 2.0f * x));
}
// - ------------------------------------------------------------------------------------------ - //
// Page 34 - Splines
// - ------------------------------------------------------------------------------------------ - //
inline float gammacorrect( const float Gamma, const float x ) {
	return pow( x, 1.0f / Gamma );
}
// - ------------------------------------------------------------------------------------------ - //
inline float bias( const float b, const float x ) {
	return pow( x, log(b) / log(0.5f) );
}
// - ------------------------------------------------------------------------------------------ - //
inline float gain( const float g, const float x ) {
	if ( x < 0.5f )
		return bias( 1.0f - g, 2.0f * x) * 0.5f;// / 2.0f; // MK
	else
		return 1.0f - bias( 1.0f - g, 2.0f * x) * 0.5f;// / 2.0f; // MK
}
// - ------------------------------------------------------------------------------------------ - //
inline float boxstep( const float a, const float b, const float x ) { 
	return clamp( (x-a)/(b-a), 0.0f, 1.0f );
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
#endif // __GEL_MATH_FLOAT_H__ //
// - ------------------------------------------------------------------------------------------ - //
