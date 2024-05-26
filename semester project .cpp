#include<iostream>
#include<fstream>									// provides functionalities for reading from and writing to files.
#include<iomanip>									// header file that contains setw() function
#include<cctype>									// header file that contains tolower() function

										//maximize the console screen for better results
using namespace std;						


//start of structures


struct person{							
	string firstname;
	string lastname;
	int roll_no;
	int semester;
	char dep[20];
	int pf,ict,isl,dis,cal;
};



//end of structures

//start of function used

void addstdnt(person p1, person d1);
void enterMarks(int &marks);
void display(void );
void gpa(float percentage);
void displaystd(person d1);
void deletestudent( void );
void update(person p1, person d1);
void show(person d1);

//end of used functions


int main(){
	
	start:
	person d1;						//a user-defined datatype also knwon as structure
	person p1;						//another user-defined datatype
	char menu;
	display();						//function for displaying menu
	char m;							
	cin>>menu;
	
	switch( tolower(menu)){
		case 'n':
			
			system("cls");			//this function is used to clear the console screen 
			addstdnt(p1,d1);		//function call to add a student and in parameters is a structure call
			
			cout<<"enter 'm' to continue to menu or any other key to exit:";		
			cin>>m;
			
			if(m=='m'){
				system("cls");
			goto start;				//a jump statement 
			}
			else{
				return 0;
			}
			
		break;
		
		case 'i':
			
			system("cls");
			displaystd(d1);
			
			cout<<"enter 'm' to continue to menu or any other key to exit:";
			cin>>m;
			
			system("cls");
		
			if(m=='m'){
				goto start;
				}
			else{
				return 0;
				}
		break;
		
			case 'd':
			system("cls");
			deletestudent();														//function call to a function for deleting a student record
		
			cout<<"enter 'm' to continue to menu or any other key to exit:";
			cin>>m;
			
			system("cls");
			if(m=='m'){
				goto start;
				}
			else{
				return 0;
			}
			break;
			
		case 'u':
			system("cls");
			update(p1,d1);
			
			cout<<"enter 'm' to continue to menu or any other key to exit:";
			cin>>m;
			
			system("cls");
		
			if(m=='m'){
			goto start;
			}
			else{
				return 0;
			}
		break;
		
		case 's':
			system("cls");
			show(d1);
			
			cout<<"enter 'm' to continue to menu or any other key to exit:";
			cin>>m;
			
			system("cls");
		
			if(m=='m'){
			goto start;
			}
			else{
				return 0;
			}
		break;
		
		case 'e':
		system("cls");
		cout<<endl<<endl<<endl;
		cout<<"			*************************************************************"<<endl;		
		cout<<"			*******                                               *******"<<endl;
		cout<<"			******* THANK YOU FOR USING STUDENT MANAGEMENT SYSTEM *******"<<endl;		
		cout<<"			*******                                               *******"<<endl;
		cout<<"			*************************************************************"<<endl;		
		cout<<endl<<endl<<endl;
		break;
		
		default:
		system("cls");
			cout<<"****invalid choice****"<<endl<<"please enter from the given options"<<endl;	
			goto start;			
}
}




//function for displaying menu
void display(void){

    cout<<"  ---------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"	 					HITEC UNIVERSITY TAXILA"<<endl;
	cout<<"	 				Student Marks Sheet Management System "<<endl;
	cout<<"  ---------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
	cout<<"------ENTER ANY CHOICE------"<<endl<<endl;
	cout<<" n____Enter New Student"<<endl;
	cout<<" i____Display Individual Student Marksheet"<<endl;
	cout<<" d____Delete Student "<<endl;
	cout<<" u____Update "<<endl;
	cout<<" s____Show all student marksheets"<<endl;
	cout<<" e____Exit"<<endl;

}







