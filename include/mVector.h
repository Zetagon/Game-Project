#ifndef MVECTOR_H
#define MVECTOR_H
#include <math.h>
#include <algorithm>
#define E_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062
class mVector
{
    public:
        /** Default constructor */
        mVector(double pX, double pY);
        /** Default destructor */
        virtual ~mVector();
        mVector& operator+=(const mVector& v);
        mVector& operator-=(const mVector& v);
        mVector& operator*=(double s);
        mVector& operator/=(double s);

        static double dot(const mVector& v,const  mVector& v1);

        double getMagnitude();

        double x; //!< Member variable "x"
        double y; //!< Member variable "y"

    protected:

    private:
};
//    inline mVector operator+(const mVector v,const  mVector& v1);
//    inline mVector operator-(const mVector& v,const  mVector& v1);
//    inline mVector operator*(const mVector& v,const double s);
inline mVector operator+(const mVector& v,const  mVector& v1)
{
    return mVector{v1.x + v.x, v1.y + v.y};
}

inline mVector operator-(const mVector& v,const  mVector& v1)
{
    return mVector{v.x - v1.x, v.y - v1.y};
}
inline mVector operator*(const  mVector& v , const double s)
{
    return mVector(v.x * s, v.y * s);
}
//for making operator commutativ
inline mVector operator*(const double s, const mVector& v){    return v * s;   }

inline mVector operator/(const  mVector& v , const double s)
{
    return mVector(v.x / s, v.y / s);
}
//for making operator commutativ
inline mVector operator/(const double s, const mVector& v){    return v / s;  }
#endif // MVECTOR_H
