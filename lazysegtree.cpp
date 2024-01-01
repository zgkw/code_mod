template < class Tag , class Info > 
struct LazySegtree {
	int n ;
	std::vector < Info > tree ; 
	std::vector < Tag > lazy ;
	LazySegtree (): n(0) {}
	LazySegtree ( const int& n , const Info& x = Info () ) {
		init ( n , x ) ;
	}
	template < class T >
	LazySegtree ( const std::vector < T >& v ) {
		init ( v ) ;
	}
	void init ( int n , const Info& x = Info () ) {
		init ( std::vector < Info > ( n , x ) ) ;
	}
	template < class T > 
	void init ( const std::vector < T >& v ) {
		n = (int)v.size () ;
        tree.assign(4 << std::__lg(n), Info());
        lazy.assign(4 << std::__lg(n), Tag());
		auto build = [ & ] ( auto&&build , int l , int r , int p ) -> void {
			if ( ( r - l ) == 1 ) {
				tree [ p ] = v [ l ] ;
				return ;
			}
			int mid = ( r + l ) >> 1 ;
			build ( build , l , mid , p << 1 ) ;
			build ( build , mid , r , p << 1 | 1 ) ;
			pull ( p ) ;
		};
		build ( build , 0 , n , 1 ) ;
	}
	void apply ( int p , const Tag& x ) {
		tree [ p ].apply ( x ) ;
		lazy [ p ].apply ( x ) ;
	}
	void push ( int p ) {
		apply ( p << 1 , lazy [ p ] ) ;
		apply ( p << 1 | 1 , lazy [ p ] );
		lazy [ p ] = Tag () ;
	}
	void pull ( int p ) {
		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
	}
	void range_Change ( int l , int r , const Tag& info ) {
		auto range_change = [ & ] ( auto&&range_change , int l , int r , int ls , int rs , int p , const Tag& info ) -> void {
			if ( rs <= l || r <= ls ) return ;
			if ( ls <= l && r <= rs ) {
				apply ( p , info );
				return ;
			}
			int mid = ( l + r ) >> 1 ;
			push ( p ) ;
			range_change ( range_change , l , mid , ls , rs , p << 1 , info ) ;
			range_change ( range_change , mid , r , ls , rs , p << 1 | 1 , info ) ;
			pull ( p ) ;
		};
		range_change ( range_change , 0 , n , l , r , 1 , info ) ;
	}
	Info range_Query ( int l , int r ) {
		auto range_query = [ & ] ( auto&& range_query , int l , int r , int ls , int rs , int p ) -> Info {
			if ( rs <= l || r <= ls ) {
				return Info () ;
			}
			if ( ls <= l && r <= rs ) {
				return tree [ p ] ;
			}
			int mid = ( l + r ) >> 1 ;
			push ( p ) ;
			return range_query ( range_query , l , mid , ls , rs , p << 1 ) 
				+ range_query ( range_query , mid , r , ls , rs , p << 1 | 1 ) ;
		};
		return range_query ( range_query , 0 , n , l , r , 1 ) ;
	}
};
struct Tag {
	int add = 0 ;
	void apply ( const Tag& x ) & {
		add += x.add ;
	}
};
struct Info {
	long long val = 0 , len = 1 ;
	void apply ( const Tag& x ) & {
		val += 1ll * x.add * ( len ) ;
	}
};

Info operator+ ( const Info & a , const Info& b ) {
	return { a.val + b.val , a.len + b.len } ;
}
