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

vector<Expense*> splitwise(vector<Expense>&transactions, unordered_map<string, int>&net_balance)
{
    for(auto expense : transactions)
    {   
        string payer = expense.p1;
        string payee = expense.p2;

        //Increase payer net balance because he will get back money
        if(net_balance.count(payee))
            net_balance[payer] += expense.amount;
        else
            net_balance.insert({payer, expense.amount});

        //Decrease payee net balance beacuse he is in debt
        if(net_balance.count(payee))
            net_balance[payee] -= expense.amount;
        else
            net_balance.insert({payee, expense.amount});
    }

    priority_queue<pair<int, string>>positive, negative;

    for(auto p : net_balance)
    {
        if(p.second > 0)
            positive.push({p.second, p.first});
        else
            negative.push({-1*p.second, p.first});
    }

    vector<Expense*>result;

    while(positive.size() > 0)
    {
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
    return result;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cout<<"Enter the number of transactions : "<<endl;
    int n;
    cin>>n;
    cout<<endl<<"Enter Transactions in this format (Payer Payee Amount) : "<<endl;

    vector<Expense>transactions;
    for(int i=0;i<n;i++)
    {
        Expense e;
        string s1,s2;
        int amt;
        cin>>s1>>s2>>amt;
        e.p1 = s1;
        e.p2 = s2;
        e.amount = amt;
        transactions.push_back(e);
    }
    // transactions.push_back({"Naman", "Sanghmitr", 100});
    // transactions.push_back({"Ishan", "Sanghmitr", 400});
    // transactions.push_back({"Sanghmitr", "Hitesh", 800});
    // transactions.push_back({"Hitesh", "Naman", 400});
    // transactions.push_back({"Hitesh", "Ishan", 300});
    // transactions.push_back({"Ishan", "Naman", 200});

    unordered_map<string, int>net_balance;
    vector<Expense*>simplified = splitwise(transactions, net_balance);
    
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