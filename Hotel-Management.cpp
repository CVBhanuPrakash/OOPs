#include<iostream>
#include<time.h>
#include<string.h>

using namespace std;

class room_bookings
{
   int room_no;
   string name;
   string address;
   string phone;
   int days;
   long bill;
   
   string room_type;
   

 public:
   void set_roomno(int r){
    room_no = r;
   }
   int getbill(){
    return bill;
   }
   void setbill(long food_bill){
    bill = food_bill;
   }
   void main_menu();    
   void add();    
   void display();     
   void rooms();  
   void edit();   
   int check(int);    
   void modify();    
   void checkout_room();           
   void modify_name();          
   void modify_address();       
   void modify_phone();         
   void modify_days();          
   
}h[100];

class food_bookings: public room_bookings{
 int room_no;
 int bill;
 public:
 void restaurant();
 void breakfast(int);
 void lunch(int);
 void dinner(int);
}r;

void room_bookings::main_menu()
{ 
 int choice;
 while(choice!=7)
 {
  cout<<"\t* MAIN MENU *"<<endl;
  cout<<"1.Book A Room"<<endl;
  cout<<"2.Search Customer by Room Number"<<endl;
  cout<<"3.Rooms Allotted"<<endl;
  cout<<"4.Modify Customer Details"<<endl;
  cout<<"5.Order Food from Restaurant"<<endl;
  cout<<"6.Checkout"<<endl;
  cout<<"7.Exit"<<endl;
  cout<<"Enter Your Choice: ";
  cin>>choice;
  switch(choice)
  {
   case 1: add();
    break;
   case 2: display();
    break;
   case 3: rooms();
    break;
   case 4:modify();
    break;
   case 5: r.restaurant();
    break;
   case 6 : checkout_room();
    break;
   case 7: return;
   default:
    {
     cout<<"Wrong choice."<<endl;
    }
  }
 }
}

void room_bookings::add()
{ 
 srand(time(NULL));
 string firstname[10] = {"Rose", "Jack", "Romeo", "Juliet", "Laila", "Majnu", "Paru", "Devadas","Shajahan","Mumtaj"};
 string lastname[10] = {"Fernandez","Ali","Jane","Rock","Manoj","Sagar","Maddy","Vaibhav","Hashwanth","Begum"};
 string firstphone[10] = {"79897","72596","99892","95507","63024","99673","98480","94945","95151","82036"};
 string lastphone[10] = {"12345","72884","40806","64073","72485","58784","01234","67592","54234","03649"};
 string colony[10] = {"Ghandi Road","Nehru Nagar","Tagore Street","MR Palli","MG Road","Demonte Colony","Church Street","Temple Street","Bhavani Nagar","Maruti Nagar"};
 string city[10] = {"Tirupati","Vishakapatanam","Bangalore","Chennai","Vijayawada","Rayachoti","Kadapa","Hyderabad","Delhi","Mumbai"};
 int r,flag;
 r = rand() %99+1;
 cout<<endl<<endl<<"Generated room number is "<<r<<endl<<endl<<endl; 
 flag = check(r);
 if(flag == 0){
  cout<<"Room already filled"<<endl<<endl;
 }
 else{
  h[r].name = firstname[rand()%9] +" " + lastname[rand()%9];
  h[r].phone = firstphone[rand()%9] + lastphone[rand()%9];
  h[r].address = colony[rand()%9] + "," +city[rand()%9];
  h[r].days = rand()%5+1;
  if(r<=50){
   h[r].bill = 1000*h[r].days;
   h[r].room_type = "Ordinary";
  }
  else if(r<=80){
   h[r].bill = 1500*h[r].days;
   h[r].room_type = "Deluxe";
  }
  else{
   h[r].bill = 2500*h[r].days;
   h[r].room_type = "Suite";
  }
  cout<<"Customer Name : "<<h[r].name<<endl;
  cout<<"Customer Mobile : "<<h[r].phone<<endl;
  cout<<"Customer Address: "<<h[r].address<<endl;
  cout<<"Number of days : "<<h[r].days<<endl;
  cout<<"Room Type : "<<h[r].room_type<<endl;
  cout<<"Estimated bill : "<<h[r].bill<<endl;
  cout<<endl<<endl<<"\tRoom Booked Successfully"<<endl<<endl<<endl;
  }
 }

