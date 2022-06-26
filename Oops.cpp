#include<iostream>

using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0; // Abstraction: every class that inherit AbstractEmployee has to implement AskforPromotion in them.
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
    string getName()  // Encapsulation: Data are hidden and getter setter are used to access the data.
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
    virtual void work()
    {
        cout<<getName()<<" is doing random work."<<endl;
    }
};

class Developer:public Employee{  //Inheritance: child class inherit all the protected and public data members and member functions from the Base/Parent class.
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
     void work()
    {
        cout<<getName()<<" is fixing bug of a "<<Language<<" program."<<endl;
    }
};

class Teacher:public Employee{
    public:
    string Subject;

    Teacher(string name,int age, int id,string subject):Employee(name,age,id)
    {
        Subject = subject;
    }

    void work()
    {
        cout<<getName()<<" is Teaching "<<Subject<<"."<<endl;
    }
};
int main()
{
    Employee e1 = Employee("Aman Tiwary",25,1);
    Employee e2 = Employee("Amit Randhawa",25,2);
    Developer d1 = Developer("Mandar Sahane",24,3,"C++");
    Teacher t1 = Teacher("Gautam Kumar",26,4,"Maths");
    e1.work();
    e2.work();
    d1.work();
    t1.work();

    Employee *e3 = & d1;
    Employee *e4 = & t1;

    e3->work();
    e4->work();
    return 0;
}