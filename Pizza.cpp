//In class Pizza Program
//5/15/2019
//Hadi H Daana


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Pizza{
	
	private:
		string pType;
		string pSize;
		int pToppings;
		float price;
		
	public:
		
		Pizza(string pT, string pS, int pTop)
		{
			pType = pT;
			pSize = pS;
			pToppings = pTop;
			price = calcPrice();
		}
		
	void setpType(string pT)
	{
		pType = pT;
	}
	string getpType()
	{
		return pType;
	}
	void setpSize(string pS)
	{
		pSize = pS;
	}
	string getpSize()
	{
		return pSize;
	}
	void setpToppings(int pTop)
	{
		pToppings = pTop;
	}
	int getpToppings()
	{
		return pToppings;
	}
	float getPrice()
	{
		return price;
	}
	
	
	float calcPrice()
	{
		float Price;
		if(pSize == "small" || pSize == "Small")
		{
			Price = 10 + (pToppings *2);
			
		}else if(pSize == "meduim" || pSize == "Meduim")
		{
			Price = 14 + (pToppings *2);
			
		}else if(pSize == "large" || pSize == "Large")
		{
			Price = 17 + (pToppings*2);
		}
		
		return Price;
		
	}
	
	void displayPizza()
	{
		//float p = calcPrice();
		cout<<"a "<<pSize<<" "<<pType<<" Pizza with "<<pToppings<<" Toppings"<<endl<<"Price is: $"<<price<<endl;
	}
	
		
};
	class Order{
	
	private:
		vector <Pizza> pizzas;
		string name;
		string number;
	public: 
		
		Order(string nm, string num)
		{
			name = nm;
			number = num;	
		}	
		
	void addPizza(Pizza apizza)
	{
		pizzas.push_back(apizza);
	}
	
	void displayOrder()
	{
		float total;
		
		cout<<endl;
		cout<<"name: "<<name<<endl;
		cout<<"phone number: "<<number<<endl;
		cout<<endl;
		cout<<"You Ordered: "<<endl;
		cout<<endl;
		for(Pizza pzs: pizzas)
		{
			pzs.displayPizza();
			total += pzs.calcPrice();
		}
		cout<<endl;
		cout<<"Your total is: $"<<total;
	}
	
	};

int main()
{
	string type;
	string size;
	int toppings;
	int pick;
	float total;
	string pNumber;
	string name;
	
	cout<<setprecision(2)<<fixed;
	
	cout<<"What is your name: "<<endl;
	getline(cin, name);
	
	cout<<"What is your Phone number: "<<endl;
	getline(cin, pNumber);
	
	Order aOrder(name, pNumber);
	do
	{
	cout<<"What kind of pizza: "<<endl;
	getline(cin, type);
	
	cout<<"What is the Size (small/meduim/large): "<<endl;
	getline(cin, size);
	
	cout<<"How many toppings: "<<endl;
	cin>>toppings;
	
	Pizza pizza(type, size, toppings);
	
	aOrder.addPizza(pizza);
	
	cout<<"Would you like another Pizza(1-> yes/ 2->no)"<<endl;
	cin>>pick;
	
	cin.clear();
	cin.ignore();
	}while(pick == 1);
	
	aOrder.displayOrder();
	
	return 0;
	
}
