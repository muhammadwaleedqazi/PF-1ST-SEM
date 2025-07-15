#include<iostream>
#include<fstream>
#include<string>
#include<limits>
using namespace std;

//Structure for medicine
struct Medicine
{
int med_id;
string med_name;
string manufacturer;
string strength;
string formulation;
double unit_price;
int stock_quantity;
string expiry_date;
bool requires_prescription;
};
int generateMed_id()
{
	ifstream infile("medicines.txt");
	int maxID=0;
	Medicine med;
	
	while(infile>>med.med_id>>med.med_name>>med.manufacturer>>med.strength>>med.formulation>>med.unit_price>>med.stock_quantity>>med.expiry_date>>med.requires_prescription)
	{
		if(med.med_id>maxID)
		{
			maxID=med.med_id;
		}
	}
	infile.close();
	return maxID+1;
}
// It is the function to add Medicines
int addMed()
{
	Medicine med;
	med.med_id=generateMed_id();
	cout<<"Enter Medicine Name: "<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, med.med_name);
	cout<<"Enter Manufacturer: "<<endl;
	getline(cin, med.manufacturer);
	cout<<"Enter Strength: "<<endl;
	getline(cin, med.strength);
	cout<<"Enter Formulation (e.g. tablet, capsule, syrup): "<<endl;
	getline(cin, med.formulation);
	cout<<"Enter the unit price of medicine: "<<endl;
	cin>>med.unit_price;
	cout<<"Enter Stock Quantity: "<<endl;
	cin>>med.stock_quantity;
	cout<<"Enter Expiry Date of medicine (YYYY-MM-DD): "<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, med.expiry_date);
	cout<<"Requires Prescription (1 for'YES', 0 for 'NO'): "<<endl;
	cin>>med.requires_prescription;
	
	ofstream outfile("medicines.txt", ios::app);
	if (outfile.is_open())
	{
	outfile<<med.med_id<<" "<<med.med_name<<" "<<med.manufacturer<<" "<<med.strength<<" "<<med.formulation<<" "<<med.unit_price<<" "<<med.stock_quantity <<" "<<med.expiry_date<<" "<<med.requires_prescription<<" "<<endl;
	outfile.close();
	cout<<"Medicine Added Successfully!"<<endl;
}
else
{
	cout<<"Error opening File !!"<<endl;
}
}
//This is the function to View Medicines Record
int viewMed()
{
	ifstream infile("medicines.txt");
	if (infile.is_open())
	{
	Medicine med;
	bool found=false;
	 while (infile >>med.med_id >> med.med_name >> med.manufacturer >> med.strength >>
               med.formulation >> med.unit_price >> med.stock_quantity >> med.expiry_date >>
               med.requires_prescription)
	{
		found=true;
		cout<<"Medicine ID: "<<med.med_id<<endl;
		cout<<"Medicine Name: "<<med.med_name<<endl;
		cout<<"Manufacture: "<<med.manufacturer<<endl;
		cout<<"Strenght: "<<med.strength<<endl;
		cout<<"Formulation: "<<med.formulation<<endl;
		cout<<"Unit Price: "<<med.unit_price<<endl;
		cout<<"Stock Quantity: "<<med.stock_quantity<<endl;
		cout<<"Expiry Date: "<<med.expiry_date<<endl;
		cout<<"Requires Prescription: "<<med.requires_prescription<<endl;
		cout<<"<._._._._._._._._._._._._._._._.>"<<endl;
	}
	if(!found)
	{
		cout<<"No Medicines found in the System."<<endl;
	}
	infile.close();
}
else
{
	cout<<"The File is Not Opened!"<<endl;
}
}
//It is function to edit medicine in the file.
int editMed()
{
	ifstream infile("medicines.txt");
	ofstream outfile("temp.txt");
	if (!infile.is_open()||!outfile.is_open())
	{
		cout<<"Error opening files!\n";
		return 1;
	}
	int medIdtoEdit;
	cout<<"Enter the Id of the Medicine to Edit: ";
	cin>>medIdtoEdit;
	Medicine med;
	bool found=false;
	while(infile>>med.med_id>>med.med_name>>med.manufacturer>>med.strength>>med.formulation>>med.unit_price>>med.stock_quantity>>med.expiry_date>>med.requires_prescription)
	{
		if(med.med_id==medIdtoEdit)
		{
		found=true;
		cout<<"Current Details: "<<endl; 
	    cout<<"Medicine ID: "<<med.med_id<<endl;
		cout<<"Medicine Name: "<<med.med_name<<endl;
		cout<<"Manufacture: "<<med.manufacturer<<endl;
		cout<<"Strenght: "<<med.strength<<endl;
		cout<<"Formulation: "<<med.formulation<<endl;
		cout<<"Unit Price: "<<med.unit_price<<endl;
		cout<<"Stock Quantity: "<<med.stock_quantity<<endl;
		cout<<"Expiry Date: "<<med.expiry_date<<endl;
		cout<<"Requires Prescription: "<<med.requires_prescription<<endl;
		cout<<"<._._._._._._._._._._._._._._._.>"<<endl;
		
		cout<<"Enter New Medicine Name: "<<endl;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		getline(cin, med.med_name);
		cout<<"Enter New Manufacturer: "<<endl;
		getline(cin, med.manufacturer);
		cout<<"Enter New Strength: "<<endl;
		getline(cin, med.strength);
		cout<<"Enter New Formulation (e.g, tablet, capsule, syrup):"<<endl;
		getline(cin, med.formulation);
		cout<<"Enter New Unit Price: "<<endl;
	    cin>>med.unit_price;
	    cout<<"Enter New Stock Quantity: "<<endl;
	    cin>>med.stock_quantity;
	    cout<<"Enter New Expiry Date (YYYY-MM-DD): "<<endl;
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    getline(cin, med.expiry_date);
	    cout<<"Require Prescription (1 for 'YES',O for'NO': "<<endl;
	    cin>>med.requires_prescription;
	    outfile<<med.med_id<<" "<<med.med_name<<" "<<med.manufacturer<<" "<<med.strength<<" "<<med.formulation<<" "<<med.unit_price<<" "<<med.stock_quantity<<" "<<med.expiry_date<<" "<<med.requires_prescription<<" "<<endl;
	    cout<<"Medicine updated successfully!"<<endl;
	    }
          else
          {
        outfile<<med.med_id<<" "<<med.med_name<<" "<<med.manufacturer<<" "<<med.strength<<" "<<med.formulation<<" "<<med.unit_price<<" "<<med.stock_quantity<<" "<<med.expiry_date<<" "<<med.requires_prescription<<" "<<endl;

		  }

	
		}
	infile.close();
	outfile.close();
	if (!found)
	{
		cout<<"Medicine with ID"<<medIdtoEdit<<"Not Found !"<<endl;
		remove("temp.txt");
	}
	else
	{
		remove("medicines.txt");
		rename("temp.txt","medicines.txt");
	}
	return 0;
}
// It is the function to search medicine in file

