#include "fun_rfKC0YN23mevcc0h.hpp"

int fun_rfKC0YN23mevcc0h() {
    // LeetCode Problem: Number Of Orders In The Backlog

    // Solution class
    class Solution {

    private:
        template<typename T1, typename T2>
        void processOrder(T1& q1, T2& q2, COMP op, int price, int amount, string n1="q1", string n2="q2") {
            if (q2.size() == 0) {
                q1.push(Order{price, amount});
                return;
            }

            while(!q2.empty() && amount > 0  ){
                Order order = q2.top(); 
                if (op == GREATER && order.price > price ) break;
                if (op == LESS && order.price < price) break;

                q2.pop();
                //cout << "=> deQueue("<< n2 << "): " << order.price << ", "<< order.amount << endl;

                int amt = min(order.amount, amount);
                order.amount -= amt;
                amount -= amt;
                if (order.amount > 0) {
                    //cout << "<= enQueue("<< n2 <<"): " << order.price << ", "<< order.amount << endl;
                    q2.push(order);
                }
            }
            if (amount > 0) {
                //cout << "<= enQueue("<< n1 <<"): " << price << ", "<< amount << endl;
                q1.push(Order{price, amount});
            }
        }

        template<typename T>
        void countQ(T& q, int& amount){
            while(!q.empty()) {
                amount = (amount + q.top().amount) % 1000000007;
                q.pop();
            }
        }
    public:
        int getNumberOfBacklogOrders(vector<vector<int>>& orders) {

            priority_queue<Order, vector<Order>, OrderComp<GREATER>> sell;
            priority_queue<Order, vector<Order>, OrderComp<LESS>> buy;


            for (auto& order : orders) {
                int& price = order[0];
                int& amount = order[1];

                if (order[2] == 0)  { //buy order
                    processOrder(buy, sell, GREATER, price, amount, "buy", "sell");
                }else { // sell order
                    processOrder(sell, buy, LESS, price, amount, "sell", "buy");
                }
            }

            int amount = 0;
            countQ(sell, amount);
            countQ(buy, amount);
            return amount ;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.getNumberOfBacklogOrders(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_rfKC0YN23mevcc0h: Executed getNumberOfBacklogOrders() from Number Of Orders In The Backlog" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rfKC0YN23mevcc0h: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
