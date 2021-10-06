#include<iostream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;
class GV {
	private:
		char ht[30];
		int t;
		char bc[15];
		char cn[20];
		float bl;
	
	public:
		GV(){}
		GV(char *ht,int t,char *bc,char *cn,float bl)
		{
		strcpy (this -> ht ,ht);
		this -> t = t;
		strcpy (this -> bc,bc);
		strcpy (this -> cn,cn);
		this -> bl = bl;
}
		~GV (){}
		friend istream& operator >>(istream &is , GV &a)
		{	cin.ignore();
			cout<<"Nhap ho ten :";
			is.getline(a.ht,30);
			cout<<"Nhap tuoi :";
			is>>a.t;
			cin.ignore();
			do{
	      	cout<<"\n Nhap bang cap : ";
      		is.getline( a.bc,15);
      		
      		if(strcmpi(a.bc,"1") != 0 && strcmpi(a.bc,"2") != 0 && strcmpi(a.bc,"3") != 0 )
      			
				  cout<<"\n Nhap lai ";
      			
}while(strcmpi(a.bc,"1") != 0 && strcmpi(a.bc,"2") != 0 && strcmpi(a.bc,"3") != 0 );
			cout<<"Nhap chuyen nganh :";
			is.getline(a.cn,20);
			cout<<"Nhap bac luong :";
			is>>a.bl;
			return is;
}		
		friend ostream& operator <<(ostream &os , GV &a){

			os<<setw(20)<<a.ht;
			os<<setw(10)<<a.t;
			if(strcmpi(a.bc,"1")==0 )
   	    		{
					os<<setw(20)<<"KHA";   
}
			 	else if(strcmpi(a.bc,"2")==0 )
   	    		{
					os<<setw(20)<<"GIOI";   
}
			   else
    			{
					os<<setw(20)<<"XUAT SAC";   
}
			os<<setw(20)<<a.cn;
			os<<setw(20)<<a.bl<<endl;
			return os;
					
}
		float lcb (){
			return bl*610;
				
}
		friend bool operator == (GV &a, GV &b){
		{
			return (strcmpi( a.bc,b.bc)==0);
}
}
		bool sosanh (GV gv)
	       {
	       	return (strcmpi(this->bc,gv.bc) > 0);
}
};
		void sapxep(GV gv[],int n)
		{
			for(int i = 0 ; i<n-1 ; i++)
			for(int j = i+1 ;j<n; j++)
			if( gv[i].sosanh (gv[j]) )
			{
				GV tg = gv[i];
					gv[i] = gv[j];
					gv[j] = tg;
}
}
		void td(){
			cout<<setw(20)<<"Ho ten "
				<<setw(10)<<"Tuoi "
				<<setw(10)<<"Bang cap "
				<<setw(20)<<"Chuyen nganh "
				<<setw(20)<<"Bac luong "<<endl;
}
main (){
		int n;
		do 
		{
			cout<<"Nhap n :";
			cin>>n;
			if (n<=0)
			cout<<"Nhap Lai";
}
		while (n<=0);		
		GV *gv = new GV[n];
		for (int i; i<n ; i++)
			{
			cout<<"\nNhap thong tin giao vien thu : "<<i+1;
			cin>>gv[i];	
}
			cout<<"\n----- Danh sach giao vien vua nhap ------\n";
		td();
		for( int i=0; i<n ; i++ )
		{
			cout<<gv[i];
}		
		cout<<"\n---Danh sach giao vien sap xep tang dan thep bang cap ---\n";
		td();
		sapxep(gv,n);			
}