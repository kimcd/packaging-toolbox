//
//  SCRATCH.h
//  component-database
//
//  Created by Christopher Kim on 5/9/22.
//  Copyright © 2022 Christopher Kim. All rights reserved.
//
#include <string>
#include <vector>

#ifndef SCRATCH_h
#define SCRATCH_h

void test_read_csv();

std::vector<std::vector<std::string>> read_in_csv(const std::string& file_name);

void search_part_csv(std::string& part_number);

void print_vector_vector(std::vector<std::vector<std::string>>& vector);


void print_vector_(std::vector<std::string>& vector);

std::vector<std::vector<std::string>> read_in_csv2(const std::string& file_name);

#endif /* SCRATCH_h */

