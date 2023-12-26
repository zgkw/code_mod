template <typename T>
class SegtreeLazyRangeAdd {
	vector<T> tree , lazy ;
	vector<T> *arr ;
	ll n , root , n4 , end ;

	void maintain ( ll cl , ll cr , ll p ){
		ll cm = cl + ( ( cr - cl ) >> 1 ) ;
		if ( cl != cr && lazy [ p ] ) {
			lazy [ p << 1 ] += lazy [ p ] ;
			lazy [ p << 1 | 1 ] += lazy [ p ] ;
			tree [ p << 1 ] += lazy [ p ] * ( cm - cl + 1 ) ;
			tree [ p << 1 | 1 ] += lazy [ p ] * ( cr - cm ) ;
			lazy [ p ] = 0 ;
		}
	}
	T range_sum ( ll l , ll r , ll cl , ll cr , ll p )
	{
		if ( l <= cl && r >= cr ) return tree [ p ] ;
		ll m = cl + ( ( cr - cl ) >> 1 ) ;
		T sum = 0 ;
		maintain ( cl , cr , p ) ;
		if ( l <= m ) sum += range_sum ( l , r , cl , m , p << 1 ) ;
		if ( r > m ) sum += range_sum ( l , r , m + 1 , cr , p << 1 | 1 ) ;
		return sum ;
	}
	void range_add ( ll l , ll r , T val , ll cl , ll cr , ll p ) {
		if ( l <= cl && r >= cr ) {
			lazy [ p ] += val ;
			tree [ p ] += ( cr - cl + 1 ) * val ;
			return ;
		}
		ll m = cl + ( ( cr - cl ) >> 1 ) ;
		maintain ( cl , cr , p ) ;
		if ( l <= m ) range_add ( l , r , val , cl , m , p << 1 ) ;
		if ( r > m ) range_add ( l , r , val , m + 1 , cr , p << 1 | 1 ) ;
		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
	}
	void build ( ll s , ll t , ll p ) { 
		if ( s == t ) {
			tree [ p ] = ( *arr )[ s ] ;
			return ;
		}
		ll m = s + ( ( t - s ) >> 1 ) ;
		build ( s , m , p << 1 ) ;
		build ( m + 1 , t , p << 1 | 1 ) ;
		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
	}
public : 
	explicit SegtreeLazyRangeAdd < T > ( vector < T > v ) {
		n = v.size () ;
		n4 = n * 4 ;
		tree = vector < T > ( n4 , 0 ) ;
		lazy = vector < T > ( n4 , 0 ) ;
		arr = &v ;
		end = n - 1 ;
		root = 1 ;
		build ( 0 , end , 1 ) ;
		arr = nullptr ;
	}	
	void show ( ll p , ll depth = 0 ) {
		if ( p > n4 || tree [ p ] == 0 ) return ;
		show ( p << 1 , depth + 1 ) ;
		for ( ll i = 0 ; i < depth ; ++ i ) putchar ( '\t' ) ;
		printf ( "%d:%d\n", tree [ p ] , lazy [ p ] ) ;
		show ( p << 1 | 1 , depth + 1 ) ;
	}

	T range_sum ( int l , int r ) { return range_sum ( l - 1 , r - 1 , 0 , end , root ) ; } 

	void range_add ( ll l , ll r , ll val ) { range_add ( l - 1 , r - 1 , val , 0 , end , root ) ; } 
};

template <typename T>
class SegtreeLazyRangeAdd_and_Mul {
	vector<T> tree , lazy_add , lazy_mul ;
	vector<T> *arr ;
	ll n , root , n4 , end ;

	void maintain ( ll cl , ll cr , ll p ){
		ll cm = cl + ( ( cr - cl ) >> 1 ) ;
		if ( cl != cr && lazy_mul [ p ] != 1 ) {
			lazy_add [ p << 1 ] *= lazy_mul [ p ] ;
			lazy_add [ p << 1 | 1 ] *= lazy_mul [ p ] ;
			lazy_mul [ p << 1 ] *= lazy_mul [ p ] ;
			lazy_mul [ p << 1 | 1 ] *= lazy_mul [ p ] ;			
			tree [ p << 1 ] *= lazy_mul [ p ] ;
			tree [ p << 1 | 1 ] *= lazy_mul [ p ] ;
			lazy_mul [ p ] = 1 ;
		}
		if ( cl != cr && lazy_add [ p ] ) {
			lazy_add [ p << 1 ] += lazy_add [ p ] ;
			lazy_add [ p << 1 | 1 ] += lazy_add [ p ] ;
			tree [ p << 1 ] += lazy_add [ p ] * ( cm - cl + 1 ) ;
			tree [ p << 1 | 1 ] += lazy_add [ p ] * ( cr - cm ) ;
			lazy_add [ p ] = 0 ;
		}
	}
	T range_sum ( ll l , ll r , ll cl , ll cr , ll p )
	{
		if ( l <= cl && r >= cr ) return tree [ p ] ;
		ll m = cl + ( ( cr - cl ) >> 1 ) ;
		T sum = 0 ;
		maintain ( cl , cr , p ) ;
		if ( l <= m ) sum += range_sum ( l , r , cl , m , p << 1 ) ;
		if ( r > m ) sum += range_sum ( l , r , m + 1 , cr , p << 1 | 1 ) ;
		return sum ;
	}
	void range_add ( ll l , ll r , T val , ll cl , ll cr , ll p ) {
		if ( l <= cl && r >= cr ) {
			lazy_add [ p ] += val ;
			tree [ p ] += ( cr - cl + 1 ) * val ;
			return ;
		}
		ll m = cl + ( ( cr - cl ) >> 1 ) ;
		maintain ( cl , cr , p ) ;
		if ( l <= m ) range_add ( l , r , val , cl , m , p << 1 ) ;
		if ( r > m ) range_add ( l , r , val , m + 1 , cr , p << 1 | 1 ) ;
		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
	}
	void range_mul ( ll l , ll r , T val , ll cl , ll cr , ll p ) {
		if ( l <= cl && r >= cr ) {
			lazy_add [ p ] *= val ;
			lazy_mul [ p ] *= val ;
			tree [ p ] = tree [ p ] * val ;
			return ;
		}
		ll m = cl + ( ( cr - cl ) >> 1 ) ;
		maintain ( cl , cr , p ) ;
		if ( l <= m ) range_mul ( l , r , val , cl , m , p << 1 ) ;
		if ( r > m ) range_mul ( l , r , val , m + 1 , cr , p << 1 | 1 ) ;
		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
	}
	void build ( ll s , ll t , ll p ) { 
		if ( s == t ) {
			tree [ p ] = ( *arr )[ s ] ;
			return ;
		}
		ll m = s + ( ( t - s ) >> 1 ) ;
		build ( s , m , p << 1 ) ;
		build ( m + 1 , t , p << 1 | 1 ) ;
		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
	}
public : 
	explicit SegtreeLazyRangeAdd_and_Mul < T > ( vector < T > v ) {
		n = v.size () ;
		n4 = n * 4 ;
		tree = vector < T > ( n4 , 0 ) ;
		lazy_add = vector < T > ( n4 , 0 ) ;
		lazy_mul = vector < T > ( n4 , 1 ) ;
		arr = &v ;
		end = n - 1 ;
		root = 1 ;
		build ( 0 , end , 1 ) ;
		arr = nullptr ;
	}	
	void show ( ll p , ll depth = 0 ) {
		if ( p > n4 || tree [ p ] == 0 ) return ;
		show ( p << 1 , depth + 1 ) ;
		for ( ll i = 0 ; i < depth ; ++ i ) putchar ( '\t' ) ;
		printf ( "%d:%d\n", tree [ p ] , lazy_add [ p ] ) ;
		show ( p << 1 | 1 , depth + 1 ) ;
	}

