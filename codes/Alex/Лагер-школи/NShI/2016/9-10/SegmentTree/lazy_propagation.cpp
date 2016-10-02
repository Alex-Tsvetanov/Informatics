#include <stdio.h>
#include <math.h>

template <typename T>
struct SegmentTree
{
	size_t MAX;
	T* tree;
	T* lazy;

	SegmentTree (size_t MAXN)
	{
		MAX = MAXN;
		tree = new T [MAX];
		lazy = new T [MAX];
	}

	~SegmentTree ()
	{
		delete[] tree;
		delete[] lazy;
	}
	 
	void updateRangeUtil(int si, int ss, int se, int us,
						 int ue, int diff)
	{
		if (lazy[si] != 0)
		{
			tree[si] += (se-ss+1)*lazy[si];
	 
			if (ss != se)
			{
				lazy[si*2 + 1]   += lazy[si];
				lazy[si*2 + 2]   += lazy[si];
			}
	 
			lazy[si] = 0;
		}
	 
		if (ss>se || ss>ue || se<us)
			return ;
	 
		if (ss>=us && se<=ue)
		{
			tree[si] += (se-ss+1)*diff;
	 
			if (ss != se)
			{
				lazy[si*2 + 1]   += diff;
				lazy[si*2 + 2]   += diff;
			}
			return;
		}
	 
		int mid = (ss+se)/2;
		updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
		updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
	 
		tree[si] = tree[si*2+1] + tree[si*2+2];
	}
public: 
	void updateRange(int n, int us, int ue, int diff)
	{
	   updateRangeUtil(0, 0, n-1, us, ue, diff);
	}
private:
	T getSumUtil(int ss, int se, int qs, int qe, int si)
	{
		if (lazy[si] != 0)
		{
			tree[si] += (se-ss+1)*lazy[si];
	 
			if (ss != se)
			{
				lazy[si*2+1] += lazy[si];
				lazy[si*2+2] += lazy[si];
			}
	 
			lazy[si] = 0;
		}
	 
		if (ss>se || ss>qe || se<qs)
			return 0;
	 
		if (ss>=qs && se<=qe)
			return tree[si];
	 
		int mid = (ss + se)/2;
		return getSumUtil(ss, mid, qs, qe, 2*si+1) +
			   getSumUtil(mid+1, se, qs, qe, 2*si+2);
	}
public:
	T getSum(int n, int qs, int qe)
	{
		if (qs < 0 || qe > n-1 || qs > qe)
		{
			printf("Invalid Input");
			return -1;
		}
	 
		return getSumUtil(0, n-1, qs, qe, 0);
	}
private:
	void constructSTUtil (T arr[], int ss, int se, int si)
	{
		if (ss > se)
			return ;
	 
		if (ss == se)
		{
			tree[si] = arr[ss];
			return;
		}
	 
		int mid = (ss + se)/2;
		constructSTUtil(arr, ss, mid, si*2+1);
		constructSTUtil(arr, mid+1, se, si*2+2);
	 
		tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
	}
public:
	void construct (T arr[], int n)
	{
		constructSTUtil(arr, 0, n-1, 0);
	}
};
 
int main ()
{
    int arr [] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

	SegmentTree<int> ST (1000);
 
    ST.construct(arr, n);
 
    printf("Sum of values in given range = %d\n",
           ST.getSum(n, 1, 3));
 
    ST.updateRange(n, 1, 5, 10);
 
    printf("Updated sum of values in given range = %d\n",
            ST.getSum( n, 1, 3));
 
    return 0;
}
