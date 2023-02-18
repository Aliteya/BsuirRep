#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string choose(int n) {
    string path;
    switch (n) {
    case 1: { path = "test1.txt"; }
          break;
    case 2: { path = "test2.txt"; }
          break;
    case 3: { path = "test3.txt"; }
          break;
    case 4: { path = "test4.txt"; }
          break;
    case 5: { path = "test5.txt"; }
          break;
    }
    return path;
}

void read(vector<vector<int>>& g, string& path, int& size) {
    ifstream fin(path);
    string s;
    getline(fin, s);
    size = stoi(s);
    cout << size << endl;
    for (size_t i = 0; i < size; i++) {
        g.push_back(vector<int>());
        getline(fin, s);
        string tmp;
        for (char j : s) {
            if (j != ' ') {
                tmp += j;
            }
            else {
                g[i].push_back(stoi(tmp));
                tmp = "";
            }
        }
        g[i].push_back(stoi(tmp));
    }
}


void dfs(int u, vector<int>& color, vector<pair<int, int>>& res, vector<vector<int>>& g) {
    color[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (color[v] == 0) {
            res.push_back({ u, v });
            dfs(v, color, res, g);
        }
    }
}

int main() {
   
    ifstream fin;
    int size=0;
    vector <vector<int>> g;


    int  n;
    string s;
    cout << "choose path from 1 to 5 " << endl;
    cin >> n;

    string path = choose(n);
   

    read(g,path, size);

 
    vector<int> color(size);
    vector<pair<int, int>> res;

   

    dfs(0, color, res, g);

    for (int i = 0; i < size - 1; i++) {
        cout << res[i].first << ' ' << res[i].second << endl;
    }

    fin.close();

    return 0;
}