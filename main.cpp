#include <iostream>

using namespace std;

void checkMax(int x, int y, int &min, int &max) {
    if (x > y) {
        min = y;
        max = x;
    }
    else {
        min = x;
        max = y;
    }
}

void problemRule(int &n) {
    if (n % 2 == 1) {
        n = n * 3 + 1;
    }
    else {
        n = n >> 1;
    }
}

int testCase(int n) {
    int max_cycles = 1;
    
    while(n != 1) {
        problemRule(n);
        max_cycles++;
    }

    return max_cycles;
}


int main(int argc, char *argv[]) {
    int x, y, min, max;
    int max_cycles = 1;
    int temp_max_cycles = 0;
    cin >> x >> y;

    checkMax(x, y, min, max);
    
    for (int i = min; i <= max; i++) {
        temp_max_cycles = testCase(i);
        
        if (temp_max_cycles > max_cycles)
            max_cycles = temp_max_cycles;
    }

    cout << x << " " << y << " " << max_cycles <<endl;

    return 0;
}