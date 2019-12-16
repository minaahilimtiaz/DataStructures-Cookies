//
//  main.cpp
//
//  Created by Ali Qadir Chauhdary on 11/22/19.
//  Copyright © 2019 Ali Qadir Chauhdary. All rights reserved.
//

#include <stdio.h>
#include"Basket_Vector.h"
#include"Basket.h"
#include"Cookie.h"
#include"Basket_Linkedlist.h"
#include <iostream>
#include<vector>
#include <list>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    Basket_LinkedList cookieBasket;
    if (cookieBasket.is_basket_empty()){
        cout << "\nEmpty basket ";
    }
    cout << endl << "Adding some cookies in basket" << endl;
    cookieBasket.add_cookie(Cookie(blackberry_galettes, large));
    cookieBasket.add_cookie(Cookie(macadamia_nut_chocolate, medium));
    cookieBasket.add_cookie(Cookie(walnut_chocolate_chunk, small));
    
    cout << "\nBasket becomes -";
    cookieBasket.print_cookies();
    
    cout << "\n\nTotal cookies= " << cookieBasket.cookie_total() << endl;
    
    cout << "\nSmall cookies= " << cookieBasket.cookie_size_total(small);
    cout << "\nMedium cookies= " << cookieBasket.cookie_size_total(medium);
    cout << "\nLarge cookies= " << cookieBasket.cookie_size_total(large) << endl;
    
    cout << "\nwalnut_chocolate_chunk= " << cookieBasket.cookie_type_total(walnut_chocolate_chunk);
    cout << "\nmacadamia_nut_chocolate cookies= " << cookieBasket.cookie_type_total(macadamia_nut_chocolate);
    cout << "\nblackberry_galettes cookies= " << cookieBasket.cookie_type_total(blackberry_galettes);
    
    cout << "\n\n--------------\nRemove random cookie ";
    Cookie c = cookieBasket.remove_any_cookie();
    cout << "\nRemoved cookie = ";
    c.print();
    
    cout << "\nBasket becomes -";
    cookieBasket.print_cookies();
    cout << "\n\n--------------\nRemove cookie  macadamia nut chocolate in medium size ";
    
    cookieBasket.remove_cookie(Cookie(macadamia_nut_chocolate, medium));
    cout << "\nBasket becomes -";
    cookieBasket.print_cookies();
    cout << "\n\n--------------\nCheck cookie macadamia nut chocolate in medium size is in basket ";
    if (cookieBasket.is_in_basket(Cookie(macadamia_nut_chocolate, medium))){
        cout << "\nPresent";
    }
    else
        cout << "\nabsent";
    cout << "\n\n--------------\nCheck cookie blackberry galettes in large size is in basket ";
    if (cookieBasket.is_in_basket(Cookie(blackberry_galettes, large))){
        cout << "\nPresent";
    }
    else
        cout << "\nabsent";
  //  ---
    cout << "\n\n--------------\nCheck cookie walnut chocolate chunk in small size is in basket ";
    if  (cookieBasket.is_in_basket(Cookie(walnut_chocolate_chunk, small))){
        cout << "\nPresent" <<endl;
    }
    else
        cout << "\nabsent";
    
   // ---
    cout << "\nClear basket ";
    cookieBasket.clear_basket();
    cout << "\ntotal = " << cookieBasket.cookie_total();




	cout << "\n\n--------------\Question 7 ";

	//Creating two baskets one for vector implementation and one for linked list implementation
	fstream  file_handler;
	Basket * b1[3];
	b1[0] = new Basket_Vector();
	b1[1] = new Basket_LinkedList();

	//reading the cookies from file
	file_handler.open("cookie_input.txt");
	if (!(file_handler.is_open()))
	{
		cout << "Input file couldn't be open" << endl;
		return 0;
	}
	string cookie_info = "";
	int i = 0;

	while (getline(file_handler, cookie_info) && i < 5)
	{
		bool comma_found = false;
		string c_type = "", c_size = "";
		int k = 0;
		int pos = cookie_info.find(",");
		c_type = cookie_info.substr(0, pos);
		c_size = cookie_info.substr(pos + 1);
		CookieType cookie_type;
		CookieSize cookie_size;
		if (c_type == "macadamia_nut_chocolate")
		{
			cookie_type = macadamia_nut_chocolate;
		}
		else if (c_type == "walnut_chocolate_chunk")
		{
			cookie_type = walnut_chocolate_chunk;
		}
		else if (c_type == "white_chocolate_raspberry")
		{
			cookie_type = white_chocolate_raspberry;
		}
		else if (c_type == "blackberry_galettes")
		{
			cookie_type = blackberry_galettes;
		}

		if (c_size == "small\r")
		{
			cookie_size = small;
		}
		else if (c_size == "medium\r")
		{
			cookie_size = medium;
		}
		else if (c_size == "large\r")
		{
			cookie_size = large;
		}
		Cookie F(cookie_type, cookie_size);
		b1[0]->add_cookie(F);
		i++;
	}

	while (getline(file_handler, cookie_info) && i < 12)
	{
		bool comma_found = false;
		string c_type = "", c_size = "";
		int k = 0;
		int pos = cookie_info.find(",");
		c_type = cookie_info.substr(0, pos);
		c_size = cookie_info.substr(pos + 1);
		CookieType cookie_type;
		CookieSize cookie_size;
		if (c_type == "macadamia_nut_chocolate")
		{
			cookie_type = macadamia_nut_chocolate;
		}
		else if (c_type == "walnut_chocolate_chunk")
		{
			cookie_type = walnut_chocolate_chunk;
		}
		else if (c_type == "white_chocolate_raspberry")
		{
			cookie_type = white_chocolate_raspberry;
		}
		else if (c_type == "blackberry_galettes")
		{
			cookie_type = blackberry_galettes;
		}

		if (c_size == "small\r")
		{
			cookie_size = small;
		}
		else if (c_size == "medium\r")
		{
			cookie_size = medium;
		}
		else if (c_size == "large\r")
		{
			cookie_size = large;
		}


		Cookie F(cookie_type, cookie_size);
		b1[1]->add_cookie(F);
		i++;
	}

	//Printing cookies in basket1
	cout << "\n\n--------------Printing cookies in basket1" << endl;
	b1[0]->print_cookies();

	cout << endl << endl << endl;

	//Printing cookies in basket2
	cout << "\n\n--------------Printing cookies in basket2" << endl;
	b1[1]->print_cookies();


	//Printing total number of blackberry_galettes cookies present in each basket
	cout << "\n\n--------------Total blackberry galettes cookies in Basket1  " << b1[0]->cookie_type_total(blackberry_galettes) << endl;
	cout << "\n\n--------------Total blackberry galettes cookies in Basket2   " << b1[1]->cookie_type_total(blackberry_galettes) << endl;

	//Printing total number of cookies present in each basket
	cout << "\n\n--------------Total cookies in Basket1  " << b1[0]->cookie_total() << endl;
	cout << "\n\n--------------Total cookies in Basket2  " << b1[1]->cookie_total() << endl;

	//Creating a third basket object
	b1[2] = new Basket_Vector();
	cout << endl << endl << endl;

	//Printing the results after union of basket1 and basket2 cookies
	cout << "\n\n--------------Union of two baskets" << endl;
	b1[2]->merge_baskets(*b1[0], *b1[1]);
	b1[2]->print_cookies();

	cout << endl << endl << endl;

	//Printing total number of blackberry galettes and total cookies in basket3
	cout << "\n\n--------------Total blackberry galettes cookies in Basket1  " << b1[2]->cookie_type_total(blackberry_galettes) << endl;
	cout << "\n\n--------------Total cookies in Basket1  " << b1[2]->cookie_total() << endl;

	cout << endl << endl << endl;

	//Printing the results after intersection of basket1 and basket2 cookies
	cout << "\n\n--------------Intersection of two baskets" << endl;
	b1[2]->intersect_baskets(*b1[0], *b1[1]);
	b1[2]->print_cookies();


	cout << endl << endl << endl;

	//Printing the results after difference of basket1 and basket2 cookies
	cout << "\n\n--------------Difference of two baskets" << endl;
	b1[2]->difference_baskets(*b1[0], *b1[1]);
	b1[2]->print_cookies();
    system("pause");
    return 0;
    
}


