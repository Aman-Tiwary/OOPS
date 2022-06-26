#include<iostream>

using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee{
    private:
    string Name;
    int Age;
    int Id;
    public:
    void Display_details(){
        cout<<"Employee Id: "<<Id<<endl;
        cout<<"Employee Name: "<<Name<<endl;
        cout<<"Employee Age: "<<Age<<endl;
        cout<<endl;
    }
    Employee(string name,int age,int id)
    {
        Name = name;
        Age = age;
        Id = id;
    }
    string getName()
    {
        return Name;
    }
    int getID()
    {
        return Id;
    }
    int getAge()
    {
        return Age;
    }
    void setName(string name)
    {
        Name=name;
    }
    void setID(int id)
    {
        Id = id;
    }
    void setAge(int age)
    {
        Age = age;
    }

    void AskForPromotion()
    {
        if(Age >= 18)
        {
            cout<<Name<<" ,You are eligible for Promotion."<<endl;
        }
        else{
            cout<<Name<<" ,You are not eligible for Promotion."<<endl;
        }
    }
};

class Developer:public Employee{
    public:
    string Language;

    Developer(string name,int age, int id,string language):Employee(name,age,id)
    {
        Language = language;
    }

    void BugFixer()
    {
        cout<<"Bug is fixed by:- "<<getName()<<" Id: "<<getID()<<" Language: "<<Language<<endl;
    }
};

int main()
{
    Employee e1 = Employee("Aman Tiwary",25,1);
    Employee e2 = Employee("Amit Randhawa",25,2);
    Developer d1 = Developer("Mandar Sahane",24,3,"C++");
    
    e1.AskForPromotion();
    e2.AskForPromotion();
    d1.BugFixer();
    return 0;
}