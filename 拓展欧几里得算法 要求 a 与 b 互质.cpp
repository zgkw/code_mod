-----  拓展欧几里得算法 要求 a 与 b 互质  ---------------------------------------------------------------------------------------------------------

void exgcd ( ll a , ll b , ll& x , ll& y )  // 注意实际上的x与y的变量类型
{
	if ( b == 0 )
	{
		x = 1, y = 0;
		return;
	}
	exgcd ( b , a % b , y , x ) ;
	y -= a / b * x ;
}

-----  拓展欧几里得算法 要求 a 与 b 互质  ---------------------------------------------------------------------------------------------------------

