#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int choice = 0;
int k = 0, n;

void add_product();
void edit_product();
void delete_product();
void search_product();
void buy_product();
void show_list();


struct product_info

{
	int id = 0;
	string name = "";
	int price = 0;
	int count = 0;

}*products;

int menu();
void load();
int main() {

	cout << "Enter number of products:  ";
	cin >> n;
	products = new product_info[n];
	load();


	while (choice != 7)

	{
		menu();
		switch (choice)
		{


		case 1:
			add_product();
			break;
		case 2:
			edit_product();
			break;
		case 3:
			delete_product();
			break;
		case 4:
			search_product();
			break;
		case 5:
			buy_product();
			break;
		case 6:
			show_list();
			break;
		case 7:
			break;

		}
	}

	return 0;

}

int menu() {
	cout << "\n\t Store Menue\n\n1-Add Product\n2-Edit Product\n3-Delete Product\n4-Search\n5-Buy\n6-Show List\n7-Exit\n";
	cin >> choice;
	return choice;
}

void load() {


	string line;
	ifstream product_file;
	product_file.open("products.txt");

	while (getline(product_file, line)) {

		string array[4];
		int j = 0;

		for (int i = 0; i <= line.size(); i++)
		{

			if (line[i] != ',' && i != (line.size()))
				array[j] = array[j] + line[i];
			else
			{

				switch (j)
				{
				case 0:
					products[k].id = stoi(array[j]);
					break;
				case 1:
					products[k].name = array[j];
					break;
				case 2:
					products[k].price = stoi(array[j]);
					break;
				case 3:
					products[k].count = stoi(array[j]);
					break;

				}
				j++;

			}

		}

		k++;
	}

	product_file.close();
}


void show_list() {
	cout << "\n List:\n";
	for (int i = 0; i<n; i++)

		cout << "product " << i + 1 << "= id: " << products[i].id << "\tname: " << products[i].name << "\tprice: " << products[i].price << "\tcount: " << products[i].count << "\n";

}
void add_product() {
	int id, count, price;
	string name;
	std::ofstream myfile;

	myfile.open("products.txt", std::ios_base::app);

	cout << "Enter the id of the product: ";
	cin >> id;
	myfile << std::endl << id << ",";

	cout << "Enter the name of the product: ";
	cin >> name;
	myfile << name << ",";

	cout << "Enter the price of the product: ";
	cin >> price;
	myfile << price << ",";

	cout << "Enter the number of the product: ";
	cin >> count;
	myfile << count;

}

void edit_product() {
	string line, name, find;
	int id, count, price;
	cout << "Enter the id of the product u want to update " << endl;
	cin >> find;

	ifstream myfile2; //for reading records
	myfile2.open("products.txt");

	ofstream temp;

	temp.open("temp.txt");
	while (getline(myfile2, line))
	{
		string array[4];
		int j = 0;

		for (int i = 0; i <= line.size(); i++)
		{

			if (line[i] != ',' && i != (line.size()))
				array[j] = array[j] + line[i];
			else
			{

				if (j == 0) {
					if (array[j] != find) 
						temp << array[j] << ",";
				}
				if (j == 1) {
					if(array[0] != find)
						temp << array[j] << ",";
				}
				if (j == 2) {
					if (array[0] != find)
						temp << array[j] << ",";
				}
				if (j == 3) {
					if (array[0] != find)
						temp << array[j] << ","<<endl;
				}
				j++;
				
			}
                
		}			
	}
	myfile2.close();
	temp.close();
	remove("products.txt");
	rename("temp.txt", "products.txt");

	cout << "enter the id of the new fruit " << endl;
	cin >> id;
	cout << "enter the name of the new fruit" << endl;
	cin >> name;
	cout << "enter price of the new fruit " << endl;
	cin >> price;
	cout << "enter the number of the new fruit " << endl;
	cin >> count;

	ofstream myfile;
	myfile.open("products.txt", ios::app | ios::out);

	myfile << id << ",";
	myfile << name << ",";
	myfile << price << ",";
	myfile << count;

}

void delete_product() {
	string line, name, find;
	int id, count, price;
	cout << "Enter the id of the product u want to delete " << endl;
	cin >> find;

	ifstream myfile2; //for reading records
	myfile2.open("products.txt");

	ofstream temp;

	temp.open("temp.txt");
	while (getline(myfile2, line))
	{
		string array[4];
		int j = 0;

		for (int i = 0; i <= line.size(); i++)
		{

			if (line[i] != ',' && i != (line.size()))
				array[j] = array[j] + line[i];
			else
			{

				if (j == 0) {
					if (array[j] != find)
						temp << array[j] << ",";
				}
				if (j == 1) {
					if (array[0] != find)
						temp << array[j] << ",";
				}
				if (j == 2) {
					if (array[0] != find)
						temp << array[j] << ",";
				}
				if (j == 3) {
					if (array[0] != find)
						temp << array[j] << "," << endl;
				}
				j++;

			}

		}
	}
	myfile2.close();
	temp.close();
	remove("products.txt");
	rename("temp.txt", "products.txt");

	
}

void search_product(){
	string line, name, find;
	int id, count, price;
	cout << "Enter the id of the product u want to search " << endl;
	cin >> find;

	ifstream myfile3; 
	myfile3.open("products.txt");

	while (getline(myfile3, line))
	{
		string array[4];
		int j = 0;

		for (int i = 0; i <= line.size(); i++)
		{

			if (line[i] != ',' && i != (line.size()))
				array[j] = array[j] + line[i];
			else
			{

				if (j == 0) {
					if (array[j] == find)
						cout<< array[j] << ",";
				}
				if (j == 1) {
					if (array[0] == find)
						cout<< array[j] << ",";
				}
				if (j == 2) {
					if (array[0] == find)
						cout<< array[j] << ",";
				}
				if (j == 3) {
					if (array[0] == find)
						cout << array[j] << endl;
				}
				j++;

			}

		}
	}
	myfile3.close();

}

void buy_product(){

	string line, name, find;
	int id, count, price,count_buy;
	cout << "Enter the id of the product u want to buy " << endl;
	cin >> find;

	ifstream myfile4;
	myfile4.open("products.txt");
	ofstream temp;

	temp.open("temp.txt");

	while (getline(myfile4, line))
	{
		string array[4];
		int j = 0;

		for (int i = 0; i <= line.size(); i++)
		{

			if (line[i] != ',' && i != (line.size()))
				array[j] = array[j] + line[i];
			else
			{

				if (j == 0) {
					if (array[j] != find)
						temp << array[j] << ",";
				}
				if (j == 1) {
					if (array[0] != find)
						temp << array[j] << ",";
				}
				if (j == 2) {
					if (array[0] != find)
						temp << array[j] << ",";
				}
				if (j == 3) {
					if (array[0] != find)
						temp << array[j] << "," << endl;
				}

				if (j == 3) {
					if (array[0] == find) {
						cout << "How many do you want?";
						cin >> count_buy;
						products[k].count -= count_buy;
						
					}
					}
					j++;

				}

			}
		}
		myfile4.close();
		temp.close();
		remove("products.txt");
		rename("temp.txt", "products.txt");
	}

