#include <iostream>
 
using namespace std;

class Person{

	public:

	string name;
	string country;
	virtual void setName(string name)=0;
	virtual void setCountry(string country)=0;	
	virtual string getName(void)=0;
	virtual string getCountry(void)=0;

	private:

	int age; 

};

class Student: public Person{

        public:
	
	Student(string name,string country){
		this->name=name;
		this->country=country;
        }
	void setName(string name){
 		this->name=name;
	}

	void setCountry(string country){
 		this->country=country;
	}

	string getName(void){
                std::cout <<"\n" << this->name << endl;
		return this->name;
	}

	string getCountry(void){
	        std::cout <<"\n" << this->country<< endl;
		return this->country;
	}
};

int main(){
	Student s("Bob","USA");


        s.getName();
        s.getCountry();
        s.setName("Alice");
	s.setCountry("UK");
        s.getName();
        s.getCountry();
       // cout << s.age <<endl;  // This is not allowed
       
  	return 0;      
}
