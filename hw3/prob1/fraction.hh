#include <iostream>
#include <stdexcept>

class fraction_exception : public std::runtime_error {
public:
  fraction_exception(const char msg[]) : std::runtime_error(msg) { }
};

class fraction {

public:

	// Constructors and destructors
	fraction(){ //default
		num = 0;
		den = 1;
	}
	fraction(int top, int bottom = 1) : num(top), den(bottom){
		if ( bottom == 0 ){
			throw fraction_exception("Attempted to initialize a fraction with 0 in the denominator");
		}
	}
	~fraction();
	
	// Named constructors
	
	// The copy constructor
	fraction ( const fraction &f );
	fraction operator=(int top); //fraction& operator=(int top);
	
	// Getters 
	int getNum() const { return num; };
	int getDen() const { return den; };
	
	// Operations
	fraction reduce_fraction ( const fraction &f ) const;
	
	fraction add ( const fraction &f ) const;
	fraction subtract ( const fraction &f ) const;
	fraction mult ( const fraction &f ) const;
	fraction divide ( const fraction &f ) const;
	
	bool equals ( const fraction &f ) const { return (num == f.num && den == f.den); };
	bool less_than ( const fraction &f ) const;
	
	inline fraction operator+(const fraction &f) { return add(f); }
	inline fraction operator-(const fraction &f) { fraction temp = f; temp.num *= -1; return add(temp); }
	inline fraction operator*(const fraction &f) { return mult(f); }
	inline fraction operator/(const fraction &f) { return divide(f); }
	inline bool operator==(const fraction &f) { return equals(f); }
	inline bool operator!=(const fraction &f) { return !equals(f); }

	inline bool operator<(const fraction &f) { return less_than(f); }
	inline bool operator>(const fraction &f) { return f.less_than(*this); }
	inline bool operator<=(const fraction &f) { return less_than(f) || equals(f); }
	inline bool operator>=(const fraction &f) { return f.less_than(*this) || f.equals(*this); }

	fraction power ( int );
	
private:
	int num,
		den;
	fraction private_reduce_fraction ();	
		
}

// Interface with ostreams
//std::ostream& operator<<(std::ostream& os, const matrix &m);