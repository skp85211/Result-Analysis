	//*********** MARKS SHEET ANALYSIS ***********//

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<ctype.h>
class STUDENT
{  private :
    int  rolln;
    int  adno;
    int  std;
    char name [20];
    char fthrname[20];
    char gender;
    int   eng,physics,chemistry,math,com;
    char  gen_behaviour[40],remarks[30];
    float tot,avg,per;
    char  gr;
    char  result[10];

    void Calper();

  public:
    void Instudentrecord();
    void Instudentmarks();


    void Dispstudentrecord();
    void Dispstudentmarks();

    int getrollno()
    { return rolln; }

    int getname(char nme[])
    {int i;
     i=strcmp(nme,name);
     return i;
    }
};  // End of class

int validatecharacter(char string[])  // Function to validate
{
    int x1;                           // the character string
    for(int i=0;string[i]!='\0';++i)
    {
      if(isalpha(string[i])||string[i]==' ')
	 x1=1;

      else
      {  cout<<"\nInvalid input.......";
	 cout<<"\nOnly alphabets are allowed.....\n";
	 cout<<"\nReenter this information.......\n";
	 x1=2;
	 break;
      }
    }
    return x1;
}                                     //  End of function validatecharacter

//***** Function to Input Student Personal Details *****//

void STUDENT::Instudentrecord()
{
    int flag1,flag2;
					 //  Dummy variables used in function(flag1,flag2)
    cout<<"\nEnter Roll no.       :";
    cin>>rolln;
  do                                  //  Loop will executed untill
  {                                   //  string is entered correctly
    cout<<"\nEnter Name           :"; //  using alphabets
    gets(name);
    flag1=validatecharacter (name);
  }while(flag1==2);

    cout<<"\nEnter Admission no.  :";
    cin>>adno;
  do                                   //  Loop will executed untill
  {                                    //  string is entered correctly
    cout<<"\nEnter Father's name  :";  //  using alphabets
    gets(fthrname);
    flag2=validatecharacter (fthrname);
  }while(flag2==2);

  do
  { cout<<"\nGender(m/f)          :";
    cin>>gender;
    if(gender=='m'||gender=='f')
    break;
    else
    { gender='0';
      cout<<"\nInvalid Input.......\nPlease Re-enter this information....\n";
    }
  }while(gender=='0');

  do
  { cout<<"\nStandard/Class       :";
    cin>>std;
    if(std>=1&&std<=12)
    break;
    else
    {std=0;
     cout<<"\nInvalid Input.......\nPlease Re-enter this infomation.....\n";
    }
  }while(std==0);
}                                      // End of function Instudentrecord()

//***** Function To Input Student Marks ****//

void STUDENT::Instudentmarks()
{   int flag3;                         // Dummy variable used in loop
				       // of this function (flag3)
    cout<<"\n\n***********MARKS REPORT***************\n\n";


    cout<<"\nEnglish         :";
    cin>>eng;

    cout<<"\nPhysics         :";
    cin>>physics;

    cout<<"\nChemistry       :";
    cin>>chemistry;

    cout<<"\nMaths           :";
    cin>>math;

    cout<<"\nC++             :";
    cin>>com;

  do
  {
    cout<<"\nGeneral Behavior:";
    gets(gen_behaviour);
    flag3=validatecharacter (gen_behaviour);
  }while(flag3==2);
   Calper ();                          // Function Calper is being called

}                                      // End of function Instudentmarks

//***** Funtion to calulate Percentage and Grade *****//

void STUDENT::Calper()
{   tot=eng+physics+chemistry+math+com;

    avg=tot/5;
    per=avg;
    if(avg>90 && avg<=100)
    {
      gr='A';
      strcpy(remarks,"Excellent");
      strcpy(result,"PASS");
    }
    if(avg>75&&avg<=90)
    {
      gr='B';
      strcpy(remarks,"V.Good");
      strcpy(result,"PASS");
    }
    if(avg>60&&avg<=75)
    {
      gr='C';
      strcpy(remarks,"Can do better");
      strcpy(result,"PASS");
    }
    if(avg>50&&avg<=60)
    {
       gr='D';
       strcpy(remarks,"Satisfactory");
       strcpy(result,"PASS");
    }
    if(avg>=40&&avg<=50)
    {
       gr='E';
       strcpy(remarks,"Just pass");
       strcpy(result,"PASS");
    }
    if(avg<40)
    {
       gr='F';
       strcpy(remarks,"Retry this year");
       strcpy(result,"FAIL");
    }
}                                      // End of function Calper

 //******* Function to display student record *********//

