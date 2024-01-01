struct Linear_sieves {
	int n ;
    vector < int > Prime ;
    vector < int > Euler ;
    vector < int > Morbius ;
    vector < bool > notprime ;
    vector < std::pair < i64 , i64 > > div ;

    Linear_sieves () {};
    Linear_sieves ( int _n ) { init ( n ) ;};

    void init ( int _n ) { n = _n ; Prime_work (); }

    void Prime_work () {
        notprime.assign ( n + 1 , 0 ) ;
        notprime [ 0 ] = 1 ;
        notprime [ 1 ] = 1 ;
        for ( i64 i = 2 ; i <= n ; ++ i ) {
            if ( notprime [ i ] == 0 ) {
				Prime.push_back ( i ) ;
            }
            for ( i64 j = 0 ; i * Prime [ j ] <= n ; ++ j ) {
                notprime [ i * Prime [ j ] ] = 1 ;

                if ( i % Prime [ j ] == 0 ) break;
            }
        }
    }
    void Euler_work () {
        Euler.assign ( n + 1 , 0 ) ;
        Euler [ 1 ] = 1 ;
        for ( i64 i = 2 ; i <= n ; ++ i ) {
            if ( notprime [ i ] == 0 ) Euler [ i ] = i - 1 ;
            for ( i64 j = 0 ; i * Prime [ j ] <= n ; ++ j ) {
                i64 now = i * Prime [ j ] ;
                if ( i % Prime [ j ] != 0 ) {
                    Euler [ now ] = ( Prime [ j ] - 1 ) * Euler [ i ] ;
                }
                else {
                    Euler [ now ] = Prime [ j ] * Euler [ i ] ;
                    break ;
                }
            }
        }
    }
    void Morbius_work () {
        Morbius.assign ( n + 1 , 0 ) ;
        Morbius [ 1 ] = 1 ;
        for ( i64 i = 2 ; i <= n ; ++ i ) {
            if ( notprime [ i ] == 0 ) Morbius [ i ] = -1 ;
            for ( i64 j = 0 ; i * Prime [ j ] <= n ; ++ j ) {
                i64 now = i * Prime [ j ] ;
                if ( i % Prime [ j ] != 0 ) {
                    Morbius [ now ] = -Morbius [ i ] ;
                } else break ;
            }
        }
    }
    void Div_work () {
        div.resize ( n + 1 ) ;
        for ( i64 i = 2 ; i <= n ; ++ i ) {
            if ( notprime [ i ] == 0 ) {
                div [ i ] = { 1 , i } ;
            }
            for ( i64 j = 1 ; Prime [ j ] <= i && i * Prime [ j ] <= n ; ++ j ) {
                div [ i * Prime [ j ] ] = { i , Prime [ j ] } ;
                if ( i % Prime [ j ] == 0 ) break;
            }
        }
    }
    i64 size () { return (ll)Prime.size () ;}
    bool isprime ( int n ) { return !notprime [ n ]; }
    i64 eu ( int n ) { return Euler [ n ] ;}
    i64 mo ( int n ) { return Morbius [ n ];}
};
