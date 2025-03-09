#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<fstream>
#include<stdlib.h>
#include <time.h>
#define MAX 100
#define patient_file "patient.dat"
void welcomescreen();
void loginscreen();
void title();
void main_menu();
//void admin_menu();
using namespace std;

class admin
{
	
    char fname[20];
	char sname[20];
	char address[200];
    char contact[10];
    char dob[100];
    int age, no_record;
    char gender[8];
    char blood_gp[5];
    char disease_past[50];
    int id;
    char symptom[500];
    char diagnosis[500];
    char medicine[500];
    char addmission[30];
    char past_disease[20];
	time_t reg_time;
	bool diagnose;
public:
	//functions
	void admin_menu(admin *);
	void add_record();
	void admin_login(admin *);
	void read_data(admin *);
	void write_data(admin *);
	void check_dependency();
	void increase_record_no();
	int return_recordno();
	void patientdata();
	void updatedata();
	int getId();
	void search_by_id(admin *);
	void updatedata_by_id(admin *);
	void setId(int);
	void delete_record(admin *);
   };
   void admin::check_dependency(){
	fstream file;
	file.open(patient_file,ios::in);
	if (file.bad()){
		file.clear();
		cout<<"\nPatient record not found."<<endl;
		cout<<"Genrating the file to handle records."<<endl;
		file.open("patient_file.txt",ios::out);
		cout<<"\nFile Created."<<endl;
		file.close();	
	}
	
//	else {
//		cout<<"\nRecords Found."<<endl;
//		file.close();
//	}
}

   
		void admin::admin_login(admin *arr)
		{
			string username;
	 string password;
	int loginattempt=0;
	cin.ignore();
		 system ("CLS");
		 title();
	while(loginattempt < 3)
	{
		cout<<"Enter your username->";
		cin>>username;
		cout<<"Enter password->";
		cin>>password;
		if(username=="khwopa" && password=="khwopa123")
		{
			cin.ignore();
		 system ("CLS");
			cout<<".............Welcome admin.................\n\n";
			cout<<"Thank you for logging in\n";
			cout<<"\nPress any key to continue....";
			getch();
	    admin_menu(arr);
		}
		else
		{
			cout<<"Invalid login attempt. Please try again.\n"<<'\n';
			loginattempt++;
		}
		
	}
	if(loginattempt==5)
	{
		cout<<"Too many attempts!";
		
	}

}


void admin::read_data(admin *arr){
	fstream file;
	no_record=0;
	int i=1;
	file.open(patient_file,ios::in);
	while(file.read((char*)&arr[i],sizeof(arr[i]))){
		no_record++;
		i++;
}	
	file.close();
}

void admin::write_data(admin *arr){
	fstream file;
	file.open(patient_file,ios::out);

	for (int i=1;i<=no_record;i++){
		if(arr[i].getId() != -1){
		file.write((char *)&arr[i],sizeof(arr[i]));
	}
	}
	file.close();
		
}

void admin::increase_record_no(){
	no_record ++;
}

int admin::return_recordno(){
	return (no_record);
}

void admin::setId(int x){
	id = x;
}

void admin::delete_record(admin *arr){
	int tid;
	cin>>tid;
	int max = return_recordno();
	for (int i=1;i<=max;i++){
		if (arr[i].getId() == tid){
			arr[i].setId(-1);
		}
	}
	
}

void admin::admin_menu(admin *arr)
{
	int n,i=1,index;
	char ch;
	system ("CLS");
	title();	
	while(1)
	{
		
	cout<<"1 Add New Patient Record "<<endl;
	cout<<"2 Full History of the Patient"<<endl;
	cout<<"3 delete Patient Record"<<endl;
	cout<<"4 update Patient Record"<<endl;
	cout<<"5 Doctor details"<<endl;
	cout<<"6 exit"<<endl;
		cin>>n;
		index = arr[0].return_recordno()+1;
		
		switch(n)
		{
			case 1:
				arr[index].add_record();
				arr[0].increase_record_no();
		 		system ("CLS");
				//getch();
				break;
			case 2:
				arr[0].search_by_id(arr);
				break;
			case 3:
				arr[0].delete_record(arr);
				break;
			case 4:
				arr[index].updatedata_by_id(arr);
				break;
			
			case 5:
				break;
			
			case 6:
				arr[0].write_data(arr);
				
				exit (0);
				break;
			default:
			cout<<"Invalid option";	
		}
		}
   }
void admin::add_record()
{	
        
         title();
	  	cout<<"enter Patient ID"<<endl;
	  	cin>>id;
	  	cout<<"enter Patient First name"<<endl;
	  	cin.ignore();
	  	cin>>fname;
	  	cout<<"enter Patient Last name"<<endl;
	  	cin.ignore();
		cin>>sname;
	  	cout<<"enter Patient Age"<<endl;
	  	cin>>age;
	  	cout<<"enter Patient Gender(M/F)"<<endl;
	  	cin>>gender;
	  	cout<<"enter Patient Blood Group"<<endl;
	  	cin>>blood_gp;
	  	cout<<"enter Patient Contact "<<endl;
	  	cin>>contact;
	  	cout<<"enter Patient date of birth"<<endl;
	  	cin>>dob;
	  	cout<<"enter Patient Address"<<endl;
	  	cin>>address;
	  	cout<<"enter past disease"<<endl;
	  	cin>>past_disease;
	  	cout<<"enter the symptom"<<endl;
	  	cin>>symptom;
	  	reg_time = time(NULL);
}
	
