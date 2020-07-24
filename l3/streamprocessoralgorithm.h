/*
 * Nicholas Schantz
 * Assignment 3
 * 2020-07-28
 * streamprocessoralgorithm.h
 *
 * Implement StreamProcessorAlgorithm class
 */

class StreamProcessorAlgorithm
{
public:
    StreamProcessorAlgorithm(istream &in, ostream &out) /* ... */
    virtual ~StreamProcessorAlgorithm() /* ... */
    void process() /* ... */
private:
    virtual bool filterToken(const string &token) const = 0;
    virtual void processToken(string &token) const = 0;
    istream &in_;
    ostream &out_;
};
