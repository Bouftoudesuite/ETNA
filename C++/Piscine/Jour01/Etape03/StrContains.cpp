#include <string>

bool		StrContains(std::string str, char c)
{
  unsigned int	i;
  bool		contains;

  i = 0;
  contains = false;
  while (i < str.size())
  {
    if (str[i] == c)
      contains = true;
    i++;
  }
  return contains;
}
