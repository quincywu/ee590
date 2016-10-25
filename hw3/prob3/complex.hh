#include <iostream>
#include <stdexcept>
#include <math.h>

#define EPSILSON 0.0001

class complex_exception : public std::runtime_error {
public:
  complex_exception(const char msg[]) : std::runtime_error(msg) { }
};

class complex {

public:

	// Constructors and destructors
	complex( double left = 0, double right = 0) : real(left), img(right) {};
	~complex();

	// Named constructors

	// The copy constructor
	complex ( const complex &c );
	complex& operator=(double left);

    // Setters
    void set(double left, double right);

	// Getters
	double getReal() const { return real; }
	double getImg() const { return img; }

	// Operations
	complex conjugate () const { complex result (real, -img); return result; } //The complex conjugate of the complex number z = x + yi is defined to be x − yi.
    double magnitude () const; // magnitude = sqrt(real^2 + img^2)
    double angle () const;

	complex add ( const complex &c ) const;
	complex mult ( const complex &c ) const;
	complex divide ( const complex &c ) const;

    bool equals ( const complex &c ) const { return fabs( magnitude() - c.magnitude() ) < EPSILSON; }
	bool less_than ( const complex &c ) const { return magnitude() < c.magnitude(); }

	inline complex operator+(const complex &c) { return add(c); }
	inline complex operator-(const complex &c) { complex result = c; result.real *= -1; result.img *= -1; return add(result); }
	inline complex operator*(const complex &c) { return mult(c); }
	inline complex operator/(const complex &c) { return divide(c); }
    inline bool operator==(const complex &c) { return equals(c); }
	inline bool operator!=(const complex &c) { return !equals(c); }

    inline complex operator*(double d) { return mult(complex(d)); }
    // negating the complex
    inline complex operator-() { complex result = *this; result.real *= -1; result.img *= -1; return result; }

    inline bool operator<(const complex &c) { return less_than(c); }
	inline bool operator>(const complex &c) { return c.less_than(*this); }
	inline bool operator<=(const complex &c) { return less_than(c) || equals(c); }
	inline bool operator>=(const complex &c) { return c.less_than(*this) || c.equals(*this); }

	complex power ( int power );
    complex e_power ();

private:
	double real,
		   img;

};

// Interface with ostreams
std::ostream& operator<<(std::ostream& os, const complex &c);