	T range_sum ( int l , int r ) { return range_sum ( l - 1 , r - 1 , 0 , end , root ) ; } 

	void range_add ( ll l , ll r , ll val ) { range_add ( l - 1 , r - 1 , val , 0 , end , root ) ; } 

	void range_mul ( ll l , ll r , ll val ) { range_mul ( l - 1 , r - 1 , vla ,  0 , end , root ) ; }
};

template <typename T>
class SegtreeLazyRangeSet {
	vector<T> tree , lazy ;
	vector<T> *arr ;
	ll n , root , n4 , end ;

	void maintain ( ll cl , ll cr , ll p ){
		ll cm = cl + ( ( cr - cl ) >> 1 ) ;
		if ( cl != cr && lazy [ p ] ) {
			lazy [ p << 1 ] = lazy [ p ] ;
			lazy [ p << 1 | 1 ] = lazy [ p ] ;
			tree [ p << 1 ] = lazy [ p ] * ( cm - cl + 1 ) ;
			tree [ p << 1 | 1 ] = lazy [ p ] * ( cr - cm ) ;
			lazy [ p ] = 0 ;
		}
	}
	T range_sum ( ll l , ll r , ll cl , ll cr , ll p )
	{
		if ( l <= cl && r >= cr ) return tree [ p ] ;
		ll m = cl + ( ( cr - cl ) >> 1 ) ;
		T sum = 0 ;
		maintain ( cl , cr , p ) ;
		if ( l <= m ) sum += range_sum ( l , r , cl , m , p << 1 ) ;
		if ( r > m ) sum += range_sum ( l , r , m + 1 , cr , p << 1 | 1 ) ;
		return sum ;
	}
	void range_set ( ll l , ll r , T val , ll cl , ll cr , ll p ) {
		if ( l <= cl && r >= cr ) {
			lazy [ p ] = val ;
			tree [ p ] = ( cr - cl + 1 ) * val ;
			return ;
		}
		ll m = cl + ( ( cr - cl ) >> 1 ) ;
		maintain ( cl , cr , p ) ;
		if ( l <= m ) range_set ( l , r , val , cl , m , p << 1 ) ;
		if ( r > m ) range_set ( l , r , val , m + 1 , cr , p << 1 | 1 ) ;
		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
	}
	void build ( ll s , ll t , ll p ) {
		if ( s == t ) {
			tree [ p ] = ( *arr )[ s ] ;
			return ;
		}
		ll m = s + ( ( t - s ) >> 1 ) ;
		build ( s , m , p << 1 ) ;
		build ( m + 1 , t , p << 1 | 1 ) ;
		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
	}
public : 
	explicit SegtreeLazyRangeAdd < T > ( vector < T > v ) {
		n = v.size () ;
		n4 = n * 4 ;
		tree = vector < T > ( n4 , 0 ) ;
		lazy = vector < T > ( n4 , 0 ) ;
		arr = &v ;
		end = n - 1 ;
		root = 1 ;
		build ( 0 , end , 1 ) ;
		arr = nullptr ;
	}	
	void show ( ll p , ll depth = 0 ) {
		if ( p > n4 || tree [ p ] == 0 ) return ;
		show ( p << 1 , depth + 1 ) ;
		for ( ll i = 0 ; i < depth ; ++ i ) putchar ( '\t' ) ;
		printf ( "%d:%d\n", tree [ p ] , lazy [ p ] ) ;
		show ( p << 1 | 1 , depth + 1 ) ;
	}

	T range_sum ( ll l , ll r ) { return range_sum ( l , r , 0 , end , root ) ; } 

	void range_set ( ll l , ll r , ll val ) { range_set ( l , r , val , 0 , end , root ) ; } 
};
