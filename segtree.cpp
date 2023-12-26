template < typename T > 
struct segtreereload {
    function < void() > build_over = [ & ] () {} ;
    function < void() > build_maintain = [ & ] () {} ;
    function < void() > range_change_over = [ & ] () {} ;
    function < void() > range_change_maintain = [ & ] () {} ;
    function < void() > range_query_over = [ & ] () {} ;
    function < void() > range_query_maintain = [ & ] () {} ;
};

template < typename T >
struct segtree :public segtreereload<T> {
    int n ; vector < T > tree ;
    segtree ( int n ) : n ( n ) , tree ( n ) {} ;
    void build ( int l , int r , int tag ) {
        if ( l == r ) {
            this->build_over () ;
            return ;
        }
        int mid = ( l + r ) >> 1 ;
        build ( l , mid , tag << 1 ) ;
        build ( mid + 1 , r , tag << 1 | 1 ) ;
        this->build_maintain () ;
    }
    void range_change ( int l , int r , int start , int end , T need , int tag ) {
        if ( l > end || r < start ) return ;
        if ( start <= l && r <= end ) {
            this->range_change_over () ;
            return ;
        }
        int mid = ( l + r ) >> 1 ;
        range_change ( l , mid , start , end , need , tag << 1 ) ;
        range_change ( mid + 1 , r , start , end , need , tag << 1 | 1 ) ;
        this->range_change_maintain () ;
    }
    void range_query ( int l , int r , int start , int end , T need , int tag ) {
        if ( l > end || r < start ) return ;
        if ( start <= l && r <= end ) {
            this->range_query_over () ;
            return ;
        }
        int mid = ( l + r ) >> 1 ;
        range_query ( l , mid , start , end , need , tag << 1 ) ;
        range_query ( mid + 1 , r , start , end , need , tag << 1 | 1 ) ;
        this->range_query_maintain () ;
    }
};
