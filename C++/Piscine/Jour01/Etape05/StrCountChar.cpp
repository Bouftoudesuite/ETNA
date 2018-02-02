#include <string>

int		StrCountChar(std::string str, char c)
{
  int		count;
  unsigned int	i;

  i = 0;
  count = 0;
  while (i < str.size())
  {
    if (str[i] == c)
      count++;
    i++;
  }
  return count;
}
