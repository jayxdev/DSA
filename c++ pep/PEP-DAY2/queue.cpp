//implement que to manage bread inventory
#include <iostream>
#include <vector>
using namespace std;

class Bread
{
public:
    string batchNo;
    int exp;//DD of manufacturing
    Bread(string batchNo, int exp)
    {
        this->batchNo = batchNo;
        this->exp = exp;
    }

};
void sellBread(vector<Bread> &q)
{
    if(q.empty())
    {
        cout<<"No bread available"<<endl;
        return;
    }
    //grab the first bread
    Bread b = q.front();
    cout<<"Selling "<<b.batchNo<<endl;
    //delete the bread
    q.erase(q.begin());
}

int main()
{
    vector<Bread> q;
   //menu driven
    while(true)
    {
        cout<<"1. Add bread"<<endl;
        cout<<"2. Sell bread"<<endl;
        cout<<"3. Update bread"<<endl;
        cout<<"4. Exit"<<endl;
        int choice;
        cin>>choice;
        if(choice == 1)
        {
            string batchNo;
            int exp;
            cout<<"Enter batch no and exp"<<endl;
            cin>>batchNo>>exp;
            Bread b(batchNo, exp);
            q.push_back(b);
        }
        else if(choice == 2)
        {   //sort the breads based on exp
            for(int i = 0; i < q.size(); i++)
            {
                for(int j = i+1; j < q.size(); j++)
                {
                    if(q[i].exp > q[j].exp)
                    {
                        swap(q[i], q[j]);
                    }
                }
            }
            sellBread(q);
        }
        else if (choice == 3)
        {
            string batchNo;
            int exp;
            //show all breads to update the date
            for(int i = 0; i < q.size(); i++)
            {
                cout<<q[i].batchNo<<" "<<q[i].exp<<endl;
            }
            cout<<"Enter batch no and exp to update"<<endl;
            cin>>batchNo>>exp;
            for(int i = 0; i < q.size(); i++)
            {
                if(q[i].batchNo == batchNo)
                {
                    q[i].exp = exp;
                    break;
                }
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0; 
}