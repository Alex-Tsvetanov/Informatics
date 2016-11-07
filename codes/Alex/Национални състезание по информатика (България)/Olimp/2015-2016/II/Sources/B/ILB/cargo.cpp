#include <iostream>
#include <cmath>

#include <vector>
#include <algorithm>
#include <queue>
const int maxn = 1e6 + 1000;
char done[maxn] = {0};

struct dup {
    int s, e, id;
};

std::vector<dup> all;
#define typeadd 1
#define typerem -1

struct point {
    int x, type, id;
};

bool operator < (const point& a, const point& b) {
    return a.x < b.x;
}

bool operator < (const dup& a, const dup& b) {
    return (a.e - a.s) > (b.e - b.s);
}

struct typeee {
    int x;
    std::vector<int> add;
    std::vector<int> rem;
};

int p;
int mmax(const std::vector<typeee> &v) {
    int len = v.size();
    int taken = 0;

/*
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i].x << "\n";
        std::cout << "add ";
        for (int j = 0; j < v[i].add.size(); j++)
            std::cout << v[i].add[j] << " ";
        std::cout << std::endl << "rem ";
         for (int j = 0; j < v[i].rem.size(); j++)
            std::cout << v[i].rem[j] << " ";
        std::cout << std::endl;
    }
*/

    std::priority_queue<dup> pq;

    for (int i = 0; i < v[0].add.size(); i++) {
 //    std::cout << "pushing " << v[0].add[i] << std::endl;
        pq.push(all[v[0].add[i]]);
    }

   // std::cout << "start iteration" << std::endl;
    for (int i = 1; i < len; i++) {
        int l = v[i].x - v[i - 1].x;
        int max_take = std::min(l * p, (int)pq.size());
     //   std::cout << v[i].x << std::endl;
        while(max_take --> 0) {
            dup xxx = pq.top();
            pq.pop();
            done[xxx.id] = 1;
       //     std::cout << "doing " << xxx.id << std::endl;
        }

        for (int j = 0; j < v[i].add.size(); j++) {
         //   std::cout << "pushing " << v[i].add[j] << std::endl;
            pq.push(all[v[i].add[j]]);
        }

        for (int j = 0; j < v[i].rem.size(); j++) {
            if (done[v[i].rem[j]] == 0) {
           //         std::cout << "failed to do " << v[i].rem[j] << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

int get_real(int x) {
    int cc = x % 7;
    if (cc > 0 && cc < 6) {
        int prev_week = x / 7;
        int res = x - 2 * prev_week;
        return res;
    }

    if (cc == 6) {
        ++x;
    }

    int prev_week = x / 7;
    int res = x - 2 * prev_week;
    return res + 1;
}

int main(){
    int n, m, ss;
    std::cin >> n >> m >> ss;
    p = ss / 2;
    all.resize(m);
    int x, y;

    std::vector<point> normal, wh;
    point ppp;

    bool has_only_holiday = false;
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;

        if (y - x <= 1) {
            int ccx = x % 7;
            int ccy = y % 7;
            if ((ccx == 0 || ccx == 6) && (ccy == 0 || ccy == 6)) {
                has_only_holiday = true;
            }

        }

        ppp.id = i;
        ppp.x = x;
        ppp.type = typeadd;
        normal.push_back(ppp);

        ppp.x = get_real(x);
        wh.push_back(ppp);

        ppp.x = y + 1;
        ppp.type = typerem;
        normal.push_back(ppp);

        ppp.x = get_real(y + 1);
        wh.push_back(ppp);

        all[i].s = x;
        all[i].e = y;
        all[i].id = i;
    }
    std::sort(normal.begin(), normal.end());

    std::vector<typeee> norm_param;
    typeee xxx;
    xxx.x = normal[0].x;
    if (normal[0].type == typeadd)
        xxx.add.push_back(normal[0].id);
    else
        xxx.rem.push_back(normal[0].id);

    for (int i = 1; i < normal.size(); i++) {
        if (normal[i].x == xxx.x) {
               if (normal[i].type == typeadd)
                   xxx.add.push_back(normal[i].id);
               else
                   xxx.rem.push_back(normal[i].id);
        } else {
            norm_param.push_back(xxx);
            xxx.add.clear();
            xxx.rem.clear();
            xxx.x = normal[i].x;
             if (normal[i].type == typeadd)
                xxx.add.push_back(normal[i].id);
             else
                xxx.rem.push_back(normal[i].id);
        }
    }

    norm_param.push_back(xxx);

    std::sort(wh.begin(), wh.end());

    std::vector<typeee> wh_param;
    xxx.x = wh[0].x;
    if (wh[0].type == typeadd)
        xxx.add.push_back(wh[0].id);
    else
        xxx.rem.push_back(wh[0].id);

    for (int i = 1; i < wh.size(); i++) {
        if (wh[i].x == xxx.x) {
               if (wh[i].type == typeadd)
                   xxx.add.push_back(wh[i].id);
               else
                   xxx.rem.push_back(wh[i].id);
        } else {
            wh_param.push_back(xxx);
            xxx.add.clear();
            xxx.rem.clear();
            xxx.x = wh[i].x;
             if (wh[i].type == typeadd)
                xxx.add.push_back(wh[i].id);
             else
                xxx.rem.push_back(wh[i].id);
        }
    }

    wh_param.push_back(xxx);

    int can_wh, can_normal;

    if (has_only_holiday)
        can_wh = 0;
    else
        can_wh = mmax(wh_param);

    can_normal = mmax(norm_param);
    if (can_wh) {
        std::cout << "OK" << std::endl;
    } else if (can_normal) {
        std::cout << "MIXED" << std::endl;
    } else {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
    return 0;
}
