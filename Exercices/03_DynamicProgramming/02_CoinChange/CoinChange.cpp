#include <iostream>
#include <vector>

using namespace std;

vector<int> table = vector<int>(10001, -2);
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) {
            return 0;
        }

        if (table[amount] == -2) {
            int act = -1;
            for(int i = 0; i < coins.size(); ++i) {
                if(coins[i] == amount) {
                    act = 1;
                } else {
                    int tmp = coinChange(coins, amount-coins[i]);
                    if(tmp >= 0) tmp++;
                    if(act == -1 || (act > tmp && tmp > 0))
                        act = tmp;
                }
            }
            table[amount] = act;
        }
        
        return table[amount];
    }