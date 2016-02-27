#include <iostream>
using namespace std;
int main()
{
   unsigned  short  M, N, m, n;
   int suma=0, maksimalna_suma=0;
   //cin>>M>>N>>m>>n;
   cin>>N>>M>>n>>m;
   short chislata[N][M];
   for(int i_N=0; i_N<N; i_N++){
        for(int i_M=0; i_M<M; i_M++){
            cin>>chislata[i_N][i_M];
        }
   }
     short razlika_N= ((N-n)+1);
     short razlika_M=((M-m)+1);
     for(int red=0; red<razlika_N; red++){

        for(int kolona=0;kolona<razlika_M; kolona++){
            for (int tekushto_N=red; tekushto_N<n+red; tekushto_N++){
                for(int tekushto_M=kolona; tekushto_M<m+kolona; tekushto_M++){
                    suma= suma+ chislata[tekushto_N][tekushto_M];
                }
            }
        if (maksimalna_suma<suma){
                maksimalna_suma=suma;

            }
            suma =0;

        }
       /* if (maksimalna_suma<suma){
                maksimalna_suma=suma;
            } */
   }
    cout<<maksimalna_suma;
    return 0;
}
