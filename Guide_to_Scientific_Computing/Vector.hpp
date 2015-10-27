#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

class Vector
{
private:
   double* mData; // data stored in vector
   int mSize; // size of vector
public:
   Vector(const Vector& otherVector);
   Vector(int size);
   ~Vector();
   int GetSize() const;
    bool SizeTest(int& size1, int& size2) const;
   double& operator[](int i); // zero-based indexing
   // read-only zero-based indexing
    double& operator[](int i) const;
   double Read(int i) const;
   double& operator()(int i); // one-based indexing
   // assignment
   Vector& operator=(const Vector& otherVector);
   Vector operator+() const; // unary +
   Vector operator-() const; // unary -
   Vector operator+(const Vector& v1) const; // binary +
   Vector operator-(const Vector& v1) const; // binary -
   // scalar multiplication
   Vector operator*(double a) const;
    double operator*(const Vector& other) const;
   // p-norm method
   double CalculateNorm(int p=2) const;
   // declare length function as a friend
   friend int length(const Vector& v);
    friend std::ostream& operator<<(std::ostream& output, const Vector& other);
};

// Prototype signature of length() friend function
int length(const Vector& v);

#endif
//Code from Chapter10.tex line 19 save as Vector.hpp
