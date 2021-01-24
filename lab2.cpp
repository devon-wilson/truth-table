#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_ARRAY = 8;
bool getConclusion(bool currentP, bool currentR)
{
	if(currentP || currentR)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool getPremise(bool currentP, bool currentQ, bool currentR)
{
	bool p, q, r, arg1, arg2, arg3, arg4;
	p = currentP;
	q = currentQ;
	r = currentR;
	if(p || q)
	{
		arg1 = 1;
	}
	else
	{
		arg1 = 0;
	}
	if(p && r)
	{
		arg2 = 1;
	}
	else
	{
		arg2 = 0;
	}
	if(r && q)
	{
		arg3 = 1;
	}
	else
	{
		arg3 = 0;
	}
	if(q)
	{
		if(r)
		{
			arg4 = 1;
		}
		else
		{
			arg4 = 0;
		}
	}
	else
	{
		arg4 = 1;
	}
	if(arg1 && arg4)   
	{
		if(!arg2)
		{
			if(arg3)
			{
				return true;//first possible case for our premise to be true( (p or q == 1 ) and (if q than r == 1) (p and r == 0) and (r and q == 1) and(<->) (r and q == 1) 
			}
			else
			{
				return false;//	
			}	
		}
		else
		{
			if(!arg3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if(!(arg1 && arg4))
	{
		if(arg2)
		{
			if(arg3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if(!arg3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	
}
int main() 
{
	bool currentP, currentQ, currentR, result1, result2, validity;
	bool p[MAX_ARRAY] = { true, false, true, false, true, false, true, false};
	bool q[MAX_ARRAY] = { true, true, false, false, true, true, false, false};
	bool r[MAX_ARRAY] = { true, true, true, true, false, false, false, false};
	cout << " " << endl;
	cout << "TRUTH TABLE " << endl;
	cout << " " << endl;
	cout << "Premise: ((P v Q) ^ (Q -> R) XOR (P ^ R)) <-> (R ^ Q) " << endl;
	cout << " " << endl;
        cout << "Conclusion: (P v R) " << endl;
	cout << " " << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "|" << "p q r" << "|" << "((P v Q) ^ (Q -> R) XOR (P ^ R)) <-> (R ^ Q) | (P v R) " << "|" << endl;
	cout << "---------------------------------------------------------------" << endl;
	for (int i = 0; i < MAX_ARRAY; i++) 
	{
		currentP = p[i];
		currentQ = q[i];
		currentR = r[i];
		cout << "|";
		cout << setw(1) << p[i];
		cout << " " << q[i];
		cout << " " << r[i] << "|";
		result1 = getPremise(currentP, currentQ, currentR);
		cout << setw(22) << getPremise(currentP, currentQ, currentR);
		result2 = getConclusion(currentP, currentR);
		cout << setw(24) << "|" << setw(5) << getConclusion(currentP, currentR);
		cout << setw(5) << "|";
		if(result1 != result2)
		{
			cout << setw(5) << " invalid!";
			validity = 0;
		}
		cout << endl;
	}
	cout << "---------------------------------------------------------------" << endl;
	if(!validity)
	{
		cout << " " << endl;
		cout << "The argument is invalid! the invalid truth table values are labeled. " << endl;
		cout << " " << endl;
	}
}

  
