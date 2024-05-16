class Solution {
public:
    bool isHappy(int n) {
	int old_n,sum=0, flag;
	old_n=n;
	while(1)
	{
		while(n)
		{
			sum=sum+pow((n%10),2);
			n/=10;
		}
		if(sum==1)
		{
			flag=1;
			break;
		}
		else if(sum==4||sum==145||sum==58)
		{
			flag=0;
			break;
		}
		n=sum;
		sum=0;
	}
	if(flag==1)
	return true;
	else
	return false;
    }
};
