
-----  矩阵快速幂  ---------------------------------------------------------------------------------------------------------

ll mq_n , mq_k ;

class MAT_POWER
{
public :
	static const ll maxmp = 200 ;
	static const ll mod = 1e9 + 7 ;

	ll mp [ maxmp ] [ maxmp ] ;

	MAT_POWER (){
		memset ( mp , 0 , sizeof mp ) ;
	}
	inline void clear_1(){
		memset ( mp , 0 , sizeof mp ) ;
		af ( i , 1 , mq_n )
			mp [ i ] [ i ] = 1 ;
	}

	MAT_POWER operator *( const MAT_POWER &x )
	{
		MAT_POWER z ;

		af ( k , 1 , mq_n )
		af ( i , 1 , mq_n )
		af ( j , 1 , mq_n )
		z.mp[ i ] [ j ] = ( z.mp [ i ] [ j ] + x.mp [ k ] [ j ] * mp [ i ] [ k ] % mod ) % mod ;

		return z ;
	}
}mp, ans;

void mQ_power ( ll n )
{
	mq_n = 3 , mq_k = n - 3 ;

	mp.mp [ 1 ] [ 1 ] = 1 , mp.mp [ 1 ] [ 2 ] = 1 , mp.mp [ 1 ] [ 3 ] = 0 ;
	mp.mp [ 2 ] [ 1 ] = 0 , mp.mp [ 2 ] [ 2 ] = 0 , mp.mp [ 2 ] [ 3 ] = 1 ;
	mp.mp [ 3 ] [ 1 ] = 1 , mp.mp [ 3 ] [ 2 ] = 0 , mp.mp [ 3 ] [ 3 ] = 0 ;

	ans.clear_1 () ;

	do{
		if ( mq_k & 1 ) ans = ans * mp ;

		mp = mp * mp ; mq_k >>= 1 ;
	}while ( mq_k ) ;
}

-----  矩阵快速幂  ---------------------------------------------------------------------------------------------------------

