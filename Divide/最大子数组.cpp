int FindMidMaxSum(const vector<int>& v, int left, int mid, int right, int* MaxLeft, int* MaxRight)
{
	if (left > mid || mid > right)
		return 0;
	int LeftSum = 0;
	int RightSum = 0;
	int LeftMaxSum = INT_MIN;
	int RightMaxSum = INT_MIN;
	int i;
	for (i = mid;i >= left;--i)
	{
		LeftSum += v[i];
		if (LeftSum > LeftMaxSum)
		{
			LeftMaxSum = LeftSum;
			*MaxLeft = i;
		}
	}
	for (i = mid + 1;i <= right;++i)
	{
		RightSum+= v[i];
		if (RightSum > RightMaxSum)
		{
			RightMaxSum = RightSum;
			*MaxRight = i;
		}
	}
	return LeftMaxSum + RightMaxSum;
}

int FindMaxSubArray(const vector<int>& v, int left, int right,int* i,int* j)
{
	if (left > right)
		return 0;
	if (left == right)
	{
		*i = *j = left;
		return v[left];
	}
	int MaxLeft1, MaxRight1,MaxLeft2, MaxRight2,MaxLeft3, MaxRight3;
	int mid = left + (right - left) / 2;
	int LeftSum = FindMaxSubArray(v, left, mid, &MaxLeft1, &MaxRight1);
	int RightSum = FindMaxSubArray(v, mid + 1, right, &MaxLeft2, &MaxRight2);
	int MidSum = FindMidMaxSum(v, left, mid, right, &MaxLeft3, &MaxRight3);
	if (LeftSum >= RightSum && LeftSum >= MidSum)
	{
		*i = MaxLeft1;
		*j = MaxRight1;
		return LeftSum;
	}
	else if (RightSum >= LeftSum && RightSum >= MidSum)
	{
		*i = MaxLeft2;
		*j = MaxRight2;
		return RightSum;
	}
	else
	{
		*i = MaxLeft3;
		*j = MaxRight3;
		return MidSum;
	}
}

int calculateMax(vector<int> prices) 
{
	int i;
	vector<int> v;
	int left, right;
	for (i = 1;i < prices.size();++i)
	{
		v.push_back(prices[i] - prices[i - 1]);
		cout << prices[i] - prices[i - 1]<<" ";
	}
	cout << endl;
	int sum1=FindMaxSubArray(v, 0, v.size() - 1, &left, &right);
	int a = left;
	int b = right;
	int sum2 = FindMaxSubArray(v, 0, left - 1, &left, &right);
	left = a;
	right = b;
	int sum3 = FindMaxSubArray(v, right, v.size()-1, &left, &right);
	if (sum1 <= sum2 && sum1 <= sum3)
	{
		if (sum2 < 0)
			return sum3;
		if (sum3 < 0)
			return sum2;
		return sum2 + sum3;
	}
	else if (sum2 <= sum1 && sum2 <= sum3)
	{
		if (sum1 < 0)
			return sum3;
		if (sum3 < 0)
			return sum1;
		return sum1 + sum3;
	}
	else
	{
		if (sum1 < 0)
			return sum2;
		if (sum2 < 0)
			return sum1;
		return sum1 + sum2;
	}
}