int searchMed()
{
	ifstream infile("medicines.txt");
	if(!infile.is_open())
	{
		cout<<"Error Opening File!"<<endl;
		return 0;
	}
	string searchTerm;
	cout<<"Enter medicine name or ID to search: ";
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	getline(cin, searchTerm);
	
	Medicine med;
	bool found=false;
	while (infile >> med.med_id >> med.med_name >> med.manufacturer >> med.strength >> 
           med.formulation >> med.unit_price >> med.stock_quantity >> med.expiry_date >> 
           med.requires_prescription)
	{
		if(med.med_name.find(searchTerm) !=string::npos||to_string(med.med_id)==searchTerm)
		{
			found= true;
			cout<<"Medicine ID: "<<med.med_id<<endl;
			cout<<"MEdicine Name: "<<med.med_name<<endl;
			cout<<"Manufacturer: "<<med.manufacturer<<endl;
			cout<<"Strength: "<<med.strength<<endl;
			cout<<"Formulation: "<<med.formulation<<endl;
			cout<<"Unit Price: "<<med.unit_price<<endl;
			cout<<"Stock Quantity: "<<med.stock_quantity<<endl;
			cout<<"Expiry Date: "<<med.expiry_date<<endl;
			cout<<"Requires Prescription: "<<(med.requires_prescription ?"Yes":"No")<<endl;
			cout<<"<._._._._._._._._._._._._._._._.>\n";
		}
	}
	infile.close();
	if(!found)
	{
		cout<<"No medicines found matching the search term.\n";
	}
 } 
 //It is the function to delete a medicine 
 void deleteMed()
 {
 	ifstream infile("medicines.txt");
 	ofstream outfile("temp.txt");
 	if (! infile.is_open()||!outfile.is_open()) 
 	{
 		cout<<"Error opening files!\n";
 		return;
	}
	int medIdtoDelete;
	cout<<"Enter the ID of the medicine to delete: ";
	cin>>medIdtoDelete;
	Medicine med;
	bool found=false;
	while(infile>>med.med_id>>med.med_name>>med.manufacturer>>med.strength>>med.formulation>>med.unit_price>>med.stock_quantity>>med.expiry_date>>med.requires_prescription)
	{
		if( med.med_id !=medIdtoDelete)
		{
        outfile << med.med_id << " " << med.med_name << " " << med.manufacturer << " "
                    << med.strength << " " << med.formulation << " " << med.unit_price << " "
                    << med.stock_quantity << " " << med.expiry_date << " "
                    << med.requires_prescription << endl;		
	}
			else
			{
				found=true;
			}
		}
		infile.close();
		outfile.close();
		if(!found)
		{
			cout<<"Medicine with ID"<<medIdtoDelete<<"notfound.\n";
			remove("temp.txt");
		}
		else
		{
			remove("medicines.txt");
			rename("temp.txt", "medicines.txt");
			cout<<"Medicine deleted successfully!\n";
		}
	}
int main()
{
	int choice;
	do{
	cout<<"Welcome to Medical Store Management System"<<endl;
	cout<<"1. Add Medicine"<<endl;
	cout<<"2. View Medicines"<<endl;
	cout<<"3. Edit Medicine"<<endl;
	cout<<"4. Search Medicine"<<endl;
	cout<<"5. Delete Medicine"<<endl;
	cout<<"0. Exit"<<endl;
	cout<<"Enter Your Choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			addMed();
			break;
		case 2:
			viewMed();
			break;
	    case 3:
	        editMed();
	        break;
		default:
			cout<<"Invalid Choice!"<<endl;
	}
}
while(choice!=0);
return 0;
}