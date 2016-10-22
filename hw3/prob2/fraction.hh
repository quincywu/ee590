#include <iostream>
#include <stdexcept>

class fraction_exception : public std::runtime_error {
public:
  fraction_exception(const char msg[]) : std::runtime_error(msg) { }
};

class fraction {

public:

	// Constructors and destructors
	fraction(int top = 0, int bottom = 1);
	~fraction();

	// Named constructors

	// The copy constructor
	fraction ( const fraction &f );
	fraction &operator=(int top); //fraction& operator=(int top);

    // Setters
    void set(int top, int bottom);

	// Getters
	int getNum() const { return num; }
	int getDen() const { return den; }

	// Operations
	fraction reduce_fraction () const;

	fraction add ( const fraction &f ) const;
	fraction mult ( const fraction &f ) const;
	fraction divide ( const fraction &f ) const;

	bool equals ( const fraction &f ) const { return (num == f.num && den == f.den); }
	bool less_than ( const fraction &f ) const { return ( (num * f.den) < (f.num * den) ); }

	inline fraction operator+(const fraction &f) { return add(f); }
	inline fraction operator-(const fraction &f) { fraction result = f; result.num *= -1; return add(result); }
	inline fraction operator*(const fraction &f) { return mult(f); }
	inline fraction operator/(const fraction &f) { return divide(f); }
	inline bool operator==(const fraction &f) { return equals(f); }
	inline bool operator!=(const fraction &f) { return !equals(f); }

    // negating the fraction
    inline fraction operator-() { fraction result = *this; result.num *= -1; return result; }

	inline bool operator<(const fraction &f) { return less_than(f); }
	inline bool operator>(const fraction &f) { return f.less_than(*this); }
	inline bool operator<=(const fraction &f) { return less_than(f) || equals(f); }
	inline bool operator>=(const fraction &f) { return f.less_than(*this) || f.equals(*this); }

	fraction power ( int power );

    //TODO VALUEOF

private:
	int num,
		den;

};

// Interface with ostreams
std::ostream& operator<<(std::ostream& os, const fraction &f);
