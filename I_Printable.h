//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_I_PRINTABLE_H
#define HACKATHON_STOCKS_I_PRINTABLE_H
#include <iostream>


class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
    //use friend function because we want to have ostream on the left side of the operator and object on the right side
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};


#endif //HACKATHON_STOCKS_I_PRINTABLE_H
