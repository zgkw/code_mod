ll inv [ maxn ] ;

void inv_f ( ll n , ll p )								// 用于求大量逆元
{
	inv[ 1 ] = 1;

	for ( int i = 2 ; i <= n ; ++ i )
		inv [ i ] = ( ll )( p - p / i ) * inv [ p % i ] % p ;
}
