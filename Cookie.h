#ifndef COOKIE_H
#define COOKIE_H
#include <iostream>
#include <string>
using namespace std;
// enum classes for CookieType and CookieSize
enum CookieType { macadamia_nut_chocolate, walnut_chocolate_chunk, blackberry_galettes, white_chocolate_raspberry };
enum CookieSize { small, medium, large };

// Cookie class
class Cookie {
    
    // member attributes
private:
    CookieType cookie_type;
    CookieSize cookie_size;
public:
    // constructor
    Cookie (){
		cookie_type = white_chocolate_raspberry;
		cookie_size = large;
    }
    Cookie(CookieType ct, CookieSize cs)
    {
        cookie_type = ct;
        cookie_size = cs;
    }
    
    // get type of cookie
    CookieType get_type() const
    {
        return cookie_type;
    }
    
    // get size of cookie
    CookieSize get_size() const
    {
        return cookie_size;
    }
    
    // override the equality operator
    bool operator==(const Cookie &c)const;
    
    // print cookie values
    void print()const
    {
        cout << "(";
        
        // print cookie_type
        switch (cookie_type)
        {
            case macadamia_nut_chocolate:
                cout << "macadamia nut chocolate,";
                break;
            case walnut_chocolate_chunk:
                cout << "walnut chocolate chunk,";
                break;
            case blackberry_galettes:
                cout << "blackberry galettes,";
                break;
            case white_chocolate_raspberry:
                cout << "white chocolate raspberry,";
                break;
        }
        
        // print cookie_size
        switch (cookie_size)
        {
            case small:
                cout << " small)" << endl;
                break;
            case medium:
                cout << " medium)" << endl;
                break;
            case large:
                cout << " large)" << endl;
                break;
        }
    }
};

// implementation of override of ==
bool Cookie::operator==(const Cookie &c)const
{
    return this->cookie_type == c.get_type() && this->cookie_size == c.get_size();
}

#endif

