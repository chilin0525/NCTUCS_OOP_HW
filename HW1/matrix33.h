#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"
using namespace vvvector;
class matrix33
{

//data
public:
    //float _record[2][2];
    vector3 vec1;
    vector3 vec2;
    vector3 vec3;


    //constructs~
    matrix33();
    matrix33(const vector3 &vec1,const vector3 &vec2, const vector3 &vec3);
    matrix33(const matrix33 &qq);

//operator overloading
    vector3         &operator[](unsigned int _index);
    matrix33        &operator=(const matrix33 _mat);
    matrix33        &operator*=(const matrix33 _mat);
    matrix33        &operator*=(double f);
    matrix33        &operator*= (const int i);
    friend matrix33 operator*(const matrix33& _mat,const matrix33& _mat2);
    friend bool     operator!=(const matrix33& _mat, const matrix33 &_mat2);
    friend matrix33 operator+(const matrix33& _mat, const matrix33 &_mat2);
    friend matrix33 operator-(const matrix33& _mat, const matrix33 &_mat2);
    friend matrix33 operator*(const matrix33& _mat,double f);

    //functions
    void identity();
    double determinant();
    matrix33 invert();
    void printMatrix() const;

};

#endif
