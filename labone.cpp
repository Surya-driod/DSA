#include <iostream>
using namespace std;
class items
{
    public:
       float w;
       float prpw; 
       void ini(float j)
       {
           w=10*(j/2);
           prpw=j/2;
       }
};

int main()
{
    items x[10];
    float k=1;
    for (int i=1;i<11;i++)
    {
        
        x[i-1].ini(k++);
    }
    
    float tw=0;
    float arr1[10];
    float arr2[10];
    
    for (int i=0;i<10;i++)
        {
             tw+=x[i].w; 
             if (tw<=200)
             {
                 arr1[i]=x[i].w;
                 arr2[i]=arr1[i]/x[i].w;
             }
             else
             {
                 arr1[i]=x[i].w-200+tw;
                 arr2[i]=arr1[i]/x[i].w-1;
                 break;
             }
        }
    for (int i=0;i<10;i++)
    {
        cout << x[i].w <<" @ "<< x[i].prpw << " || ";
        
    }
    for (int i=0;i<10;i++)
    {
        cout << arr1[i] << " ";
    }
    cout<<endl;
    float profit=0;
    for (int z=0;z<10;z++)
    {
        profit=profit+arr1[z]*x[z].prpw;
    }
    
    cout<< "total profit is " << profit<<endl;
    cout<<"factional distribution of items : " << endl;
    for (int i=0;i<10;i++)
    {
        
        cout<< arr2[i] << " ";
    }
    return 0;
}