void STUDENT::Dispstudentrecord()
{   cout<<"\n\n*************GENERAL INFORMATION***********";

    cout<<"\nNAME           :\t"<<name;

    cout<<"\tROLL NUMBER    :\t"<<rolln;

    cout<<"\nFATHER'S NAME  :\t"<<fthrname;

    cout<<"\tADMISSION NO.  :\t"<<adno;

    cout<<"\nGENDER         :\t"<<gender;

    cout<<"\tSTANDARD       :\t"<<std;
}                                      // End of function dispstudentrecord

//***** Function to Display Student Aggregate Marks *****//
void STUDENT::Dispstudentmarks()
{
    cout<<"\n\n*********** MARKS REPORT*************";
    cout<<"\n***********AGGREGATE*****************\n";

    cout<<"\n\n           \t\t100";

    cout<<"\nENGLISH     :\t\t"<<eng;

    cout<<"\tMAX. MARKS  :\t\t500";

    cout<<"\nPHYSICS     :\t\t"<<physics;

    cout<<"\tTOTAL MARKS :\t\t"<<tot;

    cout<<"\nCHEMISTRY   :\t\t"<<chemistry;

    cout<<"\tPERCENTAGE  :\t\t"<<per<<"%";

    cout<<"\nMATHS       :\t\t"<<math;

    cout<<"\tGRADE       :\t\t"<<gr;

    cout<<"\nC++         :\t\t"<<com;

    cout<<"\n\n\t\tREMARKS              :"<<remarks;

    cout<<"\n\t\tGENERAL BEHAVIOUR......:"<<gen_behaviour;

    cout<<"\n\t\tRESULT                 :"<<result;
}

//***** Function to display the Menu *****//

int displaymenu()
{
     char ch1;
     int choice;

     do
     {  cout<<"\n.........MARKS SHEET ANALYSIS............     :";

	cout<<"\n\n 1.Add Record........";
	cout<<"\n 2.Edit record.......";
	cout<<"\n 3.Delete record.....";
	cout<<"\n 4.View record.......";
	cout<<"\n 5.Exit..............";


	cout<<"\n\n\n Enter Your Choice ( 1-5) :";
	cin>>ch1;
      choice = ((int)ch1)-48;
      if(choice>=1 && choice<=5)
	      break;
      else
      {   clrscr();
	  cout<<"\nInvalid choice.......\n";
	  cout<<"\nTry again............\n\n";
	      choice=10;
       }
      }while(choice==10);
     return choice;
}                                      // End of function displaymenu()

//***** Function to INSERT *******//

void insert (STUDENT st)
{
    STUDENT stud;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    ofstream fout;
    fout.open("temp.dat",ios::app|ios::binary);
    char last='y';
    while(!fin.eof())
    {
    fin.read((char*)&stud,sizeof(STUDENT));
    if(st.getrollno()<=stud.getrollno())
    {
      fout.write((char*)&st,sizeof(st));
      last='n';
      break;
      }
      else
      fout.write((char*)&stud,sizeof(stud));
      }
      if(last=='y')
      fout.write((char*)&st,sizeof(st));
      else if(!fin.eof())
      {
	while(!fin.eof())
	{
	fin.read((char*)&stud,sizeof(stud));
	fout.write((char*)&stud,sizeof(stud));
	}
      }
      fin.close();
      fout.close();
     remove("student.dat");
    rename("temp.dat","student.dat");
}

//*** Function to Modify the record using Roll number ***//

