#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define mpq_class int64_t
#define mpz_class uint64_t
#define mpf_class double
namespace Factorizer
{
    class Polynomial
	{
        public:
            std::vector<mpq_class> coefficients;

            size_t power() const;
            mpq_class &leadingCoefficient();
            const mpq_class &leadingCoefficient() const;
            mpq_class &constantTerm();
            const mpq_class &constantTerm() const;
            
            mpq_class value(mpq_class variable) const;
            mpf_class approximateValue(mpf_class variable) const;
            
            mpq_class applyHorner(mpq_class variable);
            
            void multiply(mpq_class value);
            
            void becomeDerivative();
            Polynomial derivative() const;
    };
    size_t Polynomial::power() const
	{
        return coefficients.size()-1;
    }
    mpq_class Polynomial::value(mpq_class variable) const
	{
        mpq_class res=0;
        for(auto i:coefficients)
		{
            res*=variable;
            res+=i;
        }
        return res;
    }
    mpf_class Polynomial::approximateValue(mpf_class variable) const
	{
        mpf_class res=0;
        for(auto i:coefficients)
		{
            res*=variable;
            res+=i;
        }
        return res;
    }
    mpq_class &Polynomial::leadingCoefficient()
	{
        return coefficients.front();
    }
    const mpq_class &Polynomial::leadingCoefficient() const
	{
        return coefficients.front();
    }
    mpq_class &Polynomial::constantTerm()
	{
        return coefficients.back();
    }
    const mpq_class &Polynomial::constantTerm() const
	{
        return coefficients.back();
    }
    mpq_class Polynomial::applyHorner(mpq_class variable)
	{
        std::vector<mpq_class>::iterator i;
        for(i=coefficients.begin()+1;i!=coefficients.end();i++)
		{
            *i+=*(i-1)*variable;
        }
        mpq_class res=coefficients.back();
        coefficients.pop_back();
        return res;
    }
    void Polynomial::multiply(mpq_class by)
	{
        for(auto &i:coefficients) i*=by;
        return;
    }
    void Polynomial::becomeDerivative()
	{
        for(size_t i=0;i<power();i++)
		{
            coefficients[i]*=(unsigned long)(power()-i);
        }
        coefficients.pop_back();
        return;
    }
    Polynomial Polynomial::derivative() const
	{
        Polynomial tmp=*this;
        tmp.becomeDerivative();
        return tmp;
    }
}
namespace Factorizer
{
    struct Factor
	{
        unsigned long prime;
        size_t power;
    };
    std::vector<Factor> factorize(mpz_class x);
    std::vector<mpz_class> allDivisors(const std::vector<Factor> &factors);
    std::vector<Factor> factorize(mpz_class x)
	{
        std::vector<Factor> res;
        if(x%2==0){
            res.push_back(Factor{2, 0});
            do
			{
                x>>=1;
                res.back().power++;
            }while(x%2==0);
        }
        for(unsigned long i=3;mpz_class(i)*i<=x;i+=2)
		{
            if(x%i==0)
			{
                res.push_back(Factor{i, 0});
                do
				{
                    x/=i;
                    res.back().power++;
                }while(x%i==0);
            }
        }
        if(x>1){
            res.push_back(Factor{x, 1});
        }
        return res;
    }
    std::vector<mpz_class> allDivisors(const std::vector<Factor> &factors)
	{
        std::vector<mpz_class> res={1};
        for(auto &i:factors)
		{
            mpz_class mult=i.prime;
            size_t n=res.size();
            for(size_t j=1;j<=i.power;j++)
			{
                for(size_t k=0;k<n;k++)
				{
                    res.push_back(res[k]*mult);
                }
                if(j<i.power) mult*=i.prime;
            }
        }
        return res;
    }
} 
#include <iostream>
using namespace Factorizer;
int main()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	Polynomial poly;
	size_t N;
	std::cin >> N;
	for(size_t i=0;i<=N;i++)
	{
		mpq_class x;
		std::cin >> x;
		poly.coefficients.push_back(x);
	}
	std::vector<mpz_class> nPos=allDivisors(factorize(fabs(poly.constantTerm())));
	std::vector<mpz_class> dPos=allDivisors(factorize(fabs(poly.leadingCoefficient())));
	std::vector<mpq_class> ans;
	for(auto &i:nPos)
	{
		for(auto &j:dPos)
		{
			Polynomial tmp;
			tmp=poly;
			while(tmp.applyHorner(i/j)==0)
			{
				poly=tmp;
				ans.push_back (mpq_class(i)/j);
			}
			tmp=poly;
			while(tmp.applyHorner(-mpq_class(i)/j)==0)
			{
				poly=tmp;
				ans.push_back (-mpq_class(i)/j);
			}
		}
	}
	sort (ans.begin (), ans.end ());
	for (uint64_t i = 0 ; i < ans.size () - 1 ; i ++)
		cout << ans [i] << " ";
	cout << ans [ans.size () - 1] << std::endl;
	if (poly.power () > 0) 
		return 23546;
    return 0;
}
