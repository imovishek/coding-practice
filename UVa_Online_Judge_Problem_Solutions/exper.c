#include <iostream>
#include <fstream>
using namespace std;
unsigned long int operation (unsigned long int x)
{
if (x%2==0)
{
x=x/2;
}
else
{
x=3*x+1;
}
return x;
}
int cycle(unsigned long int x)
{
int i=1;
while(x!=1)
{
i++;
x=operation(x) ;
}
return i;
}
unsigned long int max(unsigned long int x,unsigned long int y)
{
unsigned long int max;
if (x>y)
{
max=x;
}
else
{
max=y;
}
return max;
}



int main()
{
string const nomFichier("C:/Nanoc/fichier.txt");

ofstream monFlux(nomFichier.c_str());

if(monFlux)
{
char reponse;
do
{

cout << "entrez le premier entier" << endl;
unsigned long int i;
do
{
cout << "i="<< endl;
cin>>i;
}while( i>1000000);
cout << "entrez le 2ème entier" << endl;
unsigned long int j;
do
{
cout << "j="<< endl;
cin>>j;
}while( j>1000000);

monFlux<<i<<" "<<j<<endl;
cout << "voulez vous entrer paire d'entiers? O/N?" << endl;
cin >> reponse;

}while(reponse=='O' || reponse =='o');
}
else
{
cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
}
ifstream fichier("C:/Nanoc/fichier.txt");

if(fichier)
{

string ligne;
unsigned long int x;
unsigned long int y;

while(fichier >> x) //Tant qu'on n'est pas à la fin, on lit
{
cout << x ;
fichier >> y;
cout << " " << y;
cout << " " << max(cycle(x),cycle(y))<<endl;


}
}
else
{
cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}



}
