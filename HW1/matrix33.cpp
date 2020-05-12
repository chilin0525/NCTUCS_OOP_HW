#include "matrix33.h"
#include <iostream>

using namespace std;
//constructor
matrix33::matrix33() {}
matrix33::matrix33(const matrix33 &qq)
{
    this->vec1 = qq.vec1;
    this->vec2 = qq.vec2;
    this->vec3 = qq.vec3;
}

matrix33::matrix33(const vector3 &vvec1,const vector3 &vvec2, const vector3 &vvec3){
    this->vec1 = vvec1;
    this->vec2 = vvec2;
    this->vec3 = vvec3;
}

//operator overloading

vector3& matrix33::operator[](unsigned int index){
    if(index==0){
        return vec1;
    }
    else if(index==1){
        return vec2;
    }
    else{
        return vec3;
    }
}

matrix33 &matrix33::operator=(const matrix33 _mat)
{
    this->vec1 = _mat.vec1;
    this->vec2 = _mat.vec2;
    this->vec3 = _mat.vec3;
    return *this;
}

matrix33 &matrix33::operator*=(const matrix33 _mat)
{
    this->vec1.x = _mat.vec1.x * this->vec1.x;
    this->vec1.y = _mat.vec1.y * this->vec1.y;
    this->vec1.z = _mat.vec1.z * this->vec1.z;
    this->vec2.x = _mat.vec2.x * this->vec2.x;
    this->vec2.y = _mat.vec2.y * this->vec2.y;
    this->vec2.z = _mat.vec2.z * this->vec2.z;
    this->vec3.x = _mat.vec3.x * this->vec3.x;
    this->vec3.y = _mat.vec3.y * this->vec3.y;
    this->vec3.z = _mat.vec3.z * this->vec3.z;
    return *this;
}

matrix33 &matrix33::operator*=(double f)
{
    this->vec1.x = this->vec1.x * f;
    this->vec1.y = this->vec1.y * f;
    this->vec1.z = this->vec1.z * f;
    this->vec2.x = this->vec2.x * f;
    this->vec2.y = this->vec2.y * f;
    this->vec2.z = this->vec2.z * f;
    this->vec3.x = this->vec3.x * f;
    this->vec3.y = this->vec3.y * f;
    this->vec3.z = this->vec3.z * f;
    return *this;
}

matrix33& matrix33::operator*= (const int f){
	 this->vec1.x = this->vec1.x * f;
    this->vec1.y = this->vec1.y * f;
    this->vec1.z = this->vec1.z * f;
    this->vec2.x = this->vec2.x * f;
    this->vec2.y = this->vec2.y * f;
    this->vec2.z = this->vec2.z * f;
    this->vec3.x = this->vec3.x * f;
    this->vec3.y = this->vec3.y * f;
    this->vec3.z = this->vec3.z * f;
    return *this;
}



