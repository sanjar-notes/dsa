# 2. Unary post
Created Sunday 12 January 2020


17. Both pre and post use the same symbol, how to differentiate pre and post in code?
18. Write ``data_type`` in parentheses. This indicates that the operator is a post(i.e appears on the right side of the operand).



* Rember that we don't need nesting in post operations, i.e return type ``void``.


Example
```c++
class A
{
    public:
        int a;
        A(int a)
        {
            this->a = a;
        }

        void operator++(int) // ++ as postfix
        {
            a++;
            cout << "post\n";
            return a;
        }

        A& operator++() // ++ as prefix, nesting is present return reference
        {
            cout << "pre\n";
            ++a;
            return a;
        }
};
```
