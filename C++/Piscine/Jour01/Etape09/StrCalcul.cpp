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
  while (operation[i] != '+' && operation[i] != '-' && operation[i] != '*'
	 && operation[i] != '/')
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
  while (operation[i] != '+' && operation[i] != '-' && operation[i] != '*'
	 && operation[i] != '/')
    i++;
  i++;
  while (i < operation.size())
  {
    str_second.push_back(operation[i]);
    i++;
  }
  return (str_second);
}

char		FindOperator(std::string operation)
{
  unsigned int	i;

  i = 0;
  while (i < operation.size())
  {
    if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*'
	|| operation[i] == '/')
      return (operation[i]);
    i++;
  }
  return ('\0');
}

int		StrCalcul(std::string operation)
{
  char		signe;
  unsigned int  nb_first;
  unsigned int  nb_second;

  operation = StrTrim(operation);
  signe = FindOperator(operation);
  nb_first = std::stoi(StrFirst(operation));
  nb_second = std::stoi(StrSecond(operation));
  if (signe == '+')
    return (nb_first + nb_second);
  else if (signe == '-')
    return (nb_first - nb_second);
  else if (signe == '*')
    return (nb_first * nb_second);
  else if (signe == '/' && nb_second != 0)
    return (nb_first / nb_second);
  else if (signe == '/' && nb_second == 0)
    std::cout << "Error" << std::endl;
  return (0);
}
