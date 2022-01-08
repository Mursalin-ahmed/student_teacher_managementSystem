#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
vector<string> teacher_username;
vector<string> teacher_password;
vector<string> student_username;
vector<string> student_password;
vector<string> attendence_date;
vector<string> attend_student;
vector<string> performance;
vector<string> per_student;
map<string,string> individual;
vector<string>:: iterator it;

int teacheraccount();
void changepassword();
int del_teacheraccount();
void teacher_list();
int studentaccount();
int del_studentaccount();
void student_list();

class admin
{
public:

    createAccount()
    {
        cout<<"Enter your choice :\n";
        cout<<"1.create teacher account :\n";
        cout<<"2.create student account :\n";
        int num;
        cin>>num;
        if(num==1)
        {
            teacheraccount();
        }
        else if(num==2)
        {
            studentaccount();
        }
        cout<<"press 1 to create another account and 0 to continue \n";
        int v;
        cin>>v;
        if(v==1)
            createAccount();
    }
    delAccount()
    {
        cout<<"1.delete teacher account :\n";
        cout<<"2.delete student account :\n";
        int num;
        cin>>num;
        if(num==1)
        {
            del_teacheraccount();
        }
        else if(num==2)
        {
            del_studentaccount();
        }
    }
    seePerformance()
    {
        cout<<"1.individual performance \n";
        cout<<"2.collectively performance \n";
        int num;
        cin>>num;
        if(num==1)
        {
            cout<<"Enter student name :\n";
            string s;
            cin>>s;
            cout<<s<<" performance is ";
            cout<<individual[s]<<endl;
        }
        else if(num==2){
        cout<<"student   ";
        cout<<"-> performance\n";
        for(int i=0;i<performance.size();i++)
        {
            cout<<per_student[i]<<"   ";
            cout<<performance[i]<<"\n";
        }
        }
    }
};
class teacher
{
public:
    givePerformance()
    {
        cout<<"Enter student name :\n";
        string s;
        cin>>s;
        if(count(student_username.begin(), student_username.end(), s))
        {
            cout<<"Enter performance \n";
            string s2;
            cin>>s2;
            performance.push_back(s2);
            per_student.push_back(s);
            individual.insert(make_pair(s,s2));
        }
        else
        {
            cout<<"Student name not valid.:\n";
            cout<<"Press 1 to try again 0 to continue\n";
            int num;
            cin>>num;
            if(num==1) givePerformance();

        }

    }
    seeAttendence()
    {
        cout<<"student name  ->";
        cout<<"present date :\n";
        for(int i=0;i<attendence_date.size();i++)
        {
            cout<<attend_student[i];
            cout<<"   ";
            cout<<attendence_date[i]<<"\n";
        }
    }
    seePerformance()
    {
        cout<<"1.individual performance \n";
        cout<<"2.collectively performance \n";
        int num;
        cin>>num;
        if(num==1)
        {
            cout<<"Enter student name :\n";
            string s;
            cin>>s;
            cout<<s<<" performance is ";
            cout<<individual[s]<<endl;
        }
        else if(num==2){
        cout<<"student   ";
        cout<<"-> performance\n";
        for(int i=0;i<performance.size();i++)
        {
            cout<<per_student[i]<<"   ";
            cout<<performance[i]<<"\n";
        }
        }
    }
};
class student
{
public:
    giveAttendence(string s1)
    {
      cout<<"Enter the date and month :\n";
      string s;
      cin>>s;
      attendence_date.push_back(s);
      attend_student.push_back(s1);
    }
};

string username="admin";
string password="dmin@U$T";//dmin@U$T
void changepassword()
{
    string s1,s2;
    cout<<"Enter newusername :\n";
    cin>>s1;
    cout<<"Enter password :\n";
    cin>>s2;
    username=s1;
    password=s2;
}


