#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	short T;
	cin >> T;
	
	while(T--)
	{
		int N;
		cin >> N;
		
		int* sequence = new int[N];
		
		for(int i = 0; i < N; i++)
			cin >> sequence[i];
			
		vector<bool> non4(N);		
		
		for(int i = 0; i < N; i++)
		{
			if(sequence[i] % 2 == 0)
			{
				non4[i] = 1;
			}
		}
		
		int count_before, count_after, count = 0;
		auto current = find(begin(non4), end(non4), 1);
		auto prev = begin(non4);
		bool flag = true;                
		while(sequence[current-begin(non4)]%4==0 && current != end(non4))
		{
			flag = false;
			prev = current;
			current = find(current + 1, end(non4), 1);
		}
		
		count_before = (prev == begin(non4) && flag)?(current - prev):(current - prev - 1);
		
		while(current != end(non4))
		{
			prev = current;
			current = find(current + 1, end(non4), 1);
			count_after = current - prev -1;
			
			count += (count_before + 1) * (count_after + 1);
			
			while(sequence[current-begin(non4)]%4==0 && current != end(non4))
			{
				prev = current;
				current = find(current + 1, end(non4), 1);
			}
			
			count_before = current - prev - 1;
		}
		
		int max_subseq = (N*(N+1))/2;
		
		cout << max_subseq - count << "\n";
	}
	return 0;
}