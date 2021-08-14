#include <iostream>

using namespace std;
struct elemt{ int info;
            elemt *suiv;
            };
struct pile{ elemt *sommet;
            };
bool si_vide(pile *f)
{   bool out=false;
    if(f==NULL)
        out=true;
    else{
        if(f->sommet==NULL)
            out=true;
        }
    return out;
}
void empiler(pile *&f,int val)
{ elemt *nov;
  if(f==NULL)
  {
      f= new pile;
      f->sommet=NULL;
  }
  nov=new elemt;
  nov->info=val;
  nov->suiv=f->sommet;
  f->sommet=nov;

}
int depiler(pile *&f)
{  elemt *p;
    int q=-10000;
    if(si_vide(f)==false)
      { q=f->sommet->info;
        p=f->sommet;
       f->sommet=f->sommet->suiv;
       delete p;
      }
return q;
}
void cree_pile(pile *&f,int tai)
 {  int valeur;
     for(int i=0;i<tai;i++)
     { cout<<"donner la valeur de "<<i+1<<" element:";
       cin>>valeur;
       empiler(f,valeur);
     }
 }
void supprimer(pile *&f)
{ if(si_vide(f))
     cout<<"la pile est vide!!!!\n";
  else{
    while(f->sommet!=NULL)
       depiler(f);
    cout<<"la pile a ete supprimer!!!!\n";
    }
}
void affich_pile(pile *f)
{   cout<<"-------------AFFICHAGE-------------------\n";
    if(si_vide(f)==false)
    {
        elemt *e;
        e=f->sommet;
        while(e!=NULL)
        {   cout<<e->info<<endl;
            e=e->suiv;
        }
    }
    else
        cout<<"la pile est vide,rien a affiche!!!!!\n";
    cout<<"----------------------------------------\n";
}
struct file{ elemt *first,*last;
            };
void emfiler(file *&f,int val)
{ elemt *nov;
  if(f==NULL)
  {
      f= new file;
      f->first=NULL;
      f->last=NULL;
  }
  nov=new elemt;
  nov->info=val;
  nov->suiv=NULL;
  if(f->first==NULL)
    f->first=nov;
  else
    f->last->suiv=nov;
  f->last=nov;

}
bool si_videf(file *f)
{   bool out=false;
    if (f==NULL)
        out=true;
    else{
        if((f->first==NULL)&&(f->last==NULL))
            out=true;
    }
    return out;
}
int defiler(file *&f)
{  elemt *p;
   int q=-111111;
    if(si_videf(f)==false)
      { q=f->first->info;
        p=f->first;
        f->first=f->first->suiv;
        delete p;
        if(f->first==NULL)
          f->last=NULL;
      }
return q;
}
void invr_pile(pile *f)
{   elemt *e;
    file *p=NULL;
    int val;
        e=f->sommet;
       while(e!=NULL)
       {
           emfiler(p,e->info);
           e=e->suiv;

       }
       e=f->sommet;
       while(e!=NULL)
       {
           depiler(f);
           e=e->suiv;
       }

       e=p->first;
       while(e!=NULL)
       {
           val=defiler(p);
           empiler(f,val);
           e=e->suiv;
       }


}

int main()
{
     pile *f=NULL;

    int tai;
    cout<<"donner le nombre des elements de la pile:\n";
    cin>>tai;
    cree_pile(f,tai);
    if(si_vide(f)==false)
      {
        if(f->sommet->suiv==NULL)
            affich_pile(f);
         else{
                affich_pile(f);
                invr_pile(f);
                affich_pile(f);
              }
       supprimer(f);
    }else{cout<<"la pile est vide,rien a inverse\n";
         }
    return 0;
}