int room_bookings::check(int r)
{
 int flag=0;
  if(r>99){
   flag =2;
  }
  else if(h[r].name.empty())
  {
   flag=1;
  }
 return(flag);
}

void room_bookings::display()
{
 int r,flag;
 cout<<"Enter the room number : ";
 cin>>r;
 flag = check(r);
 if(flag == 1){
  cout<<endl<<"\tThe room is Vacant"<<endl<<endl;
 }
 else if(flag ==2){
  cout<<endl<<"\tThe room Does not exists"<<endl<<endl;
 }
 else{
  cout<<endl<<endl;
  cout<<"Room Number : "<<h[r].room_no<<endl;
  cout<<"Customer Name : "<<h[r].name<<endl;
  cout<<"Customer Mobile : "<<h[r].phone<<endl;
  cout<<"Customer Address: "<<h[r].address<<endl;
  cout<<"Number of days : "<<h[r].days<<endl;
  cout<<"Room Type : "<<h[r].room_type<<endl;
  cout<<"Estimated bill : "<<h[r].bill<<endl<<endl<<endl;
 }
}

void room_bookings::rooms()
{
 int flag;
 int sno = 1;
 cout<<endl<<"\t\t\t\tFilled Rooms"<<endl<<endl;
 for(int i = 0;i<100;i++){
  flag = check(h[i].room_no);
  if(flag == 0){
   cout<<sno<<". "<<"Room No : "<<h[i].room_no<<"\t Name: "<<h[i].name<<"\t Days: "<<h[i].days<<"\t Room Type : "<<h[i].room_type<<endl;
   sno++;
  }
 }
 cout<<endl<<endl;
}
void room_bookings::edit()
{
 int flag;
 int sno = 1;
 cout<<endl<<"\t\t\t\tFilled Rooms"<<endl<<endl;
 for(int i = 0;i<100;i++){
  flag = check(h[i].room_no);
  if(flag == 0){
   cout<<sno<<". "<<"Room No : "<<h[i].room_no<<"\t Name: "<<h[i].name<<"\t Days: "<<h[i].days<<"\t Room Type : "<<h[i].room_type<<endl;
   sno++;
  }
 }
 cout<<endl<<endl;
}

