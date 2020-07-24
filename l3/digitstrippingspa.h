/*
 * Nicholas Schantz
 * Assignment 3
 * 2020-07-28
 * digitstrippingspa.h
 *
 * Implement DigitStrippingSPA class
 */

#include <algorithm>
#include <cctype.h>
#include "streamprocessoralgorithm.h"

class DigitStrippingSPA: public StreamProcessorAlgorithm
{
private:
    virtual bool filterToken(const string &token) const;
    virtual void processToken(string &token) const;
}

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
}
