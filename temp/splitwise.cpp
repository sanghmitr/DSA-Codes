#include<bits/stdc++.h>
using namespace std;

class Expense
{
    public:
        string p1;
        string p2;
        int amount;

    Expense()
    {};
    Expense(string p1, string p2, int amount)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->amount = amount;
    }
};

vector<Expense*> splitwise(vector<Expense*>&transactions, unordered_map<string, int>&net_balance)
{
    for(auto expense : transactions)
    {   
        string payer = expense->p1;
        string payee = expense->p2;

        //Increase payer net balance because he will get back money
        if(net_balance.count(payer))
            net_balance[payer] += expense->amount;
        else
            net_balance.insert({payer, expense->amount});

        //Decrease payee net balance beacuse he is in debt
        if(net_balance.count(payee))
            net_balance[payee] -= expense->amount;
        else
            net_balance.insert({payee, -1*expense->amount});
    }

    priority_queue<pair<int, string>>positive, negative;

    cout << "Current Debt status of all members Now- (Hashmap contains)" << endl;
    for(auto p : net_balance)
    {
        cout << p.first << " " << p.second << endl;
        if(p.second > 0)
            positive.push({p.second, p.first});
        else
            negative.push({-1*p.second, p.first});
    }
    cout << endl;

    vector<Expense*>result;
    int cnt = 0;
    while(positive.size() > 0)
    {
        cnt++;
        pair<int, string>receiver = positive.top();
        pair<int, string>sender = negative.top();
        positive.pop();
        negative.pop();

        Expense *ex = new Expense(sender.second, receiver.second, min(sender.first, receiver.first));

        result.push_back(ex);

        if(receiver.first > sender.first)
            positive.push({receiver.first - sender.first, receiver.second});
        else if(receiver.first < sender.first)
            negative.push({sender.first - receiver.first, sender.second});
    }
    cout << endl << cnt << endl;
    return result;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<Expense*>transactions;

    // cout<<"Enter the number of transactions : "<<endl;
    // int n;
    // cin>>n;
    // cout<<endl<<"Enter Transactions in this format (Payer Payee Amount) : "<<endl;

    
    // for(int i=0;i<n;i++)
    // {
    //     Expense e;
    //     string s1,s2;
    //     int amt;
    //     cin>>s1>>s2>>amt;
    //     e.p1 = s1;
    //     e.p2 = s2;
    //     e.amount = amt;
    //     transactions.push_back(e);
    // }
    // transactions.push_back(new Expense("Naman", "Sanghmitr", 100));
    // transactions.push_back(new Expense("Ishan", "Sanghmitr", 400));
    // transactions.push_back(new Expense("Sanghmitr", "Hitesh", 800));
    // transactions.push_back(new Expense("Hitesh", "Naman", 400));
    // transactions.push_back(new Expense("Hitesh", "Ishan", 300));
    // transactions.push_back(new Expense("Ishan", "Naman", 200));
    // transactions.push_back(new Expense("Sanghmitr", "Naman", 600));
    // transactions.push_back(new Expense("Ishan", "Hitesh", 800));
    // transactions.push_back(new Expense("Naman", "Ishan", 400));

    transactions.push_back(new Expense("Bob", "Gabe", 30));
    transactions.push_back(new Expense("David", "Gabe", 10));
    transactions.push_back(new Expense("Bob", "Fred", 10));
    transactions.push_back(new Expense("Charlie", "Fred", 30));
    transactions.push_back(new Expense("David", "Fred", 10));
    transactions.push_back(new Expense("Ema", "Fred", 10));
    transactions.push_back(new Expense("Charlie", "Bob", 40));
    transactions.push_back(new Expense("David", "Charlie", 20));
    transactions.push_back(new Expense("Ema", "David", 50));

    unordered_map<string, int>net_balance;
    vector<Expense*>simplified = splitwise(transactions, net_balance);

    cout << "-------------------------------------" << endl;
    cout << "Simplified Transactions are - " << endl;
    for(auto obj : simplified)
    {
        cout<<obj->p1<<" -> "<<obj->amount<<" -> "<<obj->p2<<endl;
    }
    return 0;
}

/*

Naman
Ishan 
400
Ishan 
Hitesh
200
Hitesh 
Sanghmitr
300
Sanghmitr
Naman
1000

*/