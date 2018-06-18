#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

void challengeSolver(std::vector<char>& input)
{
  std::list<char> output;
  auto counter = 0;
  for(auto iter = std::begin(input); iter != std::end(input); ++iter)
  {
    if (output.empty() || output.back() == *iter)
    {
      output.emplace_back(*iter);
      counter++;
      continue;
    }
    else
    {
      if (counter >= 3)
      {
        auto delete_iter = std::end(output);
        std::advance(delete_iter, -counter);
        output.erase(delete_iter, std::end(output));
        
        if (output.size() > 0)
        {
          auto riter = std::rbegin(output); 
          if (*riter == *iter)
          {
            counter = 1;
            while((*riter == *iter) && (riter != std::rend(output)))
            {
              counter++;
              ++riter;
            }
            output.emplace_back(*iter);
          }
          else
          {
            output.emplace_back(*iter);
            counter = 1;
          }
        }
        else
        {
          output.emplace_back(*iter);
          counter = 1;
        }
      }
      else
      {
        output.emplace_back(*iter);
        counter = 1;
      }

    }
  }
  for(const auto& elem: output)
  {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv)
{
  //std::vector<char> input{'A', 'B', 'B', 'C', 'C', 'C', 'B', 'B', 'D'};
  std::vector<char> input{'A', 'B', 'B', 'B', 'C'};
  challengeSolver(input);
  return 0;
}
