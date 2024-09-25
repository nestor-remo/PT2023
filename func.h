#ifndef FUNC_H
#define FUNC_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

double findMedian(std::vector<double> &file) {
  double median = 0;
  int size = file.size();
  std::sort(file.begin(), file.end());
  if (size % 2 == 0) {
    median = (file[size / 2.0 - 1] + file[size / 2.0]) / 2.0;
  } else {
    median = file[size / 2.0];
  }
  return median;
}

std::pair<std::vector<double>, std::vector<double>> split(std::vector<double> file) {
  int mid = file.size() / 2;

  std::vector<double> firstHalf(file.begin(), file.begin() + mid);
  std::vector<double> secondHalf(file.begin() + mid, file.end());

  return std::make_pair(firstHalf, secondHalf);
}

double findMean(std::vector<double> file) {
  double sum = 0;
  double mean = 0;
  for (int i = 0; i < file.size(); i++) {
    sum += file[i];
  }
  mean = sum / file.size();
  return mean;
}

double Deviation(std::vector<double> file) {
  int size = file.size();
  double par = 0;
  double deviation = 0;
  double mean = 0;
  mean = findMean(file);
  for (int i = 0; i < size; i++) {
    par += std::pow(file[i] - mean, 2);
  }
  deviation = par / (size - 1);
  deviation = std::sqrt(deviation);
  return deviation;
}

double correlation(std::vector<double> data1, std::vector<double> data2,
                   double mean1, double mean2, double deviation1,
                   double deviation2) {
  
  double correlation = 0;
  double numerator = 0;
  double denominator = 0;

  for (int i = 0; i < data1.size(); i++) {
    numerator += ((data1[i] - mean1) * (data2[i] - mean2));
  }
  numerator = numerator / data1.size();

  denominator = deviation1 * deviation2;

  correlation = numerator / denominator;

  return correlation;
}

#endif