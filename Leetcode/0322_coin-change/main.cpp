/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        std::vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for(const auto& c : coins)
        {
            if(c < dp.size())
            {
                dp[c] = 1;
            }
        }

        int min_coins = *std::min_element(coins.begin(), coins.end());
        for(int i = min_coins; i < dp.size(); i++)
        {
            int num = std::numeric_limits<int>::max();
            
            for(auto c : coins)
            {
                if(i - c < 0)
                {
                    continue;
                }
                
                if(dp[i - c] != -1)
                {
                    num = std::min(dp[i - c], num);
                }
            }
            
            if (num == std::numeric_limits<int>::max())
            {
                dp[i] = -1;
            }
            else
            {
                dp[i] = num + 1;
            }
        }

        return dp[amount];
    }
};