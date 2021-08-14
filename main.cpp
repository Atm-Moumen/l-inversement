#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
struct elemt{ char info;
              elemt *suiv;
            };
struct pile { elemt *sommet;
            };
bool si_vide(pile *p)
{
    bool out=false;
    if((p==NULL)|(p->sommet==NULL))
        out = true;
 return out;

}

void empiler(pile *&p,char val)
{ elemt *nov;
    if(p==NULL)
    {
        p = new pile;
        p->sommet=NULL;
    }
     nov = new elemt;
     nov->info=val;
     nov->suiv=p->sommet;
     p->sommet=nov;

}
char depiler(pile *&p)
{  elemt *q;
    char val='-1';
    if(si_vide(p)==false)
    { q=p->sommet;
      val=p->sommet->info;
      p->sommet=p->sommet->suiv;
      delete q;

    }
    return val;
}
int long_ch(char ch[30])
{
    int nb=0;
    int i=0;
    while(ch[i]!='\0')
    {
        nb++;
        i++;
    }
    return nb;
}

void invr_chain(char ch[30])
{   pile *p=NULL;
    elemt *e;
    char c;
    int l;
    l=strlen(ch);
    for(int i=0;i<l;i++)
    {    char v;
        v=ch[i];
        empiler(p,v);
    }
    e=p->sommet;
    while(e!=NULL)
    {   c=depiler(p);
        cout<<c;
        e=e->suiv;
    }
}


int main()
{
   char ch[30];
   cout<<"donner votre chaine de caractere: ";
   gets(ch);
   //cin>>ch;
   cout<<"--------------------------------------------\n";
   cout<<ch<<endl;
   cout<<"la chine inverse:\n";
   invr_chain(ch);
   cout<<"\n--------------------------------------------\n";

return 0;
}
