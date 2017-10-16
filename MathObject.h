//header for MathObject

template< class T >
class MathObject {

public:
	//basic math objects defined by addition and scalar multiplication
	//subtracting is just additiong with a negative value
	//division is multiplication by a factor
	virtual T operator+(T& x) = 0;
	virtual T operator*(T& x) = 0;
};