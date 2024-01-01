template < int _n >
struct ES {
	int n ;
    vector < int > Prime ;
    vector < bool > notprime ;
    vector < std::pair < i64 , i64 > > div ;

    ES (): n ( _n ) , notprime ( n + 1 ) 
            { div.resize ( n + 1 ) ; notprime [ 1 ] = 1 ; init () ;} ;

    void init () {
		Prime.push_back ( 0 ) ;
        for ( i64 i = 2 ; i <= n ; ++ i ) {
            if ( notprime [ i ] == 0 ) {
				Prime.push_back ( i ) ;
            }
            for ( i64 j = 1 ; j < (ll)Prime.size () && i * Prime [ j ] <= n ; ++ j ) {
                notprime [ i * Prime [ j ] ] = 1 ;
                div [ i * Prime [ j ] ] = { i , Prime [ j ] } ;

                if ( i % Prime [ j ] == 0 ) break;
            }
        }
    }
};
