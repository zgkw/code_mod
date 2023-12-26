class frac
{
public:
	ll head , tail ;

	frac( ll _head , ll _tail ) : head( _head ) , tail ( _tail ){};

	frac operator + ( const frac& ot )
	{
		frac res( 0 , 0 ) ;

		res.tail = tail * ot.tail ;

		res.head = head * ot.tail + ot.head * tail ;

		ll g = gcd ( res.tail , res.head ) ;

		res.head = res.head / g ;

		res.tail = res.tail / g ;

		cout << "ip:" << ip << '\n' ;

		ip += res.head / res.tail ;

		cout << "ip:" << ip << '\n' ;

		res.head = res.head % res.tail ;

		return res ;
	}
}
