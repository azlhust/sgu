// eulerian path

#include <cstdio>
#include <vector>
using namespace std;

const int N = 105;

int g[7][7], in[7], ans[N], cc;
vector<int> tot[7][7];
void dfs(int u){
  for (int i = 0; i <= 6; ++i) {
    if (g[u][i]) {
      g[u][i]--;
      g[i][u]--;
      dfs(i);
    }
  }
  ans[cc++] = u;
}

int main(){
  int n, i, a, b, cnt=0, u;
  scanf("%d",&n);
  for(i = 1; i <= n; ++i){
    scanf("%d%d",&a,&b);
    g[a][b]++;
    g[b][a]++;
    tot[a][b].push_back(i);
    in[a]++;
    in[b]++;
    u = a;
  }
 
  for(i = 0; i <= 6; ++i){
    if(in[i]&1){
      cnt++;
      u=i;
    }
  }
  
  if(cnt>2 || cnt == 1){
    puts("No solution");
    return 0;
  }

  cc=0, dfs(u);
  if (cc != n+1) {
    puts("No solution");
    return 0;
  }

  for (i = 0; i+1 < cc; i ++) {
    if (tot[ans[i]][ans[i+1]].size()){
      vector<int>& cur = tot[ans[i]][ans[i+1]];
      printf("%d +\n", cur.back());
      cur.pop_back(); 
    } else {
      vector<int>& cur = tot[ans[i+1]][ans[i]];
      printf("%d -\n", cur.back());
      cur.pop_back();
    } 
  }

  return 0;
}
