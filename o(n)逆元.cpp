ll inv [ maxn ] ;

void inv_f ( ll n , ll p )								// �����������Ԫ
{
	inv[ 1 ] = 1;

	for ( int i = 2 ; i <= n ; ++ i )
		inv [ i ] = ( ll )( p - p / i ) * inv [ p % i ] % p ;
}