//function for adding students
void addstdnt(person p1, person d1){
	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"							ENTER DATA FOR THE STUDENT	"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
		cout<<"Enter Roll No:"<<endl;		cin>>p1.roll_no;
		
	   string filename = "student_" + to_string(p1.roll_no) + ".txt";   	/*  "to_string()" is function that converts integers, 
	   																			floating-point numbers, and other numeric types, 
																				into their string representations  */
	   
	   
    fstream file(filename,ios::in | ios::out | ios::app);					//file has been opened for read write and append

              while (file >> d1.firstname >>d1.lastname>> d1.roll_no ) {		//this loop will take roll number from files and check it it exists or not
				
                if (d1.roll_no == p1.roll_no) {
                	
                    cout << "this roll number already exists"<<endl<<endl;
                    
                    file.close();
                }
        }
	if (file.is_open()){
		
			cin.ignore();
			
			cout<<"Enter First Name:"<<endl;			getline(cin,p1.firstname);
			
			cout<<"Enter Last Name:"<<endl;			getline(cin,p1.lastname);			
			
			cout<<"Enter Semester:"<<endl;			cin>>p1.semester;

			cout<<"Enter Department:"<<endl;			cin>>p1.dep;
	
			cout<<"------Enter Student Marks------"<<endl<<endl;
			
			cout<<"Enter Marks of Programming Fundamentals(100):";
			enterMarks(p1.pf);
	
			cout<<"Enter Marks of IICT (100):";
		   	enterMarks(p1.ict);
		   	
    		cout<<"Enter Marks of Discrete(100):";
    		enterMarks(p1.dis);
    		
			cout<<"Enter Marks of Calculus(100):";
   			enterMarks(p1.cal);
   			
    		cout<<"Enter Marks of Islamic studies(100):";
    		enterMarks(p1.isl);

			ofstream file(filename,ios::app);
			
				if(file<<p1.firstname<<" "<<p1.lastname<<" "<<p1.roll_no<<" "<<p1.semester<<" "<<p1.dep<<" "<<p1.pf<<" "<<p1.ict<<" "<<p1.isl<<" "<<p1.dis<<" "<<p1.cal)
				
				cout<<endl<<"			----------RECORD ADDED SUCCESSFULLY----------"<<endl;
		}
		else{
			cout<<"file error"<<endl;
		}
}





//function for taking marks and checking them 
void enterMarks(int &marks) {					//reference to each suject marks
    do {										//do will be executed till the user enter marks in accordance with set conditions 
        cout << "(0-100): ";
        cin >> marks;

        if (marks < 0 || marks > 100) {
            cout << "Invalid marks Marks should be between 0 and 100 Please try again" << endl;
        }
    } while (marks < 0 || marks > 100);			//loop will break when user enters correct marks
}




//function for displaying marks sheet of individual student
void displaystd(person d1){
	
	int roll_no;
	string line;
	
	cout<<"enter the roll number of which u want data:";				
	
	cin>>roll_no;
	
	
	 string filename = "student_" + to_string(roll_no) + ".txt";
	 
	 	fstream file(filename);					//fstream allows to read and write from a file

	  if (file.is_open()) {
                cout << "File opened" << endl;
                
				file >> d1.firstname >>d1.lastname >> d1.roll_no >> d1.semester >> d1.dep >> d1.pf >> d1.ict >> d1.isl >> d1.dis >> d1.cal;
				cout<<"  ---------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"						HITEC UNIVERSITY TAXILA	"<<endl;
				cout<<"						Student's Mark Sheet "<<endl;
				cout<<"  ---------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
						
				cout<<"Name: "<<d1.firstname<<" "<<d1.lastname<<endl;
				cout<<"Roll Number: "<<d1.roll_no<<endl;
				cout<<"Student of: "<<d1.dep<<endl;
				cout<<"Semester Number: "<<d1.semester<<endl;
				cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"Subject Name"<<"					"<<"Marks"<<endl;
				cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"Programming Fundamentals"<<"			"<<d1.pf<<"/100"<<endl;
				cout<<"IICT"<<"						"<<d1.ict<<"/100"<<endl;
				cout<<"Islamic studies"<<"					"<<d1.isl<<"/100"<<endl;
				cout<<"Discrete Structures"<<"				"<<d1.dis<<"/100"<<endl;
				cout<<"Calculus"<<"					"<<d1.cal<<"/100"<<endl;
				cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"Total Marks: 500"<<endl;
				float sum=d1.cal+d1.dis+d1.ict+d1.isl+d1.pf;
				cout<<"Obtained marks: "<<sum<<endl;
				float percentage=(sum/500)*100;
				cout<<"Percentage: "<<percentage<<"%"<<endl;	
				cout<<"GPA on the basis of total marks: ";
				gpa(percentage);								//call to a function for making GPA criteria
				cout<<endl<<endl<<"------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
            }
           else {
           	
                 cout << "File not opening or record does not exist"<<endl;
                 
        }
    }
    
    
    

//function for assigning GPA
void gpa(float percentage){
	if (percentage>= 90 && percentage<=100) {
        cout<<"A+";
    } 
	else if (percentage >= 80) {
        cout<<"A";
    } 
	else if (percentage >= 75) {
        cout<<"A-";
    } 
	else if (percentage >= 70) {
        cout<<"B+";
    } 
	else if (percentage >= 60) {
        cout<<"B";
    } 
	else if (percentage >= 50) {
        cout<<"B-";
    } 
	else if (percentage >= 40) {
        cout<<"C";
    } 
	else {
        cout<<"F";
    }
}
    
      
      