void admin::updatedata(){
	title();
	cout<<"enter Patient First name"<<endl;
	cin>>fname;
	cout<<"enter Patient Last name"<<endl;
	cin>>sname;
	cout<<"enter Patient Age"<<endl;
	cin>>age;
	cout<<"enter Patient Gender"<<endl;
	cin>>gender;
	cout<<"enter Patient Blood Group"<<endl;
	cin>>blood_gp;
	cout<<"enter Patient Contact "<<endl;
	cin>>contact;
	cout<<"enter Patient date of birth"<<endl;
	cin>>dob;
	cout<<"enter Patient Address"<<endl;
	cin>>address;
	cout<<"enter past disease"<<endl;
	cin>>past_disease;
	cout<<"enter the symptom"<<endl;
	cin>>symptom;
}

void admin::updatedata_by_id(admin *arr)
{ 
	int update_id;
	int max = arr[0].return_recordno();
	cout<<"enter Patient ID to update"<<endl;
	cin>>update_id;
		for (int i=1;i<=max;i++){
			if (arr[i].getId() == update_id)
				arr[i].updatedata();
			
	}
}
			

//void admin::delete_data()
//	{
//		int n;
//		cout<<"Enter patient id to delete";
//		cin>>n;
//	}
	void admin::search_by_id(admin *arr){
		int search_id;
		int max = arr[0].return_recordno();
		system ("CLS");
		cout<<"\nEnter Patient id to search : ";
		cin>>search_id;
		for (int i=1;i<=max;i++){
			if (arr[i].getId() == search_id)
				{
					cout<<"ID found..";
				arr[i].patientdata();
				cout<<"Press enter to continue";
				
			
			}
			else
			{
				
				cout<<"ID not found.";
				
				

			}
			
			
	}
}
	void admin::patientdata()
	{
		system ("CLS");
		title();
		cout<<"\nPatient Info."<<endl;
		cout<<"Name : "<<fname<<" "<<sname<<'\n'<<"Address : "<<address<<endl;
		cout<<"Gender : "<<gender<<'\n'<<"Age : "<<age<<endl;
		cout<<"Blood Group : "<<blood_gp<<endl;
		cout<<"Contact No : "<<contact<<endl;
		cout<<"Previous Disease : "<<past_disease<<endl;
		cout<<"Symptoms : "<<symptom<<endl;
		cout<<"Registerd Date : "<<ctime(&(reg_time))<<endl;
	}
	

int admin::getId(){
	return (id);
}
//void main_menu(void)
//{
//	int n;
//	char ch;
//	do{
//		cin>>n;
//		switch(n)	
//		{
//			case 1:
//				admin_login();
//				break;
//			case 2:
//				//D.doctor_login();
//				break;
//			case 3:
//				//P.patient_login();
//				break;
//			case 4:
//				exit (0);
//			default:
//			cout<<"Invalid option";	
//		}
//		cout<<"Login?????";
//		cin>>ch;
//		}
//		while(ch=='y');

	//}	
	class patient:public admin
	{
	public:	
	};
int main()
{
    admin A[20];
	//doctor D;
	//Patient P;
	//A[0].check_dependency();
	A[0].check_dependency();
	int n,i;
	A[0].read_data(A);
	welcomescreen();
	char ch;
	do{
		cin>>n;
		switch(n)	
		{
			case 1:
				A[0].admin_login(A);
				break;
			case 2:
				//D.doctor_login();
				break;
			case 3:
				//P.patient_login();
				break;
			case 4:
				exit (0);
				break;
			default:
			cout<<"Invalid option";	
		}
		cout<<"Login?????";
		cin>>ch;
		}
		while(ch=='y' || ch == 'Y');

	A[0].write_data(A);
//	main_menu();
		return 0;}
		
		
	void welcomescreen()
		{
			 cout<<"\t\t\t'The best doctor\n\t\t\t\t gives the least medicines'";
			 cout<<"\n\n\n\n\n\t\t\t#############################";
			 cout<<"\n\t\t\tWelcome to Khwopa Clinic";
		    cout<<"\n\n\t\t\t#############################";
			cout<<"\n\n\nOur services\n1. Primary care\n2. Sexual Health\n3. Mental Health\n4. Addiction Services\n5. Low Cost Care";   
		    cout<<"\n\n\n.................Press any key to continue........................";
		 cin.ignore();
		 system ("CLS");
		 loginscreen();

		 
	}
	void title()
{ 
	cout<<"\n\t-----------------------------------------------------";
	cout<<"\n\t                   KHWOPA CLINIC";
	cout<<"\n\t-----------------------------------------------------\n\n";
}
 
void loginscreen()
{
	title();
	cout<<"\n\n\n\t.................Please login to continue...................\n";
		 cout<<"\n\t*Enter 1 for Admin login\n";
		 cout<<"\t*Enter 2 for doctor Login\n";
		 cout<<"\t*Enter 3 for patient Login\n";
		 cout<<"\t*Enter 4 for exit\n";
		
}


