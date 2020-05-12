#include "vector3.h"
#include <iostream>
#include <cmath>
namespace vvvector{
using namespace std;

//constructor
vector3::vector3(){} // default constructor -- don't do anything with it
vector3::vector3(float inX, float inY, float inZ){
    x = inX;
    y = inY;
    z = inZ;
}
vector3::vector3(const vector3 &v){
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

//operator overloading
//[]
//const []


vector3& vector3::operator =  (const vector3 &v){
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    return *this;
}

vector3& vector3::operator += (const vector3 &v){
    this->x = this->x + v.x;
    this->y = this->y + v.y;
    this->z = this->z + v.z;
    return *this;
}


vector3& vector3::operator -= (const vector3 &v){
    this->x = this->x - v.x;
    this->y = this->x - v.y;
    this->z = this->x - v.z;
    return *this;
}

vector3& vector3::operator*=(float f){
    this->x = this->x * f;
    this->y = this->y * f;
    this->z = this->z * f;
    return *this;
}

vector3& vector3::operator/=(float f){
    this->x = this->x / f;
    this->y = this->x / f;
    this->z = this->x / f;
    return *this;
}

bool operator==(const vector3 &a, const vector3 &b){
	bool _bool=true;
    if(a.x==b.x && a.y==b.y && a.z==b.z){
        return _bool;
    }
    else{
    	  _bool=false;
        return _bool;
    }
}

bool operator!=(const vector3 &a, const vector3 &b){
	bool _bool=true;
    if(a.x==b.x || a.y==b.y || a.z==b.z){
        _bool=false;
        return _bool;
    }
    else{
        return _bool;
    }
}

vector3 operator-(const vector3 &a){
    return vector3(-a.x, -a.y, -a.z);
}

vector3 operator+(const vector3 &a, const vector3 &b){
    int _tempofx, _tempofy, _tempofz;
    _tempofx = a.x + b.x;
    _tempofy = a.y + b.y;
    _tempofz = a.z + b.z;
    return vector3(_tempofx, _tempofy, _tempofz);
}

vector3 operator-(const vector3 &a, const vector3 &b){
    int _tempofx, _tempofy, _tempofz;
    _tempofx = a.x - b.x;
    _tempofy = a.y - b.y;
    _tempofz = a.z - b.z;
    return vector3(_tempofx, _tempofy, _tempofz);
}

vector3 operator*(const vector3 &v, float f){
    int _tempofx, _tempofy, _tempofz;
    _tempofx = v.x*f;
    _tempofy = v.y*f;
    _tempofz = v.z*f;
    return vector3(_tempofx, _tempofy, _tempofz);
}

vector3 operator*(float f, const vector3 &v){
    int _tempofx, _tempofy, _tempofz;
    _tempofx = v.x*f;
    _tempofy = v.y*f;
    _tempofz = v.z*f;
    return vector3(_tempofx, _tempofy, _tempofz);
}

vector3 operator/(const vector3 &v, float f){
    int _tempofx, _tempofy, _tempofz;
    _tempofx = v.x/f;
    _tempofy = v.y/f;
    _tempofz = v.z/f;
    return vector3(_tempofx, _tempofy, _tempofz);
}

float& vector3::operator [] (unsigned int index){
    if(index==0){
        return x;
    }
    else if(index==1){
        return y;
    }
    else{
        return z;
    }
}

const float& vector3::operator [] (unsigned int index) const{
    if(index==0){
        return x;
    }
    else if(index==1){
        return y;
    }
    else{
        return z;
    }
}

//function
void  vector3::set(float xIn, float yIn, float zIn){
    x = xIn;
    y = yIn;
    z = zIn;
    return;
}

float vector3::length() const{
    return sqrt(x * x + y * y + z * z);
}

void vector3::printVector3() const{
    cout << "(" << x << "¡@" << y << " " << z << ")" << endl;
}


};
