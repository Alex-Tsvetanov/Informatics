#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int broiKraga, broiTochki, broiUdari;
int kragove[10000][3];
int tochkite[10][2];
int udarite[10000]; // ne e nuzno da gi shraniavame?

/*int solve(int sila) {

}*/

// triabva da napravia precomputation, inache shte e tvurde bavno, no i vse pak sa dali 0.6 sec, koeto si e dosta
// sqrt(goleminata na stranata na kvadratnoto pole) buckets?! quadtree?! moze bi sqrt buckets sufficeva? gledame koi presicha napulno,
// koi chastichno i tezi, koito sa chastichno, im analizirame vsichkite tochki!!!
// gledame vseki bucket ot kolko okruznosti se presicha i koi sa te. na teoria togava moze da se izvarti taka, che vsiaka okruznost da presicha
// vseki bucket i da se poluchi 100*100*10000 memory?!

// naivno reshenie: N*M*Q
// po-umno reshenie(ako vzemem vsichkite udari i napravim okruznostite samo na edna tochka i vidim za N na broi iteracii kolko sa presechnite tochki
// kato gledame vav intervala kolko okruznosti ima, linealizirame problema?) za 10000 udara pravim precompute za edna tochka, ot tam za
// 10000 iteracii minavame ostanalite sferi. taka stava (N+Q)*M problema!!!, obache dali naistina mozem taka da go linealizirame?
// predpolagam, che moze sas intervalno darvo da stane rabotata, za da proverim?! a sas sqrt buckets vmesto sas intervalno darvo?
// za vsiako M se poluchavat koncentrichni okruznosti sas edin centur. postroiavame si struktura ot danni, sas koiato mozem da vidim za vsiaka
// ot dadenite okruznosti kolko presicha ot tezi koncentrichni okruznosti!!! moze dori samo sas edin masiv, nikakvi intervalni darveta?!

// tochkite sa ni ot 0 do 10000. blagodarenie na tova mozem da imame masiv, koito ni kazva za edikakvo si razstoianie ot centura kolko koncentrichni
// okruznosti ima. taka mozem za vseki interval da computenem kolko sa okruznostite

// a kak da vmukna tova sas chetnia broi tochki?! ako nego go niama tova reshenie raboti absolutno, no moga li da go adaptiram za tova sas
// chetnia broi tochki?

// mozem da si izchislim za edinichen i dvoen radius. sled tova triabva za vseki ot udarite da smetnem za koi udar e bil cheten i za koi necheten
// broi, no tova kak shte stane?

// ako imame masiv, vav koito kazvame koia okruznost vav koi udar e ichastvala togava reshenieto pak stava N*Q? osven ako poluchim intervali i da
// triabva da gi pahnem vav intervalno darvo?

// dori da e N*Q vav worst case, pak cutvame dosta ot sluchaite za gledane!
/*
int broiOkruznosti[10000]; // kolko koncentrichni okruznosti ot opredelena tochka ot M ima na edikakvo si razstoianie ot opredelenata tochkata ot M

long long solve() {
    long long ans = 0;
    for(int m = 0; m < broiTochki; m++) { // vzimame tochka ot M
        // ot 0 ili 1 da zapochna?
        int broiMinaliOkruzosti = 0; // prez kolko ot tezi koncentrichni okruznosti sme preminali. zatova triabva da sortirame silata na udarite!!!
        for(int razstoianie = 10000; razstoianie >= 0; razstoianie--) {// za vsiako vazmozno razstoianie ot tazi tochka
            // =
        }
    }
    return ans;
}
*/

long long solve() {
    long long ans = 0, predishenUdarScore = 0, currentUdarScore = 0;
    for(int s = 0; s < broiUdari; s++) {
        predishenUdarScore = currentUdarScore;
        currentUdarScore = 0;
        //cout << ans << endl;
        for(int n = 0; n < broiKraga; n++) {
            for(int m = 0; m < broiTochki; m++) {
                    //cout << s << ' ' << n << ' ' << m << endl;
                // normalni radiusi
                if(predishenUdarScore == 0 || predishenUdarScore%2 == 1) {// branch predictiona shte go uskori tova mnogo zdravo
                    if((kragove[n][0]-tochkite[m][0])*(kragove[n][0]-tochkite[m][0])+(kragove[n][1]-tochkite[m][1])*(kragove[n][1]-tochkite[m][1]) <= (kragove[n][2]+udarite[s])*(kragove[n][2]+udarite[s])) {// intersection check
                        currentUdarScore++;
                    }
                }  else { // dvoen radius
                    //cout << -1;
                    if((kragove[n][0]-tochkite[m][0])*(kragove[n][0]-tochkite[m][0])+(kragove[n][1]-tochkite[m][1])*(kragove[n][1]-tochkite[m][1]) <= (kragove[n][2]+udarite[s]*2)*(kragove[n][2]+udarite[s]*2)) {// intersection check
                        currentUdarScore++;
                    }
                }
            }
        }
        ans += predishenUdarScore;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long ans = 0;
    cin >> broiKraga >> broiTochki >> broiUdari;
    for(int n = 0; n < broiKraga; n++) {
        cin >> kragove[n][0] >> kragove[n][1] >> kragove[n][1];
    }
    for(int n = 0; n < broiTochki; n++) {
        cin >> tochkite[n][0] >> tochkite[n][1];
    }
    for(int n = 0; n < broiUdari; n++) {
        cin >> udarite[n]; // silata na vseki udar
    }
    //sort(udarite, udarite+broiUdari);
    //reverse(udarite, udarite+broiUdari); // !!!
    cout << solve() << '\n';
    // da ne zabravia I/O optimizaciite!!!
    return 0;
}
