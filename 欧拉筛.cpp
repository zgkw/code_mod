using i64 = int64_t ;

template < typename T , bool op = false > 
struct ES {

    i64 n , Prime_cnt ;
    vector < T > Prime ;
    vector < bool > Isp ;
    vector < std::pair < i64 , i64 > > dpos ;
    

    ES ( i64 n ): n ( n ) , Prime ( n ) , Isp ( n + 1 ) 
            { Prime_cnt = 0 ; if ( op ) dpos.resize ( n + 1 ) ; Isp [ 1 ] = 1 ; } ;

    void ESor () {
        for ( i64 i = 2 ; i <= n ; ++ i ) {
            if ( Isp [ i ] == 0 ) {
                Prime [ ++ Prime_cnt ] = i ;
            }
            for ( i64 j = 1 ; j <= Prime_cnt && i * Prime [ j ] <= n ; ++ j ) {
                Isp [ i * Prime [ j ] ] = 1 ;
                if constexpr ( op ) dpos [ i * Prime [ j ] ] = { i , Prime [ j ] } ;

                if ( i % Prime [ j ] == 0 ) break;
            }
        }
    }
};

using ESO = ES < i64 , false > ;
