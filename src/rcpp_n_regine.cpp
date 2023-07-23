#include <Rcpp.h>
#include <stdio.h>
using namespace Rcpp;
#define N 5
#define MAX_SOLUTIONS 6

int tabla[N][N];
int generatedSolutions = 0;

// [[Rcpp::export]]
bool pozitieValida(int linie, int col) { 
  for (int i = 0; i < linie; i++) {
    if (tabla[i][col] == 1) {
      return false;
    }
  }
  
  for (int i = linie - 1,  j = col - 1; (i >= 0) && (j >= 0); i--, j--) {
    if (tabla[i][j] == 1) {
      return false;
    }
  }
  
  for (int i = linie - 1, j = col + 1; (i >= 0) && (j < N); i--, j++) {
    if (tabla[i][j] == 1) {
      return false;
    }
  }
  
  return true;
}

// [[Rcpp::export]]
void printSolution() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", tabla[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// [[Rcpp::export]]
void queens(int linie) {
  if (linie == N) {
    printSolution();
    generatedSolutions++;
    return;
  }
  
  for (int col = 0; col < N; col++) { 
    if (pozitieValida(linie, col)) {
      tabla[linie][col] = 1;
      queens(linie + 1);
      if (generatedSolutions == MAX_SOLUTIONS) return;
      tabla[linie][col] = 0;
    }
  }
}
/*** R
queens(0)

*/
