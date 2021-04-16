#include "Vector3D.h"

double Vector3D::GetX() const { return x; }
double Vector3D::GetY() const { return y; }
double Vector3D::GetZ() const { return z; }

void Vector3D::SetX(double value) { x = value; }
void Vector3D::SetY(double value) { y = value; }
void Vector3D::SetZ(double value) { z = value; }

Vector3D::Vector3D() : Object() { x = 0, y = 0, z = 0; }
Vector3D::Vector3D(double x = 0, double y = 0, double z = 0) throw(invalid_argument, bad_exception, MyException, const char*)  
	: Object()
{
	if (x == 1 && y == 1 && z == 1)
		throw invalid_argument("Invalid_argument");
	else if (x == 2 && y == 2 && z == 2)
		throw bad_exception();
	else if (x == 3 && y == 3 && z == 3)
		throw MyException("MyException");
	else if (x == 4 && y == 4 && z == 4)
		throw "Exception";

	this->x = x;
	this->y = y;
	this->z = z;
}
Vector3D::Vector3D(const Vector3D& A) : Object()
{
	x = A.GetX();
	y = A.GetY();
	z = A.GetZ();
}

Vector3D& Vector3D::operator = (const Vector3D& A)
{
	x = A.x;
	y = A.y;
	z = A.z;

	return *this;
}
ostream& operator << (ostream& out, const Vector3D& A)
{
	out << string(A);
	return out;
}
istream& operator >> (istream& in, Vector3D& A)
{
	cout << "Enter an X of Vector3D: "; in >> A.x;
	cout << "Enter an Y of Vector3D: "; in >> A.y;
	cout << "Enter a Z of Vector3D: "; in >> A.z;
	return in;
}
Vector3D::operator string() const
{
	stringstream ss;
	ss << "X of Vector3D is equal to " << x << endl;
	ss << "Y of Vector3D is equal to " << y << endl;
	ss << "Z of Vector3D is equal to " << z << endl;
	return ss.str();
}

Vector3D& Vector3D::operator ++ ()
{
	x++;
	return *this;
}
Vector3D& Vector3D::operator -- ()
{
	x--;
	return *this;
}
Vector3D Vector3D::operator ++ (int)
{
	Vector3D t(*this);
	y++;
	return t;
}
Vector3D Vector3D::operator -- (int)
{
	Vector3D t(*this);
	y--;
	return t;
}

Vector3D operator +(Vector3D& A, Vector3D& B)
{
	Vector3D t(A.x + B.x, A.y + B.y, A.z + B.z);
	return t;
}
Vector3D operator -(Vector3D& A, Vector3D& B)
{
	Vector3D t(A.x - B.x, A.y - B.y, A.z - B.z);
	return t;
}
double operator * (Vector3D& A, Vector3D& B)
{
	Vector3D t2(A.x * B.x, A.y * B.y, A.z * B.z);
	return t2.x + t2.y + t2.z;
}