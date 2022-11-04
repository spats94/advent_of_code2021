//
// Created by alexandr on 04.11.22.
//
#include <iostream>
#include <fstream>
#include <string>
#include "vector"

namespace day1 {

  std::vector<int> read_data() {
//    std::ifstream file("/home/alexandr/Workspace/advent_of_code2021/day01/data/data_test.txt");
    std::ifstream file("/home/alexandr/Workspace/advent_of_code2021/day01/data/data_input.txt");
    std::string str;
    std::getline(file, str);
    std::vector<int> vector = {};
    while (std::getline(file, str))
    {
      vector.emplace_back(std::stoi(str));
    }
    return vector;
  }

  void part1() {
    auto vector = read_data();
    auto last_value = vector[0];
    int kIncreese = 0;
    for (auto const el : vector) {
      if (el > last_value)
        kIncreese++;
      last_value = el;
    }
    std::cout << "day 1 part 1" << std::endl;
    std::cout << kIncreese << std::endl;
  }

  std::vector<int> do_filtr_data(std::vector<int> raw_data) {
    std::vector<int> filtr_data = {};
    for (size_t i = 2; i < raw_data.size(); i++) {
      int filt_value = 0;
      for (int i1 = 2; i1 >= 0; i1--)
        filt_value += raw_data[i - i1];
      filtr_data.emplace_back(filt_value);
    }
    return filtr_data;
  }
  void part2() {
    auto vector = read_data();
    auto vectorFiltredData = do_filtr_data(vector);
    auto last_value = vectorFiltredData.at(0);
    int kIncreese = 0;
    int kDecreese = 0;
    for (auto const el : vectorFiltredData) {
      if (el > last_value)
        kIncreese++;
      last_value = el;
    }
    std::cout << "day 1 part 2" << std::endl;
    std::cout << kIncreese << std::endl;
  }

}