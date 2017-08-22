#include <bits/stdc++.h>
#define MAX 4096
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;

char str[MAX];
char punctuation[]={'!','.', ',', ':', ';', '(', ')', '{', '}', '[', ']', '|', '~', '\'', '"', '`', '?', '<', '>', '*', '/', '+', '=',0};
char dari[4]="।";
char inCommaBegin[4]="‘";
char inCommaEnd[4]="’";
char doInCommaBegin[4]="“";
char doInCommaEnd[4]="”";

bool hPunctuation(char ch)
{
    int i;
    for(i=0;punctuation[i];i++) if(punctuation[i]==ch) return true;
    return false;
}

bool hAlpha(char ch)
{
    if(ch<='Z') return ch>='A'&&ch<='Z';
    return ch>='a'&&ch<='z';
}

bool hNumeric(char ch)
{
    return ch>='0'&&ch<='9';
}


void RemovePunctuation(char *a)
{
    int i,j,len;char temp[MAX],ts[4];
    len=strlen(a);
    for(i=j=0;i<len;i++)
    {
        if(hPunctuation(a[i])||hAlpha(a[i])||hNumeric(a[i])) continue;
        strncpy(ts,a+i,3);ts[3]=0;
        if(!strcmp(ts,dari)) break;
        strncpy(ts,a+i,3);ts[3]=0;
        if(!strcmp(ts,inCommaBegin)||!strcmp(ts,inCommaEnd)||!strcmp(ts,doInCommaBegin)||!strcmp(ts,doInCommaEnd))
        {
            i+=2;
            continue;
        }
        temp[j++]=a[i];
    }
    for(i=0;i<j;i++) a[i]=temp[i];
    a[i]=0;
    return ;
}

map<string,bool> Map;

int main()
{
    filein;
    fileout;
    Map.clear();
    while(scanf("%s",str)==1)
    {
        RemovePunctuation(str);
        if(Map.find(str)==Map.end())
        {
            printf("%s\n",str);
            Map[str]=true;
        }
    }
    return 0;
}
