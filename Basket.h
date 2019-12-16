//
//  Basket.h
//  kanjarali
//
//  Created by Ali Qadir Chauhdary on 11/18/19.
//  Copyright © 2019 Ali Qadir Chauhdary. All rights reserved.
//

#ifndef BASKET_HEADER
#define BASKET_HEADER
#include"Cookie.h"
//Abstract Class Basket for containing cookies

class Basket
{
public:
    
    //pure vitrual function for helping in getting a single cookie
    virtual Cookie get_cookie(int index)const = 0;
    
    //pure vitrual function for helping in adding a cookie in the basket
    virtual void add_cookie(const Cookie& c) = 0;
    
    //pure vitrual function for checking if given cookie is present in the basket
    virtual bool is_in_basket(const Cookie& c) const = 0;
    
    //pure vitrual function for removing a cookie from the basket
    virtual Cookie remove_any_cookie() = 0;
    
    //pure vitrual function for removing the given a cookie from the basket
    virtual void remove_cookie(const Cookie& c) = 0;
    
    //pure vitrual function for clearing the basket or to empty the basket
    virtual void clear_basket() = 0;
    
    //pure vitrual function for checking the basket is basket is empty or not
    virtual bool is_basket_empty()const = 0;
    
    //pure vitrual function for checking the total cookies present in the basket
    virtual int cookie_total() const = 0;
    
    //pure vitrual function for checking the total cookies of given size in the basket
    virtual int cookie_size_total(CookieSize size)const = 0;
    
    //pure vitrual function for checking the total cookies of given type in the basket
    virtual int cookie_type_total(CookieType t) const = 0;
    
    //pure vitrual function for printing the cookies w.r.t size from small to large
    virtual void print_cookies() const = 0;

	//pure vitrual function for copying the cookies of given basket in current basket
	virtual void copy_basket(const Basket& basket) = 0;

	//pure vitrual function for merging the cookies of given two baskets in current basket
	virtual void merge_baskets(const Basket& basket1, const Basket& basket2) = 0;

	//pure vitrual function for copying only the common cookies of given two baskets in current basket
	virtual void intersect_baskets(const Basket& basket1, const Basket& basket2) = 0;

	//pure vitrual function for copying only the cookies of basket1 not present in basket2
	virtual void difference_baskets(const Basket& basket1, const Basket& basket2) = 0;


    
};
#endif
