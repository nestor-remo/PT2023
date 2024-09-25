#include "func.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

int main() {

  std::cout << "---------AAPL VALUES---------" << std::endl;

  // PARSE AAPL CSV
  std::ifstream file1;
  file1.open("AAPL.csv");
  if (!file1.is_open()) {
    return -1;
  }

  //parses the adj_close column of the csv file
  std::vector<double> aapl_values;
  int cellCount = -1;
  std::string line, cell;
  std::getline(file1, line);
  while (std::getline(file1, cell, ',')) {
    cellCount++;
    if (cellCount == 5) {
      aapl_values.push_back(std::stod(cell));
    }
    if (cellCount == 6) {
      cellCount = 0;
    }
  }

  // DEBUG: prints all values of aapl
  for (int i = 0; i < aapl_values.size(); i++) {
    std::cout << aapl_values[i] << std::endl;
  }

  file1.close();

  std::cout << "---------MSFT VALUES---------" << std::endl;

  // PARSE MSFT CSV
  std::ifstream file2;
  file2.open("MSFT.csv");
  if (!file2.is_open()) {
    return -1;
  }

  std::vector<double> msft_values;
  cellCount = -1;
  std::getline(file2, line);
  while (std::getline(file2, cell, ',')) {
    cellCount++;
    if (cellCount == 5) {
      msft_values.push_back(std::stod(cell));
    }
    if (cellCount == 6) {
      cellCount = 0;
    }
  }

  // DEBUG: prints all values of msft
  for (int i = 0; i < msft_values.size(); i++) {
    std::cout << msft_values[i] << std::endl;
  }

  file2.close();

  std::cout << "\n\n";
  // TODO 1: Find the range *COMPLETED*
  std::cout << "AAPL RANGE: ";

  double max = *max_element(aapl_values.begin(), aapl_values.end());
  double min = *min_element(aapl_values.begin(), aapl_values.end());

  double range = max - min;
  std::cout << range << std::endl;

  std::cout << "MSFT RANGE: ";

  max = *max_element(msft_values.begin(), msft_values.end());
  min = *min_element(msft_values.begin(), msft_values.end());

  range = max - min;
  std::cout << range << std::endl;

  // TODO 2: Find the IQR *COMPLETED*
  // find median of the vector
  // split the vector into two vectors
  //  Q1 = median of first half
  //  Q3 = median of second half
  //  IQR = Q3 - Q1

  int median_aapl = findMedian(aapl_values);
  int median_msft = findMedian(msft_values);

  std::cout << "\n\n";

  std::cout << "AAPL MEDIAN: " << median_aapl << std::endl;
  std::cout << "MSFT MEDIAN: " << median_msft << std::endl;

  std::pair<std::vector<double>, std::vector<double>> aapl_split =
      split(aapl_values);
  double aapl_Q1 = findMedian(aapl_split.first);
  double aapl_Q3 = findMedian(aapl_split.second);

  double aapl_IQR = aapl_Q3 - aapl_Q1;

  std::cout << "\n\n";

  std::cout << "AAPL Q1: " << aapl_Q1 << std::endl;
  std::cout << "AAPL Q3 " << aapl_Q3 << std::endl;
  std::cout << "AAPL IQR: " << aapl_IQR << std::endl;

  std::pair<std::vector<double>, std::vector<double>> msft_split =
      split(msft_values);
  double msft_Q1 = findMedian(msft_split.first);
  double msft_Q3 = findMedian(msft_split.second);

  double msft_IQR = msft_Q3 - msft_Q1;

  std::cout << "\n\n";

  std::cout << "MSFT Q1: " << msft_Q1 << std::endl;
  std::cout << "MSFT Q3 " << msft_Q3 << std::endl;
  std::cout << "MSFT IQR: " << msft_IQR << std::endl;

  // TODO 3: Find the Std. Deviation
  // sum the vector
  // square the sum
  // divide sum by vector.size()
  // square root the division

  double aapl_mean = findMean(aapl_values);
  double msft_mean = findMean(msft_values);

  double aapl_Deviation = Deviation(aapl_values);
  double msft_Deviation = Deviation(msft_values);

  std::cout << "\n\n";

  std::cout << "AAPL DEVIATION: " << aapl_Deviation << std::endl;
  std::cout << "MSFT DEVIATION: " << msft_Deviation << std::endl;

  // TODO 4: Find correlation coefficient
  double files_correlation = correlation(aapl_values, msft_values, aapl_mean, msft_mean, aapl_Deviation, msft_Deviation);

  std::cout << "\n\n";

  std::cout << "CORRELATION BETWEEN SETS " << files_correlation << std::endl;
  // TODO 5: Determine if the vectors are cointegrated
}