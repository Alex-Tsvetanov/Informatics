#include <iostream>
using namespace std;

int p, n, s;

int main ( )
{
    ios :: sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    cin >> p >> n >> s;
    long long br = 0;
    if (n == 1)
    {
        cout << p << endl;
    }
    else if (n == 2)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                if (s > i + i1) br ++;
            }
        }
        cout << br << endl;
    }
    else if (n == 3)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    if (s > i + i1 + i2) br ++;
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 4)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        if (s > i + i1 + i2 + i3) br ++;
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 5)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            if (s > i + i1 + i2 + i3 + i4) br ++;
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 6)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                if (s > i + i1 + i2 + i3 + i4 + i5) br ++;
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 7)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6) br ++;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 8)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7) br ++;
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 9)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8) br ++;
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 10)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9) br ++;
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 11)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    for (int i10 = 0; i10 < p; i10 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9 + i10) br ++;
                                }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 12)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    for (int i10 = 0; i10 < p; i10 ++)
                                {
                                    for (int i11 = 0; i11 < p; i11 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9 + i10 + i11) br ++;
                                }
                                }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 13)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    for (int i10 = 0; i10 < p; i10 ++)
                                {
                                    for (int i11 = 0; i11 < p; i11 ++)
                                {
for (int i12 = 0; i12 < p; i12 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9 + i10 + i11 + i12) br ++;
                                }                                }
                                }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 14)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    for (int i10 = 0; i10 < p; i10 ++)
                                {
                                    for (int i11 = 0; i11 < p; i11 ++)
                                {
for (int i12 = 0; i12 < p; i12 ++)
                                {
for (int i13 = 0; i13 < p; i13 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9 + i10 + i11 + i12 + i13) br ++;
                                }                                }                                }
                                }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 15)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    for (int i10 = 0; i10 < p; i10 ++)
                                {
                                    for (int i11 = 0; i11 < p; i11 ++)
                                {
for (int i12 = 0; i12 < p; i12 ++)
                                {
for (int i13 = 0; i13 < p; i13 ++)
                                {
for (int i14 = 0; i14 < p; i14 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9 + i10 + i11 + i12 + i13 + i14) br ++;
                                }                                }                                }                                }
                                }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
     else if (n == 16)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    for (int i10 = 0; i10 < p; i10 ++)
                                {
                                    for (int i11 = 0; i11 < p; i11 ++)
                                {
for (int i12 = 0; i12 < p; i12 ++)
                                {
for (int i13 = 0; i13 < p; i13 ++)
                                {
for (int i14 = 0; i14 < p; i14 ++)
                                {
for (int i15 = 0; i15 < p; i15 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9 + i10 + i11 + i12 + i13 + i14 + i15) br ++;
                                }                                }                                }                                }                                }
                                }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 17)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    for (int i10 = 0; i10 < p; i10 ++)
                                {
                                    for (int i11 = 0; i11 < p; i11 ++)
                                {
for (int i12 = 0; i12 < p; i12 ++)
                                {
for (int i13 = 0; i13 < p; i13 ++)
                                {
for (int i14 = 0; i14 < p; i14 ++)
                                {
for (int i15 = 0; i15 < p; i15 ++)
                                {
for (int i16 = 0; i16 < p; i16 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9 + i10 + i11 + i12 + i13 + i14 + i15 + i16) br ++;
                                }                                }                                }                                }                                }                                }
                                }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 18)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    for (int i10 = 0; i10 < p; i10 ++)
                                {
                                    for (int i11 = 0; i11 < p; i11 ++)
                                {
for (int i12 = 0; i12 < p; i12 ++)
                                {
for (int i13 = 0; i13 < p; i13 ++)
                                {
for (int i14 = 0; i14 < p; i14 ++)
                                {
for (int i15 = 0; i15 < p; i15 ++)
                                {
for (int i16 = 0; i16 < p; i16 ++)
                                {
for (int i17 = 0; i17 < p; i17 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9 + i10 + i11 + i12 + i13 + i14 + i15 + i16 + i17) br ++;
                                }                                }                                }                                }                                }                                }                                }
                                }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
    else if (n == 19)
    {
        for (int i = 0; i < p; i ++)
        {
            for (int i1 = 0; i1 < p; i1 ++)
            {
                for (int i2 = 0; i2 < p; i2 ++)
                {
                    for (int i3 = 0; i3 < p; i3 ++)
                    {
                        for (int i4 = 0; i4 < p; i4 ++)
                        {
                            for (int i5 = 0; i5 < p; i5 ++)
                            {
                                for (int i6 = 0; i6 < p; i6 ++)
                                {
                                    for (int i7 = 0; i7 < p; i7 ++)
                                {
                                    for (int i8 = 0; i8 < p; i8 ++)
                                {
                                    for (int i9 = 0; i9 < p; i9 ++)
                                {
                                    for (int i10 = 0; i10 < p; i10 ++)
                                {
                                    for (int i11 = 0; i11 < p; i11 ++)
                                {
for (int i12 = 0; i12 < p; i12 ++)
                                {
for (int i13 = 0; i13 < p; i13 ++)
                                {
for (int i14 = 0; i14 < p; i14 ++)
                                {
for (int i15 = 0; i15 < p; i15 ++)
                                {
for (int i16 = 0; i16 < p; i16 ++)
                                {
for (int i17 = 0; i17 < p; i17 ++)
                                {
for (int i18 = 0; i18 < p; i18 ++)
                                {
                                    if (s > i + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8+ i9 + i10 + i11 + i12 + i13 + i14 + i15 + i16 + i17 + i18) br ++;
                                }                                }                                }                                }                                }                                }                                }                                }
                                }
                                }
                                }
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << br << endl;
    }
	return 0;
}
