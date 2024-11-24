#include<bits/stdc++.h>
using namespace std;
static int n;
class Address{
private:
    string street;
    string city;
    string state;
    string zip;
public:
    Address(string str="",string cit="",string sta="",string zi=""){
        setStreet(str);
        setCity(cit);
        setState(sta);
        setZip(zi);
    }
    void setStreet(string str){
       street=str;
    }
    void setCity(string cit){
       city=cit;
    }
    void setState(string sta){
       state=sta;
    }
    void setZip(string zi){
       zip=zi;
    }
    string getStreet(){
      return street;
    }
    string getCity(){
       return city;
    }
    string getState(){
       return state;
    }
    string getZip(){
       return zip;
    }
    string formatAddress(){
       return getStreet()+' '+getCity()+' '+getState()+' '+getZip();
    }
};
class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int d=1,int m=1,int y=2004){
       setDay(d);
       setMonth(m);
       setYear(y);
    }
    void setDay(int d){
      day=d;
    }
    void setMonth(int m){
      month=m;
    }
    void setYear(int y){
      year=y;
    }
    int getDay(){
      return day;
    }
    int getMonth(){
      return month;
    }
    int getYear(){
      return year;
    }
    string formatDate(){
       return to_string(getDay())+' '+to_string(getMonth())+' '+to_string(getYear());
    }
};
class Person{
protected:
    string firstName;
    string lasrName;
    string id;
public:
    Person(string f=" ",string l=" ",string i=" "){
       setFirstName(f);
       setLastName(l);
       setId(i);
    }
    void setFirstName(string f){
       firstName=f;
    }
    void setLastName(string l){
       lasrName=l;
    }
    void setId(string i){
       id=i;
    }
    string getFirstName(){
       return firstName;
    }
    string getLastName(){
       return lasrName;
    }
    string getId(){
       return id;
    }
};
class Extperson:public Person{
private:
    string phoneNumber;
    int type;
    Date dob;
    Address address;
public:
    Extperson(){
       type=0;
    }
    Extperson(string f,string l,string i,int tp,string phNum,Date dob1,Address address1):Person(f,l,i){
        setType(tp);
        setPhoneNumber(phNum);
        setDate(dob1);
        setAddress(address1);
    }
    void setType(int tp){
      type=tp;
    }
    int getType(){
      return type;
    }
    void setPhoneNumber(string phNum){
      phoneNumber=phNum;
    }
    string getPhoneNumber(){
      return phoneNumber;
    }
    void setDate(Date dob1){
      dob=dob1;
    }
    Date getDate(){
      return dob;
    }
    void setAddress(Address address1){
      address=address1;
    }
    Address getAddress(){
      return address;
    }
    void printExtperson(){
        getFirstName();
        getLastName();
    }
    string formatAllData(){
      return getFirstName()+' '+getLastName()+' '+getId()+' '+to_string(getType())+' '+getPhoneNumber()+' '+getDate().formatDate()+' '+getAddress().formatAddress();
    }
    string formatName(){
      return getFirstName()+' '+getLastName();
    }

};
class AddressBook {
private:
    Extperson ext[500];
    int index;
public:
    AddressBook(){
        index=-1;
    }
    void setExtperson(Extperson ext1){
        index++;
        ext[index]=ext1;
    }
    Extperson getExtperson(int indx){
        return ext[indx];
    }
    void Sort(){
      Extperson temp;
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ext[i].getLastName()<ext[j].getLastName()){
                temp=ext[i];
                ext[i]=ext[j];
                ext[j]=temp;
            }
            else if(ext[i].getLastName()==ext[j].getLastName()){
                if(ext[i].getFirstName()<ext[j].getFirstName()){
                     temp=ext[i];
                     ext[i]=ext[j];
                     ext[j]=temp;
                }
            }
         }
      }
   }
   string Search(string choice){
       string ans;
       int cnt=0;
       for(int i=0;i<n;i++){
            if(ext[i].getLastName()==choice){
            ans+=getExtperson(i).formatAllData()+"\n";
            }
       }
    return ans;
   }
   string sameMonth(int m){
        string ans;
        for(int i=0;i<n;i++){
            if(ext[i].getDate().getMonth()==m){
            ans+=getExtperson(i).formatName()+"\n";
            }
        }
        return ans;
   }
   string btwLastNames(string last1,string last2){
        string ans;
        int cnt=0;
        for(int i=0;i<n;i++){
        if(ext[i].getLastName()<=last1 && ext[i].getLastName()>=last2 ){
         ans+=getExtperson(i).formatName()+"\n";
         cnt++;
        }
      }
      return ans;
   }
   string searchType(int t){
       string ans;
       for(int i=0;i<n;i++){
        if(ext[i].getType()==t){
          ans+=getExtperson(i).formatName()+"\n";
        }
      }
      return ans;
   }
   string GivingPerson (string f,string l,string id){
            string ans;
            for(int i=0;i<n;i++){
                if(ext[i].getFirstName() == f && ext[i].getLastName() == l && ext[i].getId() == id){
                    ans+=ext[i].formatAllData();
                }
            }
            return ans;
   }
};
int main(){
    AddressBook addbook;
    cout<<"Enter the number of people you want to add them to the address book(1..500)"<<endl;
    cin>>n;
    if(n>500){
        assert(false);
    }
    cout<<"Enter [first name,last name,Id,Type(0,family-1,friend-2,business associate)"<<endl;
    cout<<"Phone Number,Date of Birth(day,month,year),Address(street,city,state,zip code)]"<<endl;
    cout<<"for " <<n<<" person "<<endl;
    for(int j=0;j<n;j++){
        string f,l,i,phNum,str,cit,sta,zi;
        int d,m,y,tp;
        cin>>f>>l>>i>>tp>>phNum>>d>>m>>y>>str>>cit>>sta>>zi;
        Extperson ex(f,l,i,tp,phNum,Date(d,m,y),Address(str,cit,sta,zi));
        addbook.setExtperson(ex);
    }
    cout<<"******sort******"<<endl;
    addbook.Sort();
    for(int i=0;i<n;i++){
        cout<<addbook.getExtperson(i).formatAllData()<<endl;
    }
    cout<<"******search by last name*******"<<endl;
    string s;
    cin>>s;
    string z =addbook.Search(s);
    if (z.size()==0){
        cout<<"the last name is not found"<<endl;
    }
    else cout<<z;
    cout<<"******Same Month*******"<<endl;
    int m;
    cin>>m;
    string z1=addbook.sameMonth(m);
    if(z1.size()==0){
        cout<<"these is no person in address book has born in this month"<<endl;
    }
    else cout<<z1;
    cout<<"******Names between two last names*******"<<endl;
    string last1,last2;
    cin>>last1>>last2;
    string z2;
    z2=addbook.btwLastNames(last1,last2);
    if(z2.size()==0){
        cout<<"the last name is not found"<<endl;
    }
    else cout<<z2;
    cout<<"******Type*******"<<endl;
    cout<<"The Choices Of Type is : "<<endl;
    cout<<"print 0 if family ,print 1 if friend,2 if business associate"<<endl;
    int t;
    cin>>t;
    string z4 =addbook.searchType(t);
    if(z4.size()==0){
        cout<<"There is no person in the address book has this Type"<<endl;
    }
    else cout<<z4;
    cout<<"*******address,phone#,date of birth*******"<<endl;
    cout<<"enter the first name , last name ,id : "<<endl;
    string z6,z7;
    string id;
    cin>>z6>>z7>>id;
    string z5=addbook.GivingPerson(z6,z7,id);
    if(z5.size()==0){
        cout<<"there is no person in this name"<<endl;
    }
    else cout<<z5;
}