void room_bookings::modify()
{ 
 int choice;
 while(choice!=7)
 {
  cout<<"\t* Modify *"<<endl;
  cout<<"1.Edit Name"<<endl;
  cout<<"2.Edit Contact Number"<<endl;
  cout<<"3.Edit Address"<<endl;
  cout<<"4.Edit Number of days of stay"<<endl;
  cout<<"5.Go Back"<<endl;
  cout<<"Enter Your Choice: ";
  cin>>choice;
  switch(choice)
  {
   case 1: modify_name();
    break;
   case 2: modify_phone();
    break;
   case 3: modify_address();
    break;
   case 4:modify_days();
    break;
   case 5: return;
   default:
    {
     cout<<"Wrong choice."<<endl;
    }
  }
 }
}
void room_bookings::modify_name()
{
 int r,flag;
 cout<<"Enter the room number : ";
 cin>>r;
 flag = check(r);
 if(flag == 1){
  cout<<endl<<"\tThe room is Vacant"<<endl<<endl;
 }
 else if(flag ==2){
  cout<<endl<<"\tThe room Does not exists"<<endl<<endl;
 }
 else{
  cout<<endl<<endl;
  cout<<"Room Number : "<<h[r].room_no<<endl;
  cout<<"Customer Name : "<<h[r].name<<endl;
  cout<<"Customer Mobile : "<<h[r].phone<<endl;
  cout<<"Customer Address: "<<h[r].address<<endl;
  cout<<"Number of days : "<<h[r].days<<endl;
  cout<<"Room Type : "<<h[r].room_type<<endl;
  cout<<"Estimated bill : "<<h[r].bill<<endl<<endl<<endl;
  cout<<"Enter the new name : ";
  cin>>h[r].name;
  cout<<"Name successfully modified"<<endl<<endl<<endl;
 }
}
void room_bookings::modify_phone()
{
 int r,flag;
 cout<<"Enter the room number : ";
 cin>>r;
 flag = check(r);
 if(flag == 1){
  cout<<endl<<"\tThe room is Vacant"<<endl<<endl;
 }
 else if(flag ==2){
  cout<<endl<<"\tThe room Does not exists"<<endl<<endl;
 }
 else{
  cout<<endl<<endl;
  cout<<"Room Number : "<<h[r].room_no<<endl;
  cout<<"Customer Name : "<<h[r].name<<endl;
  cout<<"Customer Mobile : "<<h[r].phone<<endl;
  cout<<"Customer Address: "<<h[r].address<<endl;
  cout<<"Number of days : "<<h[r].days<<endl;
  cout<<"Room Type : "<<h[r].room_type<<endl;
  cout<<"Estimated bill : "<<h[r].bill<<endl<<endl<<endl;
  cout<<"Enter the new number : ";
  cin>>h[r].phone;
  cout<<"Contact number successfully modified"<<endl<<endl<<endl;
 }
}
void room_bookings::modify_address()
{
 int r,flag;
 cout<<"Enter the room number : ";
 cin>>r;
 flag = check(r);
 if(flag == 1){
  cout<<endl<<"\tThe room is Vacant"<<endl<<endl;
 }
 else if(flag ==2){
  cout<<endl<<"\tThe room Does not exists"<<endl<<endl;
 }
 else{
  cout<<endl<<endl;
  cout<<"Room Number : "<<h[r].room_no<<endl;
  cout<<"Customer Name : "<<h[r].name<<endl;
  cout<<"Customer Mobile : "<<h[r].phone<<endl;
  cout<<"Customer Address: "<<h[r].address<<endl;
  cout<<"Number of days : "<<h[r].days<<endl;
  cout<<"Room Type : "<<h[r].room_type<<endl;
  cout<<"Estimated bill : "<<h[r].bill<<endl<<endl<<endl;
  cout<<"Enter the new address : ";
  cin>>h[r].address;
  cout<<"address successfully modified"<<endl<<endl<<endl;
 }
}
void room_bookings::modify_days()
{
 int r,flag;
 cout<<"Enter the room number : ";
 cin>>r;
 flag = check(r);
 if(flag == 1){
  cout<<endl<<"\tThe room is Vacant"<<endl<<endl;
 }
 else if(flag ==2){
  cout<<endl<<"\tThe room Does not exists"<<endl<<endl;
 }
 else{
  int temp_bill = h[r].bill;
  cout<<endl<<endl;
  cout<<"Room Number : "<<h[r].room_no<<endl;
  cout<<"Customer Name : "<<h[r].name<<endl;
  cout<<"Customer Mobile : "<<h[r].phone<<endl;
  cout<<"Customer Address: "<<h[r].address<<endl;
  cout<<"Number of days : "<<h[r].days<<endl;
  cout<<"Room Type : "<<h[r].room_type<<endl;
  cout<<"Estimated bill : "<<h[r].bill<<endl<<endl<<endl;
  cout<<"Enter the new days : ";
  cin>>h[r].days;
  cout<<"days successfully modified"<<endl;
  if(r<=50){
   h[r].bill = h[r].bill - temp_bill + 1000*h[r].days;
  }
  else if(r<=80){
   h[r].bill = h[r].bill - temp_bill +1500*h[r].days;
  }
  else{
   h[r].bill = h[r].bill - temp_bill +2500*h[r].days;
  }
  cout<<"New Estimated bill is "<<h[r].bill<<" (*Including restaurant Bills)"<<endl<<endl;
 }
}

