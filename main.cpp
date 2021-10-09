#include <iostream>
#include<fstream>
#include<time.h>
#include<string.h>
using namespace std;

void show(char ans[],int n)//showing the ans string
{
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";

}
bool check(string a,char t,int n,char ans[])//check and fill the correct characters
{
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==t)
        {
            ans[i]=t;
            f=1;
        }
    }
    if(f==0)
    {
        cout<<"Entered character is not in the word"<<endl;
        return false;
    }
    return true;
}
bool checkwin(char ans[],int n)//checking if all the char are correctly filled
{
    for(int i=0;i<n;i++)
        if(ans[i]=='_')
        return false;
    return true;
}
int hintfind(string abc,int n){//finding total vowels in the string
    int vow=0;
    for(int i=0;i<n;i++)
    {
        if(abc[i]=='a' || abc[i]=='e' || abc[i]=='i' || abc[i]=='o' || abc[i]=='u')
        {
            vow++;
        }
    }
    return vow;
}
int main()
{
    int ran=0,no=0;
    fstream f;//creating object for the fstream class
    f.open("greproject.txt",ios::in);//open the txt file greproject in input mode
    srand(time(0));//generate a random number within limit 0 to 676
    ran=rand()%677;
    ran++;//increase the ran no limit 1 to 677
    string a,b="",abc="";
    int c=0;
    while(getline(f,a)){
        ++no;
        if(no==ran){
            for(int i=0;a[i]!='\0';i++)
            {
                while(a[i]!=' '){//storing the 1st word(ans word)
                    abc+=a[i];
                    c++;//counting the size of actual word
                    break;
                }
                if(a[i]=='-')//after - words are the meaning for the actual word
                {
                    int ind=i+2;//after - there is a space so i take i+2 which is exactly pointing the 1st char of the word
                    while(a[ind]!='\0')//store the total meaning in the string b;
                    {
                        b+=a[ind++];
                    }
                    break;
                }
            }
            break;
        }
        //break;//after storing our needed strings we have to break out of the loop
    }
    //initializing total chances to 5
    int ch=5;

    char ans[c];//declare char array ans of size c(size of actual word)
    for(int i=0;i<c;i++)ans[i]='_';//initially initializing the ans array char with _ for display

    char ansc;//char used to get our ip
    int hint=1,choice;//declare the choice for getting hint

    while(ch){
            system("cls");//clear the screen after each iteration

            cout<<b<<endl;//showing the meaning of the actual word
            cout<<"Hint:"<<c<<" letter word"<<endl;//showing the total words for users simplicity
            if(hint==1){
            cout<<"Want a hint?"<<endl;
            cout<<"1.Yes\n2.No"<<endl;
            label:
            cin>>choice;
            switch(choice){
                case 1:
                    int vow;//used to find the vowels in the answer string
                    vow=hintfind(abc,c);
                    cout<<"There are "<<vow<<" vowels in the word"<<endl;
                    hint--;
                    break;
                case 2:
                    break;
                default:
                    cout<<"Choose correct choice"<<endl;
                    goto label;
                }
            }

            //after each iteration showing the ans array
            show(ans,c);
            cout<<"\n"<<ch<<" chances left"<<endl;//keep tracking the chances left after each iteration
            cout<<"\nEnter the character:";
            //user entered char
            cin>>ansc;
            if(!check(abc,ansc,c,ans)){//checking if the ansc(user entered) is in the ans string
                    ch--;//if not in string decrement the chances
                if(ch==0)
                {
                    system("cls");
                    //if no chances left showing the word and the meaning and then game over
                    cout<<"The word is "<<abc<<"-"<<b<<endl;
                    cout<<"Game over"<<endl;
                }
            }
            if(checkwin(ans,c)){//after each iteration check if we enter all the correct char and print the found
                system("cls");
                cout<<abc<<"-"<<b<<endl;
                cout<<"You found the word!!"<<endl;
                break;
            }
    }
    f.close();//closing the file
    return 0;
}