bool operator!=(const matrix33 &_mat, const matrix33 &_mat2)
{
    int count = 0;

    if(_mat.vec1.x == _mat2.vec1.x)count++;
    if(_mat.vec1.y == _mat2.vec1.y)count++;
    if(_mat.vec1.z == _mat2.vec1.z)count++;
    if(_mat.vec2.x == _mat2.vec2.x)count++;
    if(_mat.vec2.y == _mat2.vec2.y)count++;
    if(_mat.vec2.z == _mat2.vec2.z)count++;
    if(_mat.vec3.x == _mat2.vec3.x)count++;
    if(_mat.vec3.y == _mat2.vec3.y)count++;
    if(_mat.vec3.z == _mat2.vec3.z)count++;

    if (count != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

matrix33 operator+(const matrix33 &_mat, const matrix33 &_mat2)
{
    matrix33 _temp;
    _temp.vec1.x=_mat.vec1.x+_mat2.vec1.x;
    _temp.vec1.y=_mat.vec1.y+_mat2.vec1.y;
    _temp.vec1.z=_mat.vec1.z+_mat2.vec1.z;
    _temp.vec2.x=_mat.vec2.x+_mat2.vec2.x;
    _temp.vec2.y=_mat.vec2.y+_mat2.vec2.y;
    _temp.vec2.z=_mat.vec2.z+_mat2.vec2.z;
    _temp.vec3.x=_mat.vec3.x+_mat2.vec3.x;
    _temp.vec3.y=_mat.vec3.y+_mat2.vec3.y;
    _temp.vec3.z=_mat.vec3.z+_mat2.vec3.z;
    return _temp;
}

matrix33 operator-(const matrix33 &_mat, const matrix33 &_mat2)
{
    matrix33 _temp;
    _temp.vec1.x=_mat.vec1.x-_mat2.vec1.x;
    _temp.vec1.y=_mat.vec1.y-_mat2.vec1.y;
    _temp.vec1.z=_mat.vec1.z-_mat2.vec1.z;
    _temp.vec2.x=_mat.vec2.x-_mat2.vec2.x;
    _temp.vec2.y=_mat.vec2.y-_mat2.vec2.y;
    _temp.vec2.z=_mat.vec2.z-_mat2.vec2.z;
    _temp.vec3.x=_mat.vec3.x-_mat2.vec3.x;
    _temp.vec3.y=_mat.vec3.y-_mat2.vec3.y;
    _temp.vec3.z=_mat.vec3.z-_mat2.vec3.z;
    return _temp;
}

matrix33 operator*(const matrix33& _mat,const matrix33& _mat2)
{
    matrix33 _temp;
    _temp.vec1.x=_mat.vec1.x*_mat2.vec1.x+_mat.vec2.x*_mat2.vec1.y+_mat.vec3.x*_mat2.vec1.z;
    _temp.vec2.x=_mat.vec1.x*_mat2.vec2.x+_mat.vec2.x*_mat2.vec2.y+_mat.vec3.x*_mat2.vec2.z;
    _temp.vec3.x=_mat.vec1.x*_mat2.vec3.x+_mat.vec2.x*_mat2.vec3.y+_mat.vec3.x*_mat2.vec3.z;
    _temp.vec1.y=_mat.vec1.y*_mat2.vec1.x+_mat.vec2.y*_mat2.vec1.y+_mat.vec3.y*_mat2.vec1.z;
    _temp.vec2.y=_mat.vec1.y*_mat2.vec2.x+_mat.vec2.y*_mat2.vec2.y+_mat.vec3.y*_mat2.vec2.z;
    _temp.vec3.y=_mat.vec1.y*_mat2.vec3.x+_mat.vec2.y*_mat2.vec3.y+_mat.vec3.y*_mat2.vec3.z;
    _temp.vec1.z=_mat.vec1.z*_mat2.vec1.x+_mat.vec2.z*_mat2.vec1.y+_mat.vec3.z*_mat2.vec1.z;
    _temp.vec2.z=_mat.vec1.z*_mat2.vec2.x+_mat.vec2.z*_mat2.vec2.y+_mat.vec3.z*_mat2.vec2.z;
    _temp.vec3.z=_mat.vec1.z*_mat2.vec3.x+_mat.vec2.z*_mat2.vec3.y+_mat.vec3.z*_mat2.vec3.z;
    return _temp;
}

matrix33 operator*(const matrix33 &_mat,double f){
    matrix33 temp;
    temp.vec1.x = _mat.vec1.x * f;
    temp.vec1.y = _mat.vec1.y * f;
    temp.vec1.z = _mat.vec1.z * f;
    temp.vec2.x = _mat.vec2.x * f;
    temp.vec2.y = _mat.vec2.y * f;
    temp.vec2.z = _mat.vec2.z * f;
    temp.vec3.x = _mat.vec3.x * f;
    temp.vec3.y = _mat.vec3.y * f;
    temp.vec3.z = _mat.vec3.z * f;
    return temp;
}

//function  1 0 0
//          0 1 0
//          0 0 1
void matrix33::identity(){
    vec1[0] = 1;
    vec1[1] = 0;
    vec1[2] = 0;
    vec2[0] = 0;
    vec2[1] = 1;
    vec2[2] = 0;
    vec3[0] = 0;
    vec3[1] = 0;
    vec3[2] = 1;
}

double matrix33::determinant(){
    double _pos = vec1[0] * vec2[1] * vec3[2] + vec1[1] * vec2[2] * vec3[0] + vec1[2] * vec2[0] * vec3[1];
    double _nag = vec1[2] * vec2[1] * vec3[0] + vec2[2] * vec3[1] * vec1[0] + vec3[2] * vec1[1] * vec2[0];
    return (_pos - _nag);
}

matrix33 matrix33::invert(){  //wrong
    double _invertMatrix[3][3];
    double _der = (vec1[0] * vec2[1] * vec3[2] + vec1[1] * vec2[2] * vec3[0] + vec1[2] * vec2[0] * vec3[1]) - (vec1[2] * vec2[1] * vec3[0] + vec2[2] * vec3[1] * vec1[0] + vec3[2] * vec1[1] * vec2[0]);
    _invertMatrix[0][0] = (vec2[1] * vec3[2] - vec2[2] * vec3[1]) / _der;
    _invertMatrix[0][1] = (vec1[1] * vec3[2] - vec1[2] * vec3[1]) / _der * (-1);
    _invertMatrix[0][2] = (vec1[1] * vec2[2] - vec1[2] * vec2[1]) / _der;
    _invertMatrix[1][0] = (vec2[0] * vec3[2] - vec2[2] * vec3[0]) / _der * (-1);
    _invertMatrix[1][1] = (vec1[0] * vec3[2] - vec1[2] * vec3[0]) / _der;
    _invertMatrix[1][2] = (vec1[0] * vec2[2] - vec2[0] * vec1[2]) / _der * (-1);
    _invertMatrix[2][0] = (vec2[0] * vec3[1] - vec2[1] * vec3[0]) / _der;
    _invertMatrix[2][1] = (vec1[0] * vec3[1] - vec1[1] * vec3[0]) / _der * (-1);
    _invertMatrix[2][2] = (vec1[0] * vec2[1] - vec1[1] * vec2[0]) / _der;

    matrix33 _temp;
    for(int i=0;i<=2;i++){
    	for(int j=0;j<=2;j++){
    		_temp[i][j]=_invertMatrix[i][j];
		 }
	 }

    return _temp;
}

void matrix33::printMatrix() const
{
    cout << vec1.x << "  " ;
    cout << vec2.x << "  " ;
    cout << vec3.x << endl;
    cout << vec1.y << "  " ;
    cout << vec2.y << "  " ;
    cout << vec3.y << endl;
    cout << vec1.z << "  " ;
    cout << vec2.z << "  " ;
    cout << vec3.z << endl;
}

