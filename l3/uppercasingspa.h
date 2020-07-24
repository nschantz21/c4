/*
 * Nicholas Schantz
 * Assignment 3
 * 2020-07-28
 * uppercasingspa.h
 *
 * Implement UpperCasingSPA class
 */

#include <algorithm>
#include <cctype.h>
#include "streamprocessoralgorithm.h"

class UppercasingSPA: public StreamProcessorAlgorithm
{
private:
    virtual bool filterToken(const string &token) const = 0;
    virtual void processToken(string &token) const = 0;

}

bool
UpperCasingSPA::filterToken(const string &token) const
{
    return true;
}

void
UpperCasingSPA::processToken(string &token) const
{
    std::transform(token.begin(), token.end(), token.begin(), toupper);
    out_ << token;
}
