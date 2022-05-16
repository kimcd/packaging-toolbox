//
//  main.cpp
//  component-database
//
//  Created by Christopher Kim on 5/9/22.
//  Copyright © 2022 Christopher Kim. All rights reserved.
//

#include "ASD.h"

#include <iostream>
#include "SCRATCH.h"
#include "Component.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include<fstream>
using std::ifstream;
using std::ios;

#include<sstream>
using std::stringstream;

#include <iostream>
using std::cerr;
using std::endl;
using std::cout;

#include <algorithm>
using std::transform;

void test_component()
{
    design_simple_search_and_data_entry();
}


void test_read_csv() {
    
    string file_path = "/Users/christopherkim/Documents/cpp/packaging-toolbox/src/component_database.csv";
    
    vector<vector<string>> my_csv;
    
    my_csv = read_in_csv2(file_path);
    
    print_vector_vector(my_csv);
    
}


void test_db()
{

	cout << compute_db(.02, .4) << endl;
	cout << compute_oct(20, 50) << endl;
	cout << compute_area(20, 50, 0.02, 0.4) << endl;

	vector<unsigned int> f = {20, 50, 100, 250, 500, 1000, 2000};

	vector<double> asd = {0.02, 0.4, 0.4, .04, .04, .02, .01};

	ASD asd1(f, asd);

	cout << "grms == " << asd1.get_rms() << endl;


	ASD gevs(ASD::GEVS_FREQUENCIES, ASD::GEVS_ASD);

	cout << "gevs grms == " << gevs.get_rms() << endl;



}

void plus_6db()
{
	vector<double> asd = {0.02, .4, .4, .02};

	double myconstant{6};

	std::transform(
			asd.begin(),
			asd.end(),
			asd.begin(),
			[&myconstant](auto& c)
			{
		return c * pow(10, myconstant/20);
			});


	for(auto& ele : asd)
	{
		cout << ele << ", ";
	}

}

void minus_6db()
{
	vector<double> asd = {0.02, .4, .4, .02};

	double myconstant{6};

	std::transform(
			asd.begin(),
			asd.end(),
			asd.begin(),
			[&myconstant](auto& c)
			{
		return c / pow(10, myconstant/20);
			});


	for(auto& ele : asd)
	{
		cout << ele << ", ";
	}

}

void plus_xdb(vector<double>& some_asd, double some_db)
{
	std::transform(
			some_asd.begin(),
			some_asd.end(),
			some_asd.begin(),
			[&some_db](auto& c)
			{
		return c / pow(10, some_db/20);
			});


	for(auto& ele : some_asd)
	{
		cout << ele << ", ";
	}

}


int main(int argc, const char * argv[]) {
    // insert code here...
    //test_component();
    test_database_manager();
    return 0;
}



