#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;

struct Node
{
	long int data;
	Node *next;
};
Node *ListHeadPtr = NULL;;

void Insert(long int address)
{

	Node *ptrNew = new Node, *ptrTemp = ListHeadPtr;
	ptrNew->data = address;
	ptrNew->next = NULL;
	if (ListHeadPtr == NULL)
	{
		ListHeadPtr = ptrNew;
		return;
	}
	while (ptrTemp->next != NULL)
	{
		ptrTemp = ptrTemp->next;
	}

	ptrTemp->next = ptrNew;

}
void view_data(long int address)
{
	char input[1000] = {'\0'};
	ifstream in("file_project.txt");
	in.seekg(address);
	in.getline(input,1000,'$');
	for (int i = 0; i < 1000 && i!='$'; i++)
	{
		cout << input[i];
	}
	cout << endl;
	in.close();
}
int a,b,c,d,e=0,f;
class arrays
{
	char file_name_data[8192][20];
	long int file_address[8192];
public:
	arrays()
	{
		for (int i = 0; i < 8192; i++)
		{
			for (int j = 0; j < 20; j++)
				file_name_data[i][j] = ' ';
		}
		for (int k = 0; k < 8192; k++)
			file_address[k] = NULL;
	}
	char get_file_name(long int key, int i)
	{
		return this->file_name_data[key][i];
	}

	long int get_file_address(long int key)
	{
		return this->file_address[key];
	}

	void set_file_name(long int key, int i, char input [])
	{

		file_name_data[key][i] = input[i];
	}

	void set_file_address(long int key, long int address)
	{
		file_address[key] = address;
	}
	void data_storage()
	{
		char ch;
		long int address = 0, address1 = 0;
		char input[20];
		Node*temp = ListHeadPtr;
		ifstream in("file_project.txt");
		in.seekg(address1);
		in >> ch;
		while (ch != ' ' && ch != NULL)
		{
			address1 += 500;
			in.seekg(address1);
			in >> ch;
		}
		in.close();
		ofstream update("file_project.txt", ios::cur);

		for (int count = 0; count < 8192; count++)
		{
			update.seekp(address1);

			if (file_name_data[count][0]!=' ' && file_address!=NULL)
			{
				for (int j = 0; j < 20; j++)
				{
					update << file_name_data[count][j];
				}
				update << '~';
				update << file_address[count];
				address1 = address1 + 500;
			}
		}
		update.close();

	}
	void view_list()
	{
		long int address=0;
		for(int i=0;i<8192;i++)
		{
			if(file_name_data[i][0]!=' ' || file_address[i]!=NULL)
			{
				cout << "File name: " ;
				for(int j=0;j<20;j++)
				{
					cout << file_name_data[i][j];
				}
				cout << endl ;
				cout << "Address : ";
				address=file_address[i];
				cout << file_address[i];
				cout << endl;
				cout<< "Data :";
				view_data(address);
			}
		}
	}
};
long generate_text_file(int a ,int b,int c ,int d,int e ,int f)
{
	long int address_storage = 0;
	long int address_storage1 = 0;
	//	int i, j;
	ofstream project_writer;

	project_writer.open("file_project.txt", ios::trunc);

	project_writer.seekp((1024 * 1024) * a);
	project_writer.tellp();
	project_writer << '$';

	project_writer.seekp((1024 * 1024 * b)+(1024 * 1024 * c));
	project_writer.tellp();
	project_writer << '+';

	project_writer.seekp((1024 * 1024) * b);
	project_writer.tellp();
	project_writer.tellp()<<'&';

	project_writer.seekp((1024 * 1024 * b)+(1024 * 1024 * c));
	address_storage = project_writer.tellp();

	project_writer.seekp((1024 * 1024*b));
	address_storage1 = project_writer.tellp();

	for (; address_storage <= 1024 * 1024 * a; address_storage += f)
	{
		project_writer << address_storage << " ";
		Insert(address_storage);
	}

	project_writer.close();
	return 0;
}
void set_address_list()
{

	
	int a,b,c,d,e,f;
	ifstream s("sizes.txt");
	s.seekg(0);
	s >> a;
	
	s.seekg(8);
	s >> b;

	s.seekg(16);
	s >> c;

	s.seekg(24);
	s >> d;

	s.seekg(32);
	s >> e;

	s.seekg(40);
	s >> f;
	s.close();
	ofstream project_writer;

	project_writer.open("file_project.txt", ios::cur);

	long int address_storage = ((1024*1024*b)+(1024*1024*c));


	for (; address_storage <= 1024 * 1024 * 10; address_storage += f)
	{
		Insert(address_storage);
	}

	project_writer.close();

}
long int DisplaySpecificNode()
{
	return ListHeadPtr->data;
}
void DeleteNode()
{
	Node *ptrCurrent = ListHeadPtr;

	ListHeadPtr = ListHeadPtr->next;
	delete ptrCurrent;

}
long int hash_func(char *ptr, int a)
{


	int seed = 131;
	unsigned long int hash = 0;
	for (int i = 0; i < a && ptr[i] != ' '; i++)
	{
		hash = (hash * seed) + ptr[i];
	}
	hash = hash % 8192;
	return hash;
}
void adding(arrays &obj)
{

	
	int a,b,c,d,e,f;
	ifstream s("sizes.txt");
	s.seekg(0);
	s >> a;
	
	s.seekg(8);
	s >> b;

	s.seekg(16);
	s >> c;

	s.seekg(24);
	s >> d;

	s.seekg(32);
	s >> e;

	s.seekg(40);
	s >> f;
	s.close();
	long int address = 0, key = 0;
	char ch;
	long int address1 = 0;
	char input[20] = { '\0' };
	ifstream in("file_project.txt");
	in.seekg(address);
	in >> ch;
	while (address<=1024*1024*b)
	{
		in.seekg(address);
		address1=address;
		for (int i = 0; i < 20 && ch!='~'; i++)
		{
			in.seekg(address);
			in >> input[i];
			address++;
			in >> ch;
		}
		address=address1;
		key = hash_func(input, strlen(input));
		for (int j = 0; j < strlen(input); j++)
			obj.set_file_name(key, j, input);
		address += 21;
		in.seekg(address);

		in >> address1;
		obj.set_file_address(key, address1);
		address += e-21;
		in.seekg(address);
		in >> ch;
		for(int i=0;i<20;i++)
		{
			input[i]=NULL;
		}
	}
}
long int create_new_file(arrays &obj,int &counter)
{
	char input[20];
	char storage[20];
	long int hash_storage = 0;
	int size;
	long int current_address=0;

	cout << "enter name of file u want to create:";
	cin.ignore();
	cin.getline(input, 20, '\n');
	size = strlen(input);
	hash_storage = hash_func(input, size);
	for(int b=0;b<size;b++)
	{
		storage[b]=obj.get_file_name(hash_storage,b);
	}

	for(int a=0;a<size;a++)
	{
		if(storage[a]==input[a])
		{
			cout<<"file already exist "<<endl;
			counter+=1;
			break;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				obj.set_file_name(hash_storage, i, input);
			}

			current_address = DisplaySpecificNode();
			obj.set_file_address(hash_storage, current_address);
			DeleteNode();


		}

	}
	return hash_storage;
}
void write_linklist()
{
	ofstream out("file_project.txt", ios::cur);
	Node *temp = ListHeadPtr;
	out.clear();
	out.seekp(1024 * 1024);
	while (temp != NULL)
	{
		out << temp->data;
		out << ' ';
		temp = temp->next;
	}

	out.close();
}
void write_data_on_console(arrays obj,long int key)
{
	char input[1000]={'\0'};
	cout << " Enter Data :";
	cin.getline(input,1000,'\n');
	ofstream out("file_project.txt",ios::cur);
	long int address = obj.get_file_address(key);
	out.seekp(address);
	out << input;
	out << '$';
	out.close();
}
void copy_file(arrays &obj,long int key)
{
	char input[1000];
	long int address=obj.get_file_address(key);
	ifstream in("project.txt");
	in.seekg(0);
	in.getline(input,1000,'\0');
	in.close();
	ofstream out("file_project.txt",ios::cur);
	out.seekp(address);
	out << input;
	out << '$';
	out.close();
}

