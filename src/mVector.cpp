#include "mVector.h"

mVector::mVector(double pX, double pY)
{
    //ctor
    x = pX;
    y = pY;
}

mVector::~mVector()
{
    //dtor
}



double mVector::getMagnitude()
{
    return std::sqrt(x*x + y*y);
}
/** \brief Dot product of two vectors
 *
 * \param
 * \param
 * \return
 *
 */

double mVector::dot(const mVector& v, const mVector& v1)
{
    return v.x *v1.x + v.y * v1.y;
}
/** \brief return the angle between vector and x axis OBS NOT TESTED!!
 *
 *
 */




mVector& mVector::operator+=(const mVector& v)
{
    x += v.x;
    y += v.y;
    return *this;
}


mVector& mVector::operator-=(const mVector& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}
/** \brief Multiply by scalar
 *
 */

mVector& mVector::operator*=(double s)
{
    x *= s;
    y *= s;
    return *this;
}
/** \brief divide by scalar
 *
 */

mVector& mVector::operator/=(double s)
{
    x /= s;
    y /= s;
    return *this;
}