void room_bookings::checkout_room(){
 int r, flag;
 cout<<endl<<"Enter Room Number"<<endl;
 cin>>r;
 check(r);
 if(flag == 1){
  cout<<endl<<"\tThe room is Vacant"<<endl<<endl;
 }
 else if(flag == 2){
  cout<<endl<<"\tThe room Does not exists"<<endl<<endl;
 }
 else{
  cout<<endl<<endl<<"\tBill"<<endl;
  cout<<"Room Number : "<<h[r].room_no<<endl;
  cout<<"Customer Name : "<<h[r].name<<endl;
  cout<<"Customer Mobile : "<<h[r].phone<<endl;
  cout<<"Estimated bill : "<<h[r].bill<<endl<<endl;
  h[r].name.clear();
  h[r].phone.clear();
  h[r].address.clear();
  h[r].days = 0;
  h[r].bill = 0;
  cout<<"Customer Checked Out Successfully"<<endl<<endl<<endl;
 }
}
void food_bookings::restaurant(){
 int choice,flag,roomno;
 cout<<endl<<endl<<"\tFood Bookings"<<endl<<endl;
 cout<<"Enter your Room Number : ";
 cin>>roomno;
 flag = check(roomno);
 if(flag == 1){
  cout<<endl<<"\tThe room is Vacant"<<endl<<endl;
 }
 else if(flag ==2){
  cout<<endl<<"\tThe room Does not exists"<<endl<<endl;
 }
 else{
  while(choice!=5)
  {
   cout<<"\t* Order Food *"<<endl;
   cout<<"1.BreakFast"<<endl;
   cout<<"2.Lunch"<<endl;
   cout<<"3.Dinner"<<endl;
   cout<<"4.Go Back"<<endl;
   cout<<"Enter Your Choice: ";
   cin>>choice;
   switch(choice)
   {
    case 1: breakfast(roomno);
     break;
    case 2: lunch(roomno);
     break;
    case 3: dinner(roomno);
     break;
    case 4: return;
     default:
     {
      cout<<"Wrong choice."<<endl;
     }
   }
  }
 }
}
void food_bookings::breakfast(int r){
 int people,cost;
 string main[10] = {"idly","Plain Dosa","Upma Dosa","Dosa","Pesarattu","masala Dosa","Vada","Poori","Rava Dosa","Onion Dosa"};
 string firstchutney[3] = {"Coconut Chutney","Onion Chutney","Mint Chutney"};
 string secondchutney[3] = {"Bombay Chutney","Groundnut Chutney","Karam chutney"};
 string podi[3] = {"Idli karam","Karam podi","Premium Karam Podi"};
 string ghee[3] = {"Homemade Ghee","Premium Homemade Ghee","Executive Homemade Ghee"};
 string sambar[6] = {"Tamilnadu Sambar","sweet and spicy Sambar","Vegitable Sambar", "Hot Sambar", "Spicy Sambar","Special Sambar"};
 cout<<endl<<"\t Todays Menu"<<endl<<endl;
 cout<<"1."<<main[rand()%9]<<endl<<"2."<<firstchutney[rand()%2]<<endl<<"3."<<secondchutney[rand()%2]<<endl<<"4."<<podi[rand()%2]<<endl<<"5."<<ghee[rand()%2]<<endl<<"6."<<sambar[rand()%5]<<endl<<endl;
 cout<<"Enter the number of guests : ";
 cin>>people;
 cost = 300*people;
 h[r].setbill(h[r].getbill()+cost);
 cout<<"Amount of Rs"<<cost<<"/- Was added to your bill"<<endl<<endl;
 cout<<"\t Thank you"<<endl<<endl;
}

