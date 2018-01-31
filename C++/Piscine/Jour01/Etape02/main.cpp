#include <iostream>
#include <string>

int		main()
{
  unsigned int	i;
  std::string	str;

  std::cin >> str;
  while (str != "quit")
  {
    i = 0;
    while (i < str.size())
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] -= 32;
      i++;
    }
    std::cout << str << std::endl;
    std::cin >> str;
  }
  return (0);
}
