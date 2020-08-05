/*
 * Nicholas Schantz
 * Assignment 3
 * 2020-07-28
 * dsspa.h
 *
 * Implement DigitStrippingSPA class
 */

#ifndef DSSPA_H
#define DSSPA_H

#include <algorithm>
#include <cctype>
#include "spa.h"

class DigitStrippingSPA: public StreamProcessorAlgorithm
{
public:
    DigitStrippingSPA(istream &in, ostream &out):
        StreamProcessorAlgorithm(in, out)
    {}

private:
    virtual bool filterToken(const string &token) const;
    virtual void processToken(string &token) const;
};



// only allow tokens containing at least one digit to pass through
bool
DigitStrippingSPA::filterToken(const string &token) const
{
    return std::any_of(token.begin(), token.end(), isdigit);
}

// remove digits from string
void
DigitStrippingSPA::processToken(string &token) const
{
    token.erase(
        remove_if(
            token.begin(),
            token.end(),
            isdigit
        ), 
        token.end()
    );
    out_ << token << "\n";
}

#endif
