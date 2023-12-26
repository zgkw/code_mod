struct zkwSegtree_improve_graph {
    /* Author : atzk */
    int n , N , rf , r2 , r4 ;
    vector < vector < pair < int , int > > > map ;

    zkwSegtree_improve_graph ( int n ) {
        N = ( 1 << ( __lg ( n + 5 ) + 1 ) ) ;
        rf = N >> 1 , r2 = N << 1 , r4 = N << 2 ;
        map.resize ( r4 ) ;
        build () ;
    }

    void build () {
        for ( int i = 1 ; i < rf ; ++ i ) {
            ll fa = i , ls = i << 1 , rs = i << 1 | 1 ;
            map [ fa ].emplace_back ( ls , 0 ) ;
            map [ fa ].emplace_back ( rs , 0 ) ;
            map [ ls + r2 ].emplace_back ( fa + r2 , 0 ) ;
            map [ rs + r2 ].emplace_back ( fa + r2 , 0 ) ;
        }
        for ( int i = N ; i < r2 ; ++ i ) {
            ll fa = i >> 1 , now = i , son = fa + r2 ;
            map [ fa ].emplace_back ( now , 0 ) ;
            map [ now ].emplace_back ( son , 0 ) ;
        }
    }
    void linkto ( ll now , ll l , ll r , ll w ) {
        now += N ;
        for ( l += N - 1 , r += N + 1 ; l ^ r ^ 1 ; l >>= 1 , r >>= 1 ) {
            if ( ~l & 1 ) map [ now ].emplace_back ( l ^ 1 , w ) ;
            if ( r & 1 ) map [ now ].emplace_back ( r ^ 1 , w ) ;
        }
    }
    void linkfrom ( ll now , ll l , ll r , ll w ) {
        now += N ;
        l += N - 1 , r += N + 1 ;
        if ( ~l & 1 ) map [ l ^ 1 ].emplace_back ( now , w ) ;
        if ( r & 1 ) map [ r ^ 1 ].emplace_back ( now , w ) ;       
        l >>= 1 ; r >>= 1 ;
        for ( ; l ^ r ^ 1 ; l >>= 1 , r >>= 1 ) {
            if ( ~l & 1 ) map [ l ^ 1 + r2 ].emplace_back ( now , w ) ;
            if ( r & 1 ) map [ r ^ 1 + r2 ].emplace_back ( now , w ) ;
        }
    }
    void linkpoint ( ll from , ll to , ll w ) {
        map [ from + N ].emplace_back ( to + N , w ) ;
    }
    ll get ( ll now ) {
        return now - N ;
    }
};
