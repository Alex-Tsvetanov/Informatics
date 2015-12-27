struct
{
private:
    static int my_min_val (int x, int y) { return (x < y)? x: y; }
public:
    int (*minVal)(int, int);
    void setMinFunction (int (*comp)(int,int) = my_min_val)
    {
        minVal = comp;
    }
private:
    int getMid (int s, int e) {  return s + (e -s)/2;  }

    int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
    {
        if (qs <= ss && qe >= se)
            return st[index];
     
        if (se < qs || ss > qe)
            return (1<<30);
     
        int mid = getMid(ss, se);
        return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                      RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
    }
public:
    int query (int *st, int n, int qs, int qe)
    {
        if (qs < 0 || qe > n-1 || qs > qe)
        {
            return -1;
        }
     
        return RMQUtil(st, 0, n-1, qs, qe, 0);
    }
private:
    int constructSTUtil(int arr[], int ss, int se, int *st, int si)
    {
        if (ss == se)
        {
            st[si] = arr[ss];
            return arr[ss];
        }
     
        int mid = getMid(ss, se);
        st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                         constructSTUtil(arr, mid+1, se, st, si*2+2));
        return st[si];
    }

    template<typename X> X next_power_number_of_2 (X value)
    {
        return ((sizeof (X) * 8) - __builtin_clz(value));
    }
    template<typename X> X next_power_of_2 (X value)
    {
        return 1 << ((sizeof (X) * 8) - __builtin_clz(value));
    }
public:
    int* init (int arr[], int n)
    {
        int max_size = next_power_of_2 (n) - 1; 
     
        int *st = new int [max_size]; 
     
        constructSTUtil(arr, 0, n-1, st, 0);
     
        return st;
    }
} RMQ;
 
