struct Trie {
    int N , tot = 1 ;
    vector < vector < ll > > trie ;
    vector < ll > cnt ;

    Trie ( int N ) : N ( N ) , trie ( N , vector < ll > ( 26 ) ) , cnt ( N ) {} ;

    void add ( const vector < int >& now ) {
        ll p = 1 ;
        for ( auto here : now ) {
            ll& q = trie [ p ] [ here ] ;
            if ( !q ) 
                q = ++ tot ;
            p = q ;
            cnt [ p ] ++ ;
        }
    }
    
    void add(const std::string &a, char offset = 'a') {
        std::vector<int> b(a.size());
        for (int i = 0; i < a.size(); i++) {
            b[i] = a[i] - offset;
        }
        add(b);
    }
};
