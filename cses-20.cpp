#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
const int MOD = (int)1e9 + 7;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
string dir = "RDLU";
string path = "";

vector<string> paths;
int mx[100][100];

void color(){
  int col = 1;
  for (int x =0; x<7; ++x){
    for(int y=0; y<7; ++y){
      if(mx[x][y]!=0) continue;
      queue<pii> q;
      mx[x][y] = col;
      q.push({x,y});
      while(!q.empty()){
        pii curr = q.front();
        q.pop();
        for(int i=0; i<4; ++i){
          int r = curr.first + dx[i], c = curr.second + dy[i];
          if(r<0 || c<0 || r>6 || c>6 || mx[r][c]!=0) continue;
          mx[r][c] = col;
          q.push({r,c});
        }
      }
      col++;
    }
  }
}

void decolor(){
  for (int x =0; x<7; ++x){
    for(int y=0; y<7; ++y){
      if(mx[x][y]!=-1) mx[x][y] = 0;
    }
  }
}

bool inmap(int x, int y){
  if(x<0 || y<0 || x > 6 || y>6) return false;
  return true;
}

void printmap(){
  return;
  for(int i=0; i<=8; ++i){
    for(int j=0; j<=8; ++j) cout<<mx[i][j];
    cout << endl;
  }
  cout << endl;
}

void generate(int x, int y, char xdir, int n){
  if( x==7 && y==1 && n < 48) return;
  if(xdir == 'R' and mx[x][y+1]!=0 and mx[x-1][y]==0 and mx[x+1][y]==0){
    printmap();return;
  }
  if(xdir == 'D' and mx[x+1][y]!=0 and mx[x][y-1]==0 and mx[x][y+1]==0){
    printmap();return;
  }
  if(xdir == 'L' and mx[x][y-1]!=0 and mx[x-1][y]==0 and mx[x+1][y]==0){
    printmap();return;
  }
  if(xdir == 'U' and mx[x-1][y]!=0 and mx[x][y-1]==0 and mx[x][y+1]==0){
    printmap();return;;
  }
  if (x==7 && y==1 && n == 48){
    //cout<<s<<endl;
    paths.push_back(path);
    return;
  }
  for (int i=0; i<4; ++i){
    int r = x+dx[i], c = y+dy[i];
    if( mx[r][c]!=0) continue;
    mx[r][c] = 1;
    path+=dir[i];
    generate(r, c, dir[i], n+1);
    mx[r][c] = 0;
    path.pop_back();
  }
}


int main() {
  cout << "here" << endl;
  for(int i=0; i<=8; ++i){
    for(int j=0; j<=8; ++j){
      if(i==0 || j==0 || i==8 || j==8) mx[i][j]=9;
    }
  }
  mx[1][1] = 1;
  generate(1,1,'R',0);
  cout << (int) paths.size() << endl;
  string s;
  cin >> s;
  int ans  = 0;
  for(string &e : paths){
    int f = 1;
    for(int i=0; i<48; ++i){
      if(s[i]=='?') continue;
      if(s[i]!=e[i]){
        f = 0;
        break;
      }
    }
    ans+=f;
  }
  cout << ans;
  return 0;
}
