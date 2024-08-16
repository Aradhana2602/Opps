#include<bits/stdc++.h>
using namespace std;
class publication
{
    public:
    string title;
    float price;
    
    void add()
    {
        cout<<"Enter the Publication information: "<<endl;
        cout<<"Enter Title Name:"<<endl;
        cin.ignore();
        getline(cin,title);
        cout<<"Enter the price of Publication: "<<endl;
        cin>>price;
    }
    void display()
    {
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Title of Publication: "<<title<<endl;
        cout<<"Price of Publication: "<<price<<endl;
    }
};
class book: public publication
{
    //page count
    int page_count;
    public:
    void add_book()
    {
      try
      {
        add();
        cout<<"Enter Page Count of Book: "<<endl;
        cin>>page_count;
        if(page_count<=0)
        {
            throw page_count;
        }
      }
      catch(...)
      {
        cout<<"Invalid Page Count!!!"<<endl;
        page_count=0;
      }
    }

    void display_book()
    {
        display();
        cout<<"Page Count: "<<page_count<<endl;
        cout<<"-------------------------------------------------"<<endl;
    }
};
class tape: public publication
{
    //playing time
    float play_time;
    public:
    void add_tape()
    {
        try
        {
            add();
            cout<<"Enter playing time of cassettes:"<<endl;
            cin>>play_time;
            if(play_time<=0)
            throw play_time;
        }
        catch(...)
        {
            cout<<"Invalid Play Time!!!"<<endl;
            play_time=0;
        }
    }

    void display_tape()
    {
        display();
        cout<<"Play Time: "<<play_time<<" minutes"<<endl;
        cout<<"-------------------------------------------------"<<endl;
    }
};
int main()
{
    book b1[10];         //object of book 
    tape t1[10];         //bject of tape
    int ch,b_count=0,t_count=0;
    do
    {
        cout<<"~~~~~~~ PUBLICATION DATABASE SYSTEM ~~~~~~~~"<<endl;
        cout<<"-----------------MENU-----------------------"<<endl;
        cout<<"1. Add info about books"<<endl;
        cout<<"2. Add info about tapes"<<endl;
        cout<<"3. Display Books Info"<<endl;
        cout<<"4. Display Tapes Info"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            b1[b_count].add_book();
            b_count++;
            break;

            case 2:
            t1[t_count].add_tape();
            t_count++;
            break;

            case 3:
            cout << "* * * * BOOK PUBLICATION DATABASE SYSTEM * * * *"<<endl;
            for (int j=0;j<b_count;j++)
            b1[j].display_book();
            break;

            case 4:
            cout<<"* * * * TAPES PUBLICATION DATABASE SYSTEM * * * *"<<endl;
            for(int j=0;j<t_count;j++)
            t1[j].display_tape();
            break;

            case 5:
            exit(0);
        }
    } while (ch!=5);
    return 0;
}
