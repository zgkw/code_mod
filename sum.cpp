struct _Sum {
	using Long = long long ;
	Long operator() (Long x) {
		return ( x * ( x + 1 ) ) >> 1 ;
	}
	Long operator[] (long x) {
		return x * ( x + 1 ) * ( 2 * x + 1 ) / 6  ;
	}
}sum;