void copy_data_to_windows(arrays &obj)
{
	int size=0;
	long int address=0;
	long int key=0;
	char choice[20];
	char storage_name[20]={'/0'};
	long int storage_address=0;
	char storage_data[1000];
	char directory[100];
	char ch;
	cout<<"enter the name of file u want to copy : "<<endl;
	cin.ignore();
	cin.getline(choice,20,'\n');
	cout<<"enter name including directory : ";
	cin.getline(directory,100,'\n');
	size=strlen(choice);
	char answer;
	key=hash_func(choice,size);

	for(int b=0;b<size;b++)
	{
		storage_name[b]=obj.get_file_name(key,b);
	}

	for(int i=0;i<size;i++)
	{
		if(choice[i]==storage_name[i])
		{
			answer='y';

		}
		else 
		{
			answer='n';
			cout<<" no such file exists"<<endl;
			break;
		}

	}

	if(answer=='y')
	{
		storage_address=obj.get_file_address(key);
		ifstream out("file_project.txt");
		int a=0;
		out.seekg(storage_address);

		while(a<1000)
		{
			out >> ch;
			storage_data[a]=ch;
			a++;
		}
		out.close();

		ofstream outer(directory);
		outer.seekp(0);
		outer <<storage_name<<' ';
		outer <<storage_address<<' ';
		for(int c=0;c<1000;c++)
			outer <<storage_data[c];
		outer.close();

	}
}
void modify_file(arrays &obj)
{
	
	int size=0;
	long int address=0;
	long int key=0;
	char choice[20];
	char storage_name[20]={'/0'};
	long int storage_address=0;
	char storage_data[1000];
	char directory[100];
	char ch;
	char modifier[100];
	cout<<"enter the name of file u want to modify : "<<endl;
	cin.ignore();
	cin.getline(choice,20,'\n');
	cout<<"enter modification string :";
	cin.getline(modifier,100,'\n');
	size=strlen(choice);
	char answer;
	int count=0;
	key=hash_func(choice,size);

	for(int b=0;b<size;b++)
	{
		storage_name[b]=obj.get_file_name(key,b);
	}

	for(int i=0;i<size;i++)
	{
		if(choice[i]==storage_name[i])
		{
			answer='y';

		}
		else 
		{
			answer='n';
			cout<<" no such file exists"<<endl;
			break;
		}

	}

	if(answer=='y')
	{
		storage_address=obj.get_file_address(key);
		ifstream out("file_project.txt");
		int a=0;
		out.seekg(storage_address);

		while(a<1000)
		{
			out.get(ch);
			if(ch==NULL)
				break;
			storage_data[a]=ch;
			count++;
			a++;
		}
		out.close();

		ofstream outer("file_project.txt",ios::cur);
		outer.seekp(storage_address+count);
		for(int i=0;i<100 && modifier[i]!=NULL;i++)
		outer <<modifier[i];
		outer.close();

	}
}

