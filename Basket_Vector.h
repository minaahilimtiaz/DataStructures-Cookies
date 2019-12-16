//
//  Basket_Vector.h
//  kanjarali
//
//  Created by Ali Qadir Chauhdary on 11/18/19.
//  Copyright © 2019 Ali Qadir Chauhdary. All rights reserved.
//

#ifndef Basket_Vector_h
#define Basket_Vector_h


#include"Basket.h"
#include<vector>

//Vector Implement of Basket Class implementing all the virtual functions to become concrete class
class Basket_Vector : public Basket
{
    vector<Cookie> cookies;
public:
    
    // helping function for helping in getting a single cookie
    Cookie get_cookie(int index)const
    {
        return cookies[index];
    }
    
    //vector implmementation of function for adding cookie in the basket
    void add_cookie(const Cookie& c)
    {
        cookies.push_back(c);
    }
    
    //vector implmementation of function for checking cookie present in the basket or not
    bool is_in_basket(const Cookie& c)const
    {
        for (int i = 0; i < cookies.size(); i++)
        {
            if (cookies[i].get_size() == c.get_size() && cookies[i].get_type() == c.get_type())
            {
                return true;
            }
            
        }
        return false;
    }
    
    //vector implmementation of  function for removing a cookie from the basket
    Cookie remove_any_cookie()
    {
            Cookie removed_cookie = Cookie();
            int index = rand() % cookies.size();
            removed_cookie = cookies.at(index);
            cookies.erase(cookies.begin() + index);
            return removed_cookie;
        
    }
    
    //vector implmementation of function for removing given cookie from the basket
    void remove_cookie(const Cookie& c)
    {
        for (int i = 0; i < cookies.size(); i++)
        {
            if (cookies[i].get_size() == c.get_size() && cookies[i].get_type() == c.get_type())
            {
                cookies.erase(cookies.begin() + i);
                return;
            }
            
        }
    }
    
    //vector implmementation of function to empty the basket
    void clear_basket()
    {
        cookies.clear();
    }
    
    //vector implmementation of function to check if basket is empty or not
    bool is_basket_empty() const
    {
        if (cookies.empty())
        return true;
        else
        return false;
    }
    
    
    //vector implmementation of function to check total cookies present in the basket
    int cookie_total() const
    {
        return cookies.size();
    }
    
    
    //vector implmementation of function to check total cookies present in the basket of given size
    int cookie_size_total(CookieSize size) const
    {
        int matched_cookies = 0;
        for (int i = 0; i < cookies.size(); i++)
        {
            if (cookies[i].get_size() == size)
            {
                matched_cookies++;
            }
            
        }
        return matched_cookies;
        
    }
    
    
    //vector implmementation of function to check total cookies present in the basket of given type
    int cookie_type_total(CookieType t) const
    {
        int matched_cookies = 0;
        for (int i = 0; i < cookies.size(); i++)
        {
            if (cookies[i].get_type() == t)
            {
                matched_cookies++;
            }
            
        }
        return matched_cookies;
    }
    
    
    //vector implmementation of function to print  cookies present in the basket w.r.t sizes from small to large
    void print_cookies() const
    {
        for (int j = 0; j <= 2; j++) {
            for (int i = 0; i < cookies.size(); i++) {
                
                if (j == 0 && cookies[i].get_size() == small) {
                    cookies[i].print();
                }
                if (j == 1 && cookies[i].get_size() == medium) {
                    cookies[i].print();
                }
                if (j == 2 && cookies[i].get_size() == large) {
                    cookies[i].print();
                }
            }
        }
        
    }

	//vector implementation of function for copying cookies from given basket to current basket
	void copy_basket(const Basket& basket)
	{
		clear_basket();
		for (int i = 0; i < basket.cookie_total(); i++)
		{
			this->add_cookie(basket.get_cookie(i));
		}
	}

	//vector implementation of function for merging cookies from given baskets to current basket
	void merge_baskets(const Basket& basket1, const Basket& basket2)
	{
		clear_basket();
		for (int i = 0; i < basket1.cookie_total(); i++)
		{
			this->add_cookie(basket1.get_cookie(i));
		}
		for (int i = 0; i < basket2.cookie_total(); i++)
		{
			this->add_cookie(basket2.get_cookie(i));
		}

	}

	//vector implementation of function for copying only common cookies from given baskets to current basket
	void intersect_baskets(const Basket& basket1, const Basket& basket2)
	{
		clear_basket();
		for (int i = 0; i < basket1.cookie_total(); i++)
		{
			if (basket2.is_in_basket(basket1.get_cookie(i)))
			{
				add_cookie(basket1.get_cookie(i));
			}
		}
	}

	//vector implementation of function for copying cookies cookies of basket1 different from basket2
	void difference_baskets(const Basket& basket1, const Basket& basket2)
	{
		for (int i = 0; i < basket1.cookie_total(); i++)
		{
			if (basket2.is_in_basket(basket1.get_cookie(i)) == false)
			{
				add_cookie(basket1.get_cookie(i));
			}
		}

	}

    
};
#endif
