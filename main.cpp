#include <iostream>
#include <string>
#include <algorithm>

class Solver {
 private:
  std::string number_1_;
  std::string number_2_;
 public:
  Solver() {
    std::cin >> number_1_ >> number_2_;
  }
  char operator()() {
    if (number_1_[0] == '-' && number_2_[0] != '-') {
      return '<';
    }
    if (number_1_[0] == '-' && number_2_[0] != '-') {
      return '>';
    }

    ssize_t comma_place = -1;
    char answer = '=';
    ssize_t i = 0;
    for (; i < std::min(number_1_.length(), number_2_.length()); ++i) {
      if (number_1_[i] == ',') {
        if (comma_place != -1) {
          return '>';
        }
        comma_place = i;
      }
      if (number_2_[i] == ',') {
        if (comma_place != -1 && comma_place < i) {
          return '<';
        }
        comma_place = i;
      }
      if (number_1_[i] != ',' && number_2_[i] != 0 && number_2_[i] != number_1_[i]) {
        answer = (number_1_[i] < number_2_[i] && answer == '=') ? '<' : '>';
      }
    }

    if (answer != '='){
      return answer;
    }

    std::string& with_tail = (number_1_.length() > number_2_.length()) ? number_1_ : number_2_;
    char sign = (number_1_.length() > number_2_.length()) ? '>' : '<';
    for (; i < std::max(number_1_.length(), number_2_.length()); ++i){
      if (with_tail[i] != '0'){
        return sign;
      }
    }
    return '=';
  }
};

int main() {
  Solver solver;
  std::cout << solver();
  return 0;
}