void delete_file(arrays &obj)
{
	int size=0;
	long int address=0;
	long int key=0;
	char choice[20];
	char storage_name[20]={'/0'};
	long int storage_address=0;
	char storage_data[1000];
	char directory[100];
	char ch;
	cout<<"enter the name of file u want to delete : "<<endl;
	cin.ignore();
	cin.getline(choice,20,'\n');
	size=strlen(choice);
	char answer;
	int count=0;
	key=hash_func(choice,size);
	for(int b=0;b<size;b++)
	{
		storage_name[b]=obj.get_file_name(key,b);
	}
	
	for(int i=0;i<size;i++)
	{
		if(choice[i]==storage_name[i])
		{
			answer='y';

		}
		else 
		{
			answer='n';
			cout<<" no such file exists"<<endl;
			break;
		}

	}

	if(answer=='y')
	{
		storage_address=obj.get_file_address(key);
		
		ifstream out("file_project.txt");
		int a=0;
		out.seekg(storage_address);

		while(a<1000)
		{
			out.get(ch);
			if(ch==NULL)
				break;
			storage_data[a]=ch;
			count++;
			a++;
		}
		
		out.close();
		
		for(int b=0;b<size;b++)
	{
		storage_name[b]=NULL;
	}
	
		ofstream outer("file_project.txt",ios::cur);
		outer.seekp(storage_address);
		for(int i=0;i<1000;i++)
		outer <<' ';
		storage_address=0;
		outer.close();
	}
}

void main()
{
	int counter=0;
	long int key;
	arrays obj;
	ifstream in("file_project.txt");
	if (!in.fail())
	{
		in.close();
		set_address_list();
		adding(obj);
	}
	else
	{
		in.close();

		cout<<"Write file size: "<<endl;
		cin>>a;

		cout<<"Write first prtion size:  "<<endl;
		cin>> b;
		
		cout<<"Write second prtion size:  "<<endl;
		cin>> c;

		cout<<"Write third prtion size:  "<<endl;
		cin>> d;


		cout<<"Write size block size to store file name and address:  "<<endl;
		cin>>e;


		cout<<"Write size for block size in third portion (e.g 1024):  "<<endl;
		cin>> f;
		ofstream s("sizes.txt");
		s.seekp(0);
		s<<a;
		s.seekp(8);
		s<<b;

		s.seekp(16);
		s<<c;
		s.seekp(24);
		s<<d;

		s.seekp(32);
		s<<e;

		s.seekp(40);
		s<<f;
		s.close();


		generate_text_file(a,b,c,d,e,f);
	}
	int choice;
	while (1)
	{

		cout << "press 1 to create a text file" << endl;
		cout << "press 2 to list existing files" << endl;
		cout << "press 3 to copy data from hard-drive" << endl;
		cout<<  "press 4 to copy data to windows"<<endl;
		cout<<  "press 5 to modify file"<<endl;
		cout<<  "press 6 to delete file"<<endl;
		cout << "press 7 to exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			key = create_new_file(obj,counter);
			if(counter==0)
			{
				write_data_on_console(obj,key);
			}
			else
			{
				cout<<"So u can't enter any related data "<<endl;
				counter=0;
			}
			break;
		case 2:
			obj.view_list();
			getch();
			break;
		case 3:
			key = create_new_file(obj,counter); 
			cout<<counter;
			if(counter==0)
			{
				copy_file(obj,key);
			}
			else
			{
				cout<<"So u can't enter any related data "<<endl;
				counter=0;
			}
			break;
		case 4:
			copy_data_to_windows(obj);
			break;
		case 5:
			modify_file(obj);
			break;
		case 6:
			delete_file(obj);
			break;
		case 7:
			write_linklist();
			obj.data_storage();
			exit(0);
		default:
			cout << "Wrong Input. "  << endl;

		}

	}
}
