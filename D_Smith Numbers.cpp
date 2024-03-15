#include <bits/stdc++.h>
using namespace std;

bool is_prime(int num){
    if(num == 1) return false;
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}

int digit_sum(int num){
    int sum = 0;
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int prime_factor_sum(int num){
    int sum = 0;
    for(int i = 2; i * i <= num; i++){
        while(num % i == 0){
            sum += digit_sum(i);
            num /= i;
        }
    }
    if(num > 1) sum += digit_sum(num); 
    return sum;
}




int main(){
    int round;
    cin >> round;
    for(int i = 0; i < round; i++){
        int num;
        cin >> num;
        int n = num+1;
        while(true){
            if (!is_prime(n) && prime_factor_sum(n) == digit_sum(n)){
                cout << n << endl;
                break;
            }
            n++;
        }
    }
    return 0;
}
