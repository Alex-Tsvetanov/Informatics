#include <stdio.h>
#include <algorithm>//std::max


int main ()
{
	int maxLen = 0;
	int currLen = 0;
	int n;
	scanf ("%d", &n);
	int prev, curr, next;
	scanf ("%d%d%d", &prev, &curr, &next);
	
	//printf ("compare [(%d < %d) = %d] == [(%d < %d) = %d]\n", curr, prev, curr < prev, curr, next, curr < next);
	
	if ((curr < prev) == (curr < next))
		currLen ++;

	for (int i = 3 ; i < n ; i ++)
	{
		prev = curr;
		curr = next;
		scanf ("%d", &next);

		//printf ("compare [(%d < %d) = %d] == [(%d < %d) = %d]\n", curr, prev, curr < prev, curr, next, curr < next);
		
		if ((curr < prev) == (curr < next))
			currLen ++;
		else
		{
			maxLen = std::max (maxLen, currLen);
			currLen = 0;
		}
	}
	maxLen = max (maxLen, currLen);
	printf ("%d\n", maxLen);
	return 0;
}
