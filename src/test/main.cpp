#include <constexpr_math.h>

//------------------------------------------------------------------------------
// constexpr floating-point "equality" (within epsilon)
template <typename T>
constexpr bool feq(T x, T y)
{
  return cex::abs(x - y) <= std::numeric_limits<T>::epsilon();
}

int main(int, char* [])
{
  // All constants referenced from Wolfram Alpha :)

  //----------------------------------------------------------------------------
  // abs
  static_assert(feq(1.0f, cex::abs(-1.0f)), "abs(-1.0f)");
  static_assert(feq(1.0f, cex::abs(1.0f)), "abs(1.0f)");
  static_assert(feq(1.0, cex::abs(-1.0)), "abs(-1.0)");
  static_assert(feq(1.0, cex::abs(1.0)), "abs(1.0)");
  static_assert(feq(1.0l, cex::abs(-1.0l)), "abs(-1.0l)");
  static_assert(feq(1.0l, cex::abs(1.0l)), "abs(1.0l)");

  //----------------------------------------------------------------------------
  // fabs
  static_assert(feq(1.0f, cex::fabs(-1.0f)), "fabs(-1.0f)");
  static_assert(feq(1.0f, cex::fabs(1.0f)), "fabs(-1.0f)");
  static_assert(feq(1.0, cex::fabs(-1.0)), "fabs(-1.0)");
  static_assert(feq(1.0, cex::fabs(1.0)), "fabs(1.0)");
  static_assert(feq(1.0l, cex::fabs(-1.0l)), "fabs(-1.0l)");
  static_assert(feq(1.0l, cex::fabs(1.0l)), "fabs(1.0l)");
  static_assert(1.0 == cex::fabs(1), "fabs(1)");
  static_assert(1.0 == cex::fabs(-1), "fabs(1)");

  //----------------------------------------------------------------------------
  // ipow
  static_assert(feq(9.0f, cex::ipow(3.0f, 2)), "ipow(3.0f, 2)");
  static_assert(feq(0.111111f, cex::ipow(3.0f, -2)), "ipow(3.0f, -2)");

  //----------------------------------------------------------------------------
  // sqrt
  // square root of 2 = 1.414213562373095048802
  static_assert(feq(1.0f, cex::sqrt(1.0f)), "sqrt(1.0f)");
  static_assert(feq(1.4142136f, cex::sqrt(2.0f)), "sqrt(2.0f)");
  static_assert(feq(1.0, cex::sqrt(1.0)), "sqrt(1.0)");
  static_assert(feq(1.414213562373095, cex::sqrt(2.0)), "sqrt(2.0)");
  static_assert(feq(1.0l, cex::sqrt(1.0l)), "sqrt(1.0l)");
  static_assert(feq(1.4142135623730950488l, cex::sqrt(2.0l)), "sqrt(2.0l)");
  static_assert(feq(2.0, cex::sqrt(4)), "sqrt(4)");

  //----------------------------------------------------------------------------
  // cbrt
  // cube root of 2 = 1.259921049894873164767
  static_assert(feq(1.0f, cex::cbrt(1.0f)), "cbrt(1.0f)");
  static_assert(feq(1.259921f, cex::cbrt(2.0f)), "cbrt(2.0f)");
  static_assert(feq(1.0, cex::cbrt(1.0)), "cbrt(1.0)");
  static_assert(feq(1.259921049894873, cex::cbrt(2.0)), "cbrt(2.0)");
  static_assert(feq(1.0l, cex::cbrt(1.0l)), "cbrt(1.0l)");
  static_assert(feq(1.2599210498948731648l, cex::cbrt(2.0l)), "cbrt(2.0l)");
  static_assert(feq(2.0, cex::cbrt(8)), "cbrt(8)");

  //----------------------------------------------------------------------------
  // exp
  // e = 2.718281828459045235360
  static_assert(feq(2.718282f, cex::exp(1.0f)), "exp(1.0f)");
  static_assert(feq(2.7182818284590454, cex::exp(1.0)), "exp(1.0)");
  static_assert(feq(2.7182818284590452354l, cex::exp(1.0l)), "exp(1.0l)");
  static_assert(feq(2.7182818284590454, cex::exp(1)), "exp(1)");

  //----------------------------------------------------------------------------
  // sin
  // pi = 3.141592653589793238463
  constexpr float PIf = 3.141593f;
  constexpr double PI = 3.141592653589793;
  constexpr long double PIl = 3.1415926535897932385l;

  static_assert(feq(0.0f, cex::sin(PIf)), "sin(PIf)");
  static_assert(feq(0.0, cex::sin(PI)), "sin(PI)");
  static_assert(feq(0.0l, cex::sin(PIl)), "sin(PIl)");

  // pi/2 = 1.570796326794896619231
  constexpr float PI2f = 1.57079633f;
  constexpr double PI2 = 1.5707963267948966;
  constexpr long double PI2l = 1.5707963267948966192l;

  static_assert(feq(1.0f, cex::sin(PI2f)), "sin(PI/2f)");
  static_assert(feq(1.0, cex::sin(PI2)), "sin(PI/2)");
  static_assert(feq(1.0l, cex::sin(PI2l)), "sin(PI/2l)");

  // sin(1) = 0.8414709848078965066525
  static_assert(feq(0.8414709848078965, cex::sin(1)), "sin(1)");

  //----------------------------------------------------------------------------
  // cos
  static_assert(feq(1.0f, cex::cos(0.0f)), "cos(0f)");
  static_assert(feq(1.0, cex::cos(0.0)), "cos(0)");
  static_assert(feq(1.0l, cex::cos(0.0l)), "cos(0l)");
  static_assert(feq(0.0f, cex::cos(PI2f)), "cos(PI/2f)");
  static_assert(feq(0.0, cex::cos(PI2)), "cos(PI/2)");
  static_assert(feq(0.0l, cex::cos(PI2l)), "cos(PI/2l)");

  // cos(1) = 0.5403023058681397174009
  static_assert(feq(0.5403023058681397, cex::cos(1)), "cos(1)");

  //----------------------------------------------------------------------------
  // tan
  static_assert(feq(0.0f, cex::tan(0.0f)), "tan(0f)");
  static_assert(feq(0.0, cex::tan(0.0)), "tan(0)");
  static_assert(feq(0.0l, cex::tan(0.0l)), "tan(0l)");

  // pi/4 = 0.785398163397448309615
  constexpr float PI4f = 0.78539816f;
  constexpr double PI4 = 0.7853981633974483;
  constexpr long double PI4l = 0.78539816339744830962l;

  static_assert(feq(1.0f, cex::tan(PI4f)), "tan(PI/4f)");
  static_assert(feq(1.0, cex::tan(PI4)), "tan(PI/4)");
  static_assert(feq(1.0l, cex::tan(PI4l)), "tan(PI/4l)");

  // tan(1) = 1.55740772465490223050697
  static_assert(feq(1.5574077246549022, cex::tan(1)), "tan(1)");

  //----------------------------------------------------------------------------
  // floor and ceil
  static_assert(cex::floor(PIf) == 3.0f, "floor(PIf)");
  static_assert(cex::ceil(PIf) == 4.0f, "ceil(PIf)");
  static_assert(cex::floor(-PIf) == -4.0f, "floor(-PIf)");
  static_assert(cex::ceil(-PIf) == -3.0f, "ceil(-PIf)");

  static_assert(cex::floor(PI) == 3.0, "floor(PI)");
  static_assert(cex::ceil(PI) == 4.0, "ceil(PI)");
  static_assert(cex::floor(-PI) == -4.0, "floor(-PI)");
  static_assert(cex::ceil(-PI) == -3.0, "ceil(-PI)");

  #if __cplusplus == 201402L
  static_assert(cex::floor(PIl) == 3.0l, "floor(PIl)");
  static_assert(cex::ceil(PIl) == 4.0l, "ceil(PIl)");
  static_assert(cex::floor(-PIl) == -4.0l, "floor(-PIl)");
  static_assert(cex::ceil(-PIl) == -3.0l, "ceil(-PIl)");
  #endif

  static_assert(cex::floor(1) == 1.0, "floor(1)");
  static_assert(cex::ceil(1) == 1.0, "ceil(1)");

  //----------------------------------------------------------------------------
  // fmod
  static_assert(feq(1.0f, cex::fmod(9.0f, 4.0f)), "fmod(9.0f, 4.0f)");
  static_assert(feq(1.0, cex::fmod(9.0, 4.0)), "fmod(9.0, 4.0)");
  #if __cplusplus == 201402L
  static_assert(feq(1.0l, cex::fmod(9.0l, 4.0l)), "fmod(9.0l, 4.0l)");
  #endif

  static_assert(feq(1.0, cex::fmod(9, 4)), "fmod(9, 4)");
  static_assert(feq(1.0, cex::fmod(9, 4.0)), "fmod(9, 4.0)");
  #if __cplusplus == 201402L
  static_assert(feq(1.0l, cex::fmod(9, 4.0l)), "fmod(9, 4.0l)");
  static_assert(feq(1.0l, cex::fmod(9.0l, 4)), "fmod(9.0l, 4)");
  static_assert(feq(1.0l, cex::fmod(9.0l, 4.0l)), "fmod(9.0l, 4.0l)");
  #endif

  //----------------------------------------------------------------------------
  // log
  static_assert(feq(0.0f, cex::log(1.0f)), "log(1.0f)");
  static_assert(feq(0.0, cex::log(1.0)), "log(1.0)");
  static_assert(feq(0.0l, cex::log(1.0l)), "log(1.0l)");
  static_assert(feq(1.0f, cex::log(cex::exp(1.0f))), "log(ef)");
  static_assert(feq(1.0, cex::log(cex::exp(1.0))), "log(e)");
  static_assert(feq(1.0l, cex::log(cex::exp(1.0l))), "log(el)");
  static_assert(feq(0.0, cex::log(1)), "log(1)");

  // ln(2) = 0.693147180559945309417
  static_assert(feq(0.6931472f, cex::log(2.0f)), "log(2.0f)");
  static_assert(feq(0.6931471805599454, cex::log(2.0)), "log(2.0)");
  static_assert(feq(0.6931471805599453094l, cex::log(2.0l)), "log(2.0l)");

  //----------------------------------------------------------------------------
  // log10
  static_assert(feq(1.0f, cex::log10(10.0f)), "log10(10.0f)");
  static_assert(feq(1.0, cex::log10(10.0)), "log10(10.0)");
  static_assert(feq(1.0l, cex::log10(10.0l)), "log10(10.0l)");
  static_assert(feq(0.0, cex::log10(1)), "log10(1)");

  // log10(2) = 0.301029995663981195213
  static_assert(feq(0.301029996f, cex::log10(2.0f)), "log10(2.0f)");
  static_assert(feq(0.3010299956639812, cex::log10(2.0)), "log10(2.0)");
  static_assert(feq(0.3010299956639811952l, cex::log10(2.0l)), "log10(2.0l)");

  //----------------------------------------------------------------------------
  // log2
  static_assert(feq(1.0f, cex::log2(2.0f)), "log2(2.0f)");
  static_assert(feq(1.0, cex::log2(2.0)), "log2(2.0)");
  static_assert(feq(1.0l, cex::log2(2.0l)), "log2(2.0l)");
  static_assert(feq(0.0, cex::log2(1)), "log2(1)");

  // log2(10) = 3.321928094887362347870
  static_assert(feq(3.321928f, cex::log2(10.0f)), "log2(10.0f)");
  static_assert(feq(3.3219280948873606, cex::log2(10.0)), "log2(10.0)");
  static_assert(feq(3.3219280948873623479l, cex::log2(10.0l)), "log2(10.0l)");
}
