using i64 = int64_t ;

template < typename T , bool op >
struct CFS {
    
    T n , m , add_cnt ;
    vector < T > st , to , nt , w ;

    CFS ( i64 n , i64 m ) : n ( n ) , m ( m ) 
        { st.resize ( n ) , to.resize ( 2 * m + 2 ) , nt.resize ( 2 * m + 2 ) , add_cnt = 1 ;
            if ( op ) w.resize ( 2 * m + 2 ) ;}

    void add ( const i64& u , const i64& v ) {
        to [ ++ add_cnt ] = v ; nt [ add_cnt ] = st [ u ] ; st [ u ] = add_cnt ;}

    void add ( const i64& u , const i64& v , const i64& w ) {
        to [ ++ add_cnt ] = v ; nt [ add_cnt ] = st [ u ] ; this->w [ add_cnt ] = w ; st [ u ] = add_cnt ;}
};

using gs = CFS < i64 , false > ;

template <typename T>
class SegtreeLazyRangeAdd {
	vector<T> tree , lazy ;
	vector<T> *arr ;
	ll n , root , n4 , end ;

	void maintain ( ll cl , ll cr , ll p ){
		ll cm = cl + ( ( cr - cl ) >> 1 ) ;
		if ( cl != cr && (i64) lazy [ p ] ) {
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
    SegtreeLazyRangeAdd < T > () {}
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

template < typename T >
struct heavy_chain_splitting {
    
    using i64 = int64_t ;
    
    i64 n , cnt , root ;
    vector < i64 > size , son , Fa , d , top , id ; vector < i64 > v ;
    vector < T > val ; SegtreeLazyRangeAdd < T > tree ;gs g ;

    heavy_chain_splitting<T> ( i64 n , i64 root , gs& g , vector < i64 >& v ): n ( n ) , root ( root ) ,g ( g ) , v ( v ) {
        size.resize ( n ) , son.resize ( n , -1 ) , Fa.resize ( n ) , d.resize ( n ) ,
        top.resize ( n ) , id.resize ( n ) ,val.resize ( n ) ; cnt = -1 ;
        init () ;
    } 
    
    function < void ( ll , ll ) > dfs1 = [ & ] ( ll now , ll fa ) {
        Fa [ now ] = fa ; d [ now ] = d [ fa ] + 1 ;
        for ( i64 i = g.st [ now ] ; i ; i = g.nt [ i ] ) {
            ll& here = g.to [ i ] ;
            if ( here == fa ) continue ;
            dfs1 ( here , now ) ;
            size [ now ] += size [ here ] ;
            if ( !~son [ now ] || size [ son [ now ] ] < size [ here ] ) {
                son [ now ] = here ;}
        }
        ++ size [ now ] ;
    };

    function < void ( ll , ll ) > dfs2 = [ & ] ( ll now , ll fa ) {
        top [ now ] = fa ; id [ now ] = ++ cnt ; val [ cnt ] = v [ now ] ;
        if ( ~son [ now ] ) dfs2 ( son [ now ] , fa ) ;
        for ( i64 i = g.st [ now ] ; i ; i = g.nt [ i ] ) {
            ll& here = g.to [ i ] ;
            if ( here == Fa [ now ] || here == son [ now ] ) continue ;
            dfs2 ( here , here ) ;   
        }
    };

    function < void ( ll , ll , ll ) > update = [ & ] ( ll u , ll v , ll w ) mutable {
        auto& fa = Fa ;
        while ( top [ u ] != top [ v ] ) {
            if ( d [ top [ u ] ] < d [ top [ v ] ] ) swap ( u , v ) ;
            tree.range_add ( id [ top [ u ] ] + 1 , id [ u ] + 1 , w ) ;
            u = fa [ top [ u ] ] ;
        }
        if ( d [ u ] > d [ v ] ) swap ( u , v ) ;
        tree.range_add ( id [ u ] + 1 , id [ v ] + 1 , w ) ;
    };

    function < i64 ( i64 , i64 ) > query = [ & ] ( ll u , ll v ) mutable {
        auto& fa = Fa ;
        T sum = 0 ;
        while ( top [ u ] != top [ v ] ) {
            if ( d [ top [ u ] ] < d [ top [ v ] ] ) swap ( u , v ) ;
            sum += tree.range_sum ( id [ top [ u ] ] + 1 , id [ u ] + 1 ) ;
            u = fa [ top [ u ] ] ;
        }
        if ( d [ u ] > d [ v ] ) swap ( u , v ) ;
        sum += tree.range_sum ( id [ u ] + 1 , id [ v ] + 1 ) ;
        return (i64)sum ;
    };

    function < void ( i64 , i64 ) > rootupdate = [ & ] ( ll root , ll w ) mutable {
        tree.range_add ( id [ root ] + 1 , id [ root ] + size [ root ]/*  -1 + 1 */ , w ) ;
    };

    function < i64 ( i64 ) >  rootquery = [ & ] ( ll root ) mutable {
        return (i64)tree.range_sum ( id [ root ] + 1 , id [ root ] + size [ root ]/*  - 1 + 1  */) ;
    };

    void init () {
        dfs1 ( root , root ) ;
        dfs2 ( root , root ) ;
        SegtreeLazyRangeAdd < T > tree ( val ) ;
        this->tree = move ( tree ) ;
    }
};
