#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class sudoku {
  private:
    bool fi;
    vector<vector<int> > M;
    vector<vector<bool> > F;  
    int numit;
    
  public:
    void read_and_initialize() {
      int x,f,c;
      numit = 0;
      M = vector<vector<int> > (10, vector<int> (10));
      F = vector<vector<bool> > (10, vector<bool> (10));   
      
      for (int i=1; i<10; i++) {
        for (int j=1; j<10; j++) {
          M[i][j] = 0;
          F[i][j] = false;
        }
      }
      fi=false;
      
      cin >> x;
      while (x!=0) {
        cin >> f >> c;
        M[f][c] = x;
        F[f][c] = true;
        cin >> x;
      }
      
    }
    
    void write() {
      cout << numit << endl;
      for (int i=1; i<10; i++) {
        for (int j=1; j<10; j++) {
          cout << M[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;         
    }
    
    void solve(int n) {
      numit++;
      if (n==81) {
        write();
        return;
      }
      else {
        int f = (n)%9 + 1;
        int c = (n)/9 + 1;
        if (F[f][c]) solve(n+1);
        else {
          for (int i=1; i<10 && !fi; i++) {
            if (!o_sq(f,c,i) && !o_row(f,i) && !o_col(c,i)) {
              M[f][c]=i;
              F[f][c]=true;
              solve(n+1);              
            }
            M[f][c]=0;
            F[f][c]=false;
          }    
        }
      }   
    } 
    
    bool o_row (int f, int x) {
      for (int i=1; i<10; i++) {
        if (M[f][i] == x) 
          return true;
      }
      return false;        
    }
    
    bool o_col (int c, int x) {
      for (int i=1; i<10; i++) {
        if (M[i][c] == x) 
          return true;
      }
      return false;
    }
    
    bool o_sq (int f, int c, int x) {
      while ((f-1)%3 != 0) f--;
      while ((c-1)%3 != 0) c--;
      for (int i=f; i<(f+3); i++) {
        for (int j=c; j<(c+3); j++) {
          if (M[i][j]==x) {
            return true;
          }
        }
      }            
      return false;             
    }    
};
      
int main(int argc, char *argv[]) {
    sudoku s;
    s.read_and_initialize();
    s.write();
    s.solve(0);
    return true;
}