void food_bookings::lunch(int r){
 string soups[10] = {"Hot and sour","Chicken machou","Pepper chicken","Sweet corn","Lentil","Creamy Potato","Ramen","Spicy Watermelon","Smoked Pumpkin","French Onion Soup"};
 string starters[10] = {"Pepper Chicken","Kaju Chicken","Appolo Fish","Prawns","Mushroom manchurian","Chicken Manchurian","Chicken 65","Mutton fry","Adoni spicy chicken","Chicken fry"};
 string noodles[10] = {"Chicken","Chicken and egg","Egg","Fish","Mutton","Fish and egg","Mutton and egg","Fish and chicken","Fish and mutton","Chicken and mutton"};
 string maincourse[10] = {"Chicken curry","Butter Chicken","Mutton curry","AP chicken curry","Mughalai Chicken","Punjabi chicken curry","Chicken Tikka masala","Afgani Chicken curry","Schezwan Chicken Curry","Egg tomato curry"};
 string roti[5] = {"Butter naan","Roti","Butter roti","Butter Kulcha","Rumali Roti"};
 string biriyani[5] = {"Egg","Chicken","Mutton","Fish","Prawn"};
 string softdrinks[5] = {"Thumps up","Coke","Pepsi","Sprite","Limca"};
 string softdrinks2[5] = {"Fanta","Mirinda","Sting","Mountain dew","Redbull"};
 cout<<endl<<"\t Todays Menu"<<endl<<endl;
 cout<<"1."<<soups[rand()%9]<<" soup"<<endl<<"2."<<starters[rand()%9]<<endl<<"3."<<noodles[rand()%9]<<" noodles"<<endl<<"4."<<maincourse[rand()%9]<<endl<<"5."<<roti[rand()%4]<<endl<<"6."<<biriyani[rand()%4]<<" Biriyani"<<endl<<"7."<<softdrinks[rand()%4]<<endl<<"8."<<softdrinks2[rand()%4]<<endl<<endl;
 int people,cost;
 cout<<"Enter the number of guests : ";
 cin>>people;
 cost = 750*people;
 h[r].setbill(h[r].getbill()+cost);
 cout<<"Amount of Rs"<<cost<<"/- Was added to your bill"<<endl<<endl<<endl;
 cout<<"\t Thank you"<<endl<<endl;
}

void food_bookings::dinner(int r){
 string soups[10] = {"Hot and sour","Chicken machou","Pepper chicken","Sweet corn","Lentil","Creamy Potato","Ramen","Spicy Watermelon","Smoked Pumpkin","French Onion Soup"};
 string starters[10] = {"Pepper Chicken","Kaju Chicken","Appolo Fish","Prawns","Mushroom manchurian","Chicken Manchurian","Chicken 65","Mutton fry","Adoni spicy chicken","Chicken fry"};
 string noodles[10] = {"Chicken","Chicken and egg","Egg","Fish","Mutton","Fish and egg","Mutton and egg","Fish and chicken","Fish and mutton","Chicken and mutton"};
 string maincourse[10] = {"Chicken curry","Butter Chicken","Mutton curry","AP chicken curry","Mughalai Chicken","Punjabi chicken curry","Chicken Tikka masala","Afgani Chicken curry","Schezwan Chicken Curry","Egg tomato curry"};
 string roti[5] = {"Butter naan","Roti","Butter roti","Butter Kulcha","Rumali Roti"};
 string biriyani[5] = {"Egg","Chicken","Mutton","Fish","Prawn"};
 string softdrinks[5] = {"Thumps up","Coke","Pepsi","Sprite","Limca"};
 string softdrinks2[5] = {"Fanta","Mirinda","Sting","Mountain dew","Redbull"};
 cout<<endl<<"\t Todays Menu"<<endl<<endl;
 cout<<"1."<<soups[rand()%9]<<" soup"<<endl<<"2."<<starters[rand()%9]<<endl<<"3."<<noodles[rand()%9]<<" noodles"<<endl<<"4."<<maincourse[rand()%9]<<endl<<"5."<<roti[rand()%4]<<endl<<"6."<<biriyani[rand()%4]<<" Biriyani"<<endl<<"7."<<softdrinks[rand()%4]<<endl<<"8."<<softdrinks2[rand()%4]<<endl<<endl;
 int people,cost;
 cout<<"Enter the number of guests : ";
 cin>>people;
 cost = 750*people;
 h[r].setbill(h[r].getbill()+cost);
 cout<<"Amount of Rs"<<cost<<"/- Was added to your bill"<<endl<<endl;
 cout<<"\t Thank you"<<endl<<endl;
}
int main()
{
 for(int i = 1;i<100;i++){
  h[i].set_roomno(i);
 }
 room_bookings h;
 h.main_menu();
 return 0;
}