void Modify_roll(int rno)
{
    STUDENT stud;
    fstream fin3;
    int flag4=0,rec=0,ch;
    fin3.open("student.dat",ios::in|ios::out|ios::binary);
    if(!fin3)
    cout<<"\nFile does not exists......";
    else
    cout<<"\nFile is ready to Modifying the record.....";
    while(fin3.read((char*)&stud,sizeof (STUDENT)))
    {
       rec++;
      if(rno==stud.getrollno())
      {
      do
       {
	cout<<"\n\nWhich Record do you want modify--------:";
	cout<<"\n\n1.General Information of Student...";
	cout<<"\n2.Marks Report of Student....";

	cout<<"\n\nEnter your choice:";
	cin>>ch;
	if(ch==1)
	{
	 clrscr();
	 cout<<"\n\nStudent General Information is as follow----:";
	 stud.Dispstudentrecord();

	 cout<<"\nEnter New General Information---:";
	 stud.Instudentrecord();
	}
	else if(ch==2)
	{
	 clrscr();
	 cout<<"\n\nStudent marks report is as follow  --:";
	 stud.Dispstudentmarks();

	 cout<<"\nEnter new Marks report  --:";
	 stud.Instudentmarks();
	}
	else
	{ ch=0;
	  cout<<"\n\nInvalid Input....\nRe-Enter this information........";
	}
       }while(ch==0);

	fin3.seekg((rec-1)*sizeof (STUDENT),ios::beg);     // Placing the file ponter at previously
							  // read record,which is being modified
	fin3.write((char*)&stud,sizeof (STUDENT));

	flag4=1;

	break;
      }
    }
    if(flag4==0)
      cout<<"\n\nRoll No. does not exists........\n";
    else
      cout<<"\nRecord Modified.................\n";
    fin3.close();
}

//**** Function to Modify record using Name ****//

void Modify_name(int val)
{
    STUDENT stud;
    fstream fin5;
    int flag4=0,rec=0,ch;
    fin5.open("student.dat",ios::in|ios::out|ios::binary);
    if(!fin5)
    cout<<"\nFile does not exists......";
    else
    cout<<"\nFile is ready to Modifying the record.....";
    while(fin5.read((char*)&stud,sizeof (STUDENT)))
    {
       rec++;

      if(val==0)
      {
       do
       {
	cout<<"\n\nWhich Record do you want modify--------:";
	cout<<"\n\n1.General Information of Student...";
	cout<<"\n2.Marks Report of Student....";

	cout<<"\n\nEnter your choice:";
	cin>>ch;
	if(ch==1)
	{
	 clrscr();
	 cout<<"\n\nStudent General Information is as follow----:";
	 stud.Dispstudentrecord();

	 cout<<"\nEnter New General Information---:";
	 stud.Instudentrecord();
	}
	else if(ch==2)
	{
	 clrscr();
	 cout<<"\n\nStudent marks report is as follow  --:";
	 stud.Dispstudentmarks();

	 cout<<"\nEnter new Marks report  --:";
	 stud.Instudentmarks();
	}
	else
	{ ch=0;
	  cout<<"\n\nInvalid Input....\nRe-Enter this information........";
	}
       }while(ch==0);


	fin5.seekg((rec-1)*sizeof (STUDENT),ios::beg);     // Placing the file ponter at previously
							  // read record,which is being modified
	fin5.write((char*)&stud,sizeof (STUDENT));

	flag4=1;
	break;
      }
    }

    if(flag4==0)
      cout<<"\n\nName does not exists........\n";
    else
      cout<<"\nRecord Modified.................\n";
    fin5.close();

}

//*** Function to Delete Record ***//

void Delete(int rno)
{
    STUDENT stud;
    int flag=0;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);

    if(!fin)
      cout<<"\n\nFile does not exits........";
    else
      cout<<"\n\nFile is ready to Delete the record...........\n";

   ofstream fout;
   fout.open("temp.dat",ios::out|ios::binary);
    while(fin.read((char*)&stud,sizeof (STUDENT)))
    {
      if(rno!= stud.getrollno())
	 fout.write((char*)&stud,sizeof (STUDENT));

      else
	 flag = 1;
    }

    if ( flag == 0)
	cout<<"\nRoll No. does not exists........";
    else
	cout<<"\nRecord Deleted................";

    fin.close();
    fout.close();

   remove("student.dat");
   rename("temp.dat","student.dat");

}// end of delete function

//**** Function to Display Student Record ****//

