#ifndef LAB_3_1
#define LAB_3_1
#include <iostream>

class Vector {
  private:
    double x, y, z;
  public:
  Vector(double x, double y, double z);
  Vector& operator = (const Vector& vec);
  Vector& operator += (const Vector& vec);
  Vector& operator -= (const Vector& vec);
  Vector& operator *= (const Vector& vec);
  Vector& operator /= (const Vector& vec);
  bool operator == (const Vector& vec) const;
  bool operator <= (const Vector& vec) const;
  bool operator >= (const Vector& vec) const;
  bool operator < (const Vector& vec) const;
  bool operator > (const Vector& vec) const;
  Vector operator + (const double num) const;
  Vector operator * (const double num) const;
  Vector operator * (const Vector& vec) const;
  Vector operator - (const Vector& vec) const;
  Vector operator + (const Vector& vec) const;
  Vector operator / (const Vector& vec) const;
  Vector& operator ++ ();
  Vector& operator -- ();
  Vector operator ++ (int);
  Vector operator -- (int);
  friend std::ostream& operator << (std::ostream& os, const Vector& vec);
};

#endif