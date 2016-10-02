#include <vector>
#include <utility>

typedef std::pair <int, int> point;
typedef std::pair <point, point> turn_t;

/*abstract*/ class player
{
public:
	int player_num; 
	char ** map;
	int myX, myY;
public:
	virtual turn_t turn (int, int) = 0;
};