void Display_Studentfile(int rn)
{
    STUDENT stud;
    ifstream fin2;
    fin2.open("student.dat",ios::in|ios::binary);

    if(!fin2)
    cout<<"\n\nFile does not exits........";
    else
    cout<<"\n\nFile is ready to display the record...........\n";

    while(fin2.read((char*)&stud,sizeof (STUDENT)))
    {
      if(rn==stud.getrollno())
      {
       cout<<"\n\nStudent Details are as follow   ---:";
       stud.Dispstudentrecord();

       cout<<"\n\nStudent Marks report are as follow  ---:";
       stud.Dispstudentmarks();
      }
    }
    fin2.close();
}

//**** Function to Choose the Option from Menu ****//

void chooseopt(void)
{                                         // Function Prototype
     int displaymenu(void);
     int ch, ch1;
     char ch2;

    for( ; ; )
    {
     ch=displaymenu();
     switch(ch)                           // Start of switch case
     {
      case 1 :  clrscr();
		STUDENT s;
		cout<<"\n \t\t Adding New Record.......\n\n";

	       do
	       {
		 clrscr();
		 cout<<"\n\nEnter the details of Student to be added :";
		 s.Instudentrecord();

		 cout<<"\n\nEnter the marks report of Student to be added :";
		 s.Instudentmarks();

		 insert (s);

		 cout<<"\n\nDo you want to add more records(y/n)?";
		 cin>>ch2;
	       }while(ch2=='y');

		cout<<"\nPress any key to continue.......";
		getchar();

	      clrscr();
	      continue ;

      case 2:   clrscr();
		cout<<"\n Editing Record............\n\n";
		int rn;
		char name1[20];

	      do
	      {
		cout<<"\n\n1.Modifying record using Name......";
		cout<<"\n2.Modifying record using Roll No.......";

		cout<<"\n\nEnter your choice  : ";
		cin>>ch1;

		if(ch1==1)
		{
		 cout<<"\n\nEnter the Name whose record has to be modified  :";
		 gets(name1);
		 int value=s.getname(name1);
		 Modify_name(value);
		}

		else if(ch1==2)
		{
		 cout<<"\n\nEnter the Roll no. whose record has to be modified  :";
		 cin>>rn;
		 Modify_roll(rn);
		}

		else
		{
		  cout<<"\nInvalid input......\nRe-enter this information.......";
		  ch1=3;
		}
	      }while(ch1==3);

		cout<<"\nPress any key to continue.......";
		getchar();
		clrscr();
	      break;

      case 3:   clrscr();
		cout<<"\n Deleting Record...........\n\n";
		int drn;

		cout<<"\n\nEnter the Roll no. to be deleted  :";
		cin>>drn;

		Delete(drn);

		cout<<"\nPress any key to continue.......";
		getchar();

		clrscr();
	       break;

      case 4:   clrscr();
		cout<<"\n \tViewing Record.........\n\n";
		int rn1;

		cout<<"\nEnter the Roll no. whose record you want see...";
		cin>>rn1;

		Display_Studentfile(rn1);

		cout<<"\n\nPress any key to continue........";
		getchar();

		clrscr();
	       continue ;

      case 5: char wish;
	       do
	       {
		  cout<<"\n Are you sure you want to exit (y/n):";
		  cin>>wish;

		  if(wish=='y')
		  {
		    cout<<"\nThanks for using this software...";
		    cout<<"\nTerminating.......................";
		    cout<<" \n\n Press any key to continue..";
		    getchar();

		    exit(0);
		  }
		  else if(wish=='n')
		  {
		    cout<<"\nPress any key to continue........";
		    clrscr();
		    chooseopt();     // Recursive Function
		  }
		  else
		   cout<<" \n\n Ivalid Input.......";
	       }while(wish !='y' || wish !='n');


	       break;
       default : cout<<"\n\n Something Went Wrong....";
		 break;
	}                                 // End of switch
    }
}                                         // End of function chooseopt()

//**** Main Function ****//

void main()
{    clrscr();
     void chooseopt(void);

      STUDENT stud;
      ofstream fout;

      fout.open("student.dat",ios::out|ios::binary);
      if(!fout)
      cout<<"\nFile does not created...";
      else
      cout<<"\nFile is created for using......\n";
      fout.close();

     chooseopt();                         // Calling the function chooseopt
}
