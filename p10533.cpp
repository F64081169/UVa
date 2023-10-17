#include<bits/stdc++.h>
using namespace std;

struct Number{
  bool isComposite;
  int totalDigitPrimeCount;
};

int bitSum(int number){
  int sum = 0;
  while(number > 0){
    sum += number % 10;
    number /= 10;
  }
  return sum;
}

int main(){
  const int TOTAL_NUMBER = 1000000;

  vector<Number> numbers(TOTAL_NUMBER, Number{false, 0});
  for(int i = 2; i < TOTAL_NUMBER ; ++i){
    if(numbers[i].isComposite){
      numbers[i].totalDigitPrimeCount = numbers[i-1].totalDigitPrimeCount;
      continue;
    }

    for(int j = i + i ; j < TOTAL_NUMBER ; j += i){
      numbers[j].isComposite = true;
    }

    numbers[i].totalDigitPrimeCount = numbers[i-1].totalDigitPrimeCount + 
      ((!numbers[bitSum(i)].isComposite)? 1 : 0);
  }

  int N;
  while(scanf("%d", &N) != EOF){
    for(int caseNumber = 1 ; caseNumber <= N ; ++caseNumber){
      int t1, t2;
      scanf("%d%d", &t1, &t2);
      printf("%d\n", numbers[t2].totalDigitPrimeCount - numbers[t1-1].totalDigitPrimeCount);
    }
  }
  return 0;
}
