/*
 *
 * Program to test IntegerRange class
 */

int main()
{
    IntegerRange<int> r1(-2, 3);
    copy(r1.begin(), r1.end(), ostream_iterator<int>(cout, " "));

    IntegerRange<unsigned> r2(0, 6);
    copy(r2.begin(), r2.end(), ostream_iterator<unsigned>(cout, " "));
    
    return 0;
}
