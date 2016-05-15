#include <vector>
#include <utility>

using point = std::pair <int, int>;
using turn_t = std::pair <point, point>;

/*abstract*/ class player
{
public:
	int player_num; 
	const char ** map;
	int myX, myY;
public:
	virtual turn_t turn (int, int) = 0;
};

