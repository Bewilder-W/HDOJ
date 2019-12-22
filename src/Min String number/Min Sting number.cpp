# include <iostream>
# include <string>
# include <vector>
//算拼接最小数 例如 32 321 3  生成321323 
using namespace std;

void quicksort(vector<int> & arr,int low ,int high)
{
	if(low>=high)
		return ;
	int i=low,j=high,pivot=arr[low];
	while(i<j)
	{
		while(i<j&&arr[j]>pivot)
			j--;
		if(i<j)
			arr[i++]=arr[j];
		while(i<j&&arr[i]<pivot)
			i++;
		if(i<j)
			arr[j--]=arr[i];
	}
	arr[i]=pivot;
	quicksort(arr,low,i-1);
	quicksort(arr,i+1,high);
}

string min(string s1,string s2)
{
	string a=s1+s2;
	string b=s2+s1;
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	vector<int> data;
	vector<string> arr;
	int a,n;
	string s;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>a;
			data.push_back(a);
		}
		quicksort(data,0,data.size()-1);
		string min_s=to_string(data[0]);
		for(int i=1;i<data.size();++i)
		{
			s=to_string(data[i]);
			min_s=min(min_s,s);
		 } 
		 cout<<min_s<<endl;
	}	
	return 0;
}
