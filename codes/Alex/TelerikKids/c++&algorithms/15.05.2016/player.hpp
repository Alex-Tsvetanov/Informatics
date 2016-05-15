#include <vector>
#include <utility>

using point = pair <int, int>;
using turn_t = point;

/*abstract*/ class player
{
private:
	int player_num; 
	const char ** map;
public:
	player (int pl_n)
	{
		player_num = pl_n;
		
	}
	virtual turn_t turn () = 0;
};

