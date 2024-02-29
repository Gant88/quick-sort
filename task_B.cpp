#include <iostream>
#include <string>
#include <vector>

struct pattern{
  std::string login;
  uint32_t tasks;
  uint32_t sum;

  bool operator < (const pattern &p) const{
      if(tasks<p.tasks) return true;
      else if(tasks==p.tasks){
          if(sum>p.sum) return true;
          else if(sum==p.sum){
              if(login>p.login)
                  return true;
          }
      }

      return false;
  }

  bool operator<=(const pattern &p) const{
      if(tasks<p.tasks) return true;
      else if(tasks==p.tasks){
          if(sum>p.sum) return true;
          else if(sum==p.sum){
              if(login>p.login || login==p.login)
                  return true;
          }
      }
      return false;
  }

  bool operator>=(const pattern &p) const{
      if(tasks>p.tasks) return true;
      else if(tasks==p.tasks){
          if(sum<p.sum) return true;
          else if(sum==p.sum){
              if(login<p.login || login==p.login)
                  return true;
          }
      }
      return false;
  }

  bool operator>(const pattern &p) const{
      if(tasks>p.tasks) return true;
      else if(tasks==p.tasks){
          if(sum<p.sum) return true;
          else if(sum==p.sum){
              if(login<p.login)
                  return true;
          }
      }
      return false;
  }
};

void quickSort(std::vector<pattern>::iterator begin,
               std::vector<pattern>::iterator end){

    if(begin>=end){ return;}

    auto ind = end - begin;
    pattern pivot = *(begin + ind/2);

    auto left_tmp = begin;
    auto right_tmp = end;

    while(left_tmp<=right_tmp){
        while(*left_tmp>pivot)
            left_tmp++;
        while(*right_tmp<pivot)
            right_tmp--;

        if(left_tmp<=right_tmp){
            std::iter_swap(left_tmp, right_tmp);
            left_tmp++;
            right_tmp--;
        }
    }

    quickSort(begin, right_tmp);
    quickSort(left_tmp, end);
}

int main(){

    uint32_t n;
    std::cin >> n;

    std::vector<pattern> vec;
    for(uint32_t i = 0; i < n; i++){
        pattern card;
        std::cin >> card.login >> card.tasks >> card.sum;
        vec.push_back(card);
    }

    quickSort(vec.begin(), vec.end()-1);
    for(uint32_t j=0;j<vec.size();j++)
        std::cout << vec[j].login << std::endl;

    return 0;
}
