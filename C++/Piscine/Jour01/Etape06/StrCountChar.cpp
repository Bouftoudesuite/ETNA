#include <iostream>
#include <string>

std::string	StrTrim(std::string operation)
{
  unsigned int	i;
  std::string	str_trim;

  i = 0;
  while (i < operation.size())
  {
    if (operation[i] != ' ')
      str_trim.push_back(operation[i]);
    i++;
  }
  return (str_trim);
}

std::string	StrFirst(std::string operation)
{
  unsigned int	i;
  std::string	str_first;

  i = 0;
  while (operation[i] != '+')
  {
    str_first.push_back(operation[i]);
    i++;
  }
  return (str_first);
}

std::string	StrSecond(std::string operation)
{
  unsigned int	i;
  std::string	str_second;

  i = 0;
  while (operation[i] != '+')
    i++;
  i++;
  while (i < operation.size())
  {
    str_second.push_back(operation[i]);
    i++;
  }
  return (str_second);
}

int		StrAdd(std::string operation)
{
  unsigned int  nb_first;
  unsigned int  nb_second;
  std::string	str_first;
  std::string	str_second;

  operation = StrTrim(operation);
  str_first = StrFirst(operation);
  str_second = StrSecond(operation);
  nb_first = std::stoi(str_first);
  nb_second = std::stoi(str_second);
  return (nb_first + nb_second);
}
