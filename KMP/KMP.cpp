//暴力匹配
void NaiveStringMatcher(const string& text, const string& pattern)
{
	int n = text.size();
	int m = pattern.size();
	int i;
	int s;
	for (s = 0;s <= n - m;++s)
	{
		for (i = 0;i < m;++i)
		{
			if (text[s + i] != pattern[i])
				break;
		}
		if (i == m)
			cout << "Pattern occurs with shift " << s << endl;
	}
}

void CalcNext(vector<int>& next, const string& p)
{
	int length = p.size();
	next.resize(length);
	next[0] = -1;
	int k = -1, j = 0;
	while(j < length-1)
	{
		while (k >= 0 && p[j] != p[k])
			k = next[k];
		k++;
		j++;
		next[j] = k;
	}
}

void KMP(const string& text, const string& pattern)
{
	int tlen = text.size();
	int plen = pattern.size();
	vector<int> next;
	CalcNext(next, pattern);
	int i, j=0;
	for (i = 0;i < tlen;++i)
	{
		while (j > 0 && text[i] != pattern[j])
			j = next[j];
		if (text[i] == pattern[j])
			j++;
		if (j == plen)
		{
			cout << "Pattern occurs with shift " << i - plen + 1 << endl;
			j = next[j-1];
		}
	}
}

int main()
{
	string t = "google";
	string p1 = "google";
	string p2 = "googla";
	string p3 = "ogle";
	//NaiveStringMatcher(t, p1);
	//NaiveStringMatcher(t, p2);
	//NaiveStringMatcher(t, p3);
	KMP(t, p1);
	KMP(t, p2);
	KMP(t, p3);
}
