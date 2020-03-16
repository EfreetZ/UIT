#include<iostream>
#include<string>

using namespace std;

class Animal
{
public:
	string mouth;

	void eat();
	void sleep();
	void drool();
};

class Pig : virtual public Animal
{
public:
	void climb();
};

class Turtle : virtual public Animal
{
public:
	void swim();
};

class Creation : public Pig , public Turtle
{
public:
	void W();
};


void Animal::eat()
{
	cout<<"I am eating!"<<endl;
}

void Animal::sleep()
{
	cout<<"I am sleep."<<endl;
}

void Animal::drool()
{
	cout<<"I am so happy!"<<endl;
}

void Pig::climb()
{
	cout<<"I can climb!"<<endl;
}
void Turtle::swim()
{
	cout<<"I can swim!"<<endl;
}

void Creation ::W()
{
	cout<<"We ar lively"<<endl;
}

int main()
{
	Pig pig;
	Turtle turtle;
	Creation c;

	pig.eat();
	turtle.eat();
	pig.climb();
	turtle.swim();
	cout<<endl;
	c.eat();
	c.W();
	
	return 0;
}
//虚继承的作用是防止产生歧义。