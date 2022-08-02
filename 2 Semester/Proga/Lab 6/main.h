#include <iostream>

struct StructOfPolynom 
{
    int deg;
    int set;
};

template <int len>
class Polynom
{
protected:
    StructOfPolynom ArrOfPolynom[len]{};
public:
    constexpr Polynom() {}
    constexpr Polynom(std::initializer_list<StructOfPolynom> listOfNodes)
    {
        if (len == 0)
        {
            Polynom();
        }
        int index = 0;
        for (auto& i : listOfNodes)
        {
            ArrOfPolynom[index] = i;
            index++;
        }
    }

    constexpr int mean(const int x) const
    {
        int result = 0;
        int mult = 1;
        if (len == 0)
        {
            return 0;
        }
        for (auto& i : ArrOfPolynom)
        {
            mult = 1;
            for (int j = 0; j < i.deg; j++)
            {
                mult *= x;
            }
            mult *= i.set;
            result += mult;;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const Polynom& pol) 
    {
        for (int i = 0; i < len; i++)
        {
            std::cout << pol.ArrOfPolynom[i].set << "x^" << pol.ArrOfPolynom[i].deg << " ";
            if ((i + 1 < len) && (pol.ArrOfPolynom[i + 1].set > 0))
            {
                std::cout << "+";
            }
        }
        return out;
    }
    /*friend std::istream& operator >> (std::istream& in, const Polynom& pol)
    {
        int _len;
        std::cout << "¬ведите количество слагаемых в полиноме" << '\n';
        std::cin >> _len;
        if (_len == 0)
        {
            Polynom pp();
            pol = pp;
            return in;
        }
        else
        {
            std::initializer_list<StructOfPolynom> listOfNodes;
            std::cout << "¬ведите коэффициенты полинома" << '\n';
            for (int i = _len; i >= 0; i--)
            {
                StructOfPolynom Node;
                std::cin >> Node.deg >> Node.set;
                listOfNodes.;
            }
            Polynom pp(_len, listOfNodes);
            pol = pp;
            return in;
        }
    }*/
};
