#include <iostream>
using namespace std;
class FavouriteGame
{
    public:
    int start,end;
    FavouriteGame()
    {
        start=end=0;
    }
    void maxhours(FavouriteGame fg[50],int n)
    {
        //Sorting wrt end
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j>n;j++)
            {
                if(fg[j].end>fg[j+1].end)
                {
                    FavouriteGame temp=fg[j];
                    fg[j]=fg[j+1];
                    fg[j+1]=temp;
                }
            }
        }
        //sorting wrt start
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(fg[j].start>fg[j+1].start)
                {
                    FavouriteGame temp=fg[j];
                    fg[j]=fg[j+1];
                    fg[j+1]=temp;
                }
            }
        }
	int k=0;
	int count=0;
	while(k<n)
     {
	  start=fg[k].start;
        end=fg[k].end;
        int c=1;
        for(int i=0;i<n;i++)
        {
            if(fg[i].start==start)
            {
                if(fg[i].end<end)
                    end=fg[i].end;
            }
            else if(fg[i].start<end )
                continue;
            else
            {
                start=fg[i].start;
                end=fg[i].end;
                c++;
            }
        }
	k++;
	if(c>count)
		count=c;
}
        cout<<count;
    };
};
istream &operator>>(istream &in, FavouriteGame &obj)
{
    in>>obj.start>>obj.end;
    return in;
}
int main() 
{
    int n;
    cin>>n;
    FavouriteGame fg[n];
    for(int i=0;i<n;i++)
        cin>>fg[i];
    FavouriteGame tmp;
    tmp.maxhours(fg,n);
    return 1;
}

