#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;


class AhoCorasick{

public:

    map< int, string > st_w;
    vector< vector< int > > G, Aut;
    vector< int > F, N;
    vector< bool > endOfWord;
    vector< string > Dic;
    int maxc, s_alf, prx;

    void insert(string &S){
        int at = 0;

        for(char c : S){
            int let = c - 'a';
            if(G[at][let] == -1) G[at][let] = prx++;
            at = G[at][let];
        }

        endOfWord[at] = true;
        st_w[at] = S;
    }

    void search(string &T){
        int at = 0;
        for(int i = 0; i<T.size(); i++){
            int let = T[i] - 'a'; // letra base do alfabeto
            at = Aut[at][let];
            if(endOfWord[at]){
                cout << "Word found! Position : " << i << '\n';
                cout << st_w[at] << '\n';
            }

            int state = at;
            while(N[state] != 0){
                state = N[state];
                cout << st_w[state] << '\n';
            }
        }
    }

    void makelink(const tuple<int, int, int> &p){
        int state = get<0>(p), par = get<1>(p), cpar = get<2>(p);
        if(par == 0){
            F[state] = 0;
            N[state] = 0;
        }
        else{
            int pre = F[par];
            while(G[pre][cpar] == -1) pre = F[pre];
            F[state] = G[pre][cpar];

            if(endOfWord[F[state]]) N[state] = F[state];
            else N[state] = N[F[state]];
        }
    }

    AhoCorasick(vector< string > &Dic_, int maxc_ = 1e6, int s_alf_ = 26){
        maxc = maxc_;
        s_alf = s_alf_;
        Dic = Dic_;
        prx = 1;

        G = vector< vector< int > >(maxc, vector<int>(s_alf, -1));
        Aut = vector < vector< int > >(maxc, vector<int>(s_alf));
        F = vector< int >(maxc);
        N = vector< int >(maxc);
        endOfWord = vector< bool >(maxc, false);

        queue< tuple<int, int , int > > q;

        for(int i = 0; i<Dic.size(); i++) insert(Dic[i]);
        for(int i = 0; i<s_alf; i++){
            if(G[0][i] == -1)  G[0][i] = 0;
            else q.push({G[0][i], 0, i});

            Aut[0][i] = G[0][i];
        }

        while(!q.empty()){
            tuple<int, int, int> p = q.front(); q.pop();

            makelink(p);

            int state = get<0>(p);

            for(int i = 0; i<s_alf; i++){
                if(G[state][i] != -1){
                    q.push({G[state][i], state, i});
                    Aut[state][i] = G[state][i];
                }
                else{
                    Aut[state][i] = Aut[F[state]][i];
                }
            }
        }
    }

};

int main(){
    vector<string> Dic = {"hers", "she", "his", "he", "to"};

    AhoCorasick AC(Dic, 100, 26);
    string s = "sheshehersahsheahtoototo";
    AC.search(s);

    return 0;
}
