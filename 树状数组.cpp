template < typename T >
struct Tree
{
	using i64 = int64_t ;

	i64 n ; vector < T > tree ;
	explicit Tree ( i64 n ) : n ( n ) , tree ( vector < T > ( n + 1 ) ) {}

	void add ( i64 u , i64 k ) { if ( u <= 0 ) return ;
			while ( u <= n ) tree [ u ] += k , u += lowbit ( u ) ;  }
	i64 query ( i64 r ) { if ( r <= 0 ) return 0 ;
			i64 cnt = 0 ;while ( r ) cnt += (i64) tree [ r ] , r -= lowbit ( r ) ;
				return cnt ;}	
	i64 range_query ( i64 l , i64 r ) { return query ( r ) - query ( l - 1 ) ;} 
};
