struct
{
private:
    static int my_min_val (int x, int y) { std::cout << "MIN_FUNC" << std::endl; return (x < y)? x: y; }
public:
    int (*minVal)(int, int);
    void setMinFunction (int (*comp)(int,int) = my_min_val)
    {
        minVal = comp;
    }
private:
    int getMid (int s, int e) {  return s + (e -s)/2;  }

    int RMQUtil(const int *st, const int ss, const int se, const int qs, const int qe, const int index)
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
    int query (const int *st, const int n, const int qs, const int qe)
    {
        if (qs < 0 || qe > n-1 || qs > qe)
        {
            return -1;
        }
     
        return RMQUtil(st, 0, n-1, qs, qe, 0);
    }
private:
    int constructSTUtil(const int arr[], const int ss, const int se, int *st, const int si)
    {
		std::cout << "LOG 3" << std::endl;
		std::cout << ss << " " << se << std::endl;
		std::cout << si << std::endl;
		std::cout << sizeof (st) / sizeof (int) << std::endl;
        if (ss == se)
        {
			std::cout << "LOG 7" << std::endl;
            st[si] = arr[ss];
			std::cout << "LOG 8" << std::endl;
            return arr[ss];
        }
		std::cout << "LOG 4" << std::endl;
     
        int mid = getMid(ss, se);
		std::cout << "LOG 5" << std::endl;
		std::cout << si << std::endl;
        st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                         constructSTUtil(arr, mid+1, se, st, si*2+2));
		std::cout << "LOG 6" << std::endl;
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
    int* init (const int arr[], const int n)
    {
        int max_size = next_power_of_2 (n) - 1; 
     
		std::cout << max_size << std::endl;
        int *st = new int [max_size]; 
     
		std::cout << "LOG 1" << std::endl;
        constructSTUtil(arr, 0, n-1, st, 0);
		std::cout << "LOG 2" << std::endl;
     
        return st;
    }
} RMQ;
 
