/**
 * Copyright (c) 2022 Alvin Wong
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <windowsnumerics.h>
#include <sstream>

using namespace Windows::Foundation::Numerics;

constexpr float pi = 3.141592654f;

std::ostream &operator<<(std::ostream &os, float2 const &v) {
  os << "{" << v.x << ", " << v.y << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, float3 const &v) {
  os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, float4 const &v) {
  os << "{" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, float3x2 const &v) {
  os << "{ {" << v.m11 << ", " << v.m12
    << "}, {" << v.m21 << ", " << v.m22
    << "}, {" << v.m31 << ", " << v.m32
    << "} }";
  return os;
}

std::ostream &operator<<(std::ostream &os, float4x4 const &v) {
  os << "{ {" << v.m11 << ", " << v.m12 << ", " << v.m13 << ", " << v.m14
    << "}, {" << v.m21 << ", " << v.m22 << ", " << v.m23 << ", " << v.m24
    << "}, {" << v.m31 << ", " << v.m32 << ", " << v.m33 << ", " << v.m34
    << "}, {" << v.m41 << ", " << v.m42 << ", " << v.m43 << ", " << v.m44
    << "} }";
  return os;
}

std::ostream &operator<<(std::ostream &os, plane const &v) {
  os << "{ {" << v.normal.x << ", " << v.normal.y << ", " << v.normal.z
    << "}, " << v.d << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, quaternion const &v) {
  os << "{" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "}";
  return os;
}

#define CATCH_CONFIG_RUNNER
// https://github.com/catchorg/Catch2/releases/tag/v2.13.10
#include "catch.hpp"

class eq2
  : public Catch::MatcherBase<float2>
{
  float m_x{NAN};
  float m_y{NAN};
public:
  explicit eq2(float2 v)
    : m_x(v.x), m_y(v.y)
  {}
  eq2(float x, float y)
    : m_x(x), m_y(y)
  {}
  bool match(float2 const& v) const override {
    return v.x == Approx(m_x) && v.y == Approx(m_y);
  }
  std::string describe() const override {
    std::ostringstream ss;
    ss << "is equal to ";
    ss << float2(m_x, m_y);
    return ss.str();
  }
};

class eq3
  : public Catch::MatcherBase<float3>
{
  float m_x{NAN};
  float m_y{NAN};
  float m_z{NAN};
public:
  explicit eq3(float3 v)
    : m_x(v.x), m_y(v.y), m_z(v.z)
  {}
  eq3(float x, float y, float z)
    : m_x(x), m_y(y), m_z(z)
  {}
  bool match(float3 const& v) const override {
    return v.x == Approx(m_x) && v.y == Approx(m_y) && v.z == Approx(m_z);
  }
  std::string describe() const override {
    std::ostringstream ss;
    ss << "is equal to ";
    ss << float3(m_x, m_y, m_z);
    return ss.str();
  }
};

class eq4
  : public Catch::MatcherBase<float4>
{
  float m_x{NAN};
  float m_y{NAN};
  float m_z{NAN};
  float m_w{NAN};
public:
  explicit eq4(float4 v)
    : m_x(v.x), m_y(v.y), m_z(v.z), m_w(v.w)
  {}
  eq4(float x, float y, float z, float w)
    : m_x(x), m_y(y), m_z(z), m_w(w)
  {}
  bool match(float4 const& v) const override {
    return v.x == Approx(m_x) && v.y == Approx(m_y) && v.z == Approx(m_z) && v.w == Approx(m_w);
  }
  std::string describe() const override {
    std::ostringstream ss;
    ss << "is equal to ";
    ss << float4(m_x, m_y, m_z, m_w);
    return ss.str();
  }
};

class eq3x2
  : public Catch::MatcherBase<float3x2>
{
  float m_11{NAN};
  float m_12{NAN};
  float m_21{NAN};
  float m_22{NAN};
  float m_31{NAN};
  float m_32{NAN};
public:
  explicit eq3x2(float3x2 v)
    : m_11(v.m11), m_12(v.m12)
    , m_21(v.m21), m_22(v.m22)
    , m_31(v.m31), m_32(v.m32)
  {}
  eq3x2(
    float m11, float m12,
    float m21, float m22,
    float m31, float m32
  )
    : m_11(m11), m_12(m12)
    , m_21(m21), m_22(m22)
    , m_31(m31), m_32(m32)
  {}
  bool match(float3x2 const& v) const override {
    return
      v.m11 == Approx(m_11) && v.m12 == Approx(m_12) &&
      v.m21 == Approx(m_21) && v.m22 == Approx(m_22) &&
      v.m31 == Approx(m_31) && v.m32 == Approx(m_32);
  }
  std::string describe() const override {
    std::ostringstream ss;
    ss << "is equal to ";
    ss << float3x2(
      m_11, m_12,
      m_21, m_22,
      m_31, m_32
    );
    return ss.str();
  }
};

class eq4x4
  : public Catch::MatcherBase<float4x4>
{
  float m_11{NAN};
  float m_12{NAN};
  float m_13{NAN};
  float m_14{NAN};
  float m_21{NAN};
  float m_22{NAN};
  float m_23{NAN};
  float m_24{NAN};
  float m_31{NAN};
  float m_32{NAN};
  float m_33{NAN};
  float m_34{NAN};
  float m_41{NAN};
  float m_42{NAN};
  float m_43{NAN};
  float m_44{NAN};
public:
  explicit eq4x4(float4x4 v)
    : m_11(v.m11), m_12(v.m12), m_13(v.m13), m_14(v.m14)
    , m_21(v.m21), m_22(v.m22), m_23(v.m23), m_24(v.m24)
    , m_31(v.m31), m_32(v.m32), m_33(v.m33), m_34(v.m34)
    , m_41(v.m41), m_42(v.m42), m_43(v.m43), m_44(v.m44)
  {}
  eq4x4(
    float m11, float m12, float m13, float m14,
    float m21, float m22, float m23, float m24,
    float m31, float m32, float m33, float m34,
    float m41, float m42, float m43, float m44
  )
    : m_11(m11), m_12(m12), m_13(m13), m_14(m14)
    , m_21(m21), m_22(m22), m_23(m23), m_24(m24)
    , m_31(m31), m_32(m32), m_33(m33), m_34(m34)
    , m_41(m41), m_42(m42), m_43(m43), m_44(m44)
  {}
  bool match(float4x4 const& v) const override {
    return
      v.m11 == Approx(m_11) && v.m12 == Approx(m_12) && v.m13 == Approx(m_13) && v.m14 == Approx(m_14) &&
      v.m21 == Approx(m_21) && v.m22 == Approx(m_22) && v.m23 == Approx(m_23) && v.m24 == Approx(m_24) &&
      v.m31 == Approx(m_31) && v.m32 == Approx(m_32) && v.m33 == Approx(m_33) && v.m34 == Approx(m_34) &&
      v.m41 == Approx(m_41) && v.m42 == Approx(m_42) && v.m43 == Approx(m_43) && v.m44 == Approx(m_44);
  }
  std::string describe() const override {
    std::ostringstream ss;
    ss << "is equal to ";
    ss << float4x4(
      m_11, m_12, m_13, m_14,
      m_21, m_22, m_23, m_24,
      m_31, m_32, m_33, m_34,
      m_41, m_42, m_43, m_44
    );
    return ss.str();
  }
};

class eqp
  : public Catch::MatcherBase<plane>
{
  float m_x{NAN};
  float m_y{NAN};
  float m_z{NAN};
  float m_d{NAN};
public:
  explicit eqp(plane v)
    : m_x(v.normal.x), m_y(v.normal.y), m_z(v.normal.z), m_d(v.d)
  {}
  eqp(float x, float y, float z, float d)
    : m_x(x), m_y(y), m_z(z), m_d(d)
  {}
  bool match(plane const& v) const override {
    return v.normal.x == Approx(m_x) && v.normal.y == Approx(m_y) &&
      v.normal.z == Approx(m_z) && v.d == Approx(m_d);
  }
  std::string describe() const override {
    std::ostringstream ss;
    ss << "is equal to ";
    ss << plane(m_x, m_y, m_z, m_d);
    return ss.str();
  }
};

class eqq
  : public Catch::MatcherBase<quaternion>
{
  float m_x{NAN};
  float m_y{NAN};
  float m_z{NAN};
  float m_w{NAN};
public:
  explicit eqq(quaternion v)
    : m_x(v.x), m_y(v.y), m_z(v.z), m_w(v.w)
  {}
  eqq(float x, float y, float z, float w)
    : m_x(x), m_y(y), m_z(z), m_w(w)
  {}
  bool match(quaternion const& v) const override {
    return v.x == Approx(m_x) && v.y == Approx(m_y) && v.z == Approx(m_z) && v.w == Approx(m_w);
  }
  std::string describe() const override {
    std::ostringstream ss;
    ss << "is equal to ";
    ss << quaternion(m_x, m_y, m_z, m_w);
    return ss.str();
  }
};

using namespace Catch::literals;

// === float2 ===

TEST_CASE("float2-ctors") {
  CHECK_THAT(float2(2.0f, 3.0f), eq2(2.0f, 3.0f));
  CHECK_THAT(float2(2.0f), eq2(2.0f, 2.0f));
}

TEST_CASE("float2-methods") {
  CHECK_THAT(float2::zero(), eq2(0.0f, 0.0f));
  CHECK(float2::zero().x == 0.0f);
  CHECK(float2::zero().y == 0.0f);
  CHECK_THAT(float2::one(), eq2(1.0f, 1.0f));
  CHECK(float2::one().x == 1.0f);
  CHECK(float2::one().y == 1.0f);
  CHECK_THAT(float2::unit_x(), eq2(1.0f, 0.0f));
  CHECK(float2::unit_x().x == 1.0f);
  CHECK(float2::unit_x().y == 0.0f);
  CHECK_THAT(float2::unit_y(), eq2(0.0f, 1.0f));
  CHECK(float2::unit_y().x == 0.0f);
  CHECK(float2::unit_y().y == 1.0f);
}

TEST_CASE("float2-operators") {
  const float2 v1{ 3.0f, 4.0f };
  const float2 v2{ 8.0f, 16.0f };
  CHECK_THAT(v1 + v2, eq2(11.0f, 20.0f));
  CHECK_THAT(v1 - v2, eq2(-5.0f, -12.0f));
  CHECK_THAT(v1 * v2, eq2(24.0f, 64.0f));
  CHECK_THAT(v1 * 2.0f, eq2(6.0f, 8.0f));
  CHECK_THAT(3.0f * v1, eq2(9.0f, 12.0f));
  CHECK_THAT(v1 / v2, eq2(0.375f, 0.25f));
  CHECK_THAT(v1 / 10.0f, eq2(0.3f, 0.4f));
  CHECK_THAT(-v1, eq2(-3.0f, -4.0f));
  float2 v3;
  v3 = {1.0f, 2.0f};
  CHECK_THAT(v3 += v1, eq2(4.0f, 6.0f));
  v3 = {1.0f, 2.0f};
  CHECK_THAT(v3 -= v1, eq2(-2.0f, -2.0f));
  v3 = {1.5f, 2.0f};
  CHECK_THAT(v3 *= v1, eq2(4.5f, 8.0f));
  v3 = {1.0f, 2.0f};
  CHECK_THAT(v3 *= 3.0f, eq2(3.0f, 6.0f));
  v3 = {1.0f, 2.0f};
  CHECK_THAT(v3 /= v1, eq2(0.333333f, 0.5f));
  v3 = {1.0f, 2.0f};
  CHECK_THAT(v3 /= 5.0f, eq2(0.2f, 0.4f));
  v3 = {3.0f, 4.0f};
  CHECK((v3 == v1) == true);
  CHECK((v3 == v2) == false);
  CHECK((v3 != v1) == false);
  CHECK((v3 != v2) == true);
}

TEST_CASE("float2-functions") {
  const float2 v1{ 3.0f, 4.0f };
  const float2 v2{ 8.0f, 16.0f };
  const float2 v3{ 10.0f, 10.0f };

  CHECK(length(v1) == 5.0_a);
  CHECK(length(v2) == 17.88854_a);
  CHECK(length_squared(v1) == 25.0_a);
  CHECK(length_squared(v2) == 320.0_a);
  CHECK(distance(v1, v2) == 13.0_a);
  CHECK(distance_squared(v1, v2) == 169.0_a);
  CHECK(dot(v1, v2) == 88.0_a);
  CHECK_THAT(normalize(v1), eq2(0.6f, 0.8f));
  CHECK_THAT(normalize(v2), eq2(0.4472136f, 0.8944272f));
  CHECK_THAT(reflect(v1, float2::unit_x()), eq2(-3.0f, 4.0f));
  CHECK_THAT(reflect(v1, float2::unit_y()), eq2(3.0f, -4.0f));
  CHECK_THAT(reflect(v1, normalize(v2)), eq2(-1.4f, -4.8f));
  CHECK_THAT(reflect(v1, v2), eq2(-1405, -2812)); // Appears to be garbage
  CHECK_THAT(min(v2, v3), eq2(8.0f, 10.0f));
  CHECK_THAT(max(v2, v3), eq2(10.0f, 16.0f));
  CHECK_THAT(clamp(v1, v2, v3), eq2(8.0f, 16.0f));
  CHECK_THAT(clamp(v2, v1, v3), eq2(8.0f, 10.0f));
  CHECK_THAT(lerp(v1, v2, 0.0f), eq2(3.0f, 4.0f));
  CHECK_THAT(lerp(v1, v2, 0.5f), eq2(5.5f, 10.0f));
  CHECK_THAT(lerp(v1, v2, 1.0f), eq2(8.0f, 16.0f));
  CHECK_THAT(lerp(v1, v2, -0.5f), eq2(0.5f, -2.0f));
  CHECK_THAT(lerp(v1, v2, 1.5f), eq2(10.5f, 22.0f));
  // TODO: transform
  const quaternion q1 = normalize(quaternion(-1.0f, 2.0f, -3.0f, 4.0f));
  CHECK_THAT(transform(v1, q1), eq2(3.06667f, -1.46667f));
}

// === float3 ===

TEST_CASE("float3-ctors") {
  CHECK_THAT(float3(2.0f, 3.0f, 4.0f), eq3(2.0f, 3.0f, 4.0f));
  CHECK_THAT(float3(float2(2.0f, 3.0f), 4.0f), eq3(2.0f, 3.0f, 4.0f));
  CHECK_THAT(float3(2.0f), eq3(2.0f, 2.0f, 2.0f));
}

TEST_CASE("float3-methods") {
  CHECK_THAT(float3::zero(), eq3(0.0f, 0.0f, 0.0f));
  CHECK(float3::zero().x == 0.0f);
  CHECK(float3::zero().y == 0.0f);
  CHECK(float3::zero().z == 0.0f);
  CHECK_THAT(float3::one(), eq3(1.0f, 1.0f, 1.0f));
  CHECK(float3::one().x == 1.0f);
  CHECK(float3::one().y == 1.0f);
  CHECK(float3::one().z == 1.0f);
  CHECK_THAT(float3::unit_x(), eq3(1.0f, 0.0f, 0.0f));
  CHECK(float3::unit_x().x == 1.0f);
  CHECK(float3::unit_x().y == 0.0f);
  CHECK(float3::unit_x().z == 0.0f);
  CHECK_THAT(float3::unit_y(), eq3(0.0f, 1.0f, 0.0f));
  CHECK(float3::unit_y().x == 0.0f);
  CHECK(float3::unit_y().y == 1.0f);
  CHECK(float3::unit_y().z == 0.0f);
  CHECK_THAT(float3::unit_z(), eq3(0.0f, 0.0f, 1.0f));
  CHECK(float3::unit_z().x == 0.0f);
  CHECK(float3::unit_z().y == 0.0f);
  CHECK(float3::unit_z().z == 1.0f);
}

TEST_CASE("float3-operators") {
  const float3 v1{ 3.0f, 4.0f, 5.0f };
  const float3 v2{ 8.0f, 16.0f, 24.0f };
  CHECK_THAT(v1 + v2, eq3(11.0f, 20.0f, 29.0f));
  CHECK_THAT(v1 - v2, eq3(-5.0f, -12.0f, -19.0f));
  CHECK_THAT(v1 * v2, eq3(24.0f, 64.0f, 120.0f));
  CHECK_THAT(v1 * 2.0f, eq3(6.0f, 8.0f, 10.0f));
  CHECK_THAT(3.0f * v1, eq3(9.0f, 12.0f, 15.0f));
  CHECK_THAT(v1 / v2, eq3(0.375f, 0.25f, 0.208333f));
  CHECK_THAT(v1 / 10.0f, eq3(0.3f, 0.4f, 0.5f));
  CHECK_THAT(-v1, eq3(-3.0f, -4.0f, -5.0f));
  float3 v3;
  v3 = {1.0f, 2.0f, 3.0f};
  CHECK_THAT(v3 += v1, eq3(4.0f, 6.0f, 8.0f));
  v3 = {1.0f, 2.0f, 3.0f};
  CHECK_THAT(v3 -= v1, eq3(-2.0f, -2.0f, -2.0f));
  v3 = {1.5f, 2.0f, 2.5f};
  CHECK_THAT(v3 *= v1, eq3(4.5f, 8.0f, 12.5f));
  v3 = {1.0f, 2.0f, 3.0f};
  CHECK_THAT(v3 *= 3.0f, eq3(3.0f, 6.0f, 9.0f));
  v3 = {1.0f, 2.0f, 3.0f};
  CHECK_THAT(v3 /= v1, eq3(0.333333f, 0.5f, 0.6f));
  v3 = {1.0f, 2.0f, 3.0f};
  CHECK_THAT(v3 /= 5.0f, eq3(0.2f, 0.4f, 0.6f));
  v3 = {3.0f, 4.0f, 5.0f};
  CHECK((v3 == v1) == true);
  CHECK((v3 == v2) == false);
  CHECK((v3 != v1) == false);
  CHECK((v3 != v2) == true);
}

TEST_CASE("float3-functions") {
  const float3 v1{ 3.0f, 4.0f, 5.0f };
  const float3 v2{ 8.0f, 16.0f, 24.0f };
  const float3 v3{ 10.0f, 10.0f, 10.0f };

  CHECK(length(v1) == 7.07107_a);
  CHECK(length(v2) == 29.93326_a);
  CHECK(length_squared(v1) == 50.0_a);
  CHECK(length_squared(v2) == 896.0_a);
  CHECK(distance(v1, v2) == 23.02173_a);
  CHECK(distance_squared(v1, v2) == 530.0_a);
  CHECK(dot(v1, v2) == 208.0_a);
  CHECK_THAT(normalize(v1), eq3(0.424264f, 0.565685f, 0.707107f));
  CHECK_THAT(normalize(v2), eq3(0.267261f, 0.534522f, 0.801784f));
  CHECK_THAT(cross(v1, v2), eq3(16.0f, -32.0f, 16.0f));
  CHECK_THAT(cross(v2, v1), eq3(-16.0f, 32.0f, -16.0f));
  CHECK_THAT(cross(v1, v3), eq3(-10.0f, 20.0f, -10.0f));
  CHECK_THAT(cross(v2, v3), eq3(-80.0f, 160.0f, -80.0f));
  CHECK_THAT(reflect(v1, float3::unit_x()), eq3(-3.0f, 4.0f, 5.0f));
  CHECK_THAT(reflect(v1, float3::unit_y()), eq3(3.0f, -4.0f, 5.0f));
  CHECK_THAT(reflect(v1, float3::unit_z()), eq3(3.0f, 4.0f, -5.0f));
  CHECK_THAT(reflect(v1, normalize(v2)), eq3(-0.714285f, -3.42857f, -6.14286f));
  CHECK_THAT(reflect(v1, v2), eq3(-3325, -6652, -9979)); // Appears to be garbage
  CHECK_THAT(min(v2, v3), eq3(8.0f, 10.0f, 10.0f));
  CHECK_THAT(max(v2, v3), eq3(10.0f, 16.0f, 24.0f));
  CHECK_THAT(clamp(v1, v2, v3), eq3(8.0f, 16.0f, 24.0f));
  CHECK_THAT(clamp(v2, v1, v3), eq3(8.0f, 10.0f, 10.0f));
  CHECK_THAT(lerp(v1, v2, 0.0f), eq3(3.0f, 4.0f, 5.0f));
  CHECK_THAT(lerp(v1, v2, 0.5f), eq3(5.5f, 10.0f, 14.5f));
  CHECK_THAT(lerp(v1, v2, 1.0f), eq3(8.0f, 16.0f, 24.0f));
  CHECK_THAT(lerp(v1, v2, -0.5f), eq3(0.5f, -2.0f, -4.5f));
  CHECK_THAT(lerp(v1, v2, 1.5f), eq3(10.5f, 22.0f, 33.5f));
  // TODO: transform
  const quaternion q1 = normalize(quaternion(-1.0f, 2.0f, -3.0f, 4.0f));
  CHECK_THAT(transform(v1, q1), eq3(6.73333f, -2.13333f, -0.333333f));
}

// === float4 ===

TEST_CASE("float4-ctors") {
  CHECK_THAT(float4(2.0f, 3.0f, 4.0f, 5.0f), eq4(2.0f, 3.0f, 4.0f, 5.0f));
  CHECK_THAT(float4(float2(2.0f, 3.0f), 4.0f, 5.0f), eq4(2.0f, 3.0f, 4.0f, 5.0f));
  CHECK_THAT(float4(float3(2.0f, 3.0f, 4.0f), 5.0f), eq4(2.0f, 3.0f, 4.0f, 5.0f));
  CHECK_THAT(float4(2.0f), eq4(2.0f, 2.0f, 2.0f, 2.0f));
}

TEST_CASE("float4-methods") {
  CHECK_THAT(float4::zero(), eq4(0.0f, 0.0f, 0.0f, 0.0f));
  CHECK(float4::zero().x == 0.0f);
  CHECK(float4::zero().y == 0.0f);
  CHECK(float4::zero().z == 0.0f);
  CHECK(float4::zero().w == 0.0f);
  CHECK_THAT(float4::one(), eq4(1.0f, 1.0f, 1.0f, 1.0f));
  CHECK(float4::one().x == 1.0f);
  CHECK(float4::one().y == 1.0f);
  CHECK(float4::one().z == 1.0f);
  CHECK(float4::one().w == 1.0f);
  CHECK_THAT(float4::unit_x(), eq4(1.0f, 0.0f, 0.0f, 0.0f));
  CHECK(float4::unit_x().x == 1.0f);
  CHECK(float4::unit_x().y == 0.0f);
  CHECK(float4::unit_x().z == 0.0f);
  CHECK(float4::unit_x().w == 0.0f);
  CHECK_THAT(float4::unit_y(), eq4(0.0f, 1.0f, 0.0f, 0.0f));
  CHECK(float4::unit_y().x == 0.0f);
  CHECK(float4::unit_y().y == 1.0f);
  CHECK(float4::unit_y().z == 0.0f);
  CHECK(float4::unit_y().w == 0.0f);
  CHECK_THAT(float4::unit_z(), eq4(0.0f, 0.0f, 1.0f, 0.0f));
  CHECK(float4::unit_z().x == 0.0f);
  CHECK(float4::unit_z().y == 0.0f);
  CHECK(float4::unit_z().z == 1.0f);
  CHECK(float4::unit_z().w == 0.0f);
  CHECK_THAT(float4::unit_w(), eq4(0.0f, 0.0f, 0.0f, 1.0f));
  CHECK(float4::unit_w().x == 0.0f);
  CHECK(float4::unit_w().y == 0.0f);
  CHECK(float4::unit_w().z == 0.0f);
  CHECK(float4::unit_w().w == 1.0f);
}

TEST_CASE("float4-operators") {
  const float4 v1{ 3.0f, 4.0f, 5.0f, 6.0f };
  const float4 v2{ 8.0f, 16.0f, 24.0f, 13.0f };
  CHECK_THAT(v1 + v2, eq4(11.0f, 20.0f, 29.0f, 19.0f));
  CHECK_THAT(v1 - v2, eq4(-5.0f, -12.0f, -19.0f, -7.0f));
  CHECK_THAT(v1 * v2, eq4(24.0f, 64.0f, 120.0f, 78.0f));
  CHECK_THAT(v1 * 2.0f, eq4(6.0f, 8.0f, 10.0f, 12.0f));
  CHECK_THAT(3.0f * v1, eq4(9.0f, 12.0f, 15.0f, 18.0f));
  CHECK_THAT(v1 / v2, eq4(0.375f, 0.25f, 0.208333f, 0.461538f));
  CHECK_THAT(v1 / 10.0f, eq4(0.3f, 0.4f, 0.5f, 0.6f));
  CHECK_THAT(-v1, eq4(-3.0f, -4.0f, -5.0f, -6.0f));
  float4 v3;
  v3 = {1.0f, 2.0f, 3.0f, 4.0f};
  CHECK_THAT(v3 += v1, eq4(4.0f, 6.0f, 8.0f, 10.0f));
  v3 = {1.0f, 2.0f, 3.0f, 4.0f};
  CHECK_THAT(v3 -= v1, eq4(-2.0f, -2.0f, -2.0f, -2.0f));
  v3 = {1.5f, 2.0f, 2.5f, 3.0f};
  CHECK_THAT(v3 *= v1, eq4(4.5f, 8.0f, 12.5f, 18.0f));
  v3 = {1.0f, 2.0f, 3.0f, 4.0f};
  CHECK_THAT(v3 *= 3.0f, eq4(3.0f, 6.0f, 9.0f, 12.0f));
  v3 = {1.0f, 2.0f, 3.0f, 4.0f};
  CHECK_THAT(v3 /= v1, eq4(0.333333f, 0.5f, 0.6f, 0.666667f));
  v3 = {1.0f, 2.0f, 3.0f, 4.0f};
  CHECK_THAT(v3 /= 5.0f, eq4(0.2f, 0.4f, 0.6f, 0.8f));
  v3 = {3.0f, 4.0f, 5.0f, 6.0f};
  CHECK((v3 == v1) == true);
  CHECK((v3 == v2) == false);
  CHECK((v3 != v1) == false);
  CHECK((v3 != v2) == true);
}

TEST_CASE("float4-functions") {
  const float4 v1{ 3.0f, 4.0f, 5.0f, 6.0f };
  const float4 v2{ 8.0f, 16.0f, 24.0f, 13.0f };
  const float4 v3{ 10.0f, 10.0f, 10.0f, 10.0f };

  CHECK(length(v1) == 9.27362_a);
  CHECK(length(v2) == 32.63434_a);
  CHECK(length_squared(v1) == 86.0_a);
  CHECK(length_squared(v2) == 1065.0_a);
  CHECK(distance(v1, v2) == 24.06242_a);
  CHECK(distance_squared(v1, v2) == 579.0_a);
  CHECK(dot(v1, v2) == 286.0_a);
  CHECK_THAT(normalize(v1), eq4(0.323498f, 0.431331f, 0.539164f, 0.646997f));
  CHECK_THAT(normalize(v2), eq4(0.245141f, 0.490281f, 0.735422f, 0.398353f));
  CHECK_THAT(min(v2, v3), eq4(8.0f, 10.0f, 10.0f, 10.0f));
  CHECK_THAT(max(v2, v3), eq4(10.0f, 16.0f, 24.0f, 13.0f));
  CHECK_THAT(clamp(v1, v2, v3), eq4(8.0f, 16.0f, 24.0f, 13.0f));
  CHECK_THAT(clamp(v2, v1, v3), eq4(8.0f, 10.0f, 10.0f, 10.0f));
  CHECK_THAT(lerp(v1, v2, 0.0f), eq4(3.0f, 4.0f, 5.0f, 6.0f));
  CHECK_THAT(lerp(v1, v2, 0.5f), eq4(5.5f, 10.0f, 14.5f, 9.5f));
  CHECK_THAT(lerp(v1, v2, 1.0f), eq4(8.0f, 16.0f, 24.0f, 13.0f));
  CHECK_THAT(lerp(v1, v2, -0.5f), eq4(0.5f, -2.0f, -4.5f, 2.5f));
  CHECK_THAT(lerp(v1, v2, 1.5f), eq4(10.5f, 22.0f, 33.5f, 16.5f));
  // TODO: transform
  const quaternion q1 = normalize(quaternion(-1.0f, 2.0f, -3.0f, 4.0f));
  const float3 v4{ 3.0f, 4.0f, 5.0f };
  const float2 v5{ 3.0f, 4.0f };
  CHECK_THAT(transform(v1, q1), eq4(6.73333f, -2.13333f, -0.333333f, 6.0f));
  CHECK_THAT(transform4(v4, q1), eq4(6.73333f, -2.13333f, -0.333333f, 1.0f));
  CHECK_THAT(transform4(v5, q1), eq4(3.06667f, -1.46667f, -3.66667f, 1.0f));
}

// === float3x2 ===

TEST_CASE("float3x2-ctors") {
  CHECK_THAT(float3x2(
    1.0f, 2.0f,
    3.0f, 4.0f,
    5.0f, 6.0f
  ), eq3x2(
    1.0f, 2.0f,
    3.0f, 4.0f,
    5.0f, 6.0f
  ));
}

TEST_CASE("float3x2-methods") {
  CHECK_THAT(float3x2::identity(), eq3x2(
    1.0f, 0.0f,
    0.0f, 1.0f,
    0.0f, 0.0f
  ));
}

TEST_CASE("float3x2-operators") {
  const float3x2 v1{
    1.0f, 2.0f,
    3.0f, 4.0f,
    5.0f, 6.0f,
  };
  const float3x2 v2{
    7.0f, 4.0f,
    2.0f, 5.0f,
    9.0f, 3.0f,
  };
  CHECK_THAT(v1 + v2, eq3x2(
    8.0f, 6.0f,
    5.0f, 9.0f,
    14.0f, 9.0f
  ));
  CHECK_THAT(v1 - v2, eq3x2(
    -6.0f, -2.0f,
    1.0f, -1.0f,
    -4.0f, 3.0f
  ));
  CHECK_THAT(v1 * v2, eq3x2(
    // v1.m11 * v2.m11 + v1.m12 * v2.m21 + 0.0f * v2.m31, v1.m11 * v2.m12 + v1.m12 * v2.m22 + 0.0f * v2.m32,
    // v1.m21 * v2.m11 + v1.m22 * v2.m21 + 0.0f * v2.m31, v1.m21 * v2.m12 + v1.m22 * v2.m22 + 0.0f * v2.m32,
    // v1.m31 * v2.m11 + v1.m32 * v2.m21 + 1.0f * v2.m31, v1.m31 * v2.m12 + v1.m32 * v2.m22 + 1.0f * v2.m32
    11.0f, 14.0f,
    29.0f, 32.0f,
    56.0f, 53.0f
  ));
  CHECK_THAT(v1 * 2.0f, eq3x2(
    2.0f, 4.0f,
    6.0f, 8.0f,
    10.0f, 12.0f
  ));
  CHECK_THAT(-v1, eq3x2(
    -1.0f, -2.0f,
    -3.0f, -4.0f,
    -5.0f, -6.0f
  ));
  float3x2 v3;
  v3 = {
    9.0f, 3.0f,
    8.0f, 2.0f,
    7.0f, 1.0f,
  };
  CHECK_THAT(v3 += v1, eq3x2(
    10.0f, 5.0f,
    11.0f, 6.0f,
    12.0f, 7.0f
  ));
  v3 = {
    9.0f, 3.0f,
    8.0f, 2.0f,
    7.0f, 1.0f,
  };
  CHECK_THAT(v3 -= v1, eq3x2(
    8.0f, 1.0f,
    5.0f, -2.0f,
    2.0f, -5.0f
  ));
  v3 = {
    9.0f, 3.0f,
    8.0f, 2.0f,
    7.0f, 1.0f,
  };
  CHECK_THAT(v3 *= v1, eq3x2(
    18.0f, 30.0f,
    14.0f, 24.0f,
    15.0f, 24.0f
  ));
  v3 = {
    9.0f, 3.0f,
    8.0f, 2.0f,
    7.0f, 1.0f,
  };
  CHECK_THAT(v3 *= 3.0f, eq3x2(
    27.0f, 9.0f,
    24.0f, 6.0f,
    21.0f, 3.0f
  ));
  v3 = {
    1.0f, 2.0f,
    3.0f, 4.0f,
    5.0f, 6.0f,
  };
  CHECK((v3 == v1) == true);
  CHECK((v3 == v2) == false);
  CHECK((v3 != v1) == false);
  CHECK((v3 != v2) == true);
}

TEST_CASE("float3x2-functions") {
  const float3x2 v1{
    1.0f, 2.0f,
    3.0f, 4.0f,
    5.0f, 6.0f,
  };
  CHECK(is_identity(v1) == false);
  CHECK(is_identity(float3x2::identity()) == true);
  CHECK(is_identity(float3x2{
    1.0f, 0.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
  }) == true);
  CHECK(determinant(v1) == -2.0_a);
  CHECK_THAT(translation(v1), eq2(5.0f, 6.0f));
  // TODO
}

// === float4x4 ===

TEST_CASE("float4x4-ctors") {
  CHECK_THAT(float4x4(
    1.0f, 2.0f, 3.0f, 4.0f,
    5.0f, 6.0f, 7.0f, 8.0f,
    9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f
  ), eq4x4(
    1.0f, 2.0f, 3.0f, 4.0f,
    5.0f, 6.0f, 7.0f, 8.0f,
    9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f
  ));
}

TEST_CASE("float4x4-methods") {
  CHECK_THAT(float4x4::identity(), eq4x4(
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
  ));
}

TEST_CASE("float4x4-operators") {
  const float4x4 v1{
    1.0f, 2.0f, 3.0f, 4.0f,
    5.0f, 6.0f, 7.0f, 8.0f,
    9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const float4x4 v2{
    3.0f, 7.0f, 4.0f, 13.0f,
    5.0f, 2.0f, 9.0f, 21.0f,
    17.0f, 14.0f, 28.0f, 11.0f,
    8.0f, 1.0f, 18.0f, 15.0f,
  };
  CHECK_THAT(v1 + v2, eq4x4(
    4.0f, 9.0f, 7.0f, 17.0f,
    10.0f, 8.0f, 16.0f, 29.0f,
    26.0f, 24.0f, 39.0f, 23.0f,
    21.0f, 15.0f, 33.0f, 31.0f
  ));
  CHECK_THAT(v1 - v2, eq4x4(
    -2.0f, -5.0f, -1.0f, -9.0f,
    0.0f, 4.0f, -2.0f, -13.0f,
    -8.0f, -4.0f, -17.0f, 1.0f,
    5.0f, 13.0f, -3.0f, 1.0f
  ));
  CHECK_THAT(v1 * v2, eq4x4(
    96.0f, 57.0f, 178.0f, 148.0f,
    228.0f, 153.0f, 414.0f, 388.0f,
    360.0f, 249.0f, 650.0f, 628.0f,
    492.0f, 345.0f, 886.0f, 868.0f
  ));
  CHECK_THAT(v1 * 2.0f, eq4x4(
    2.0f, 4.0f, 6.0f, 8.0f,
    10.0f, 12.0f, 14.0f, 16.0f,
    18.0f, 20.0f, 22.0f, 24.0f,
    26.0f, 28.0f, 30.0f, 32.0f
  ));
  CHECK_THAT(-v1, eq4x4(
    -1.0f, -2.0f, -3.0f, -4.0f,
    -5.0f, -6.0f, -7.0f, -8.0f,
    -9.0f, -10.0f, -11.0f, -12.0f,
    -13.0f, -14.0f, -15.0f, -16.0f
  ));
  float4x4 v3;
  v3 = {
    5.0f, 2.0f, 9.0f, 21.0f,
    3.0f, 7.0f, 4.0f, 13.0f,
    8.0f, 1.0f, 18.0f, 15.0f,
    17.0f, 14.0f, 28.0f, 11.0f,
  };
  CHECK_THAT(v3 += v1, eq4x4(
    6.0f, 4.0f, 12.0f, 25.0f,
    8.0f, 13.0f, 11.0f, 21.0f,
    17.0f, 11.0f, 29.0f, 27.0f,
    30.0f, 28.0f, 43.0f, 27.0f
  ));
  v3 = {
    5.0f, 2.0f, 9.0f, 21.0f,
    3.0f, 7.0f, 4.0f, 13.0f,
    8.0f, 1.0f, 18.0f, 15.0f,
    17.0f, 14.0f, 28.0f, 11.0f,
  };
  CHECK_THAT(v3 -= v1, eq4x4(
    4.0f, 0.0f, 6.0f, 17.0f,
    -2.0f, 1.0f, -3.0f, 5.0f,
    -1.0f, -9.0f, 7.0f, 3.0f,
    4.0f, 0.0f, 13.0f, -5.0f
  ));
  v3 = {
    5.0f, 2.0f, 9.0f, 21.0f,
    3.0f, 7.0f, 4.0f, 13.0f,
    8.0f, 1.0f, 18.0f, 15.0f,
    17.0f, 14.0f, 28.0f, 11.0f,
  };
  CHECK_THAT(v3 *= v1, eq4x4(
    369.0f, 406.0f, 443.0f, 480.0f,
    243.0f, 270.0f, 297.0f, 324.0f,
    370.0f, 412.0f, 454.0f, 496.0f,
    482.0f, 552.0f, 622.0f, 692.0f
  ));
  v3 = {
    5.0f, 2.0f, 9.0f, 21.0f,
    3.0f, 7.0f, 4.0f, 13.0f,
    8.0f, 1.0f, 18.0f, 15.0f,
    17.0f, 14.0f, 28.0f, 11.0f,
  };
  CHECK_THAT(v3 *= 3.0f, eq4x4(
    15.0f, 6.0f, 27.0f, 63.0f,
    9.0f, 21.0f, 12.0f, 39.0f,
    24.0f, 3.0f, 54.0f, 45.0f,
    51.0f, 42.0f, 84.0f, 33.0f
  ));
  v3 = {
    1.0f, 2.0f, 3.0f, 4.0f,
    5.0f, 6.0f, 7.0f, 8.0f,
    9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  CHECK((v3 == v1) == true);
  CHECK((v3 == v2) == false);
  CHECK((v3 != v1) == false);
  CHECK((v3 != v2) == true);
}

TEST_CASE("float4x4-functions") {
  const float4x4 v1{
    1.0f, 2.0f, 3.0f, 4.0f,
    5.0f, 6.0f, 7.0f, 8.0f,
    9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  };
  const float4x4 v2{
    7.0f, 5.0f, 2.4f, 0.0f,
    4.0f, 1.3f, 5.9f, 0.0f,
    8.2f, 3.4f, 1.0f, 0.0f,
    4.7f, 5.1f, 2.2f, 1.0f,
  };
  CHECK(is_identity(v1) == false);
  CHECK(is_identity(float4x4::identity()) == true);
  CHECK(is_identity(float4x4{
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
  }) == true);
  CHECK(determinant(v1) == 0.0_a);
  CHECK(determinant(v2) == 97.636_a);
  CHECK_THAT(translation(v2), eq3(4.7f, 5.1f, 2.2f));
  CHECK_THAT(transpose(v1), eq4x4(
    1.0f, 5.0f, 9.0f, 13.0f,
    2.0f, 6.0f, 10.0f, 14.0f,
    3.0f, 7.0f, 11.0f, 15.0f,
    4.0f, 8.0f, 12.0f, 16.0f
  ));
  CHECK_THAT(transpose(v2), eq4x4(
    7.0f, 4.0f, 8.2f, 4.7f,
    5.0f, 1.3f, 3.4f, 5.1f,
    2.4f, 5.9f, 1.0f, 2.2f,
    0.0f, 0.0f, 0.0f, 1.0f
  ));
  // TODO
  CHECK_THAT(make_float4x4_translation(float3(1.0f, 2.0f, 3.0f)), eq4x4(
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    1.0f, 2.0f, 3.0f, 1.0f
  ));
  CHECK_THAT(make_float4x4_scale(float3(4.0f, 5.0f, 6.0f)), eq4x4(
    4.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 5.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 6.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
  ));
  const quaternion q1 = normalize(quaternion(-1.0f, 2.0f, -3.0f, 4.0f));
  CHECK_THAT(make_float4x4_from_quaternion(q1), eq4x4(
    0.133333f, -0.933333f, -0.333333f, 0.0f,
    0.666667f,  0.333333f, -0.666667f, 0.0f,
    0.733333f, -0.133333f,  0.666667f, 0.0f,
    0.0f,       0.0f,       0.0f,      1.0f
  ));
  CHECK_THAT(transform(v1, q1), eq4x4(
    3.66667f, -0.666667f, 0.333333f, 4.0f,
    9.8f,     -3.6f,     -0.999999f, 8.0f,
    15.9333f, -6.53333f, -2.33333f,  12.0f,
    22.0667f, -9.46667f, -3.66667f,  16.0f
  ));
}

// === plane ===

TEST_CASE("plane-ctors") {
  CHECK_THAT(plane(1.0f, 2.0f, 3.0f, 4.0f), eqp(1.0f, 2.0f, 3.0f, 4.0f));
  CHECK_THAT(plane(float3{1.0f, 2.0f, 3.0f}, 4.0f), eqp(1.0f, 2.0f, 3.0f, 4.0f));
  CHECK_THAT(plane(float4{1.0f, 2.0f, 3.0f, 4.0f}), eqp(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("plane-operators") {
  const plane v1 { 1.0f, 2.0f, 3.0f, 4.0f };
  const plane v2 { 3.0f, 7.0f, 19.0f, 23.0f };
  const plane v3 { 1.0f, 2.0f, 3.0f, 4.0f };
  CHECK((v3 == v1) == true);
  CHECK((v3 == v2) == false);
  CHECK((v3 != v1) == false);
  CHECK((v3 != v2) == true);
}

TEST_CASE("plane-functions") {
  const plane v1 { 1.0f, 2.0f, 3.0f, 4.0f };
  CHECK_THAT(normalize(v1), eqp(0.267261f, 0.534522f, 0.801784f, 1.06904f));
  // TODO
  const quaternion q1 = normalize(quaternion(-1.0f, 2.0f, -3.0f, 4.0f));
  CHECK_THAT(transform(v1, q1), eqp(3.66667f, -0.666667f, 0.333333f, 4.0f));
}

// === quaternion ===

TEST_CASE("quaternion-ctors") {
  CHECK_THAT(quaternion(1.0f, 2.0f, 3.0f, 4.0f), eqq(1.0f, 2.0f, 3.0f, 4.0f));
  CHECK_THAT(quaternion(float3{1.0f, 2.0f, 3.0f}, 4.0f), eqq(1.0f, 2.0f, 3.0f, 4.0f));
}

TEST_CASE("quaternion-methods") {
  CHECK_THAT(quaternion::identity(), eqq(0.0, 0.0, 0.0, 1.0));
}

TEST_CASE("quaternion-operators") {
  const quaternion v1 { 1.0f, 2.0f, 3.0f, 4.0f };
  const quaternion v2 { 3.0f, 7.0f, 19.0f, 23.0f };
  CHECK_THAT(v1 + v2, eqq(4.0f, 9.0f, 22.0f, 27.0f));
  CHECK_THAT(v1 - v2, eqq(-2.0f, -5.0f, -16.0f, -19.0f));
  CHECK_THAT(v1 * v2, eqq(52.0f, 64.0f, 146.0f, 18.0f));
  CHECK_THAT(v1 * 2.0f, eqq(2.0f, 4.0f, 6.0f, 8.0f));
  CHECK_THAT(v1 / v2, eqq(-0.00632911f, 0.0295359f, -0.00843882f, 0.175105f));
  CHECK_THAT(-v1, eqq(-1.0f, -2.0f, -3.0f, -4.0f));
  quaternion v3;
  v3 = {3.0f, 4.0f, 5.0f, 6.0f};
  CHECK_THAT(v3 += v1, eqq(4.0f, 6.0f, 8.0f, 10.0f));
  v3 = {3.0f, 4.0f, 5.0f, 6.0f};
  CHECK_THAT(v3 -= v1, eqq(2.0f, 2.0f, 2.0f, 2.0f));
  v3 = {1.5f, 2.0f, 2.5f, 3.0f};
  CHECK_THAT(v3 *= v1, eqq(10.0f, 12.0f, 20.0f, -1.0f));
  v3 = {3.0f, 4.0f, 5.0f, 6.0f};
  CHECK_THAT(v3 *= 3.0f, eqq(9.0f, 12.0f, 15.0f, 18.0f));
  v3 = {3.0f, 4.0f, 5.0f, 6.0f};
  CHECK_THAT(v3 /= v1, eqq(0.133333f, 0.266667f, -5.96046e-8f, 1.66667f));
  v3 = {1.0f, 2.0f, 3.0f, 4.0f};
  CHECK((v3 == v1) == true);
  CHECK((v3 == v2) == false);
  CHECK((v3 != v1) == false);
  CHECK((v3 != v2) == true);
}

TEST_CASE("quaternion-functions") {
  const quaternion v1 { 1.0f, 2.0f, 3.0f, 4.0f };
  CHECK(is_identity(v1) == false);
  CHECK(is_identity(quaternion::identity()) == true);
  CHECK(is_identity(quaternion{0.0f, 0.0f, 0.0f, 1.0f}) == true);
  CHECK(length(v1) == 5.47723_a);
  CHECK(length_squared(v1) == 30.0_a);
  CHECK_THAT(normalize(v1), eqq(0.182574f, 0.365148f, 0.547723f, 0.730297f));
  CHECK_THAT(conjugate(v1), eqq(-1.0f, -2.0f, -3.0f, 4.0f));
  CHECK_THAT(inverse(v1), eqq(-0.0333333f, -0.0666667f, -0.1f, 0.133333f));
  const float3 v2 { 0.0f, 1.0f, 0.0f };
  CHECK_THAT(make_quaternion_from_axis_angle(v2, 0.0f), eqq(0.0f, 0.0f, 0.0f, 1.0f));
  CHECK_THAT(make_quaternion_from_axis_angle(v2, -pi/2), eqq(0.0f, -0.707107f, 0.0f, 0.707107f));
  CHECK_THAT(make_quaternion_from_yaw_pitch_roll(0.0f, 0.0f, 0.0f), eqq(0.0f, 0.0f, 0.0f, 1.0f));
  CHECK_THAT(make_quaternion_from_yaw_pitch_roll(pi/2, 0.0f, 0.0f), eqq(0.0f, 0.707107f, 0.0f, 0.707107f));
  CHECK_THAT(make_quaternion_from_yaw_pitch_roll(0.0f, pi/2, 0.0f), eqq(0.707107f, 0.0f, 0.0f, 0.707107f));
  CHECK_THAT(make_quaternion_from_yaw_pitch_roll(0.0f, 0.0f, pi/2), eqq(0.0f, 0.0f, 0.707107f, 0.707107f));
  CHECK_THAT(make_quaternion_from_yaw_pitch_roll(-pi/2, 0.0f, 0.0f), eqq(0.0f, -0.707107f, 0.0f, 0.707107f));
  CHECK_THAT(make_quaternion_from_yaw_pitch_roll(pi/4, pi/4, pi/4), eqq(0.46194f, 0.191342f, 0.191342f, 0.844623f));
  const float4x4 m1{
     0.707107f,  0.0f,       0.707107f, 1.0f,
     0.0f,       1.0f,       0.0f,      2.0f,
    -0.707107f,  0.0f,       0.707107f, 3.0f,
     4.0f,       5.0f,       6.0f,      1.0f,
  };
  CHECK_THAT(make_quaternion_from_rotation_matrix(m1), eqq(0.0f, -0.382684f, 0.0f, 0.92388f));
  const float4x4 m2{
     0.381126f,  0.904788f,  0.190003f, 0.0f,
     0.523383f, -0.380566f,  0.762391f, 0.0f,
     0.762111f, -0.191122f, -0.618594f, 0.0f,
     0.0f,       0.0f,       0.0f,      1.0f
  };
  CHECK_THAT(make_quaternion_from_rotation_matrix(m2), eqq(0.771409f, 0.462845f, 0.308563f, 0.309017f));
  const float4x4 m3{
    -0.618594f,  0.762391f,  0.190003f, 0.0f,
    -0.191122f, -0.380566f,  0.904788f, 0.0f,
     0.762111f,  0.523383f,  0.381126f, 0.0f,
     0.0f,       0.0f,       0.0f,      1.0f
  };
  CHECK_THAT(make_quaternion_from_rotation_matrix(m3), eqq(0.308563f, 0.462845f, 0.771409f, 0.309017f));
  const float4x4 m4{
    -0.618594f,  0.762111f, -0.191122f, 0.0f,
     0.190003f,  0.381126f,  0.904788f, 0.0f,
     0.762391f,  0.523383f, -0.380566f, 0.0f,
     0.0f,       0.0f,       0.0f,      1.0f
  };
  CHECK_THAT(make_quaternion_from_rotation_matrix(m4), eqq(0.308563f, 0.771409f, 0.462845f, 0.309017f));
  const quaternion v3 { 4.0f, 3.0f, 2.0f, 1.0f };
  CHECK(dot(v1, v3) == 20.0_a);
  const quaternion v4 { 0.0f, 0.0f, 1.0f, 0.0f };
  const quaternion v5 { 0.46194f, 0.191342f, 0.191342f, 0.844623f };
  const quaternion v6 { -0.327447f, -0.218298f, -0.436596f, 0.809017f };
  const quaternion v7 { 0.925506f, 0.154251f, 0.308502f, 0.156434f };
  CHECK(dot(v4, v5) == 0.19134_a);
  CHECK(dot(v6, v7) == -0.34486_a);
  CHECK_THAT(slerp(v1, v3, 0.0), eqq(v1));
  CHECK_THAT(slerp(v1, v3, 1.0), eqq(v3));
  CHECK_THAT(slerp(v1, v3, 0.4), eqq(2.2f, 2.4f, 2.6f, 2.8f));
  CHECK_THAT(slerp(v4, v5, 0.0), eqq(v4));
  CHECK_THAT(slerp(v4, v5, 1.0), eqq(v5));
  CHECK_THAT(slerp(v4, v5, 0.4), eqq(0.246519f, 0.102112f, 0.851841f, 0.450743f));
  CHECK_THAT(slerp(v6, v7, 0.0), eqq(v6));
  CHECK_THAT(slerp(v6, v7, 1.0), eqq(-v7));
  CHECK_THAT(slerp(v6, v7, 0.4), eqq(-0.694796f, -0.232276f, -0.464552f, 0.497491f));
  CHECK_THAT(lerp(v1, v3, 0.0), eqq(normalize(v1)));
  CHECK_THAT(lerp(v1, v3, 1.0), eqq(normalize(v3)));
  CHECK_THAT(lerp(v4, v5, 0.4), eqq(0.236225f, 0.0978475f, 0.86491f, 0.431919f));
  CHECK_THAT(lerp(v4, v5, 0.0), eqq(v4));
  CHECK_THAT(lerp(v4, v5, 1.0), eqq(v5));
  CHECK_THAT(lerp(v4, v5, 0.4), eqq(0.236225f, 0.0978475f, 0.86491f, 0.431919f));
  CHECK_THAT(lerp(v6, v7, 0.0), eqq(v6));
  CHECK_THAT(lerp(v6, v7, 1.0), eqq(-v7));
  CHECK_THAT(lerp(v6, v7, 0.4), eqq(-0.68441f, -0.232713f, -0.465426f, 0.510691f));
  CHECK_THAT(concatenate(v1, v3), eqq(22.0f, 4.0f, 16.0f, -12.0f));
}


int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}
