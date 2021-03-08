class Polynomial
{
private:
public:
    int *degCoeff;
    int degree;
    Polynomial()
    {
        degCoeff = new int[1];
        degree = 0;
        degCoeff[0] = 0;
    }

    Polynomial(const Polynomial &t)
    {
        // delete[] degCoeff;
        degCoeff = new int[t.degree + 1];
        degree = t.degree;

        // copy the values
        for (int i = 0; i < degree + 1; i++)
            degCoeff[i] = t.degCoeff[i];
    }

    // accessor - 1
    void print() const
    {
        for (int i = 0; i < degree + 1; i++)
        {
            if (degCoeff[i] != 0) // print only for non zero coefficient
                cout << degCoeff[i] << "x" << i << " ";
        }
        cout << "\n";
    }

    // mutator - 1
    void setCoefficient(int degree, int coeff)
    {
        if (degree > this->degree)
        {
            // make the new array
            int *new_arr = new int[degree + 1];

            // copy the values
            int i = 0;
            for (; i < this->degree + 1; i++)
                new_arr[i] = degCoeff[i];
            for (; i < degree; i++)
                new_arr[i] = 0;

            // delete the old
            delete[] degCoeff;

            // reassign the to the new array
            degCoeff = new_arr;
            this->degree = degree;
        }
        // set the value if <=
        degCoeff[degree] = coeff;
    }
    // inspector - none

    // operator 4
    void operator=(const Polynomial &t) // for deep copy
    {
        // handles all 3 cases.
        // check if space is enough
        if (t.degree > degree)
            degCoeff = new int[t.degree + 1];

        //copy the values over

        for (int i = 0; i < t.degree + 1; i++)
            degCoeff[i] = t.degCoeff[i];

        // make the others zero, runs only if lhs is greater
        // for (; i < t.degree + 1; i++)
        //     degCoeff[i] = 0;
        degree = t.degree;
    }

    Polynomial &operator+(const Polynomial &t) const
    {
        // identify the big and the small
        const Polynomial &big = t.degree >= degree ? t : *this;
        const Polynomial &small = t.degree < degree ? t : *this;

        // create a polynomial of the bigger
        Polynomial *sum = new Polynomial(big);

        int i = 0;
        for (i = 0; i < small.degree + 1; i++)
            sum->degCoeff[i] = big.degCoeff[i] + small.degCoeff[i];

        // copy the rest from the bigger one
        for (; i < big.degree + 1; i++)
            sum->degCoeff[i] = big.degCoeff[i];

        return *sum;
        // cannot return a reference as it will be a dangling reference.
        // As sum will go out of scope. Hence preserving a copy.
    }

    Polynomial &operator-(const Polynomial &t) const
    {
        // identify the big and the small
        const Polynomial &big = t.degree >= degree ? t : *this;
        const Polynomial &small = t.degree < degree ? t : *this;

        // create a polynomial of the bigger
        Polynomial *diff = new Polynomial(big);

        int i = 0;
        for (i = 0; i < small.degree + 1; i++)
            diff->degCoeff[i] = degCoeff[i] - t.degCoeff[i];

        // if p>=q, then Ok
        // if q > p
        if (degree < t.degree)
        {
            for (; i < big.degree + 1; i++)
                (diff->degCoeff[i]) *= -1;
        }
        return *diff;
        // cannot return a reference as it will be a dangling reference.
        // As sum will go out of scope. Hence preserving a copy.
    }

    Polynomial &operator*(const Polynomial &t) const
    {
        Polynomial *prod = new Polynomial;
        prod->degree = degree + t.degree; // maximum degree possible

        prod->degCoeff = new int[prod->degree + 1]; // space for the product array

        // for (int i = 0; i < prod->degree + 1; i++)
        //     prod->degCoeff[i] = 0;
        for (int a = 0; a < degree + 1; a++)
        {
            for (int b = 0; b < t.degree + 1; b++)
                prod->degCoeff[a + b] = prod->degCoeff[a + b] + (degCoeff[a] * t.degCoeff[b]);
        }
        return *prod;
    }
};

// Coding Ninjas Solution