int teacheraccount()
{
    string name;
    string pass;
    cin.ignore();

    cout<<"Enter teacher name: ";
    cin>>name;
    teacher_username.push_back(name);
    cout<<"Enter password :";
    cin>>pass;
    teacher_password.push_back(pass);

}
int del_teacheraccount()
{
    string name;
    string pass;
    cin.ignore();

    cout<<"Enter teacher name: ";
    cin>>name;

    cout<<"Enter password :";
    cin>>pass;


    it = find (teacher_username.begin(), teacher_username.end(), name);
    teacher_username.erase(it);

    it = find (teacher_password.begin(), teacher_password.end(), pass);
    teacher_password.erase(it);
}
void teacher_list()
{
    for(int i=0; i<teacher_username.size(); i++)
    {
        cout<<i+1<<". "<<teacher_username[i]<<" "<<teacher_password[i]<<endl;
    }
}
int studentaccount()
{
    string name;
    string pass;
    cin.ignore();

    cout<<"Enter student name: ";
    cin>>name;
    student_username.push_back(name);
    cout<<"Enter password :";
    cin>>pass;
    student_password.push_back(pass);
}
int del_studentaccount()
{
    string name;
    string pass;
    cin.ignore();

    cout<<"Enter student name: ";
    cin>>name;

    cout<<"Enter password :";
    cin>>pass;


    it = find (student_username.begin(), student_username.end(), name);
    student_username.erase(it);

    it = find (student_password.begin(), student_password.end(), pass);
    student_password.erase(it);
}
void student_list()
{
    for(int i=0; i<student_username.size(); i++)
    {
        cout<<i+1<<". "<<student_username[i]<<" "<<student_password[i]<<endl;
    }
}
int main()
{
    admin a;
    teacher t;
    student s;

    int num;
    do
    {
        cout<<"Enter the types of account you want to log in :"<<endl;
        cout<<"1.Admin:\n2.Teacher\n3.student:\n4.Exit.\n";

        cin>>num;
        if(num==1)
        {
            string s1;
            string s2;
            cout<<"Enter user name: \n";
            cin>>s1;
            cout<<"Enter password :\n";
            cin>>s2;
            if(s1==username && s2==password)
            {
                int option;
                do
                {
                    cout<<"1.change password \n";
                    cout<<"2.create account \n";
                    cout<<"3.delete account \n";
                    cout<<"4.show teacher_list \n";
                    cout<<"5.show student_list \n";
                    cout<<"6.see performance \n";
                    cout<<"7.log out \n";
                    cin>>option;
                    if(option==1)
                        changepassword();
                    else if(option==2)
                        a.createAccount();
                    else if(option==3)
                        a.delAccount();
                    else if(option==4)
                        teacher_list();
                    else if(option==5)
                        student_list();
                    else if(option==6)
                        a.seePerformance();
                }
                while(option!=7);
            }
            else cout<<"wrong username or password \n";
        }
            else if(num==2)
            {
                string s1;
                string s2;
                cout<<"Enter teacher_user name: \n";
                cin>>s1;
                cout<<"Enter password :\n";
                cin>>s2;
                int right=0;
                if(count(teacher_username.begin(), teacher_username.end(), s1))
                {
                    right=1;
                }
                else right=0;
                if(count(teacher_password.begin(), teacher_password.end(), s2))
                {
                    right=1;
                }
                else right=0;

                if(right==1)
                {
                    int num;
                    do{
                    cout<<"welcome to "<<s1<<" account :\n";
                    cout<<"1.seeAttendence \n";
                    cout<<"2.givePerformance \n";
                    cout<<"3.seePerformance \n";
                    cout<<"4.logout \n";

                    cin>>num;
                    if(num==1)
                        t.seeAttendence();
                    else if(num==2)
                        t.givePerformance();
                    else if(num==3)
                        t.seePerformance();

                }while(num!=4);
                }
                else cout<<"you are not a valid user :\n";
            }
            else if(num==3)
            {
                string s1;
                string s2;
                cout<<"Enter student user name: \n";
                cin>>s1;
                cout<<"Enter password :\n";
                cin>>s2;
                int right=0;
                if(count(student_username.begin(), student_username.end(), s1))
                {
                    right=1;
                }
                else right=0;
                if(count(student_password.begin(), student_password.end(), s2))
                {
                    right=1;
                }
                else right=0;

                if(right==1)
                {
                    int num;
                    do{
                    cout<<"welcome to"<<s1<<" account :\n";
                    cout<<"1. give your attendence  \n";
                    cout<<"2. see your previous performance  \n";

                    cout<<"3. logout  \n";

                    cin>>num;
                    if(num==1)
                    {
                        s.giveAttendence(s1);
                    }
                    else if(num==2)
                    {
                        cout<<s1<<"your previous performance is ";
                         cout<<individual[s1]<<endl;
                    }

                    }while(num!=3);
               }
                else cout<<"you are not a valid user :\n";
            }
            else if(num==4)
            {
                cout<<"Finished :\n";
            }
        }
        while(num!=4);
    }