//function for deleting a students record
void deletestudent( void){
		int roll_no;
		
		cout<<"Enter Student Roll number to delete his record:"<<endl;
		cin>>roll_no;
		
	    string filename = "student_" + to_string(roll_no)+ ".txt";
		
		if(remove(filename.c_str())==0){										/*	since remove a function from C library so it uses string literals,
																				meaning those string that dont have  a null character but C++ strings
																	 			automatically insert a null charcater at the end of string so "c_str()" 
																 				has been used to convert c++ string into a C-style string	*/ 
			cout<<"	----------Student Deleted----------"<<endl;
				}
		else{
			cout<<"deletion unsuccessfull or record does not exist"<<endl;
		}
}
    
    
    
    
//function for updating record of a student
void update(person p1,person d1){

		int roll_no;
		cout<<"enter the roll no of which u want to update record:"<<endl;		cin>>roll_no;
		string oldfilename = "student_" + to_string(roll_no)+ ".txt";
		fstream oldfile(oldfilename);	
		oldfile>> d1.firstname >>d1.lastname>> d1.roll_no >> d1.semester >> d1.dep ;
		cout<<"  ---------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"						Update Data for "<<d1.dep<<"-"<<roll_no<<endl;
		cout<<"  ---------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
						
    	cout<<"enter the roll no:"<<endl;		cin>>p1.roll_no;
    	
    	string newfilename = "student_" + to_string(p1.roll_no) + ".txt";
    	fstream newfile(newfilename,ios::in | ios::out | ios::app);
    	newfile.open(newfilename);
    		   	
    if(newfile.is_open()){	  
    	  
		cin.ignore();							//it is used to clear the input stream for unwanted characters
			
		cout<<"Enter First Name:"<<endl;			getline(cin,p1.firstname);
			
		cout<<"Enter Last Name:"<<endl;			getline(cin,p1.lastname);
	
		cout<<"Enter Semester:"<<endl;			cin>>p1.semester;

		cout<<"Enter Department:"<<endl;			cin>>p1.dep;
	
		
		cout<<"Enter Student Marks"<<endl<<endl;

		cout<<"Enter Marks of Programming Fundamentals(100):";
		enterMarks(p1.pf);
	
		cout<<"Enter Marks of IICT(100):";
		enterMarks(p1.ict);
		   	
    	cout<<"Enter Marks of Discrete(100):";
    	enterMarks(p1.dis);
    		
		cout<<"Enter Marks of Calculus(100):";
   		enterMarks(p1.cal);
   			
    	cout<<"Enter Marks of Islamic studies(100):";
    	enterMarks(p1.isl);
	
		fstream newfile(newfilename);
			
			if(newfile<<p1.firstname<<" "<<p1.lastname<<" "<<p1.roll_no<<" "<<p1.semester<<" "<<p1.dep<<" "<<p1.pf<<" "<<p1.ict<<" "<<p1.isl<<" "<<p1.dis<<" "<<p1.cal){		
				newfile.close();
				oldfile.close();
								   cout<<"			----------Record Updated Successfully----------"<<endl;

				string filename = "student_" + to_string(roll_no)+ ".txt";
	   			if(remove(filename.c_str())==0){
	   				cout<<"."<<endl;
				   }
				}
			else{
				cout<<"error in data insertion"<<endl;
			}		
	}
	else{
		cout<<"error opening file"<<endl;
	}
}



//function for showing result of all the student enrolled
void show(person d1) {
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "               					         HITEC UNIVERSITY All Student Result" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    // Print table headers
    cout << left << setw(25) << "Name" << setw(15) << "Roll No" << setw(12) << "Semester"
         << setw(17) << "Department" << setw(12) << "P.F" << setw(12) << "IICT"
         << setw(12) << "ISL" << setw(15) << "Discrete" << setw(15) << "Calculus"
         << setw(13) << "%age" << setw(16) << "GPA" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl<<endl;

    for (int i = 1;i<=5000 ; i++) {									//here for loop will check for all the files with different roll number 
        string filename = "student_" + to_string(i) + ".txt";
        fstream file(filename);
        file.open(filename);

        if (file.is_open()) {
        	
            fstream file(filename);

            while (file >> d1.firstname >> d1.lastname >> d1.roll_no >> d1.semester >> d1.dep >> d1.pf >> d1.ict >> d1.isl >> d1.dis >> d1.cal) {
            	
                float sum = d1.cal + d1.dis + d1.ict + d1.isl + d1.pf;
                
                float percentage = (sum / 500) * 100;

                // Print data in table form
                cout << left << setw(25) << d1.firstname + " " + d1.lastname<< setw(15) << d1.roll_no << setw(13) << d1.semester
                     << setw(16) << d1.dep << setw(13) << d1.pf << setw(11) << d1.ict
                     << setw(13) << d1.isl << setw(15) << d1.dis << setw(15) << d1.cal
                     << setw(12) << percentage << setw(18);
                gpa(percentage);
                cout << endl;
                file.close();
            }
        }
    }
    cout<<endl;
	  cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl<<endl;
	  
}

 