/*
* Malko opletena matematika, ina4e sum dovolen, daje be6e interesna
* Bez zabelejki
* 8 / 0
*/
#include <cstdio>
#include <utility>

const long long MAX_FIX = 69069;

const int MAX_ANSW = 3 * MAX_FIX;

std::pair<long long, long long> answ[MAX_ANSW];
int answCnt;

int main() {
	long long p;
	scanf("%lli", &p);
	
	for (long long h = 1;h < MAX_FIX;h++) {
		long long minK = (2 * h + 2) * h - p;
		minK = minK / 2 + 1;
		if (minK <= 0) {
			minK = 1;
		}
		long long minW = p + 2 * minK - h;
		minW = minW / (2 * h + 1) + (minW % (2 * h + 1) > 0);
		long long maxW = (p + h) / (2 * h + 1);
		if (h < 25) {
			//printf("H: %lli K: %lli MinW: %lli MaxW %lli\n", h, minK, minW, maxW);
		}
		for (long long w = minW;w <= maxW;w++) {
			long long curK = 2 * w * h + w + h - p;
			if ((curK > 0) && ((curK & 1) == 0) && (curK <= 2 * h)) {
				answ[answCnt++] = std::make_pair(h, w);
			}
		}
	}
	
	for (long long w = MAX_FIX - 1;w >= 1;w--) {
		long long minK = w * (2 * w + 2) - p + 1;
		minK = minK / 2 + (minK & 1);
		if (minK <= 0) {
			minK = 1;
		}
		long long minH = p - w + 2 * minK - 1;
		minH = minH / (2 * w + 1) + (minH % (2 * w + 1) > 0);
		long long maxH = (p + w - 1) / (2 * w + 1);
		for (long long h = minH;h <= maxH;h++) {
			long long curK = 1 + 2 * w * h + w + h - p;
			if ((curK > 0) && ((curK & 1) == 0) && (curK <= 2 * w)) {
				answ[answCnt++] = std::make_pair(h, w);
			}
		}
			
		if (maxH < minH) {
			//break;
		}
		//printf("%lli %lli\n", p - w + 2 * minK - 1, p + w  - 1);
		if (w < 25) {
			//printf("Width: %lli minK: %lli minH: %lli maxH: %lli \n", w, minK, minH, maxH);
		}
	}
	
	printf("%i\n", answCnt);
	for (int i = 0;i < answCnt;i++) {
		printf("%lli %lli\n", answ[i].first, answ[i].second);
	}
}

/*
Secret spies from China
try to steal your mind's elation.
Little girls from Sweden
dream of silver screen quotation.
And if you want this kind of dreams
it's californication.

...

Pay your surgen very well to break 
the spell of aging.
Celebrity skin is this your chin, or
is the war your waging ?
First born unicorn
Hardcore softporn

Dream of californication
...

RCHP <3 */
