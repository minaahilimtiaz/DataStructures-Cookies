
#ifndef QUESTION5_H
#define QUESTION5_H
#include"Basket.h"
#include<list>
#include<iterator>
#include<iostream>
//LinkedList implementation of the Basket  
class Basket_LinkedList :public Basket
{
	list<Cookie> cookies;
public:

	// helping function for helping in getting a single cookie
	Cookie get_cookie(int index)const
	{
	
		list <Cookie> ::const_iterator it = cookies.cbegin();
		for (int i = 0; i < index; i++) {
			it++;

		}

		Cookie cookie_item = *it;
		return cookie_item;
	}

	//linked list implmementation of function for adding cookie in the basket
	void add_cookie(const Cookie& c)
	{
		cookies.insert(cookies.end(), c);
	}

	//linked list implmementation of function for checking cookie present in the basket or not
	bool is_in_basket(const Cookie& c)const
	{
		list <Cookie> ::const_iterator cookie_itr = cookies.begin();
		for (int i = 0; cookie_itr != cookies.end(); cookie_itr++) {
			Cookie cookie_item = *cookie_itr;
			if (cookie_item == c)
			{
				return true;
			}

		}
		return false;
	}

	//linked list implmementation of  function for removing a cookie from the basket
	Cookie remove_any_cookie()
	{
		    Cookie removed_cookie = Cookie();
			int index = rand() % cookies.size();
			list <Cookie> ::iterator cookie_itr = cookies.begin();
			for (int i = 0; cookie_itr != cookies.end() && i < index; i++) {
				cookie_itr++;
			}

			removed_cookie = *cookie_itr;
			cookies.erase(cookie_itr);
		    return removed_cookie;

	}

	//linked list implmementation of function for removing given cookie from the basket
	void remove_cookie(const Cookie& c)
	{
		cookies.remove(c);
	}

	//linked list implmementation of function to empty the basket
	void clear_basket()
	{
		cookies.clear();
	}

	bool is_basket_empty() const
	{
		if (cookies.empty())
			return true;
		else
			return false;
	}

	//linkedlist implmementation of function to check total cookies present in the basket
	int cookie_total() const
	{
		return cookies.size();
	}

	//linked list implmementation of function to check total cookies present in the basket of given size
	int cookie_size_total(CookieSize size) const
	{
		int matched_cookies = 0;
		list <Cookie> ::const_iterator cookie_itr = cookies.begin();
		for (int i = 0; cookie_itr != cookies.end(); cookie_itr++) {
			Cookie cookie_item = *cookie_itr;
			if (cookie_item.get_size() == size)
			{
				matched_cookies++;
			}

		}
		return matched_cookies;

	}

	//linked list implmementation of function to check total cookies present in the basket of given type
	int cookie_type_total(CookieType t) const
	{
		int matched_cookies = 0;
		list<Cookie>mylist;
		list <Cookie> ::const_iterator cookie_itr = cookies.begin();
		for (int i = 0; cookie_itr != cookies.end(); cookie_itr++) {
			Cookie cookie_item = *cookie_itr;
			if (cookie_item.get_type() == t)
			{
				matched_cookies++;
			}

		}
		return matched_cookies;

	}


	//linkied list implmementation of function to print  cookies present in the basket w.r.t sizes from small to large
	void print_cookies() const
	{
		for (int j = 0; j <= 2; j++) {
			list <Cookie> ::const_iterator cookie_itr = cookies.begin();
			for (int i = 0; cookie_itr != cookies.end(); cookie_itr++) {
				Cookie cookie_item = *cookie_itr;
				if (j == 0 && cookie_item.get_size() == small) {
					cookie_item.print();
				}
				if (j == 1 && cookie_item.get_size() == medium) {
					cookie_item.print();
				}
				if (j == 2 && cookie_item.get_size() == large) {
					cookie_item.print();
				}
			}
		}

	}

	//linked list implementation of function for copying cookies from given basket to current basket
	void copy_basket(const Basket& basket)
	{
		clear_basket();
		list <Cookie> ::iterator cookie_itr = cookies.begin();
		for (int i = 0; cookie_itr != cookies.end(); cookie_itr++) {
			Cookie cookie_item = *cookie_itr;
			add_cookie(cookie_item);
		}

	}

	//linked list implementation of function for merging cookies from given baskets to current basket
	void merge_baskets(const Basket& basket1, const Basket& basket2)
	{
		clear_basket();
		for (int i = 0; basket1.cookie_total(); i++) {
			add_cookie(basket1.get_cookie(i));
		}
		for (int j = 0; basket2.cookie_total(); j++) {
			add_cookie(basket1.get_cookie(j));
		}

	}

	//linked list implementation of function for copying only common cookies from given baskets to current basket
	void intersect_baskets(const Basket& basket1, const Basket& basket2)
	{
		clear_basket();
		for (int i = 0; basket1.cookie_total(); i++) {
			if (basket2.is_in_basket(basket1.get_cookie(i)))
			{
				add_cookie(basket1.get_cookie(i));
			}
		}

	}

	//linked list implementation of function for copying cookies cookies of basket1 different from basket2
	void difference_baskets(const Basket& basket1, const Basket& basket2)
	{
		clear_basket();
		for (int i = 0; basket1.cookie_total(); i++) {
			if ((basket2.is_in_basket(basket1.get_cookie(i))) == false)
			{
				add_cookie(basket1.get_cookie(i));
			}
		}
	}

};
#endif